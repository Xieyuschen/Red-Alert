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
LabelTTF * GameScene::ifBuild;
TMXTiledMap *GameScene::_tiledMap1;

Scene * GameScene::createScene()
{
	Scene *scene = Scene::createWithPhysics();
	PhysicsWorld *phyWorld = scene->getPhysicsWorld();
	//������������debug
	//phyWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	phyWorld->setGravity(Vec2(0, 0));
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	/************��ͼ************/
	//��Ϸ��ͼ
	_tiledMap1 = TMXTiledMap::create(GAMEMAP1);
	_tiledMap1->setAnchorPoint(Vec2(0, 0));
	_tiledMap1->setPosition(0, 0);
	addChild(_tiledMap1,0);
	TMXLayer *UnreachableGroundLayer = _tiledMap1->getLayer("UnreachableGroundLayer");
	//��ͼ����
	schedule(schedule_selector(GameScene::update));
	//��ͼ�ƶ�������¼�
	mouse_event = EventListenerMouse::create();
	mouse_event->onMouseMove = CC_CALLBACK_1(GameScene::onMouseMove, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(mouse_event, 1);
	/*mouse_event->onMouseMove = [&](Event *event)
	{
	EventMouse* e = static_cast<EventMouse*>(event);
	crusor_position = Vec2(e->getCursorX(), e->getCursorY());
	};*/
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

	//�����ﲻ�ɽ���ʱ��ʾ�ı�ǩ
	ifBuild = LabelTTF::create(MyUtility::gbk_2_utf8("�Ƿ�����"), "�����п�", 15);
	ifBuild->setColor(Color3B::RED);
	ifBuild->setAnchorPoint(Vec2(0.5, 0.5));
	ifBuild->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - ifBuild->getContentSize().height / 2));
	ifBuild->setTag(0);//���Ϊ0��1�ֱ��Ӧ���������������������Ϊ�����ƶ��Ϳ��ƶ�
	ifBuild->setVisible(false);//����ǩ���ɼ�ʱ������ɱ���������Ϊ�����ƶ�
	addChild(ifBuild);

	//����һ�����ؾ���
	Buildings *base = Buildings::creatWithBuildingTypes(START_BASE);
	base->setAnchorPoint(Vec2(0, 0));
	base->setScale(0.3);
	base->setPosition(Vec2(origin.x + visibleSize.width * -0.03, origin.y + visibleSize.height *-0.06));
	_tiledMap1->addChild(base, 10,GameSceneNodeTagBuilding);

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
	auto backMenu = MenuItemLabel::create(backLabel, CC_CALLBACK_1(GameScene::backToMenuScene, this));
	float back_x = backMenu->getContentSize().width;  //��ò˵����
	float back_y = backMenu->getContentSize().height; //��ò˵�����
	backMenu->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height - back_y));
	auto mn = Menu::create(backMenu, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	//������Ӫ�˵�
	MenuItemImage *buildingMenu1 = MenuItemImage::create(CASERN, CASERN, CC_CALLBACK_1(GameScene::buildingsCreate, this));
	buildingMenu1->setAnchorPoint(Vec2(0.5, 0.5));
	buildingMenu1->setScale(0.3);
	float menu1_x = buildingMenu1->getContentSize().width;
	float menu1_y = buildingMenu1->getContentSize().height;
	buildingMenu1->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height - menu1_y / 3));
	buildingMenu1->setTag(START_CASERN);
	buildingMenu1->setOpacity(128);
	Menu *bmn1 = Menu::create(buildingMenu1, NULL);
	bmn1->setPosition(Vec2::ZERO);
	this->addChild(bmn1, 20);
	auto buildingLabel1 = LabelTTF::create(MyUtility::gbk_2_utf8("��Ӫ"), "�����п�", 8);
	buildingLabel1->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height - menu1_y / 3));
	this->addChild(buildingLabel1,30);

	//�����糧�˵�
	MenuItemImage *buildingMenu2 = MenuItemImage::create(ELECTRICSTATION, ELECTRICSTATION, CC_CALLBACK_1(GameScene::buildingsCreate, this));
	buildingMenu2->setAnchorPoint(Vec2(0.5, 0.5));
	buildingMenu2->setScale(0.3);
	float menu21_x = buildingMenu2->getContentSize().width;
	float menu2_y = buildingMenu2->getContentSize().height;
	buildingMenu2->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height - 80));
	buildingMenu2->setTag(START_ELECTRICSTATION);
	buildingMenu2->setOpacity(128);
	Menu *bmn2 = Menu::create(buildingMenu2, NULL);
	bmn2->setPosition(Vec2::ZERO);
	this->addChild(bmn2, 20);
	auto buildingLabel2 = LabelTTF::create(MyUtility::gbk_2_utf8("�糧"), "�����п�", 8);
	buildingLabel2->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height -80));
	this->addChild(buildingLabel2, 30);

	/*************test**************/
	//�����󹤲˵�
	MenuItemImage *soldierMenu1 = MenuItemImage::create(MINER, MINER, CC_CALLBACK_1(GameScene::soldiersCreate, this));
	soldierMenu1->setAnchorPoint(Vec2(0.5, 0.5));
	soldierMenu1->setScale(1.2);
	//float smenu1_x = soldierMenu1->getContentSize().width;
	//float smenu1_y = soldierMenu1->getContentSize().height;
	soldierMenu1->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height - 200));
	soldierMenu1->setTag(START_MINER);
	soldierMenu1->setOpacity(128);
	Menu *smn1 = Menu::create(soldierMenu1, NULL);
	smn1->setPosition(Vec2::ZERO);
	this->addChild(smn1, 20);
	auto soldierLabel1 = LabelTTF::create(MyUtility::gbk_2_utf8("��"), "�����п�", 8);
	soldierLabel1->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height - 200));
	this->addChild(soldierLabel1,30);
	

	//������Ӵ���������
	buildingContactListener = EventListenerPhysicsContact::create();
	buildingContactListener->onContactBegin = [this](PhysicsContact &contact)
	{
		log("buildings contact");
		Buildings *buildingSpriteA = (Buildings *)(contact.getShapeA()->getBody()->getNode());
		Buildings *buildingSpriteB = (Buildings *)(contact.getShapeB()->getBody()->getNode());
		if (!buildingSpriteA || !buildingSpriteB)
		{
			return false;
		}
		//�ж����������Ƿ�Ϊ�����������һ������Ҫ�����
		if (buildingSpriteA->getTag() == GameSceneNodeTagBuilding && buildingSpriteB->getTag() == GameSceneNodeTagBuilding)
		{
			//��Ҫ����Ľ������ǿ��ƶ���
			if (buildingSpriteA->getifMove() && !buildingSpriteB->getifMove())
			{
				buildingSpriteA->setifMove(CAN_MOVE);//�ô˽�������Ϊ���ƶ�
				buildingSpriteB->setOpacity(128);//�������ƶ��Ľ������͸��
												 //����ǩ���ñ�ǣ�ʹ������ļ��������Ը��ݱ�ǩ�ж��Ƿ���Ҫ����������Ϊ�����ƶ�
				this->ifBuild->setTag(1);
				this->ifBuild->setVisible(true);//��ʾ��ֹ����ı�ǩ
				return true;
			}
			if (buildingSpriteB->getifMove() && !buildingSpriteA->getifMove())
			{
				buildingSpriteB->setifMove(CAN_MOVE);
				buildingSpriteA->setOpacity(128);
				this->ifBuild->setTag(1);
				this->ifBuild->setVisible(true);
				return true;
			}
		}
		return false;
	};
	buildingContactListener->onContactPreSolve = [this](PhysicsContact &contact, PhysicsContactPreSolve &solve)
	{
		log("buildings contactpresolve");
		Buildings *buildingSpriteA = (Buildings *)(contact.getShapeA()->getBody()->getNode());
		Buildings *buildingSpriteB = (Buildings *)(contact.getShapeB()->getBody()->getNode());
		if (!buildingSpriteA || !buildingSpriteB)
		{
			return false;
		}
		if (buildingSpriteA->getTag() == GameSceneNodeTagBuilding && buildingSpriteB->getTag() == GameSceneNodeTagBuilding)
		{
			if (buildingSpriteA->getifMove() && !buildingSpriteB->getifMove())
			{
				buildingSpriteA->setifMove(CAN_MOVE);
				buildingSpriteB->setOpacity(128);
				this->ifBuild->setTag(1);
				this->ifBuild->setVisible(true);
				return true;
			}
			if (buildingSpriteB->getifMove() && !buildingSpriteA->getifMove())
			{
				buildingSpriteB->setifMove(CAN_MOVE);
				buildingSpriteA->setOpacity(128);
				this->ifBuild->setTag(1);
				this->ifBuild->setVisible(true);
				return true;
			}
		}
		return false;
	};
	buildingContactListener->onContactPostSolve = [this](PhysicsContact &contact, const PhysicsContactPostSolve &solve)
	{
		log("buildings contactpostsolve");
		Buildings *buildingSpriteA = (Buildings *)(contact.getShapeA()->getBody()->getNode());
		Buildings *buildingSpriteB = (Buildings *)(contact.getShapeB()->getBody()->getNode());
		if (!buildingSpriteA || !buildingSpriteB)
		{
			return;
		}
		if (buildingSpriteA->getTag() == GameSceneNodeTagBuilding && buildingSpriteB->getTag() == GameSceneNodeTagBuilding)
		{
			if (buildingSpriteA->getifMove() && !buildingSpriteB->getifMove())
			{
				buildingSpriteA->setifMove(CAN_MOVE);
				buildingSpriteB->setOpacity(128);
				this->ifBuild->setTag(1);
				this->ifBuild->setVisible(true);
				return;
			}
			if (buildingSpriteB->getifMove() && !buildingSpriteA->getifMove())
			{
				buildingSpriteB->setifMove(CAN_MOVE);
				buildingSpriteA->setOpacity(128);
				this->ifBuild->setTag(1);
				this->ifBuild->setVisible(true);
				return;
			}
		}
	};
	buildingContactListener->onContactSeparate = [this](PhysicsContact &contact)
	{
		log("buildings contactseparate");
		Buildings *buildingSpriteA = (Buildings *)(contact.getShapeA()->getBody()->getNode());
		Buildings *buildingSpriteB = (Buildings *)(contact.getShapeB()->getBody()->getNode());
		if (!buildingSpriteA || !buildingSpriteB)
		{
			return;
		}
		if (buildingSpriteA->getTag() == GameSceneNodeTagBuilding && buildingSpriteB->getTag() == GameSceneNodeTagBuilding)
		{
			if (buildingSpriteA->getifMove() && !buildingSpriteB->getifMove())
			{
				buildingSpriteA->setifMove(CAN_MOVE);//����������Կ��ƶ�
				buildingSpriteB->setOpacity(255);//�����ƶ��Ľ�����ָ�Ϊ��͸��
				this->ifBuild->setTag(0);//��ǩ�ı��Ϊ0����������������Խ���������Ϊ�����ƶ�
				this->ifBuild->setVisible(false);//��ǩ���ɼ�
				return;
			}
			if (buildingSpriteB->getifMove() && !buildingSpriteA->getifMove())
			{
				buildingSpriteB->setifMove(CAN_MOVE);
				buildingSpriteA->setOpacity(255);
				this->ifBuild->setTag(0);
				this->ifBuild->setVisible(false);
				return;
			}
		}
		return;
	};
	_eventDispatcher->addEventListenerWithFixedPriority(buildingContactListener, 20);

	//ʵʱˢ�½�Ǯ
	this->Money = 4000;
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
	Director::getInstance()->getEventDispatcher()->removeEventListener(Buildings::touchBuildingListener);
	Director::getInstance()->getEventDispatcher()->removeEventListener(mouse_event);
	Director::getInstance()->getEventDispatcher()->removeEventListener(keyboard_listener);
	Director::getInstance()->getEventDispatcher()->removeEventListener(buildingContactListener);
	Director::getInstance()->getEventDispatcher()->removeEventListener(mouseRectListener);
	this->unschedule(schedule_selector(GameScene::moneyUpdate));
	this->unschedule(schedule_selector(GameScene::update));
}

//����MenuScene
void GameScene::backToMenuScene(Ref *pSender)
{
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
				break;
			}
			Money -= ELECTRICSTATION_PRICE;
			//������׼����ʱ����ÿ�ֽ�����׼��ʱ�䲻ͬ
			this->scheduleOnce(schedule_selector(GameScene::electricStationReady), 2.0f);
			break;
		}
		//////////
		//������
		//////////
	}

}

/***************test*************/
void GameScene::soldiersCreate(Ref *pSender)
{
	MenuItem *mnitm = (MenuItem *)pSender;
	switch (mnitm->getTag())
	{
		case START_MINER:
		{
			if (Money < MINER_PRICE)
			{
				break;
			}
			Money -= MINER_PRICE;
			//׼����ʱ��
			this->scheduleOnce(schedule_selector(GameScene::minerReady), 0.5f);
		}
	}
}

void GameScene::minerReady(float dt)
{
	//ͨ��Soldiers��������ʿ��
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto miner = Soldiers::createWithSoldierTypes(START_MINER);
	miner->setAnchorPoint(Vec2(0.5, 0.5));
	miner->setScale(1.0);
	float soldiers_x = miner->getContentSize().width;
	float soldiers_y = miner->getContentSize().height;
	miner->setPosition(Vec2(visibleSize.width - soldiers_x, visibleSize.height - soldiers_y / 6));
	_tiledMap1->addChild(miner, 10, GameSceneNodeTagBuilding);
}

//���������
void GameScene::casernReady(float dt)
{
	//ͨ��Buildings��������������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto casern = Buildings::creatWithBuildingTypes(START_CASERN);
	casern->setAnchorPoint(Vec2(0.5, 0.5));
	casern->setScale(0.3);
	float building_x = casern->getContentSize().width;
	float building_y = casern->getContentSize().height;
	casern->setPosition(Vec2(visibleSize.width - building_x, visibleSize.height - building_y / 6));
	_tiledMap1->addChild(casern, 10, GameSceneNodeTagBuilding);
}
void GameScene::electricStationReady(float dt)
{
	//ͨ��Buildings��������������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto casern = Buildings::creatWithBuildingTypes(START_ELECTRICSTATION);
	casern->setAnchorPoint(Vec2(0.5, 0.5));
	casern->setScale(0.3);
	float building_x = casern->getContentSize().width;
	float building_y = casern->getContentSize().height;
	casern->setPosition(Vec2(visibleSize.width - building_x, visibleSize.height - building_y / 6));
	_tiledMap1->addChild(casern, 10, GameSceneNodeTagBuilding);
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
		/*
		//X
		case EventKeyboard::KeyCode::KEY_X:
		unit_manager->genCreateMessage(1, grid_map->getGridPoint(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2)));
		break;
		//�ո� ���ػ���
		case EventKeyboard::KeyCode::KEY_SPACE:
		focusOnBase();
		break;
		*/
	default:
		break;
	}
}


	
