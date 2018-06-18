#ifndef _GameManager_H_
#define _GameManager_H_
#include"cocos2d.h"
#include<iostream>
#include"MyUtility.h"
#include"ConstUtil.h"
#include"MenuScene.h"
#include"Buildings/Buildings.h"
#include"Soldiers/Soldiers.h"
#include"network/SocketClient.h"
#include"network/SocketServer.h"
#include"network/socket_message.h"
#include"network/GameMessage.pb.h"
#include"network/GameMessageWrap.h"

USING_NS_CC;

class GameManager:public cocos2d::Ref
{
	friend class Soldiers;
	friend class Buildings;
	friend class GameScene;
	friend class Notice;
public:
	CREATE_FUNC(GameManager);
	bool init();                                                 //��ʼ��
	GameMessageSet* msgs = nullptr;                              //��Ϸ��Ϣ��
	void setMessageSet(GameMessageSet* _msgs);                   //������Ϣ��
	void setTiledMap(TMXTiledMap* _tiledMap);                    //������Ƭ��ͼ
	void setGameScene(GameScene* _game_scene);                   //������Ϸ����
	void setNotice(Notice* _notice);                             //��Ϸ��ʾ
	void setSocketClient(SocketClient* _socket_client);          //����ǿͻ��ˣ������ÿͻ����׽���
	void setPlayerID(int _player_id);                            //�������ID
	int  getPlayerID();                                          //��ȡ��λ������Ӫ
	int  getnextID();                                            //��ȡ��һ������ID
	void setPlayernum(int _player_num);                          //�����������
	int  getPlayernum();                                         //��ȡ�������
	void produceSoldiers(SoldierTypes soldierType, int _player_id, int _id);              //����ʿ��
	void produceBuildings(BuildingTypes buildingType, int _player_id, int _id);           //��������
	void updateGameState();                                      //ͨ�������շ���Ϣ��������Ϸ״̬
	void genCreateBuildingMessage(BuildingTypes buildingtype);   //����������������Ϣ
	void genCreateSoldierMessage(SoldierTypes soldiertype);       //��������������Ϣ
	void deleteAll(int _player_id);                               //ʧ�ܺ��Ƴ����н�����ʿ��

private:
	Map<int, Soldiers*> sid_map;                                 //ID��ʿ����Ӧ��
	Map<int, Buildings*> bid_map;                                //ID�ͽ�����Ӧ��
	SocketClient * socket_client = nullptr;                      //�ͻ����׽���
	int player_id;                                               //���ID
	int player_num;                                              //�������
	int next_id;                                                 //��һ��������λ��id
    TMXTiledMap* tiledMap;                                       //��Ƭ��ͼ
	GameScene* game_scene;                                       //��Ϸ����
	Notice* notice = nullptr;                                    //��Ϸ��ʾ

};


#endif //!_GameManager_H_
