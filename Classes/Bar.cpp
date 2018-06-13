#include"Bar.h"
void Bar::update(float dt)
{
	clear();
	Node *parent = getParent();
	if (parent->getTag() == GameSceneNodeTagBuilding)//������Ѫ��
	{
		auto temp = dynamic_cast<Buildings *>(parent);
		auto rate = float(temp->getcurrentHealth()) / float(temp->getMaxHealth());//��ǰѪ������Ѫ֮��
		drawRect(Point(0, 0), Point(Length, Height), color);//�հ׾���
		drawSolidRect(Point(0, 0), Point(Length * rate, Height), color);//ʵ��Ѫ��
	}
	if (parent->getTag() == GameSceneNodeTagSoldier)//����Ѫ��
	{
		auto temp = dynamic_cast<Soldiers *>(parent);
		auto rate = float(temp->getcurrentHealth()) / float(temp->getMaxHealth());
		drawRect(Point(0, 0), Point(Length, Height), color);
		drawSolidRect(Point(0, 0), Point(Length * rate, Height), color);
	}
}

void Bar::setLength(float length)
{
	Length = length;
}

void Bar::setHeight(float height)
{
	Height = height;
}