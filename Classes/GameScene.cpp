#include"GameScene.h"


Scene * GameScene::createScene()
{
	Scene *scene = Scene::create();
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
	_tiledMap1 = TMXTiledMap::create(GameMap1);
	addChild(_tiledMap1, -1);
	//��ͼ����
	schedule(schedule_selector(GameScene::update));
	//��ͼ�ƶ�������¼�
	auto mouse_event = EventListenerMouse::create();
	mouse_event->onMouseMove = [&](Event *event)
	{
		EventMouse* e = static_cast<EventMouse*>(event);
		crusor_position = Vec2(e->getCursorX(), e->getCursorY());
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(mouse_event, 1);
	//��ͼ�ƶ��ļ����¼�
	auto keyboard_listener = EventListenerKeyboard::create();
	keyboard_listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboard_listener, this);

	//����һ�����ؾ���
	Buildings *base = Buildings::creatWithBuildingTypes(START_BASE);
	base->setAnchorPoint(Vec2(0, 0));
	base->setScale(0.3);
	base->setPosition(Vec2(origin.x + visibleSize.width * -0.03, origin.y + visibleSize.height *-0.06));
	addChild(base, 10, GameSceneNodeTagBuilding);

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

	//����һ��ѡ��������˵���Ŀǰֻ�б�Ӫ�����û���ͼ����
	MenuItemImage *buildingMenu = MenuItemImage::create(BASE, BASE, CC_CALLBACK_1(GameScene::buildingsCreate, this));
	buildingMenu->setAnchorPoint(Vec2(0.5, 0.5));
	buildingMenu->setScale(0.2);
	float menu_x = buildingMenu->getContentSize().width;
	float menu_y = buildingMenu->getContentSize().height;
	buildingMenu->setPosition(Vec2(visibleSize.width, origin.y + visibleSize.height - menu_y / 6));
	buildingMenu->setTag(CASERN);
	buildingMenu->setOpacity(128);
	Menu *bmn = Menu::create(buildingMenu, NULL);
	bmn->setPosition(Vec2::ZERO);
	this->addChild(bmn, 20);

	//�������ƶ�������
	//ԭ��д�����λ�õ�
	//ע��ʱ�õ�  ....->...(��������this->getchildbytag(GameSceneNodeBuilding))
	//���޷��ƶ�
	/////////////////



	//ʵʱˢ�½�Ǯ
	this->Money = 4000;
	this->schedule(schedule_selector(GameScene::moneyUpdate), 1.0f, CC_REPEAT_FOREVER, 0);

}

void GameScene::onExit()
{
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeEventListener(Buildings::touchBuildingListener);

	this->unschedule(schedule_selector(GameScene::moneyUpdate));
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
		case CASERN:
		{
			if (Money < CASERN_PRICE)//�ж�ǰ�Ƿ��㹻
			{
				break;
			}
			Money -= CASERN_PRICE;
			//������׼����ʱ����ÿ�ֽ�����׼��ʱ�䲻ͬ
			this->scheduleOnce(schedule_selector(GameScene::casernReady), 2.0f);
			break;
		}
		//////////
		//������
		//////////
	}

}

void GameScene::casernReady(float dt)
{
	//ͨ��Buildings��������������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto casern = Buildings::creatWithBuildingTypes(CASERN);
	casern->setAnchorPoint(Vec2(0.5, 0.5));
	casern->setScale(0.2);
	float building_x = casern->getContentSize().width;
	float building_y = casern->getContentSize().height;
	casern->setPosition(Vec2(visibleSize.width - building_x, visibleSize.height - building_y / 6));
	this->addChild(casern, 10, GameSceneNodeTagBuilding);
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
	MoneyLabel->setColor(Color3B::YELLOW);
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

