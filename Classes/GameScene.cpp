#include"GameScene.h"

void MouseRect::update(float dt)
{
	clear();
	Node *parent = getParent();
	end = touch_end - parent->getPosition();
	drawRect(start, end, Color4F(0, 1, 0, 1));
}
void MouseRect::reset()
{
	setVisible(false);
	if (isScheduled(schedule_selector(MouseRect::update)))
	{
		unschedule(schedule_selector(MouseRect::update));
	}
	touch_start = Point{ 0,0 };
	touch_end = Point{ 0,0 };
	start = Point{ 0,0 };
	end = Point{ 0,0 };
}

int GameScene::Money;
TMXTiledMap *GameScene::_tiledMap1;
Rect GameScene::select_rect;
int GameScene::mapType;
int GameScene::playerid;

//Mouse Rect��ط���
Rect GameScene::getvisionRect()
{
	auto visible_origin = Vec2(0, 0) - _tiledMap1->getPosition();
	auto visible_size = Director::getInstance()->getVisibleSize();
	return cocos2d::Rect(visible_origin, visible_size);
}

GameScene* GameScene::create(SocketClient* _socket_client, SocketServer* _socket_server)
{
	GameScene *game_scene = new (std::nothrow) GameScene();
	if (game_scene && game_scene->init(_socket_client, _socket_server))
	{
		game_scene->autorelease();
		return game_scene;
	}
	CC_SAFE_DELETE(game_scene);

	return nullptr;
}

Scene * GameScene::createScene(SocketClient* _socket_client, SocketServer* _socket_server)
{
	Scene *scene = Scene::createWithPhysics();
	PhysicsWorld *phyWorld = scene->getPhysicsWorld();
	//������������debug
	//phyWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	phyWorld->setGravity(Vec2(0, 0));
	auto layer = GameScene::create(_socket_client, _socket_server);
	scene->addChild(layer);
	return scene;
}

bool GameScene::init(SocketClient* _socket_client, SocketServer* _socket_server)
{
	if (!Layer::init())
	{
		return false;
	}
	//���������
	socket_client = _socket_client;
	socket_server = _socket_server;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	/************��ͼ************/
	//��Ϸ��ͼ
	if (mapType == 1)
	{
		_tiledMap1 = TMXTiledMap::create(GAMEMAP1);
	}
	else
	{
		_tiledMap1 = TMXTiledMap::create(GAMEMAP2);
	}
	_tiledMap1->setAnchorPoint(Vec2(0, 0));
	_tiledMap1->setPosition(0, 0);
	addChild(_tiledMap1, 0);
	//TMXLayer *colliableLayer = _tiledMap1->getLayer("CollidableLayer");
	TMXObjectGroup *objectsGroup = _tiledMap1->objectGroupNamed("Objects");
	ValueVector objects = objectsGroup->getObjects();
	for (auto obj : objects) 
	{
		ValueMap& dict = obj.asValueMap();
		float x = dict["x"].asFloat();
		float y = dict["y"].asFloat();
		Point p1 = Vec2(x, y);
		Point p2 = gettiledMap()->convertToNodeSpace(p1);
		float width = dict["width"].asFloat();
		float height = dict["height"].asFloat();
		PhysicsBody * phy = PhysicsBody::createBox(Size(width, height));
		phy->setDynamic(false);
		Sprite * sp = Sprite::create();
		sp->setPosition(Vec2(x, y));
		sp->setAnchorPoint(ccp(0,0));
		sp->setContentSize(Size(width, height));
		sp->setPhysicsBody(phy);
		_tiledMap1->addChild(sp);
	}


	//��ͼ����
	schedule(schedule_selector(GameScene::update));
	//��ͼ�ƶ�������¼�
	mouse_event = EventListenerMouse::create();
	mouse_event->onMouseMove = CC_CALLBACK_1(GameScene::onMouseMove, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(mouse_event, 1);
	//���ּ����¼�
	auto keyboard_listener = EventListenerKeyboard::create();
	keyboard_listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboard_listener, this);
	
	//������һ�����ο�
	mouseRect = MouseRect::create();
	mouseRect->setVisible(false);
	_tiledMap1->addChild(mouseRect);
	mouseRectListener = EventListenerTouchOneByOne::create();
	mouseRectListener->onTouchBegan = CC_CALLBACK_2(GameScene::mouseRectOnTouchBegan, this);
	mouseRectListener->onTouchMoved = CC_CALLBACK_2(GameScene::mouseRectOnTouchMoved, this);
	mouseRectListener->onTouchEnded = CC_CALLBACK_2(GameScene::mouseRectOnTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseRectListener, this);

	if (_socket_server)
	{
		int t = _socket_server->getconnection_num();
		log("%d", t);
	}
	//��������
	if ((_socket_server&&_socket_server->getconnection_num() >= 1)||(_socket_client&&_socket_client->total()>=1))
	{
		auto tiledmap = GameScene::gettiledMap();
		auto group = tiledmap->getObjectGroup("Buildings");
		ValueMap buildobj;
		buildobj = group->getObject("base1");
		float x1 = buildobj["x"].asFloat();
		float y1 = buildobj["y"].asFloat();
		float width1 = buildobj["width"].asFloat();
		float height1 = buildobj["height"].asFloat();
		PhysicsBody * phy1 = PhysicsBody::createBox(Size(width1, height1));
		phy1->setDynamic(false);
		Sprite * sp1 = Sprite::create();
		sp1->setPosition(Vec2(x1, y1));
		sp1->setAnchorPoint(ccp(0, 0));
		sp1->setContentSize(Size(width1, height1));
		sp1->setPhysicsBody(phy1);
		_tiledMap1->addChild(sp1);
		Buildings *base1 = Buildings::creatWithBuildingTypes(START_BASE);
		base1->setAnchorPoint(Vec2(0, 0));
		base1->setScale(1);
		base1->setPosition(Vec2(16, 16));
		base1->createBar();
		base1->hpBar->setPosition(base1->hpBar->getPosition() - Vec2(10, 0));
		_tiledMap1->addChild(base1, 10, GameSceneNodeTagBuilding);
	}
	if ((_socket_server&&_socket_server->getconnection_num() >= 2) || (_socket_client&&_socket_client->total() >= 2))
	{
		auto tiledmap = GameScene::gettiledMap();
		auto group = tiledmap->getObjectGroup("Buildings");
		ValueMap buildobj;
		buildobj = group->getObject("base2");
		float x2 = buildobj["x"].asFloat();
		float y2 = buildobj["y"].asFloat();
		float width2 = buildobj["width"].asFloat();
		float height2 = buildobj["height"].asFloat();
		PhysicsBody * phy2 = PhysicsBody::createBox(Size(width2, height2));
		phy2->setDynamic(false);
		Sprite * sp2 = Sprite::create();
		sp2->setPosition(Vec2(x2, y2));
		sp2->setAnchorPoint(ccp(0, 0));
		sp2->setContentSize(Size(width2, height2));
		sp2->setPhysicsBody(phy2);
		_tiledMap1->addChild(sp2);
		Buildings *base2 = Buildings::creatWithBuildingTypes(START_BASE);
		base2->setAnchorPoint(Vec2(0, 0));
		base2->setScale(1);
		base2->setPosition(Vec2(x2, y2));
		base2->createBar();
		base2->hpBar->setPosition(base2->hpBar->getPosition() - Vec2(10, 0));
		_tiledMap1->addChild(base2, 10, GameSceneNodeTagBuilding);
	}
	if ((_socket_server&&_socket_server->getconnection_num() >= 3) || (_socket_client&&_socket_client->total() >= 3))
	{
		auto tiledmap = GameScene::gettiledMap();
		auto group = tiledmap->getObjectGroup("Buildings");
		ValueMap buildobj;
		buildobj = group->getObject("base3");
		float x3 = buildobj["x"].asFloat();
		float y3 = buildobj["y"].asFloat();
		float width3 = buildobj["width"].asFloat();
		float height3 = buildobj["height"].asFloat();
		PhysicsBody * phy3 = PhysicsBody::createBox(Size(width3, height3));
		phy3->setDynamic(false);
		Sprite * sp3 = Sprite::create();
		sp3->setPosition(Vec2(x3, y3));
		sp3->setAnchorPoint(ccp(0, 0));
		sp3->setContentSize(Size(width3, height3));
		sp3->setPhysicsBody(phy3);
		_tiledMap1->addChild(sp3);
		Buildings *base3 = Buildings::creatWithBuildingTypes(START_BASE);
		base3->setAnchorPoint(Vec2(0, 0));
		base3->setScale(1);
		base3->setPosition(Vec2(x3, y3));
		base3->createBar();
		base3->hpBar->setPosition(base3->hpBar->getPosition() - Vec2(10, 0));
		_tiledMap1->addChild(base3, 10, GameSceneNodeTagBuilding);
	}
	if ((_socket_server&&_socket_server->getconnection_num() >= 4) || (_socket_client&&_socket_client->total() >= 4))
	{
		auto tiledmap = GameScene::gettiledMap();
		auto group = tiledmap->getObjectGroup("Buildings");
		ValueMap buildobj;
		buildobj = group->getObject("base1");
		float x4 = buildobj["x"].asFloat();
		float y4 = buildobj["y"].asFloat();
		float width4 = buildobj["width"].asFloat();
		float height4 = buildobj["height"].asFloat();
		PhysicsBody * phy4 = PhysicsBody::createBox(Size(width4, height4));
		phy4->setDynamic(false);
		Sprite * sp4 = Sprite::create();
		sp4->setPosition(Vec2(x4, y4));
		sp4->setAnchorPoint(ccp(0, 0));
		sp4->setContentSize(Size(width4, height4));
		sp4->setPhysicsBody(phy4);
		_tiledMap1->addChild(sp4);
		Buildings *base4 = Buildings::creatWithBuildingTypes(START_BASE);
		base4->setAnchorPoint(Vec2(0, 0));
		base4->setScale(1);
		base4->setPosition(Vec2(x4, y4));
		base4->createBar();
		base4->hpBar->setPosition(base4->hpBar->getPosition() - Vec2(10, 0));
		_tiledMap1->addChild(base4, 10, GameSceneNodeTagBuilding);
	}
	
	return true;
}

void GameScene::onEnter()
{
	Layer::onEnter();
	log("GameScene onEnter");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�������ز˵�
	auto backLabel = LabelTTF::create(MyUtility::gbk_2_utf8("����"), "�����п�", 15);
	backLabel->setColor(Color3B::GREEN);
	auto backMenu = MenuItemLabel::create(backLabel, CC_CALLBACK_1(GameScene::backToMenuScene, this));
	float back_x = backMenu->getContentSize().width;  //��ò˵����
	float back_y = backMenu->getContentSize().height; //��ò˵�����
	backMenu->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - back_y));
	auto mn = Menu::create(backMenu, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	//������Ӫ�˵�
	MenuItemImage *buildingMenu1 = MenuItemImage::create(CASERN, CASERN, CC_CALLBACK_1(GameScene::buildingsCreate, this));
	buildingMenu1->setAnchorPoint(Vec2(0.5, 0.5));
	buildingMenu1->setScale(1);
	float menu1_x = buildingMenu1->getContentSize().width;
	float menu1_y = buildingMenu1->getContentSize().height;
	buildingMenu1->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 40));
	buildingMenu1->setTag(START_CASERN);
	buildingMenu1->setOpacity(128);
	Menu *bmn1 = Menu::create(buildingMenu1, NULL);
	bmn1->setPosition(Vec2::ZERO);
	this->addChild(bmn1, 20);
	auto buildingLabel1 = LabelTTF::create(MyUtility::gbk_2_utf8("��Ӫ"), "�����п�", 8);
	buildingLabel1->setColor(Color3B::GREEN);
	buildingLabel1->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 40));
	this->addChild(buildingLabel1,30);

	//�����糧�˵�
	MenuItemImage *buildingMenu2 = MenuItemImage::create(ELECTRICSTATION, ELECTRICSTATION, CC_CALLBACK_1(GameScene::buildingsCreate, this));
	buildingMenu2->setAnchorPoint(Vec2(0.5, 0.5));
	buildingMenu2->setScale(1);
	float menu2_x = buildingMenu2->getContentSize().width;
	float menu2_y = buildingMenu2->getContentSize().height;
	buildingMenu2->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 80));
	buildingMenu2->setTag(START_ELECTRICSTATION);
	buildingMenu2->setOpacity(128);
	Menu *bmn2 = Menu::create(buildingMenu2, NULL);
	bmn2->setPosition(Vec2::ZERO);
	this->addChild(bmn2, 20);
	auto buildingLabel2 = LabelTTF::create(MyUtility::gbk_2_utf8("�糧"), "�����п�", 8);
	buildingLabel2->setColor(Color3B::GREEN);
	buildingLabel2->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height -80));
	this->addChild(buildingLabel2, 30);

	//����ս�������˵�
	MenuItemImage *buildingMenu3 = MenuItemImage::create(TANKFACTORY, TANKFACTORY, CC_CALLBACK_1(GameScene::buildingsCreate, this));
	buildingMenu3->setAnchorPoint(Vec2(0.5, 0.5));
	buildingMenu3->setScale(1);
	float menu3_x = buildingMenu3->getContentSize().width;
	float menu3_y = buildingMenu3->getContentSize().height;
	buildingMenu3->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 120));
	buildingMenu3->setTag(START_TANKFACTORY);
	buildingMenu3->setOpacity(128);
	Menu *bmn3 = Menu::create(buildingMenu3, NULL);
	bmn3->setPosition(Vec2::ZERO);
	this->addChild(bmn3, 20);
	auto buildingLabel3 = LabelTTF::create(MyUtility::gbk_2_utf8("ս������"), "�����п�", 8);
	buildingLabel3->setColor(Color3B::GREEN);
	buildingLabel3->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 120));
	this->addChild(buildingLabel3, 30);

	//�����󳡲˵�
	MenuItemImage *buildingMenu4 = MenuItemImage::create(OREYARD, OREYARD, CC_CALLBACK_1(GameScene::buildingsCreate, this));
	buildingMenu4->setAnchorPoint(Vec2(0.5, 0.5));
	buildingMenu4->setScale(1);
	float menu4_x = buildingMenu4->getContentSize().width;
	float menu4_y = buildingMenu4->getContentSize().height;
	buildingMenu4->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 160));
	buildingMenu4->setTag(START_OREYARD);
	buildingMenu4->setOpacity(128);
	Menu *bmn4 = Menu::create(buildingMenu4, NULL);
	bmn4->setPosition(Vec2::ZERO);
	this->addChild(bmn4, 20);
	auto buildingLabel4 = LabelTTF::create(MyUtility::gbk_2_utf8("��"), "�����п�", 8);
	buildingLabel4->setColor(Color3B::GREEN);
	buildingLabel4->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 160));
	this->addChild(buildingLabel4, 30);
	

	//�����󹤲˵�
	MenuItemImage *soldierMenu1 = MenuItemImage::create(MINER1, MINER1, CC_CALLBACK_1(GameScene::soldiersCreate, this));
	soldierMenu1->setAnchorPoint(Vec2(0.5, 0.5));
	soldierMenu1->setScale(1.2);
	soldierMenu1->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 200));
	soldierMenu1->setTag(START_MINER);
	soldierMenu1->setOpacity(128);
	Menu *smn1 = Menu::create(soldierMenu1, NULL);
	smn1->setPosition(Vec2::ZERO);
	this->addChild(smn1, 20);
	auto soldierLabel1 = LabelTTF::create(MyUtility::gbk_2_utf8("��"), "�����п�", 8);
	soldierLabel1->setColor(Color3B::GREEN);
	soldierLabel1->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 200));
	this->addChild(soldierLabel1,30);

	//����˵�
	MenuItemImage *soldierMenu2 = MenuItemImage::create(POLICEMAN1, POLICEMAN1, CC_CALLBACK_1(GameScene::soldiersCreate, this));
	soldierMenu2->setAnchorPoint(Vec2(0.5, 0.5));
	soldierMenu2->setScale(1.2);
	soldierMenu2->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 225));
	soldierMenu2->setTag(START_POLICEMAN);
	soldierMenu2->setOpacity(128);
	Menu *smn2 = Menu::create(soldierMenu2, NULL);
	smn2->setPosition(Vec2::ZERO);
	this->addChild(smn2, 20);
	auto soldierLabel2 = LabelTTF::create(MyUtility::gbk_2_utf8("����"), "�����п�", 8);
	soldierLabel2->setColor(Color3B::GREEN);
	soldierLabel2->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 225));
	this->addChild(soldierLabel2, 30);

	//̹�˲˵�
	MenuItemImage *soldierMenu3 = MenuItemImage::create(TANK1, TANK1, CC_CALLBACK_1(GameScene::soldiersCreate, this));
	soldierMenu3->setAnchorPoint(Vec2(0.5, 0.5));
	soldierMenu3->setScale(1.2);
	soldierMenu3->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 250));
	soldierMenu3->setTag(START_TANK);
	soldierMenu3->setOpacity(128);
	Menu *smn3 = Menu::create(soldierMenu3, NULL);
	smn3->setPosition(Vec2::ZERO);
	this->addChild(smn3, 20);
	auto soldierLabel3 = LabelTTF::create(MyUtility::gbk_2_utf8("̹��"), "�����п�", 8);
	soldierLabel3->setColor(Color3B::GREEN);
	soldierLabel3->setPosition(Vec2(visibleSize.width-20, origin.y + visibleSize.height - 250));
	this->addChild(soldierLabel3, 30);

	//սʿ�˵�
	MenuItemImage *soldierMenu4 = MenuItemImage::create(WARRIOR1, WARRIOR1, CC_CALLBACK_1(GameScene::soldiersCreate, this));
	soldierMenu4->setAnchorPoint(Vec2(0.5, 0.5));
	soldierMenu4->setScale(1.2);
	soldierMenu4->setPosition(Vec2(visibleSize.width - 20, origin.y + visibleSize.height - 275));
	soldierMenu4->setTag(START_WARRIOR);
	soldierMenu4->setOpacity(128);
	Menu *smn4 = Menu::create(soldierMenu4, NULL);
	smn4->setPosition(Vec2::ZERO);
	this->addChild(smn4, 20);
	auto soldierLabel4 = LabelTTF::create(MyUtility::gbk_2_utf8("սʿ"), "�����п�", 8);
	soldierLabel4->setColor(Color3B::GREEN);
	soldierLabel4->setPosition(Vec2(visibleSize.width - 20, origin.y + visibleSize.height - 275));
	this->addChild(soldierLabel4, 30);


	//������Ӵ���������
	spriteContactListener = EventListenerPhysicsContact::create();
	spriteContactListener->onContactBegin = [this](PhysicsContact &contact)
	{
		log("SPRITE CONTACT");
		Sprite *SpriteA = (Sprite *)(contact.getShapeA()->getBody()->getNode());
		Sprite *SpriteB = (Sprite *)(contact.getShapeB()->getBody()->getNode());
		if (!SpriteA || !SpriteB)
		{
			return false;
		}
		//�˴�Ϊ�����ֽӴ�
		if (SpriteA->getTag() == GameSceneNodeTagSoldier && SpriteB->getTag() == GameSceneNodeTagSoldier)
		{
			auto soldierSpriteA = dynamic_cast<Soldiers *>(SpriteA);
			auto soldierSpriteB = dynamic_cast<Soldiers *>(SpriteB);
			if (!soldierSpriteA->getifSelect() && !soldierSpriteB->getifSelect())
			{
				//ͨ���������������λ��
				Size s = soldierSpriteA->getContentSize();
				Vec2 rand = soldierSpriteB->getPosition() + (Vec2(s.width, s.height) * (1 + CCRANDOM_0_1()));
				soldierSpriteA->setPosition(rand);
				return false;
			}
			/*if (!soldierSpriteA->getifSelect() && soldierSpriteB->getifSelect())
			{
			Size s = soldierSpriteA->getContentSize();
			Vec2 rand = soldierSpriteA->getPosition() + (Vec2(s.width, s.height) * (1 + CCRANDOM_0_1()));
			soldierSpriteB->setPosition(rand);
			return false;
			}
			return false;*/
			/*Size s = soldierSpriteA->getContentSize();
			Vec2 rand = soldierSpriteB->getPosition() + (Vec2(s.width, s.height) * (1 + CCRANDOM_0_1()));
			soldierSpriteA->setPosition(rand);
			return false;*/
		}
		if (SpriteA->getTag() == GameSceneNodeTagBuilding && SpriteB->getTag() == GameSceneNodeTagSoldier)
		{
			auto soldierSpriteA = dynamic_cast<Soldiers *>(SpriteA);
			auto soldierSpriteB = dynamic_cast<Buildings *>(SpriteB);

		}
		return false;
	};

	spriteContactListener->onContactSeparate = [this](PhysicsContact &contact)
	{
		return;
	};
	_eventDispatcher->addEventListenerWithFixedPriority(spriteContactListener, 20);

	//ʵʱˢ�½�Ǯ
	this->Money = 5000;
	__String *currentMoney = __String::createWithFormat("Money:%d", this->Money);
	auto MoneyLabel = LabelTTF::create(currentMoney->getCString(), "Marker Felt", 15);
	float Money_x = MoneyLabel->getContentSize().width;
	float Money_y = MoneyLabel->getContentSize().height;
	MoneyLabel->setPosition(origin.x + visibleSize.width - Money_x * 0.75, origin.y + Money_y);
	MoneyLabel->setColor(Color3B::RED);
	this->addChild(MoneyLabel, 20, GameSceneNodeTagMoney);
	this->schedule(schedule_selector(GameScene::moneyUpdate), 1.0f, CC_REPEAT_FOREVER, 0);

}

void GameScene::onExit()
{
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeEventListener(mouse_event);
	Director::getInstance()->getEventDispatcher()->removeEventListener(keyboard_listener);
	Director::getInstance()->getEventDispatcher()->removeEventListener(spriteContactListener);
	Director::getInstance()->getEventDispatcher()->removeEventListener(mouseRectListener);
	this->unschedule(schedule_selector(GameScene::moneyUpdate));
	this->unschedule(schedule_selector(GameScene::update));
	if (socket_client)
	{
		socket_client->close();
		delete socket_client;
		socket_client = nullptr;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	if (socket_server)
	{
		socket_server->close();
		delete socket_server;
		socket_server = nullptr;
	}
	if (_onExitCallback)
		_onExitCallback();
	if (_componentContainer && !_componentContainer->isEmpty())
	{
		_componentContainer->onExit();
	}
	this->pause();
	_running = false;
	for (const auto &child : _children)
		child->onExit();
}

//����MenuScene
void GameScene::backToMenuScene(Ref *pSender)
{
	if (socket_server)
	{
		socket_server->close();
		//delete socket_server;
		socket_server = nullptr;
	}
	socket_client->close();
	delete socket_client;
	socket_client = nullptr;
	Scene *sc = Scene::create();
	auto layer = MenuScene::create();
	sc->addChild(layer);

	auto reScene = TransitionSplitRows::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

//ѡ�����ｨ��
void GameScene::buildingsCreate(Ref *pSender)
{
	MenuItem *mnitem = (MenuItem *)pSender;
	switch (mnitem->getTag())
	{
		case START_CASERN:
		{
			if (Money < CASERN_PRICE)//�ж�Ǯ�Ƿ��㹻
			{
				break;
			}
			Money -= CASERN_PRICE;
			//������׼����ʱ����ÿ�ֽ�����׼��ʱ�䲻ͬ
			this->scheduleOnce(schedule_selector(GameScene::casernReady), 2.0f);
			break;
		}
		case START_ELECTRICSTATION:
		{
			if (Money < ELECTRICSTATION_PRICE)//�ж�Ǯ�Ƿ��㹻
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/insufficientfund.wav");
				break;
			}
			Money -= ELECTRICSTATION_PRICE;
			//������׼����ʱ����ÿ�ֽ�����׼��ʱ�䲻ͬ
			this->scheduleOnce(schedule_selector(GameScene::electricStationReady), 1.8f);
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/unitready.wav");
			break;
		}
		case START_TANKFACTORY:
		{
			if (Money < TANKFACTORY_PRICE)      //�ж�Ǯ�Ƿ��㹻
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/insufficientfund.wav");
				break;
			}
			Money -= TANKFACTORY_PRICE;
			this->scheduleOnce(schedule_selector(GameScene::tankFactoryReady), 2.5f);
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/unitready.wav");
			break;
		}
		case START_OREYARD:
		{
			if (Money < OREYARD_PRICE)         //�ж�Ǯ�Ƿ��㹻
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/insufficientfund.wav");
				break;
			}
			Money -= OREYARD_PRICE;
			this->scheduleOnce(schedule_selector(GameScene::oreYardReady), 1.5f);
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/unitready.wav");
			break;
		}
	}
}

void GameScene::soldiersCreate(Ref *pSender)
{
	MenuItem *mnitm = (MenuItem *)pSender;
	switch (mnitm->getTag())
	{
	case START_MINER:
	{
		if (Money < MINER_PRICE || !_tiledMap1->getChildByName("oreYard"))
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/insufficientfund.wav");
			break;
		}
		Money -= MINER_PRICE;
		//׼����ʱ��
		this->scheduleOnce(schedule_selector(GameScene::minerReady), 1.0f);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/unitready.wav");
		break;
	}
	case START_POLICEMAN:
	{
		if (Money < POLICEMAN_PRICE || !_tiledMap1->getChildByName("casern"))
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/insufficientfund.wav");
			break;
		}
		Money -= POLICEMAN_PRICE;
		//׼����ʱ��
		this->scheduleOnce(schedule_selector(GameScene::policemanReady), 1.5f);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/unitready.wav");
		break;
	}
	case START_TANK:
	{
		if (Money < TANK_PRICE || !_tiledMap1->getChildByName("tankFactory"))
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/insufficientfund.wav");
			break;
		}
		Money -= TANK_PRICE;
		this->scheduleOnce(schedule_selector(GameScene::tankReady), 2.0f);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/unitready.wav");
		break;
	}
	case START_WARRIOR:
	{
		if (Money < WARRIOR_PRICE || !_tiledMap1->getChildByName("casern"))
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/insufficientfund.wav");
			break;
		}
		Money -= WARRIOR_PRICE;
		this->scheduleOnce(schedule_selector(GameScene::warriorReady), 2.0f);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/unitready.wav");
		break;
	}
	}
}

//���ֻ���
void GameScene::minerReady(float dt)
{
	//ͨ��Soldiers��������ʿ��
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto miner = Soldiers::createWithSoldierTypes(START_MINER);
	miner->setAnchorPoint(Vec2(0.5, 0.5));
	miner->setScale(1.2);
	float soldiers_x = miner->getContentSize().width;
	float soldiers_y = miner->getContentSize().height;
	Size s = _tiledMap1->getChildByName("oreYard")->getContentSize() * 0.3;
	Vec2 position = _tiledMap1->getChildByName("oreYard")->getPosition() + Vec2(s.width, 0);
	miner->setPosition(position);
	//miner->setPosition(Vec2(visibleSize.width - soldiers_x, visibleSize.height - soldiers_y / 6));
	miner->setName("miner");
	miner->createBar();
	_tiledMap1->addChild(miner, 10, GameSceneNodeTagSoldier);
}
void GameScene::policemanReady(float dt)
{
	//ͨ��Soldiers��������ʿ��
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto policeman = Soldiers::createWithSoldierTypes(START_POLICEMAN);
	policeman->setAnchorPoint(Vec2(0.5, 0.5));
	policeman->setScale(1.2);
	float soldiers_x = policeman->getContentSize().width;
	float soldiers_y = policeman->getContentSize().height;
	Size s = _tiledMap1->getChildByName("casern")->getContentSize() * 0.3;
	Vec2 position = _tiledMap1->getChildByName("casern")->getPosition() + Vec2(s.width, 0);
	policeman->setPosition(position);
	//policeman->setPosition(Vec2(visibleSize.width - soldiers_x, visibleSize.height - soldiers_y / 6));
	policeman->setName("policeman");
	policeman->createBar();
	_tiledMap1->addChild(policeman, 10, GameSceneNodeTagSoldier);
}
void GameScene::warriorReady(float dt)
{
	//ͨ��Soldiers��������ʿ��
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto warrior = Soldiers::createWithSoldierTypes(START_WARRIOR);
	warrior->setAnchorPoint(Vec2(0.5, 0.5));
	warrior->setScale(1.2);
	float soldiers_x = warrior->getContentSize().width;
	float soldiers_y = warrior->getContentSize().height;
	Size s = _tiledMap1->getChildByName("casern")->getContentSize() * 0.3;
	Vec2 position = _tiledMap1->getChildByName("casern")->getPosition() + Vec2(s.width, 0);
	warrior->setPosition(position);
	warrior->setName("warrior");
	warrior->createBar();
	_tiledMap1->addChild(warrior, 10, GameSceneNodeTagSoldier);
}
void GameScene::tankReady(float dt)
{
	//ͨ��Soldiers��������ʿ��
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto tank = Soldiers::createWithSoldierTypes(START_TANK);
	tank->setAnchorPoint(Vec2(0.5, 0.5));
	tank->setScale(1.2);
	float soldiers_x = tank->getContentSize().width;
	float soldiers_y = tank->getContentSize().height;
	Size s = _tiledMap1->getChildByName("tankFactory")->getContentSize() * 0.3;
	Vec2 position = _tiledMap1->getChildByName("tankFactory")->getPosition() + Vec2(s.width, 0);
	tank->setPosition(position);
	//tank->setPosition(Vec2(visibleSize.width - soldiers_x, visibleSize.height - soldiers_y / 6));
	tank->setName("tank");
	tank->createBar();
	_tiledMap1->addChild(tank, 10, GameSceneNodeTagSoldier);
}


//���������
void GameScene::casernReady(float dt)
{
	//ͨ��Buildings��������������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto casern = Buildings::creatWithBuildingTypes(START_CASERN);
	casern->setAnchorPoint(Vec2(0, 0));
	casern->setScale(1);
	float building_x = casern->getContentSize().width;
	float building_y = casern->getContentSize().height;
	casern->setPosition(Vec2(16, 176));
	casern->setName("casern");
	casern->createBar();
	_tiledMap1->addChild(casern, 10, GameSceneNodeTagBuilding);
}
void GameScene::electricStationReady(float dt)
{
	//ͨ��Buildings��������������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto electricStation = Buildings::creatWithBuildingTypes(START_ELECTRICSTATION);
	electricStation->setAnchorPoint(Vec2(0, 0));
	electricStation->setScale(1);
	float building_x = electricStation->getContentSize().width;
	float building_y = electricStation->getContentSize().height;
	electricStation->setPosition(Vec2(112, 176));
	electricStation->setName("electricStation");
	electricStation->createBar();
	_tiledMap1->addChild(electricStation, 10, GameSceneNodeTagBuilding);
}
void GameScene::tankFactoryReady(float dt)
{
	//ͨ��Building��������������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto tankFactory = Buildings::creatWithBuildingTypes(START_TANKFACTORY);
	tankFactory->setAnchorPoint(Vec2(0, 0));
	tankFactory->setScale(1);
	float building_x = tankFactory->getContentSize().width;
	float building_y = tankFactory->getContentSize().height;
	tankFactory->setPosition(Vec2(112, 16));
	tankFactory->setName("tankFactory");
	tankFactory->createBar();
	_tiledMap1->addChild(tankFactory, 10, GameSceneNodeTagBuilding);
}
void GameScene::oreYardReady(float dt)
{
	//ͨ��Building��������������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto oreYard = Buildings::creatWithBuildingTypes(START_OREYARD);
	oreYard->setAnchorPoint(Vec2(0, 0));
	oreYard->setScale(1);
	float building_x = oreYard->getContentSize().width;
	float building_y = oreYard->getContentSize().height;
	oreYard->setPosition(Vec2(16,96));
	oreYard->setName("oreYard");
	oreYard->createBar();
	_tiledMap1->addChild(oreYard, 10, GameSceneNodeTagBuilding);
}

void GameScene::moneyUpdate(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//����һ����ǩ�Ƴ�
	if (this->getChildByTag(GameSceneNodeTagMoney))
	{
		this->removeChildByTag(GameSceneNodeTagMoney);
	}
	//�����±�ǩ
	if (this->Money <= 0)
	{
		this->Money = 0;
	}
	__String *currentMoney = __String::createWithFormat("Money:%d", (this->Money)++);
	auto MoneyLabel = LabelTTF::create(currentMoney->getCString(), "Marker Felt", 15);
	float Money_x = MoneyLabel->getContentSize().width;
	float Money_y = MoneyLabel->getContentSize().height;
	MoneyLabel->setPosition(origin.x + visibleSize.width - Money_x * 0.75, origin.y + Money_y);
	MoneyLabel->setColor(Color3B::RED);
	this->addChild(MoneyLabel, 20, GameSceneNodeTagMoney);
}

void GameScene::update(float dt)
{
	scrollMap();
}

void GameScene::scrollMap()
{
		auto mapCenter = _tiledMap1->getPosition();
		auto visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		int horizontal_state, vertical_state;
		horizontal_state = (origin.x + visibleSize.width - BOX_EDGE_WITDH_SMALL < crusor_position.x)
			+ (origin.x + visibleSize.width - BOX_EDGE_WITDH < crusor_position.x)
			- (origin.x + BOX_EDGE_WITDH_SMALL > crusor_position.x)
			- (origin.x + BOX_EDGE_WITDH > crusor_position.x);
		vertical_state = (origin.y + visibleSize.height - BOX_EDGE_WITDH_SMALL < crusor_position.y)
			+ (origin.y + visibleSize.height - BOX_EDGE_WITDH < crusor_position.y)
			- (origin.y + BOX_EDGE_WITDH_SMALL > crusor_position.y)
			- (origin.y + BOX_EDGE_WITDH > crusor_position.y);
		Vec2 scroll(0, 0);
		scroll += Vec2(-SCROLL_LENGTH, 0)*horizontal_state;
		scroll += Vec2(0, -SCROLL_LENGTH)*vertical_state;
		mapCenter += scroll;
		if (_tiledMap1->getBoundingBox().containsPoint((-scroll) + Director::getInstance()->getVisibleSize())
			&& _tiledMap1->getBoundingBox().containsPoint(-scroll))
			_tiledMap1->setPosition(mapCenter);
}

void GameScene::onMouseMove(Event *event)
{
	EventMouse* e = static_cast<EventMouse*>(event);
	crusor_position = Vec2(e->getCursorX(), e->getCursorY());
}

bool GameScene::mouseRectOnTouchBegan(Touch *pTouch, Event *event)
{
	Point touch = pTouch->getLocation();
	last_touch = touch;
	mouseRect->start = touch - _tiledMap1->getPosition();
	mouseRect->touch_start = touch;
	mouseRect->touch_end = touch;
	mouseRect->schedule(schedule_selector(MouseRect::update));
	return true;
}

void GameScene::mouseRectOnTouchMoved(Touch *pTouch, Event *event)
{
	Point touch = pTouch->getLocation();
	this->mouseRect->touch_end = touch;
	this->mouseRect->clear();
	this->mouseRect->setVisible(true);
}

void GameScene::mouseRectOnTouchEnded(Touch *pTouch, Event *event)
{
	Point touch = pTouch->getLocation();
	this->mouseRect->setVisible(false);
	if (this->mouseRect->isScheduled(schedule_selector(MouseRect::update)))
	{
		this->mouseRect->unschedule(schedule_selector(MouseRect::update));
	}
	mouseRect->end = touch - _tiledMap1->getPosition();
	Point maptouch = mouseRect->end;
	Point last_maptouch = mouseRect->start;
	if ((maptouch - last_maptouch).length() < MIN_SELECT_RECT_SIZE)
	{
		auto target = dynamic_cast<Soldiers *>(event->getCurrentTarget());
		if (!target)
		{
			return;
		}
		if (target->getTag() == GameSceneNodeTagBuilding || target->getTag() == GameSceneNodeTagSoldier)
		{
			///////////////
			//ȱ��Ѫ����ʾ
			///////////////
			log("search");
			if (target->getTag() == GameSceneNodeTagSoldier && target->getifSelect())
			{
				target->setifSelect(SELECT_ON);
			}
		}
	}
	else
	{
		select_rect = { MIN(last_maptouch.x, maptouch.x), MIN(last_maptouch.y, maptouch.y),
			abs(last_maptouch.x - maptouch.x), abs(last_maptouch.y - maptouch.y) };
		for (auto &sprite : _tiledMap1->getChildren())
		{
			if (!select_rect.containsPoint(sprite->getPosition()))
			{
				if (sprite->getTag() == GameSceneNodeTagBuilding)
				{
					auto temp = dynamic_cast<Buildings *>(sprite);
					temp->hideHpBar();
					continue;
				}
				if (sprite->getTag() == GameSceneNodeTagSoldier)
				{
					auto temp = dynamic_cast<Soldiers *>(sprite);
					temp->hideHpBar();
					continue;
				}
				continue;
			}
			if (sprite->getTag() == GameSceneNodeTagBuilding)
			{
				auto temp = dynamic_cast<Buildings *>(sprite);
				temp->displayHpBar();
			}
			if (sprite->getTag() == GameSceneNodeTagSoldier)
			{
				auto temp = dynamic_cast<Soldiers *>(sprite);
				temp->displayHpBar();
				temp->setifSelect(SELECT_ON);
			}
		}
	}
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keycode, cocos2d::Event* pEvent)
{
	auto mapCenter = _tiledMap1->getPosition();
	Director::getInstance()->getVisibleSize();
	switch (keycode)
	{
		//W ����
	case EventKeyboard::KeyCode::KEY_W:
		mapCenter += Vec2(0, -100);
		if (_tiledMap1->getBoundingBox().containsPoint(Vec2(0, 100) + Director::getInstance()->getVisibleSize()))
			_tiledMap1->setPosition(mapCenter);
		break;
		//A ����
	case EventKeyboard::KeyCode::KEY_A:
		mapCenter += Vec2(100, 0);
		if (_tiledMap1->getBoundingBox().containsPoint(Vec2(-100, 0)))
			_tiledMap1->setPosition(mapCenter);
		break;
		//S ����
	case EventKeyboard::KeyCode::KEY_S:
		mapCenter += Vec2(0, 100);
		if (_tiledMap1->getBoundingBox().containsPoint(Vec2(0, -100)))
			_tiledMap1->setPosition(mapCenter);
		break;
		//D ����
	case EventKeyboard::KeyCode::KEY_D:
		mapCenter += Vec2(-100, 0);
		if (_tiledMap1->getBoundingBox().containsPoint(Vec2(100, 0) + Director::getInstance()->getVisibleSize()))
			_tiledMap1->setPosition(mapCenter);
		break;
		//�رջ�������ƶ���Ļ
	case EventKeyboard::KeyCode::KEY_P:
		if (p_flag)
		{
			log("map move by mouse close");
			p_flag = false;
			Director::getInstance()->getEventDispatcher()->removeEventListener(mouse_event);
			break;
		}
		log("map move by mouse open");
		p_flag = true;
		mouse_event = EventListenerMouse::create();
		mouse_event->onMouseMove = CC_CALLBACK_1(GameScene::onMouseMove, this);
		Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(mouse_event, 1);
		break;
		//����control�����Ի��߲����Ի������ο�
	case EventKeyboard::KeyCode::KEY_CTRL:
		if (ctrl_flag)
		{
			log("mouse Rect unusable");
			ctrl_flag = false;
			Director::getInstance()->getEventDispatcher()->removeEventListener(mouseRectListener);
			break;
		}
		log("mouse Rect usable");
		ctrl_flag = true;
		mouseRectListener = EventListenerTouchOneByOne::create();
		mouseRectListener->onTouchBegan = CC_CALLBACK_2(GameScene::mouseRectOnTouchBegan, this);
		mouseRectListener->onTouchMoved = CC_CALLBACK_2(GameScene::mouseRectOnTouchMoved, this);
		mouseRectListener->onTouchEnded = CC_CALLBACK_2(GameScene::mouseRectOnTouchEnded, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseRectListener, this);
		break;
	default:
		break;
	}
}


void GameScene::setMapType(int maptype)
{
	if (maptype == 1)
	{
		mapType = 1;
	}
	else
	{
		mapType = 2;
	}
}
	
