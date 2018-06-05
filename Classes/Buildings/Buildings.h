#ifndef __Buildings_H_
#define __Buildings_H_
#include"cocos2d.h"
#include<iostream>
#include"cocos2d.h"
#include"ConstUtil.h"
#include"GameScene.h"

USING_NS_CC;


////////////////////////////////////
//�������Ѫ�����ٺʹݻٷ��������
////////////////////////////////////


class Buildings :public Sprite
{
public:
	Buildings(BuildingTypes buildingType);        //ͨ��ö�������ж������ʲô������

	static Buildings *creatWithBuildingTypes(BuildingTypes buildingType);

private:
	CC_SYNTHESIZE(BuildingTypes, buildingtype, BuildingType);
	CC_SYNTHESIZE(int, health, currentHealth);
	CC_SYNTHESIZE(int, price, Price);
	CC_SYNTHESIZE(bool, if_move, ifMove);

	//�����������
	static EventListenerTouchOneByOne *touchBuildingListener;
	static EventDispatcher *eventDispatcher;
};




#endif // !__Buildings_H_



