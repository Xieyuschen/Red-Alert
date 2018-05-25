//����˽���

#ifndef __ServerScene_H_
#define __ServerScene_H_
#include"cocos2d.h"
#include<iostream>
#include"ConstUtil.h"
#include "extensions/cocos-ext.h"  
#include "popupLayer/PopupLayer.h"
#include"MyUtility.h"
USING_NS_CC_EXT;
USING_NS_CC;
#define START_SERVER 1
#define START_GAME 2

class ServerScene :public Layer
{
public:
	static Scene* createScene();                                      //��������
	virtual bool init();                                              //��ʼ������
	CREATE_FUNC(ServerScene);                                          //���create�������������
	void addMenuSprites();                                            //���Menu
private:
	Size visibleSize;                                                 //���ڳߴ�
	void addBackgroundSprite();                                       //��ӳ�������
	void menuTouchDown(Object *pSender, Control::EventType event);    //Menu����ص�����
	void jumpToGameScene(float dt);                                   //��ת��GameScene
	void showServer();
};

#endif // !__ServerScene_H_
