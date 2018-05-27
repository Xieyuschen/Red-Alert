//Ƭͷ����

#ifndef __SplashScene_H_
#define __SplashScene_H_
#include"cocos2d.h"
#include<iostream>
#include"ConstUtil.h"
#include"MenuScene.h"

#include"MyUtility.h"//��д�ط�
USING_NS_CC;

class SplashScene :Layer
{
public:
	bool init();                        //��ʼ������
	CREATE_FUNC(SplashScene);           //���create�������������
	static Scene * createScene();       //��������
	const double MOVE_SPLEED = 0.5f;    //���������ٶ�
	void moveSeSpriteToRight();         //����se.png���������ƶ��İ취
	void moveJingSpriteToRight();       //����hong.png���������ƶ��İ취
	void initMoveSprite();              //��ʼ��ͼƬ�ķ���
	void startMoveSprite(float dt);     //��ʼ�ƶ�����
	void spriteFadeOut();               //������ʧ����
	void gotoMenuScene();               //�������������MenuScene����

private:
	Sprite* hong_Sprite;                //hong.png����
	Sprite* se_Sprite;                  //se.png����
	Sprite* jing_Sprite;                //jing.png����
	Sprite* jie_Sprite;                 //jie.png����
	Size visibleSize;                   //���ڴ�С
	Size spriteSize;                    //ͼƬ�ĳߴ��С

	void jumpToMenuScen(Ref *pSender);

};
#endif // !__SplashScene_H_

