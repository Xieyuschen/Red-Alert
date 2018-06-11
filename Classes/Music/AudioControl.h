#pragma once
#ifndef AUDIOCONTROL_H_
#define AUDIOCONTROL_H_

#include"cocos2d.h"
#include"SimpleAudioEngine.h"
#include"MenuScene.h"
#include"MyUtility.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

/*
AudioControl�� �̳���Layer
����������С�Ŀ���
*/
class AudioControl :public Layer
{
public:

	//������������
	static Scene* createScene();
    //��ʼ������
	virtual bool init();
	void musicTogglemenuCallBack(Ref* pSender);
	void effectTogglemenuCallBack(Ref* pSender);
	void onEnter();

	CREATE_FUNC(AudioControl);
};


#endif // !AUDIOCONTROL_H_
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"