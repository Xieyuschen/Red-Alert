//�ͻ��˽���

#ifndef __ClientScene_H_
#define __ClientScene_H_
#include"cocos2d.h"
#include<iostream>
#include"ConstUtil.h"
#include "extensions/cocos-ext.h"  
#include "popupLayer/PopupLayer.h"
#include"MyUtility.h"
USING_NS_CC_EXT;
USING_NS_CC;
#define JOIN_GAME 1
#define GO_BACK 2

class ClientScene :public Layer
{
public:
	static Scene* createScene();                                      //��������
	virtual bool init();                                              //��ʼ������
	CREATE_FUNC(ClientScene);                                          //���create�������������
	void addMenuSprites();                                            //���Menu
private:
	Size visibleSize;                                                 //���ڳߴ�
	void addBackgroundSprite();                                       //��ӳ�������
	void menuTouchDown(Object *pSender, Control::EventType event);    //Menu����ص�����
};

#endif // !__ClientScene_H_
