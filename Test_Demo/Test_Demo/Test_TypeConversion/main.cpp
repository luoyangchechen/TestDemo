#include <iostream>
#include <string>
using namespace std;

/**************************************************************
*
* Copyright      :http://www.cnblogs.com/chechen/
*
* Created        : 2018-7-26 21:57:39
*
* Author         :  chechen
*
* Description    : [CN]   ��Чֵת��   [CN]
*
**************************************************************/
void TestInValid()
{
	double d = atof("-");
	
	cout << d << endl;//0.00000000000000000

	//���ַ���ת��Ϊlong int  ������#include <string>ͷ�ļ���

	try
	{
		double d2 = stol("-");//���쳣���������  ������ͨ��try catch ����
	}
	catch (...)
	{

	}	
}


int main()
{
	TestInValid();
	return 0;
}