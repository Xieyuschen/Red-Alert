//�����б����

#ifndef __RoomScene_H_
#define __RoomScene_H_
#include"cocos2d.h"
#include<iostream>
#include"ConstUtil.h"
#include "extensions/cocos-ext.h"  
#include "popupLayer/PopupLayer.h"
#include"MyUtility.h"
#include "ServerScene.h"
#include "ClientScene.h"
USING_NS_CC_EXT;
USING_NS_CC;
#define START_SERVER 1
#define START_CLIENT 2
#define GO_BACK 3

class RoomScene:public Layer
{
public:
	static Scene* createScene();                                      //��������
	virtual bool init();                                              //��ʼ������
	CREATE_FUNC(RoomScene);                                           //���create�������������
	void addMenuSprites();                                            //���Menu
private:
	Size visibleSize;                                                 //���ڳߴ�
	void addBackgroundSprite();                                       //��ӳ�������
	void menuTouchDown(Object *pSender, Control::EventType event);    //Menu����ص�����
	void jumpToServerScene(float dt);                                  //��ת��ServeScene
	void jumpToClientScene(float dt);                                 //��ת��ClientScene
};

#endif // !__RoomScene_H_

