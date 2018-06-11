#include <math.h>  
#include "Astar.h"  

void Astar::InitAstar(vector<bool> &_maze, int mapWidth, int mapHeight)
{
	maze = _maze;
	width = mapWidth;
	height = mapHeight;
}
int Astar::calculateG(Apoint *temp_start, Apoint *point)
{
	int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y)) == 1 ? strMove : tiltMove;
	//����ǳ�ʼ�ڵ㣬���丸�ڵ��ǿ�
	int parentG = point->parent == NULL ? 0 : point->parent->G;
	return parentG + extraG;
}
int Astar::calculateH(Apoint *point, Apoint *end)
{
	return sqrt((double)(end->x - point->x)*(double)(end->x - point->x)+(double)(end->y-point->y)*(double)(end->y)-point->y)*strMove;
}
int Astar::calculateF(Apoint *point)
{
	return point->G + point->H;
}

Apoint *Astar::getLeastF()
{
	if (!openList.empty())
	{
		auto resPoint = openList.front();
		for (auto point : openList)
			if (point->F < resPoint->F)
				resPoint = point;
		return resPoint;
	}
	return NULL;
}
Apoint *Astar::findPath(Apoint &startPoint, Apoint &endPoint, bool ifIgnoreCorner)
{
	openList.clear();
	closeList.clear();
	openList.push_back(new Apoint(startPoint.x, startPoint.y));
	//�������,��������һ���ڵ㣬�������  
	while (!openList.empty())
	{
		auto currentPoint = getLeastF();//�ҵ�Fֵ��С�ĵ�
		vector<Apoint*>::iterator it = openList.begin();
		for (; it != openList.end(); it++)
		{
			if (*it == currentPoint)
				break;
		}

		openList.erase(it);//�ӿ����б���ɾ��
		closeList.push_back(currentPoint);//�ŵ��ر��б� 
		//1,�ҵ���ǰ��Χ�˸����п���ͨ���ĸ���  
		auto surroundingPoints = getSurroundingPoints(currentPoint, ifIgnoreCorner);
		for (auto &target : surroundingPoints)
		{
			//2,��ĳһ�����ӣ���������ڿ����б��У�
			//���뵽�����б����õ�ǰ��Ϊ�丸�ڵ㣬
			//����F G H  
			if (!ifInList(openList, target))
			{
				target->parent = currentPoint;
				target->G = calculateG(currentPoint, target);
				target->H = calculateH(target, &endPoint);
				target->F = calculateF(target);
				openList.push_back(target);
			}
			//3����ĳһ�����ӣ����ڿ����б��У�����Gֵ, �����ԭ���Ĵ�, ��ʲô������, �����������ĸ��ڵ�Ϊ��ǰ��,������G��F  
			else
			{
				int tempG = calculateG(currentPoint, target);
				if (tempG < target->G)
				{
					target->parent = currentPoint;
					target->G = tempG;
					target->F = calculateF(target);
				}
				
					
				
			}
			Apoint *resPoint = ifInList(openList, &endPoint);
			if (resPoint)
				return resPoint;
			

		}
	}
	return NULL;
}
vector<Apoint*> Astar::getPath(Apoint &startPoint, Apoint &endPoint, bool ifIgnoreCorner)
{
	log("from point============>%d,%d", startPoint.x, startPoint.y);
	log("to point===========>%d,%d", endPoint.x, endPoint.y);
	Apoint *result = findPath(startPoint, endPoint, ifIgnoreCorner);
	vector<Apoint*> path;
	//����·��
	//���û�ҵ�·�������ؿ�����
	int s = 1;
	while (result->parent)
	{
		vector<Apoint*>::iterator it = path.begin();
		for (; it != path.end(); it++)
		{
			if (*it == result)
				break;
		}
		path.insert(it, 0);
		result = result->parent;
		s++;
	}
	log("s===>%d", s);
	return path;
}
Apoint *Astar::ifInList(const vector<Apoint*>&list, const Apoint *point)const
{
	//�ж�ĳ���ڵ��Ƿ����б���
	//�Ƚ�����
	for (auto p : list)
	{
		if (p->x == point->x&&p->y == point->y)
			return p;
		return NULL;
	}
}
bool Astar::ifAbleReach(const Apoint *point, const Apoint *target, bool ifIgnoreCorner)const
{
	if (target->x<0 || target->x>width - 1
		|| target->y<0 || target->y>height - 1//������ͼ
		|| maze[width*target->y + target->x] == false//���ϰ���
		|| (target->x == point->x&&target->y == point->y)//�뵱ǰ�ڵ��غ�
		|| ifInList(closeList, target))//�ڹر��б���
		return false;
	else
	{
		//б�Խ�Ҫ�ж��Ƿ��ס  
		if (maze[width*target->y + point->x] == true
			&& maze[width*point->y + target->x] == true)
			return true;
		else
			return ifIgnoreCorner;
	}
}
vector<Apoint*> Astar::getSurroundingPoints(const Apoint *point, bool ifIgnoreCorner) const
{
	vector<Apoint*> surroundingPoints;
	for (int x = point->x - 1; x <= point->x + 1; x++)
	{
		for (int y = point->y - 1; y <= point->y + 1; y++)
			if (ifAbleReach(point, new Apoint(x, y), ifIgnoreCorner))
				surroundingPoints.push_back(new Apoint(x, y)); 

	}
	return surroundingPoints;
}

