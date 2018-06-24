#include"Introduce.h"

Scene * IntroductionScene::createScene()
{
	auto scene = Scene::create();
	auto layer = IntroductionScene::create();
	scene->addChild(layer);
	return scene;
}

bool IntroductionScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	//page1
	string gameIntroduction1 = "\
	\nһ����Ϸ��ʼ��������\n\
	\n1.����RedAlert.exe\n\
	\n2.����ˣ�\
	\n  ��ʼ��Ϸ->ѡ���ͼ->������Ϸ->\n���ö˿ں�(Ĭ��Ϊ8008)->����������\n\
	\n3.�ͻ��ˣ�\
	\n  ��ʼ��Ϸ->ѡ���ͼ(��ѡ����������ͬ�ĵ�ͼ)->\n������Ϸ->������ȷ��IP��ַ��˿ں�->������Ϸ\n\
	\n4.����ˣ�\
	\n  �����·�����ʾ��ǰ������Ϸ�������������ʼ��Ϸ���ɽ�����Ϸ\n";
	page1 = LabelTTF::create(MyUtility::gbk_2_utf8(gameIntroduction1), "�����п�", 15);
	page1->setHorizontalAlignment(TextHAlignment::CENTER);
	page1->setPosition(Vec2(origin.x + visibleSize.width / 2, 
		origin.y + visibleSize.height - page1->getContentSize().height / 2));
	page1->setVisible(true);
	addChild(page1);

	//page2
	string gameIntroduction2 = "\
	\n������Ϸ���ݽ���\n\
	\n1.��ͼ��\
	\n  ����Ϸ֧�����Ų�ͬ�ĵ�ͼ���ɹ��������ѡ��\n\
	\n  ��ͼ�ƶ�:������Ƶ������Ե����ͼ�����Զ��ƶ���\
	\n  ��ʹ�ÿ�ݼ�P�ر��Զ��ƶ����� Ҳ��ʹ��WSAD�����������е�ͼ�ƶ�\n\
	\n2.��ң�\
	\n  ����Ϸ���֧���ĸ������ͬһ��������������ս\n\
	\n3.��Ǯ(Money)��\
	\n  ��ʼֵΪ7000 ���������������������\n\
	\n  ��Ǯ����ʱ�����������������Ƚ���\n\
	\n  ��Ϸ���ڽϺõ���Ǯ�������������(ǰ����Ҫ�п�)��\
	\n	������Զ��ɿ󣬲ɿ�ɹ����ȡ�ýϴ������\n";
	page2 = LabelTTF::create(MyUtility::gbk_2_utf8(gameIntroduction2), "�����п�", 15);
	page2->setHorizontalAlignment(TextHAlignment::CENTER);
	page2->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - page2->getContentSize().height / 2));
	page2->setVisible(false);
	addChild(page2);

	//page3
	string gameIntroduction3 = "\
	\n4.����(Power)��\
	\n  ��ʼֵΪ4000\n\
	\n  �����������Ŀǰ��Ϸ�������������м������ֵ�������\
	\n  ���һ����Ҫ����3000����\n\
	\n  ��������ʱ�����������������ȼ���\n\
	\n  �ڼ����е糧������£�������ʱ��������ٶȻ�������\n";
	page3 = LabelTTF::create(MyUtility::gbk_2_utf8(gameIntroduction3), "�����п�", 15);
	page3->setHorizontalAlignment(TextHAlignment::CENTER);
	page3->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - page3->getContentSize().height / 2));
	page3->setVisible(false);
	addChild(page3);

	//page4
	string gameIntroduction4 = "\
	\n5.�����\
	\n  �����Ϸ�����ұߵ�ͼ�꣬�Ϳ���������Ӧ�Ľ����\
	\n  һ��������ͬʱӵ��һ��ͬ���͵Ľ����\
	\n  ����Ϸ֧�����ֲ�ͬ�Ľ�����\n\
	\n  �ٻ��أ�ӵ�нϸߵ�Ѫ�������ر��ݻٺ���Ҽ����֡�\
	\n  ��Ϸ��Ŀ����Ǵݻ������������˵Ļ���\n\
	\n  �ۿ󳡣������������\n\
	\n  ��ս������������������ǿ��ı��֣�̹��\n\
	\n  �ݱ�Ӫ���������������սʿ���ֱ���\n\
	\n  �޵糧�����硣�����ӵ�е糧ʱ�������������ٶȻ����ӿ�\n";
	page4 = LabelTTF::create(MyUtility::gbk_2_utf8(gameIntroduction4), "�����п�", 15);
	page4->setHorizontalAlignment(TextHAlignment::CENTER);
	page4->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - page4->getContentSize().height / 2));
	page4->setVisible(false);
	addChild(page4);

	//page5
	string gameIntroduction5 = "\
	\n6.���֣�\
	\n  ��������Ӧ�Ľ�����ʱ�������Ϸ�����ұߵ�ͼ�꣬\
	\n  �Ϳ���������Ӧ��ʿ��������Ϸ֧�����ֱ���\n\
	\n  �ٿ�����ɿ���������ϵͳ�Զ��ٿأ���Ҳ��ܿ��ơ�\n\
	\n  ���������֮����ص�ͼ�ϱ�־������·���Զ�ǰ���󳡣�\
	\n  �ɿ��Զ����ؿ󳡱���ʧ��ͬʱ��Ǯ��õ�һ��������\
	\n  ���������������������������Ҫ�������ʹ����˳������\n\
	\n  �ھ��죺�ɱ�Ӫ�����������ϵͣ��۸����\n\
	\n  ��սʿ���ɱ�Ӫ������������ǿ���ж��ٶ������۸�����\n\
	\n  ��̹�ˣ���ս������������������ǿ���ж��ٶȿ죬�۸�ϸ�\n\
	\n  �����ƶ���ʹ������ѡҪ�ƶ��ı��֣�\
	\n  ���ڿ�ѡ״̬�ı��־Ϳ����ƶ����������λ��\
	\n  �������е��ϰ���ط���������ֲ����ƶ�\n";
	page5 = LabelTTF::create(MyUtility::gbk_2_utf8(gameIntroduction5), "�����п�", 15);
	page5->setHorizontalAlignment(TextHAlignment::CENTER);
	page5->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - page5->getContentSize().height / 2));
	page5->setVisible(false);
	addChild(page5);

	//page6
	string gameIntroduction6 = "\
	\n7.����������\
	\n  ���������ڵ���3000ʱ���Ϳ��Ե����Ϸ�����ұߵ�ͼ����б���������\
	\n  ������ϵ����м���ʿ�������������һ�������\n\
	\n  ���ں����ʱ��ʹ�ñ�����������������ʹ�书Ч���ӵ����\n";
	page6 = LabelTTF::create(MyUtility::gbk_2_utf8(gameIntroduction6), "�����п�", 15);
	page6->setHorizontalAlignment(TextHAlignment::CENTER);
	page6->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - page6->getContentSize().height / 2));
	page6->setVisible(false);
	addChild(page6);

	//page7
	string gameIntroduction7 = "\
	\n������Ϸ��ݼ�\n\
	\n  ����Ϸ֧�������̽�����������������¿�ݼ��Է����û�ʹ��\n\
	\n  SPACE����������ת����������\n\
	\n  W���������� S���������� A���������� D����������\n\
	\n  CTRL����ϷĬ�Ͽ������ѡ����\
	\n  ��CTRL��ʼ�رմ˹��ܣ��ٰ�һ���ֿɽ��俪��\n\
	\n  P����ϷĬ�Ͽ�����ͼ�Զ��ƶ�����\
	\n  ��P�رյ�ͼ�Զ��ƶ����� �ٰ�һ���ֿɽ��俪��\n";
	page7 = LabelTTF::create(MyUtility::gbk_2_utf8(gameIntroduction7), "�����п�", 15);
	page7->setHorizontalAlignment(TextHAlignment::CENTER);
	page7->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - page7->getContentSize().height / 2));
	page7->setVisible(false);
	addChild(page7);

	//page8
	string gameIntroduction8 = "\
	\n�ġ�ע������\n\
	\n  ������Ϸʱ�������Ҫѡ��ͬһ�ŵ�ͼ��\
	\n  ������Ȼ���Խ�����Ϸ���������ڲ�ͬ�ĵ�ͼ�Ͻ���ս��\n\
	\n  ���ر��߻ٺ���յ�ʤ����Ϣ�����ǲ������˳���Ϸ����\
	\n  ��Һ�������Ȼ�����ӣ����޷������������κβ��������ɹ�ս\
	\n  ����յ�ʤ����Ϣ����Ϸ��δ�������벻Ҫ�ر���Ϸ\
	\n  �ر���Ϸ��������������Ϸ�ж�\n\
	\n  ���ڱ���Ϸ��Ҫ�������У�\
	\n  һ��ĳһ�û�����Ϸ����ʱ��;�˳���ʧȥ���ӣ�\
	\n  ���ᵼ�������жϣ�������ҵĳ��򶼽��쳣��\
	\n  ����벻Ҫ����Ϸ��;������Ϸ������Ϸ��С��\n\
	\n  �벻Ҫ��ʿ���ڶ�ʱ���ڶ���ƶ���\
	\n  ����һ���ڷ�����ʮ���ƶ�ָ����ᵼ������ӵ������Ϸ����\n";
	page8 = LabelTTF::create(MyUtility::gbk_2_utf8(gameIntroduction8), "�����п�", 15);
	page8->setHorizontalAlignment(TextHAlignment::CENTER);
	page8->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - page8->getContentSize().height / 2));
	page8->setVisible(false);
	addChild(page8);

	auto nextlabel = LabelTTF::create(MyUtility::gbk_2_utf8("��һҳ"), "�����п�", 15);
	nextPageMenu = MenuItemLabel::create(nextlabel, CC_CALLBACK_1(IntroductionScene::nextPage, this));
	float next_x = nextPageMenu->getContentSize().width;
	float next_y = nextPageMenu->getContentSize().height;
	nextPageMenu->setPosition(Vec2(origin.x + visibleSize.width / 2 + next_x, origin.y + next_y));

	auto lastlabel = LabelTTF::create(MyUtility::gbk_2_utf8("��һҳ"), "�����п�", 15);
	lastPageMenu = MenuItemLabel::create(lastlabel, CC_CALLBACK_1(IntroductionScene::lastPage, this));
	float last_x = nextPageMenu->getContentSize().width;
	float last_y = nextPageMenu->getContentSize().height;
	lastPageMenu->setPosition(Vec2(origin.x + visibleSize.width /2 - last_x, origin.y + last_y));
	lastPageMenu->setVisible(false);

	auto backlabel = LabelTTF::create(MyUtility::gbk_2_utf8("����"), "�����п�", 15);
	backMenu = MenuItemLabel::create(backlabel, CC_CALLBACK_1(IntroductionScene::backToMenuScene, this));
	float back_x = backMenu->getContentSize().width;
	float back_y = backMenu->getContentSize().height;
	backMenu->setPosition(Vec2(origin.x + visibleSize.width - back_x, origin.y + back_y));

	auto menu = Menu::create(nextPageMenu, lastPageMenu, backMenu, NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);

	return true;
}

void IntroductionScene::backToMenuScene(Ref *pSender)
{
	auto sc = MenuScene::createScene();
	auto reScene = TransitionFadeTR::create(0.5f, sc);
	Director::getInstance()->pushScene(reScene);
}

void IntroductionScene::nextPage(Ref *pSender)
{
	pageNumber++;
	if (pageNumber == 2)
	{
		page1->setVisible(false);
		page2->setVisible(true);
	}
	if (pageNumber == 3)
	{
		page2->setVisible(false);
		page3->setVisible(true);
	}
	if (pageNumber == 4)
	{
		page3->setVisible(false);
		page4->setVisible(true);
	}
	if (pageNumber == 5)
	{
		page4->setVisible(false);
		page5->setVisible(true);
	}
	if (pageNumber == 6)
	{
		page5->setVisible(false);
		page6->setVisible(true);
	}
	if (pageNumber == 7)
	{
		page6->setVisible(false);
		page7->setVisible(true);
	}
	if (pageNumber == 8)
	{
		page7->setVisible(false);
		page8->setVisible(true);
		nextPageMenu->setVisible(false);
	}
	lastPageMenu->setVisible(true);
}

void IntroductionScene::lastPage(Ref *pSender)
{
	pageNumber--;
	if (pageNumber == 1)
	{
		page1->setVisible(true);
		page2->setVisible(false);
		lastPageMenu->setVisible(false);
	}
	if (pageNumber == 2)
	{
		page2->setVisible(true);
		page3->setVisible(false);
	}
	if (pageNumber == 3)
	{
		page3->setVisible(true);
		page4->setVisible(false);
	}
	if (pageNumber == 4)
	{
		page4->setVisible(true);
		page5->setVisible(false);
	}
	if (pageNumber == 5)
	{
		page5->setVisible(true);
		page6->setVisible(false);
	}
	if (pageNumber == 6)
	{
		page6->setVisible(true);
		page7->setVisible(false);
	}
	if (pageNumber == 7)
	{
		page7->setVisible(true);
		page8->setVisible(false);
	}
	nextPageMenu->setVisible(true);
}