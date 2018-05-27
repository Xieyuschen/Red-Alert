//�˵�����
#ifndef __MenuScene_H_
#define __MenuScene_H_


#include"cocos2d.h"
#include<iostream>
#include"ConstUtil.h"
#include"extensions/cocos-ext.h"  
#include"popupLayer/PopupLayer.h"
#include"SplashScene.h"
#include"MyUtility.h"
#include"GameScene.h"
USING_NS_CC_EXT;
USING_NS_CC;

class MenuScene :public Layer
{
public:
	static Scene* createScene();                                      //��������
	virtual bool init();                                              //��ʼ������
	CREATE_FUNC(MenuScene);                                           //���create�������������
	void popupQuitLayer();                                            //�����Ի���������������ʾ����
	void quitButtonCallback(Node* pNode);                             //�Ի��򰴼��ľ�����Ӧ�취
private:
	Size visibleSize;                                                 //���ڳߴ�
	void addBackgroundSprite();                                       //��ӳ�������
	void addMenuSprites();                                            //���Menu
	void menuTouchDown(Object *pSender,Control::EventType event);     //Menu����ص�����
	void jumpToIntroduction(float dt);                                //��ת��IntroScene
};

#endif // !__MenuScene_H_

