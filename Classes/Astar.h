#pragma once
#include<vector>
#include<list>
#include<unordered_map>
#include"Cocos2d.h"
USING_NS_CC;
using namespace std;


const int strMove = 10;
const int tiltMove = 14;

struct Apoint :public Ref
{
	int x, y;//����
	int F, G, H;//F=G+H
	Apoint* parent;
	//��ʼ��
	Apoint(int _x,int _y):
		x(_x),y(_y),F(0),G(0),H(0),parent(NULL){}
};
class Astar {
public:
	void InitAstar(vector<bool>&_maze, int mapWidth,int mapHeight);
	vector<Apoint*> getPath(Apoint &startPoint, Apoint &endPoint, bool ifIgnoreCorner);
private:
	Apoint *findPath(Apoint &startPoint, Apoint &endPoint, bool ifIgnoreCorner);
	vector<Apoint*> getSurroundingPoints(const Apoint *point, bool ifIgnoreCorner)const;
	bool ifAbleReach
	(const Apoint *point, const Apoint *target, bool ifIngoreCorner)const;
    //�ж�ĳ���Ƿ����������һ���ж� 
	Apoint* ifInList(const vector<Apoint*> &list, const Apoint *point)const;
	//�жϿ���/�ر��б����Ƿ����ĳ��
	Apoint *getLeastF();
	//�ӿ����б��з���Fֵ��С�Ľڵ�  
	//����FGHֵ
	int calculateG(Apoint *temp_start, Apoint *point);
	int calculateH(Apoint *point, Apoint *end);
	int calculateF(Apoint *point);
	
private:
	std::vector<bool> maze;
	vector<Apoint*> openList;  //�����б�  
	vector<Apoint*> closeList; //�ر��б�  



	int width;
	int height;

};

