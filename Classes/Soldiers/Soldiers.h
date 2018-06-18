
#ifndef __Soldiers_H_
#define __Soldiers_H_
#include"cocos2d.h"
#include<iostream>
#include"cocos2d.h"
#include"ConstUtil.h"
#include"GameScene.h"
#include"Buildings/Buildings.h"
#include"Bar.h"
#include"Astar.h"
USING_NS_CC;

class Attackeffect :public ParticleFire
{
public:
	bool init();
	CREATE_FUNC(Attackeffect);

	void setAtkPath(Vec2 from, Vec2 to);

private:
	Vec2 From;
	Vec2 To;
	Vec2 moveFromTo;
	int moveSpeed = 3;
	void updateAtkEffect(float dt);
};

class Explosioneffect :public ParticleFire
{
<<<<<<< HEAD
public:
	bool init();
	CREATE_FUNC(Explosioneffect);
private:
	void updateRemove(float dt);
};

class Soldiers :public Sprite
{
	friend class Buildings;
=======
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151
	friend class Bar;
	friend class Astar;
	friend class Apoint;
public:
	Soldiers(SoldierTypes soldierType);        //ͨ��ö�������ж������ʲô������
<<<<<<< HEAD
	//~Soldiers();
	static Soldiers *createWithSoldierTypes(SoldierTypes soldierType);
	
	void update(float dt);
=======
	static Soldiers *createWithSoldierTypes(SoldierTypes soldierType);


>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151
private:
	CC_SYNTHESIZE(SoldierTypes, soldiertype, SoldierType);
	CC_SYNTHESIZE(int, health, currentHealth);
	CC_SYNTHESIZE(int, price, Price);
	CC_SYNTHESIZE(bool, ifselect, ifSelect);
	CC_SYNTHESIZE(int, maxHealth, MaxHealth);
<<<<<<< HEAD
	CC_SYNTHESIZE(float, speed, Speed);
	CC_SYNTHESIZE(int, power, Power);
	CC_SYNTHESIZE(int, atkRadius, AtkRadius);
	
private:
	CC_SYNTHESIZE(bool, ifAttack, IfAttack);
	int attackCD = 30;
	CC_SYNTHESIZE(Soldiers *, sEnemy, SoldierEnemy);
	CC_SYNTHESIZE(Buildings *, bEnemy, BuildingEnemy);
	CC_SYNTHESIZE_RETAIN(Soldiers *, attacker, Attacker);
	//CC_SYNTHESIZE(int, attackerPower, AttackerPower);
public:
	void findEnemy();
	void attack();


	//�ƶ���ط���
	vector<Vec2> moveToPath;
	void soldierAutoMove();

=======
	CC_SYNTHESIZE(int, speed, Speed);
	//���ּ�����
	static EventListenerTouchOneByOne *touchSoldierListener;
	static EventDispatcher * eventDispatcher;

	//��������ת������Ƭ����
	static Apoint turnToApoint(Vec2 vecPoint);
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151
	//Ѫ��
	Bar *hpBar = nullptr;
	void createBar();
	void displayHpBar();
	void hideHpBar();
};


#endif //!__Soldiers_H_


