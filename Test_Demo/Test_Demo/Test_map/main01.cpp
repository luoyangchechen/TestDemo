#include <iostream>
#include <time.h>

//随机生成0或者1
//int main()
//{
//	srand((unsigned)time(NULL));//srand()就是给rand()提供种子seed 
//
//	//100次随机生成0或者1
//	for (int i =0; i < 100; i++)
//	{
//		int num = rand()%2;//对2取余得到就是0或者1
//
//		printf("第%d次随机生成的数: %d \n",i+1,num);
//	}
//	printf("\n");
//	return 0;
//}

int main()
{
	srand((unsigned)time(NULL));//srand()就是给rand()提供种子seed

	for (int i = 0; i < 100; i++)
	{
		int num = rand()%100;//对100取余操作
		printf("第%d次随机生成0~100的数: %d \n",i+1,num);
	}
	printf("\n");

	return 0;
}
