#include <iostream>
#include <conio.h>
#include "list.h"
using namespace std;

int main()
{
	system("color 1f");

	printf("\n\n");
	printf("    \t *******************************************************************\n");
	printf("    \t ******                                                       ******\n");
	printf("    \t ******                C��������������                         ******\n");
	printf("    \t ******      ���ݲ��������е��������һ������,���ռ�             ******\n");
	printf("    \t ******      ��Ӹߵ����γ�һ���������д����Ĳ���            ******\n");
	printf("    \t*******      ����,�����ɾ������,����Ĳ��Һ���(����             ******\n");
	printf("    \t ******      �����˱�Ų���)                                   ******\n");
	printf("    \t ******                 2018-8-11                             ******\n");
	printf("    \t ******             http://www.cnblogs.com/chechen/           ******\n");
	printf("    \t ******                 �����������                           ******\n");


	char c = _getch();//��������ȴ�����

	CList list;
	list.Load();

	while(list.Menu())
		;

	return 0;
}