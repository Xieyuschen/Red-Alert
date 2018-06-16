
#ifndef __Soldiers_H_
#define __Soldiers_H_
#include"cocos2d.h"
#include<iostream>
#include"cocos2d.h"
#include"ConstUtil.h"
#include"GameScene.h"
#include"Bar.h"
#include"Astar.h"
USING_NS_CC;

class Soldiers :public Sprite
{
	friend class Bar;
	friend class Astar;
	friend class Apoint;
public:
	Soldiers(SoldierTypes soldierType);        //ͨ��ö�������ж������ʲô������
	static Soldiers *createWithSoldierTypes(SoldierTypes soldierType);


private:
	CC_SYNTHESIZE(SoldierTypes, soldiertype, SoldierType);
	CC_SYNTHESIZE(int, health, currentHealth);
	CC_SYNTHESIZE(int, price, Price);
	CC_SYNTHESIZE(bool, ifselect, ifSelect);
	CC_SYNTHESIZE(int, maxHealth, MaxHealth);
	CC_SYNTHESIZE(int, speed, Speed);
	//���ּ�����
	static EventListenerTouchOneByOne *touchSoldierListener;
	static EventDispatcher * eventDispatcher;

	//��������ת������Ƭ����
	static Apoint turnToApoint(Vec2 vecPoint);
	//Ѫ��
	Bar *hpBar = nullptr;
	void createBar();
	void displayHpBar();
	void hideHpBar();
};


#endif //!__Soldiers_H_


