#ifndef __BAR_H_
#define __BAR_H_
#include<iostream>
#include"cocos2d.h"
#include"ConstUtil.h"
#include"Soldiers/Soldiers.h"
USING_NS_CC;

class Bar : public DrawNode
{
public:
	void update(float dt);//Ѫ��ˢ��
	CREATE_FUNC(Bar);
	void setLength(float length);//����
	void setHeight(float height);//���
private:
	float Length = 0;
	float Height = 0;
	Color4F color{ 0.8, 0, 0, 0.8 };//��ɫ
};

#endif // !__BAR_H_