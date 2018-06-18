#ifndef __Buildings_H_
#define __Buildings_H_
#include"cocos2d.h"
#include<iostream>
#include"cocos2d.h"
#include"ConstUtil.h"
#include"GameScene.h"
#include"Soldiers/Soldiers.h"
#include"Bar.h"
USING_NS_CC;


////////////////////////////////////
//�������Ѫ�����ٺʹݻٷ��������
////////////////////////////////////


class Buildings :public Sprite
{
	friend class Soldiers;
	friend class Bar;
public:
	Buildings(BuildingTypes buildingType);        //ͨ��ö�������ж������ʲô������
	//~Buildings();

	static Buildings *creatWithBuildingTypes(BuildingTypes buildingType);
	void update(float dt);
private:
	CC_SYNTHESIZE(BuildingTypes, buildingtype, BuildingType);
	CC_SYNTHESIZE(int, health, currentHealth);
	CC_SYNTHESIZE(int, price, Price);
	CC_SYNTHESIZE(int, maxHealth, MaxHealth);

	//CC_SYNTHESIZE(Soldiers *, attacker, Attacker);

	//Ѫ��
	Bar *hpBar = nullptr;
	void createBar();
	void displayHpBar();
	void hideHpBar();
};




#endif // !__Buildings_H_



