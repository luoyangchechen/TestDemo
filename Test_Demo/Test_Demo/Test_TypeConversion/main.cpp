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
* Description    : [CN]   无效值转换   [CN]
*
**************************************************************/
void TestInValid()
{
	double d = atof("-");
	
	cout << d << endl;//0.00000000000000000

	//将字符串转换为long int  包含在#include <string>头文件中

	try
	{
		double d2 = stol("-");//抛异常，程序崩溃  但可以通过try catch 捕获
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