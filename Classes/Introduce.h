#ifndef __INTRODUCE_H_
#define __INTRODUCE_H_

#include<iostream>
#include<string>
#include"cocos2d.h"
#include"MyUtility.h"
#include"MenuScene.h"
using namespace std;
USING_NS_CC;

class IntroductionScene :public Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(IntroductionScene);

private:
	//���ڼ�¼�ڼ�ҳ
	int pageNumber = 1;

	//�ֱ�����һҳ����һҳ�����ز˵������İ�ť
	MenuItemLabel *nextPageMenu;
	MenuItemLabel *lastPageMenu;
	MenuItemLabel *backMenu;

	//һ����8ҳ
	LabelTTF *page1;
	LabelTTF *page2;
	LabelTTF *page3;
	LabelTTF *page4;
	LabelTTF *page5;
	LabelTTF *page6;
	LabelTTF *page7;
	LabelTTF *page8;

	//�ص�����
	void backToMenuScene(Ref *pSender);
	void nextPage(Ref *pSender);
	void lastPage(Ref *pSender);
};


#endif // !__INTRODUCE_H_
