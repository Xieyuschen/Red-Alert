#ifndef __Soldiers_H_
#define __Soldiers_H_
#include"cocos2d.h"
#include<iostream>
#include"cocos2d.h"
#include"ConstUtil.h"
#include"GameScene.h"

USING_NS_CC;

class Soldiers :public Sprite
{
public:
	Soldiers(SoldierTypes soldierType);        //ͨ��ö�������ж������ʲô������
	static Soldiers *createWithSoldierTypes(SoldierTypes soldierType);

private:
	CC_SYNTHESIZE(SoldierTypes, soldiertype, SoldierType);
	CC_SYNTHESIZE(int, health, currentHealth);
	CC_SYNTHESIZE(int, price, Price);
	CC_SYNTHESIZE(bool, ifselect, ifSelect);

	//���ּ�����
	static EventListenerTouchOneByOne *touchSoldierListener;
	static EventDispatcher * eventDispatcher;
};


#endif //!__Soldiers_H_


