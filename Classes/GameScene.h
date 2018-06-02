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

class MouseRect :public DrawNode
{
public:
	CREATE_FUNC(MouseRect);
	Point touch_start, touch_end;
	Point start, end;
	void update(float dt);
	void reset();
};



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

	//����Ƿ���Խ���ı�ǩ
	static LabelTTF *getIfBuild()
	{
		return ifBuild;
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
	bool ctrl_flag = true;//��һ�ΰ�ctrl��ص������ο��ٰ����Կ���
	bool mouseRectOnTouchBegan(Touch *pTouch, Event *event);
	void mouseRectOnTouchMoved(Touch *pTouch, Event *event);
	void mouseRectOnTouchEnded(Touch *pTouch, Event *event);


	void backToMenuScene(Ref *pSender);//����MenuScene
	void buildingsCreate(Ref *pSender);//ѡ�����ｨ�죬������˵��ص�����

	void casernReady(float dt);//��Ӫ׼��
	//////////////////////////////
	//����������������׼������
	//////////////////////////////

	void moneyUpdate(float dt);//ʵʱˢ�½�Ǯ

	static int Money;//��Ǯ
	static LabelTTF *ifBuild;//�����ﲻ�ɽ���ʱ��ʾ�ı�ǩ

	TMXTiledMap * _tiledMap1;
	Point crusor_position{ 0, 0 };
	
};


#endif // !__GameScene_H_
