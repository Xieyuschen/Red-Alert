//��Ϸ����

#ifndef __GameScene_H_
#define __GameScene_H_
#include"cocos2d.h"
#include<iostream>
#include"MyUtility.h"
#include"ConstUtil.h"
#include"MenuScene.h"
#include"Buildings/Buildings.h"
#include"Soldiers/Soldiers.h"
#include"SimpleAudioEngine.h"
#include"network/SocketClient.h"
#include"network/SocketServer.h"
#include"network/socket_message.h"
using namespace ui;
USING_NS_CC;
class MouseRect :public DrawNode
{
public:
	CREATE_FUNC(MouseRect);
	Point touch_start;             //������ʼ��
	Point touch_end;               //����������
	Point start, end;              //ѡ��ʼ ������
	void update(float dt);         //�����εĸ��º���
	void reset();                  //�����趨����
};


class GameScene :public Layer
{
	friend class Buildings;
	friend class Soldiers;
public:
	static GameScene* create(SocketClient* _socket_client, SocketServer* _socket_server);
	static Scene *createScene(SocketClient* _socket_client, SocketServer* _socket_server = nullptr);
	virtual bool init(SocketClient* _socket_client, SocketServer* _socket_server);
	virtual void onEnter();
	virtual void onExit();
	void update(float dt);
	void scrollMap();
	static TMXTiledMap *gettiledMap()
	{
		return _tiledMap1;
	}
<<<<<<< HEAD
	static vector<Soldiers *> getSoldiers()
=======
	static void setMapType(int maptype);
	static Rect getSelectRect()
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151
	{
		return soldierSprites;
	}
<<<<<<< HEAD
=======
	static Rect select_rect;
	static int playerid ;
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151


private:
	//��ͼ��ط���
	EventListenerMouse * mouse_event;//��ͼ�ƶ�������¼�
	void onMouseMove(Event *event);
	bool p_flag = true;              //��һ�ΰ���ص���ͼ�ƶ�����¼����ٰ��ɿ���

	//���̲�����ط���
	EventListenerKeyboard * keyboard_listener;//���ּ����¼�
	void onKeyPressed(EventKeyboard::KeyCode keycode, cocos2d::Event* pEvent);

	EventListenerPhysicsContact * spriteContactListener;//������Ӵ�������

	//�˵���ť
	void backToMenuScene(Ref *pSender);//����MenuScene
	void buildingsCreate(Ref *pSender);//ѡ�����ｨ�죬������˵��ص�����
	void soldiersCreate(Ref *pSender); //ѡ��������������ֲ˵��ص�����

	//������׼������
	void casernReady(float dt);           //��Ӫ׼��
	void electricStationReady(float dt);  //�糧׼��
	void tankFactoryReady(float dt);      //ս������׼��
	void oreYardReady(float dt);          //��׼��
	static vector<Buildings *> buildingSprites;//���潨����

	//����׼������
	void minerReady(float dt);
	void policemanReady(float dt);
	void tankReady(float dt);
<<<<<<< HEAD
	static vector<Soldiers *> soldierSprites;//�������
	//�����ƶ�������
	EventListenerTouchOneByOne *soldierMove;

=======
	void warriorReady(float dt);
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151

	//��Ǯ��ط���
	void moneyUpdate(float dt);//ʵʱˢ�½�Ǯ
	static int Money;          //��Ǯ

	static TMXTiledMap * _tiledMap1;  //��Ƭ��ͼ
	static int mapType;




//Mouse Rect��ط���
public:
	Rect getvisionRect();
private:
	MouseRect *mouseRect = nullptr;
	EventListenerTouchOneByOne *mouseRectListener;
	bool ctrl_flag = true;//��һ�ΰ�ctrl��ص������ο��ٰ����Կ���
	bool mouseRectOnTouchBegan(Touch *pTouch, Event *event);
	void mouseRectOnTouchMoved(Touch *pTouch, Event *event);
	void mouseRectOnTouchEnded(Touch *pTouch, Event *event);
	Rect mini_map_rect{};
	Point last_touch{ 0, 0 };
	Point crusor_position{ 0, 0 };
<<<<<<< HEAD

//network
	SocketServer* socket_server = nullptr;
	SocketClient* socket_client = nullptr;
};
=======
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151

//network
	SocketServer* socket_server = nullptr;
	SocketClient* socket_client = nullptr;
};



#endif // !__GameScene_H_
