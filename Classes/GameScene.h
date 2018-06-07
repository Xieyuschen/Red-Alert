//��Ϸ����

#ifndef __GameScene_H_
#define __GameScene_H_
#include"cocos2d.h"
#include<iostream>
#include"MyUtility.h"
#include"ConstUtil.h"
#include"MenuScene.h"
#include"Buildings/Buildings.h"
<<<<<<< HEAD
#include"Soldiers/Soldiers.h"
=======
#include"Soldiers.h"
>>>>>>> xiaorui

USING_NS_CC;
class MouseRect :public DrawNode
{
public:
	CREATE_FUNC(MouseRect);
	Point touch_start, touch_end;
	Point start, end;
	void update(float dt);
	void reset();
};

<<<<<<< HEAD

=======
>>>>>>> xiaorui
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
	static TMXTiledMap *gettiledMap()
	{
		return _tiledMap1;
	}


	//����Ƿ���Խ���ı�ǩ
	static LabelTTF *getIfBuild()
	{
		return ifBuild;
	}
	static TMXTiledMap *gettiledMap()
	{
		return _tiledMap1;
	}
	static Rect getSelectRect()
	{
		return select_rect;
	}
private:
	//EventListenerTouchOneByOne * touchBuildingListener;
	EventListenerMouse * mouse_event;//��ͼ�ƶ�������¼�
	void onMouseMove(Event *event);
	bool p_flag = true;//��һ�ΰ���ص���ͼ�ƶ�����¼����ٰ��ɿ���
	EventListenerKeyboard * keyboard_listener;//���ּ����¼�
	void onKeyPressed(EventKeyboard::KeyCode keycode, cocos2d::Event* pEvent);
	EventListenerPhysicsContact * buildingContactListener;//������Ӵ�������

	MouseRect *mouseRect = nullptr;
	EventListenerTouchOneByOne *mouseRectListener;
	bool mouseRectOnTouchBegan(Touch *pTouch, Event *event);
	void mouseRectOnTouchMoved(Touch *pTouch, Event *event);
	void mouseRectOnTouchEnded(Touch *pTouch, Event *event);
	static Rect select_rect;


	void backToMenuScene(Ref *pSender);//����MenuScene
	void buildingsCreate(Ref *pSender);//ѡ�����ｨ�죬������˵��ص�����
<<<<<<< HEAD
	void soldiersCreate(Ref *pSender); //ѡ��������������ֲ˵��ص�����

	void casernReady(float dt);           //��Ӫ׼��
	void electricStationReady(float dt);  //�糧׼��
	void tankFactoryReady(float dt);      //ս������׼��
	void oreYardReady(float dt);          //��׼��


	void minerReady(float dt);
=======
	void soldiersCreate(Ref *pSender);//ѡ���������

	void casernReady(float dt);//��Ӫ׼��
	void electricStationReady(float dt);  //�糧׼��
	void minerReady(float dt);
							   //////////////////////////////
							   //����������������׼������
							   //////////////////////////////
>>>>>>> xiaorui

	static int Money;//��Ǯ
	void moneyUpdate(float dt);//ʵʱˢ�½�Ǯ

	static LabelTTF *ifBuild;//�����ﲻ�ɽ���ʱ��ʾ�ı�ǩ
<<<<<<< HEAD
	static TMXTiledMap * _tiledMap1;  //��Ƭ��ͼ
	Point crusor_position{ 0, 0 };
=======

	static TMXTiledMap * _tiledMap1;
	Point crusor_position{ 0, 0 };

>>>>>>> xiaorui
};


#endif // !__GameScene_H_
