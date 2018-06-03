//��Ϸ����

#ifndef __GameScene_H_
#define __GameScene_H_
#include"cocos2d.h"
#include<iostream>
#include"MyUtility.h"
#include"ConstUtil.h"
#include"MenuScene.h"
#include"Buildings/Buildings.h"

USING_NS_CC;


class GameScene :public Layer
{
public:

	static Scene *createScene();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	CREATE_FUNC(GameScene);
	void update(float dt);
	void scrollMap();

private:
	//EventListenerTouchOneByOne * touchBuildingListener;

	void backToMenuScene(Ref *pSender);//����MenuScene
	void buildingsCreate(Ref *pSender);//ѡ�����ｨ�죬������˵��ص�����
	void soldiersCreate(Ref *pSender); //ѡ��������������ֲ˵��ص�����

	void casernReady(float dt);//��Ӫ׼��
	void electricStationReady(float dt);  //�糧׼��
	//////////////////////////////
	//����������������׼������
	//////////////////////////////
	void minerReady(float dt);//��׼��

	void moneyUpdate(float dt);//ʵʱˢ�½�Ǯ

	int Money;//��Ǯ
	TMXTiledMap * _tiledMap1;
	Point crusor_position{ 0, 0 };
	void onKeyPressed(EventKeyboard::KeyCode keycode, cocos2d::Event* pEvent);
};


#endif // !__GameScene_H_
