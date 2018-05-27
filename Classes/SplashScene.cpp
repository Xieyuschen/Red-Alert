#include"SplashScene.h"

//��ʼ������
bool SplashScene::init()                    
{
	//����ʼ��ʧ�ܣ�����false
	if (!Layer::init())
	{
		return false;
	}
	//��ʼ�����ڳߴ����
	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//��ʼ���������鷽��
	initMoveSprite();
	//������ʱ����������ʼһ��󶯻���ʼ����
	scheduleOnce(schedule_selector(SplashScene::startMoveSprite), 1);

	//����������������MenuScene�Ĳ˵�
	auto jumpLable = LabelTTF::create(MyUtility::gbk_2_utf8("����"), "�����п�", 15);
	auto jumpMenu = MenuItemLabel::create(jumpLable, CC_CALLBACK_1(SplashScene::jumpToMenuScen, this));
	float jump_x = jumpMenu->getContentSize().width;
	float jump_y = jumpMenu->getContentSize().height;
	jumpMenu->setPosition(Vec2(origin.x + visibleSize.width - jump_x, origin.y + jump_y));
	auto *mn = Menu::create(jumpMenu, NULL);
	mn->setPosition(Vec2::ZERO);
	addChild(mn);



	return true;
}

//��������
Scene * SplashScene::createScene()          
{
	auto scene = Scene::create();
	auto layer = SplashScene::create();
	scene->addChild(layer);
	return scene;
}

//��ʼ��ͼƬ
void SplashScene::initMoveSprite()           
{
	//��������
	hong_Sprite = Sprite::create(HONG_IMAGE);
	se_Sprite = Sprite::create(SE_IMAGE);
	jing_Sprite = Sprite::create(JING_IMAGE);
	jie_Sprite = Sprite::create(JIE_IMAGE);
	//��ȡ�����ߴ縳ֵ,ÿ��ͼƬ��С��ͬ��117*113��
	spriteSize = hong_Sprite->getContentSize();
	//�����ҷ��þ���ͼƬ��Ч��Ϊ��ɫ����족
	se_Sprite->setPosition(ccp((visibleSize.width / 2 )- (2* spriteSize.width),visibleSize.height/2));
	jing_Sprite->setPosition(ccp(visibleSize.width / 2 - spriteSize.width, visibleSize.height / 2));
	jie_Sprite->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	hong_Sprite->setPosition(ccp(visibleSize.width / 2 + spriteSize.width, visibleSize.height/2));
	//�Ѿ���ê��������(0,0.5)�������ܱ�֤����ͼƬ���������ڴ���λ��
	hong_Sprite->setAnchorPoint(ccp(0, 0.5));
	se_Sprite->setAnchorPoint(ccp(0, 0.5));
	jing_Sprite->setAnchorPoint(ccp(0, 0.5));
	jie_Sprite->setAnchorPoint(ccp(0, 0.5));

	//��Ӿ��鵽����
	this->addChild(hong_Sprite);
	this->addChild(se_Sprite);
	this->addChild(jing_Sprite);
	this->addChild(jie_Sprite);
}

//��ʼ�ƶ�����
void SplashScene::startMoveSprite(float dt)
{
	//������������ʼ����ĩһ���������ȿ�ʼ���������ƶ�һ��λ��
	MoveBy * movehongToLeft1 = MoveBy::create(MOVE_SPLEED, ccp(-spriteSize.width, 0));
	hong_Sprite->runAction(movehongToLeft1);
	//����jie���������ƶ�һ��λ�ã������������൱��jie��hong����λ��
	MoveBy * movejieToRight = MoveBy::create(MOVE_SPLEED, ccp(spriteSize.width, 0));
	CallFunc * callFunc1 = CallFunc::create(CC_CALLBACK_0(SplashScene::moveJingSpriteToRight, this));
	//����jie�������������moveJingSpriteToLeft()��������ʼ����jing�Ķ���
	jie_Sprite->runAction(Sequence::create(movejieToRight, callFunc1, NULL));
}

//����jing����
void SplashScene::moveJingSpriteToRight()
{
	//����hong���������ٴ��ƶ�һ��λ��
	MoveBy * movehongToLeft2 = MoveBy::create(MOVE_SPLEED, ccp(-spriteSize.width, 0));
	hong_Sprite->runAction(movehongToLeft2);
	//����jing���������ƶ�һ��λ�ã�ͬhong����λ��
	MoveBy * movejingToRight = MoveBy::create(MOVE_SPLEED, ccp(spriteSize.width, 0));
	CallFunc * callFunc2 = CallFunc::create(CC_CALLBACK_0(SplashScene::moveSeSpriteToRight, this));
	//����jing�������������moveJingSpriteToLeft()��������ʼ����se�Ķ���
	jing_Sprite->runAction(Sequence::create(movejingToRight, callFunc2, NULL));
}

//����se����
void SplashScene::moveSeSpriteToRight()
{
	//����hong���������ٴ��ƶ�һ��λ��
	MoveBy * movehongToLeft3 = MoveBy::create(MOVE_SPLEED, ccp(-spriteSize.width, 0));
	hong_Sprite->runAction(movehongToLeft3);
	//����se���������ƶ�һ��λ�ã�ͬhong����λ��
	MoveBy * moveseToRight = MoveBy::create(MOVE_SPLEED, ccp(spriteSize.width, 0));
	CallFunc * callFunc3 = CallFunc::create(CC_CALLBACK_0(SplashScene::spriteFadeOut, this));
	//����se�������������spriteFadeOut()��������ʼ������ʧ�Ķ���
	se_Sprite->runAction(Sequence::create(moveseToRight, callFunc3, NULL));
}

//������ʧ����
void SplashScene::spriteFadeOut()
{
	//�����ĸ���ʧ��FadeOut����������ʱ��2s
	FadeOut * fadeout1 = FadeOut::create(2);
	FadeOut * fadeout2 = FadeOut::create(2);
	FadeOut * fadeout3 = FadeOut::create(2);
	FadeOut * fadeout4 = FadeOut::create(2);
	se_Sprite->runAction(fadeout1);
	jing_Sprite->runAction(fadeout2);
	jie_Sprite->runAction(fadeout3);
	CallFunc * callFunc4 = CallFunc::create(CC_CALLBACK_0(SplashScene::gotoMenuScene, this));
	//�������������gotoMenuScene()��������MenuScene����
	hong_Sprite->runAction(Sequence::create(fadeout4, callFunc4, NULL));
}

//���볡��MenuScene
void SplashScene::gotoMenuScene()
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}

//����������MenuScene
void SplashScene::jumpToMenuScen(Ref *pSender)
{
	//����MenuScene�����Ұ��水�зָ��
	Scene *sc = Scene::create();
	auto layer = MenuScene::create();
	sc->addChild(layer);
	auto reScene = TransitionSplitRows::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}