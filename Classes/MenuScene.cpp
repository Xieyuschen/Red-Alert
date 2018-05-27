#include"MenuScene.h"
//��ʼ������
bool MenuScene::init()
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

//��������
Scene * MenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

//��ӳ�������
void MenuScene::addBackgroundSprite()
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
void MenuScene::addMenuSprites()
{
	
	//1 start game
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton1 = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton1 = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * startGameTTF = LabelTTF::create(MyUtility::gbk_2_utf8("��ʼ��Ϸ"), "�����п�", 25);
	//����controlButton
	ControlButton * startGameBtn = ControlButton::create(startGameTTF, NormalButton1);
	//���singleButton�˵����µ�Ч��ͼƬ
	startGameBtn->setBackgroundSpriteForState(PressButton1, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	startGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.58);
	//���õ���Ļص�����
	startGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	startGameBtn->setTag(START_GAME);
	//���Menu������
	addChild(startGameBtn);

	//2 introdunction
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton2 = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton2 = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * introGameTTF = LabelTTF::create(MyUtility::gbk_2_utf8("��Ϸ����"), "�����п�", 25);
	//����controlButton
	ControlButton * introGameBtn = ControlButton::create(introGameTTF, NormalButton2);
	//���singleButton�˵����µ�Ч��ͼƬ
	introGameBtn->setBackgroundSpriteForState(PressButton2, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	introGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.45);
	//���õ���Ļص�����
	introGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	introGameBtn->setTag(INTRODUCTION);
	//���Menu������
	addChild(introGameBtn);

	//3 quit game
	//���ò˵�������ͼƬ
	Scale9Sprite * NormalButton3 = Scale9Sprite::create(NORMAL_MENU);
	//���ò˵�����ͼƬ
	Scale9Sprite * PressButton3 = Scale9Sprite::create(PRESS_MENU);
	//�����˵�����Ҫ��Label����
	LabelTTF * quitGameTTF = LabelTTF::create(MyUtility::gbk_2_utf8("�˳���Ϸ"), "�����п�", 25);
	//����controlButton
	ControlButton * quitGameBtn = ControlButton::create(quitGameTTF, NormalButton3);
	//���singleButton�˵����µ�Ч��ͼƬ
	quitGameBtn->setBackgroundSpriteForState(PressButton3, Control::State::SELECTED);
	//���õ�����Ϸ�˵����λ��
	quitGameBtn->setPosition(visibleSize.width * 0.84, visibleSize.height * 0.32);
	//���õ���Ļص�����
	quitGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	//���ò˵���ť��Tag
	quitGameBtn->setTag(QUIT_GAME);
	//���Menu������
	addChild(quitGameBtn);
}

//Menu����ص�����
void MenuScene::menuTouchDown(Object *pSender, Control::EventType event)
{
	ControlButton * button = (ControlButton*)pSender;
	int tag = button->getTag();
	switch (tag)
	{
		case START_GAME:    
		{
			//����GameScene�����Ұ��水�зָ��
			Scene *sc = Scene::create();
			auto layer = GameScene::create();
			sc->addChild(layer);
			auto reScene = TransitionSplitRows::create(1.0f, sc);
			Director::getInstance()->replaceScene(reScene);
			break;
		}
		case INTRODUCTION:
		{
			scheduleOnce(schedule_selector(MenuScene::jumpToIntroduction), 0.5);
			Director::getInstance()->replaceScene(SplashScene::createScene());
			break;
		}
		case QUIT_GAME:
		{
			popupQuitLayer();
			break;
		}
		break;
	}
}

//��ת��IntroScene
void MenuScene::jumpToIntroduction(float dt)
{

}

void MenuScene::popupQuitLayer()
{
	//���ݱ��������Ի���
	PopupLayer* popDialog = PopupLayer::create(DIALOG_BG);
	//���öԻ����С
	popDialog->setContentSize(CCSizeMake(350,200));
	//���öԻ�����⣬��ʾ����
	popDialog->setTitle("��ʾ",18);
	popDialog->setContentText("ȷ���˳���Ϸ��",22,20,100);
	//�ڶԻ��������ȷ����ȡ����Menu�����������ø��Ե�tag
	popDialog->addButton(DIALOG_BUTTON, DIALOG_BUTTON2, "��", 1);
	popDialog->addButton(DIALOG_BUTTON, DIALOG_BUTTON2, "��", 0);
	//���öԻ���İ�����Ӧ����
	popDialog->setCallbackFunc(this, callfuncN_selector(MenuScene::quitButtonCallback));
	this->addChild(popDialog);
}

void MenuScene::quitButtonCallback(Node* pNode)
{
	//���ݰ�����tag������Ӧ�ķ���
	if (pNode->getTag() == 1)
	{
		//���ȷ�������˳�
		Director::getInstance()->end();
	}
	else
	{
		//���ȡ������رնԻ���
		pNode->getParent()->removeFromParent();
	}
}