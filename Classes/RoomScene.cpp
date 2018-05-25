#include"RoomScene.h"

Scene *RoomScene::createScene()
{
	auto scene = Scene::create();
	auto layer = RoomScene::create();
	scene->addChild(layer);
	return scene;
}

bool RoomScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//��ʼ�����ڳߴ����
	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//��ӳ�������
	addBackgroundSprite();
	//���Menu
	addMenuSprites();
	return true;
}

void RoomScene::addBackgroundSprite()
{
	//��ӱ���ͼƬ
	Sprite * MenuBackgroundSprite = Sprite::create(MENU_BACKGROUND);
	//������������ʾͼƬ
	MenuBackgroundSprite->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	//����ê����������
	MenuBackgroundSprite->setAnchorPoint(ccp(0.5, 0.5));
	//���ñ�����С������Ļ����������
	Size WinSize = CCDirector::sharedDirector()->getWinSize();
	float winx = WinSize.width;
	float winy = WinSize.height;
	float backgroundx = MenuBackgroundSprite->getTextureRect().getMaxX();
	float backgroundy = MenuBackgroundSprite->getTextureRect().getMaxY();
	MenuBackgroundSprite->setScaleX(winx / backgroundx);
	MenuBackgroundSprite->setScaleY(winy / backgroundy);
	//��ӱ���������
	this->addChild(MenuBackgroundSprite);
}

//���Menu
void RoomScene::addMenuSprites()
{
	//1 start game
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton1 = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton1 = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * startGameTTF = LabelTTF::create(MyUtility::gbk_2_utf8("������Ϸ"), "�����п�", 25);
	//����controlButton
	ControlButton * startGameBtn = ControlButton::create(startGameTTF, NormalButton1);
	//���singleButton�˵����µ�Ч��ͼƬ
	startGameBtn->setBackgroundSpriteForState(PressButton1, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	startGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.58);
	//���õ���Ļص�����
	startGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(RoomScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	startGameBtn->setTag(START_SERVER);
	//���Menu������
	addChild(startGameBtn);

	//2 introdunction
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton2 = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton2 = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * introGameTTF = LabelTTF::create(MyUtility::gbk_2_utf8("������Ϸ"), "�����п�", 25);
	//����controlButton
	ControlButton * introGameBtn = ControlButton::create(introGameTTF, NormalButton2);
	//���singleButton�˵����µ�Ч��ͼƬ
	introGameBtn->setBackgroundSpriteForState(PressButton2, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	introGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.45);
	//���õ���Ļص�����
	introGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(RoomScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	introGameBtn->setTag(START_CLIENT);
	//���Menu������
	addChild(introGameBtn);

	//3 quit game
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton3 = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton3 = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * quitGameTTF = LabelTTF::create(MyUtility::gbk_2_utf8("����"), "�����п�", 25);
	//����controlButton
	ControlButton * quitGameBtn = ControlButton::create(quitGameTTF, NormalButton3);
	//���singleButton�˵����µ�Ч��ͼƬ
	quitGameBtn->setBackgroundSpriteForState(PressButton3, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	quitGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.32);
	//���õ���Ļص�����
	quitGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(RoomScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	quitGameBtn->setTag(GO_BACK);
	//���Menu������
	addChild(quitGameBtn);
}

void RoomScene::menuTouchDown(Object *pSender, Control::EventType event)
{
	ControlButton * button = (ControlButton*)pSender;
	int tag = button->getTag();
	switch (tag)
	{
	case START_SERVER:
	{
		scheduleOnce(schedule_selector(RoomScene::jumpToServerScene), 0.5);
		break;
	}
	case START_CLIENT:
	{
		scheduleOnce(schedule_selector(RoomScene::jumpToClientScene), 0.5);
		break;
	}
	case GO_BACK:
	{
		Director::getInstance()->popScene();
		break;
	}
	break;
	}
}

void RoomScene::jumpToServerScene(float dt)
{
	auto sc = ServerScene::createScene();
	auto reScene = TransitionFadeTR::create(0.5f, sc);
	Director::getInstance()->pushScene(reScene);
}

void RoomScene::jumpToClientScene(float dt)
{
	auto sc = ClientScene::createScene();
	auto reScene = TransitionFadeTR::create(0.5f, sc);
	Director::getInstance()->pushScene(reScene);
}
