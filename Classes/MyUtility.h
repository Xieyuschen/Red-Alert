//���Windowsƽ̨GBK��ʽ�������������� ���÷�ʽ MyUtility::gbk_2_utf8() ע�����ͷ�ļ�

#ifndef __MyUtility_H__
#define __MyUtility_H__
#include<string>
#include<Windows.h>
using namespace std;
class MyUtility
{
public:
	static string gbk_2_utf8(const string text);
};


#endif // !__MyUtility_H__



