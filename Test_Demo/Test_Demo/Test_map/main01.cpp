#include <iostream>
#include <time.h>

//�������0����1
//int main()
//{
//	srand((unsigned)time(NULL));//srand()���Ǹ�rand()�ṩ����seed 
//
//	//100���������0����1
//	for (int i =0; i < 100; i++)
//	{
//		int num = rand()%2;//��2ȡ��õ�����0����1
//
//		printf("��%d��������ɵ���: %d \n",i+1,num);
//	}
//	printf("\n");
//	return 0;
//}

int main()
{
	srand((unsigned)time(NULL));//srand()���Ǹ�rand()�ṩ����seed

	for (int i = 0; i < 100; i++)
	{
		int num = rand()%100;//��100ȡ�����
		printf("��%d���������0~100����: %d \n",i+1,num);
	}
	printf("\n");

	return 0;
}
