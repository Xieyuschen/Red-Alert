//����˽���

#ifndef __ServerScene_H_
#define __ServerScene_H_
#include"cocos2d.h"
#include<iostream>
#include"ConstUtil.h"
#include "extensions/cocos-ext.h"  
#include "popupLayer/PopupLayer.h"
#include"MyUtility.h"
#include"GameScene.h"
USING_NS_CC_EXT;
USING_NS_CC;
<<<<<<< HEAD
#define START_SERVER 10
#define START_GAME 11
#define GO_BACK 12
=======
#define START_SERVER 4
#define START_GAME 5
#define GO_BACK 6
>>>>>>> master

class ServerScene :public Layer
{
public:
	static Scene* createScene();                                      //��������
	virtual bool init();                                              //��ʼ������
	CREATE_FUNC(ServerScene);                                         //���create�������������
	void addMenuSprites();                                            //���Menu
private:
	Size visibleSize;                                                 //���ڳߴ�
	void addBackgroundSprite();                                       //��ӳ�������
	void menuTouchDown(Object *pSender, Control::EventType event);    //Menu����ص�����
<<<<<<< HEAD
	void editBoxReturn(EditBox* editBox);
	void connectionSchdeule(float f);
	Label* connection_msg_;
=======
	void editBoxReturn(EditBox* editBox);                             //��������Ķ˿���Ϣ
	void connectionSchdeule(float f);
	Label* connection_msg_;                                           //������Ϣ
>>>>>>> master
};

#endif // !__ServerScene_H_
