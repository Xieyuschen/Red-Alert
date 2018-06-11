#include "AudioControl.h"
USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;


cocos2d::Scene * AudioControl::createScene()
{
	auto scene = Scene::create();
	auto layer = AudioControl::create();
	scene->addChild(layer);
	return scene;
}

bool AudioControl::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize1 = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/* ���� */
	auto back_ground = Sprite::create("menubackground.png");
	back_ground->setPosition(origin + visibleSize1 / 2);
	back_ground->setScaleX(visibleSize1.width / back_ground->getContentSize().width);
	back_ground->setScaleY(visibleSize1.height / back_ground->getContentSize().height);
	addChild(back_ground, -5);

	/* Bgm���� */
	auto music_label = LabelTTF::create(MyUtility::gbk_2_utf8("��������"), "�����п�", 20);
	music_label->setPosition(Vec2(origin.x + visibleSize1.width * 0.5, origin.y + visibleSize1.height * 0.7));
	this->addChild(music_label);

	auto music_slider = Slider::create();
	music_slider->loadBarTexture("slider1.png");
	music_slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
	music_slider->loadProgressBarTexture("slider2.png");
	float musicPercent = UserDefault::getInstance()->getFloatForKey("musicPercent");
	if (musicPercent == 0.0f)
	{
		musicPercent = 100.0f;
	}

	music_slider->setPercent(musicPercent);
	music_slider->setPosition(Vec2(origin.x + visibleSize1.width * 0.75, origin.y + visibleSize1.height * 0.7));

	music_slider->addEventListener([=](Ref* pSender, Slider::EventType type)
	{
		if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
		{
			int percent = music_slider->getPercent();
			SimpleAudioEngine::getInstance()->setBackgroundMusicVolume((float)(percent) / 100);
			UserDefault::getInstance()->setFloatForKey("musicPercent", percent);
		}
	});
	this->addChild(music_slider);

	/* EffectVolume */

	auto effect_label = LabelTTF::create(MyUtility::gbk_2_utf8("��Ч����"), "�����п�", 20);
	effect_label->setPosition(Vec2(origin.x + visibleSize1.width * 0.5, origin.y + visibleSize1.height * 0.5));
	this->addChild(effect_label);

	auto effect_slider = Slider::create();
	effect_slider->loadBarTexture("slider1.png");
	effect_slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
	effect_slider->loadProgressBarTexture("slider2.png");
	float effectPercent = UserDefault::getInstance()->getFloatForKey("effectPercent");
	if (effectPercent == 0.0f)
	{
		effectPercent = 100.0f;
	}

	effect_slider->setPercent(effectPercent);
	effect_slider->setPosition(Vec2(origin.x + visibleSize1.width * 0.75, origin.y + visibleSize1.height * 0.5));

	effect_slider->addEventListener([=](Ref* pSender, Slider::EventType type)
	{
		if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
		{
			int percent = effect_slider->getPercent();
			SimpleAudioEngine::getInstance()->setEffectsVolume((float)(percent) / 100);
			UserDefault::getInstance()->setFloatForKey("effectPercent", percent);
		}
	});
	this->addChild(effect_slider);
	/*music_toggle_menu: ON/OFF*/
	MenuItemFont::setFontSize(18);
	auto music_toggle_menu = MenuItemToggle::createWithTarget(this, menu_selector(AudioControl::musicTogglemenuCallBack), MenuItemFont::create("OFF"), MenuItemFont::create("ON"), NULL);
	music_toggle_menu->setPosition(Vec2(origin.x + visibleSize1.width * 0.92, origin.y + visibleSize1.height * 0.7));
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		music_toggle_menu->setSelectedIndex(1);
		UserDefault::getInstance()->setFloatForKey("index", 1);
	}
	else
	{
		music_toggle_menu->setSelectedIndex(0);
		UserDefault::getInstance()->setFloatForKey("index", 0);
	}

	//effect_toggle_menu: ON/OFF*/
	
	auto effect_toggle_menu = MenuItemToggle::createWithTarget(this, menu_selector(AudioControl::effectTogglemenuCallBack), MenuItemFont::create("OFF"), MenuItemFont::create("ON"), NULL);
	effect_toggle_menu->setPosition(Vec2(origin.x + visibleSize1.width * 0.92, origin.y + visibleSize1.height * 0.5));

	if (SimpleAudioEngine::sharedEngine()->getEffectsVolume())
	{
		effect_toggle_menu->setSelectedIndex(1);
	}
	else
	{
		effect_toggle_menu->setSelectedIndex(0);
	}
	
	auto menu = Menu::create(music_toggle_menu, effect_toggle_menu, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	/* ReturnButton */
	auto return_button = Button::create("normalmenu.png");
	return_button->setScale(0.9);
	return_button->setTitleText("BACK");
	return_button->setTitleFontName("fonts/Marker Felt.ttf");
	return_button->setTitleFontSize(16);
	return_button->setPosition(Vec2(origin.x + visibleSize1.width * 0.5, origin.x + visibleSize1.height*0.3));

	return_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			auto transition = TransitionFlipY::create(0.5, MenuScene::createScene());
			Director::getInstance()->replaceScene(transition);
		}
	});
	this->addChild(return_button);
	return true;
}

void AudioControl::onEnter()
{
	Layer::onEnter();
}


void AudioControl::musicTogglemenuCallBack(Ref * pSender)
{

	//������ʱMenuItemToggle  
	auto temp = (MenuItemToggle*)pSender;
	//����MenuItemToggle��ѡ�����������ֵĿ���  
	if (temp->getSelectedIndex() == 0)
	{
		//��ͣ��������  
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}
	if (temp->getSelectedIndex() == 1)
	{
		//������������  
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}

	auto musicToggleMenuItem = (MenuItemToggle*)pSender;
	log("musicToggleMenuItem %d", musicToggleMenuItem->getSelectedIndex());

}
void AudioControl::effectTogglemenuCallBack(Ref * pSender)
{

	//������ʱMenuItemToggle  
	MenuItemToggle* temp = (MenuItemToggle*)pSender;
	//����CCMenuItemToggle��ѡ�����������ֵĿ���  
	if (temp->getSelectedIndex() == 0)
	{
		//��ͣ��������  
		SimpleAudioEngine::sharedEngine()->pauseAllEffects();
	}
	if (temp->getSelectedIndex() == 1)
	{
		//������������  
		SimpleAudioEngine::sharedEngine()->resumeAllEffects();
	}

}