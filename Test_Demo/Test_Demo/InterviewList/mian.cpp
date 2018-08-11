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
	printf("    \t ******                C语言链表面试题                         ******\n");
	printf("    \t ******      根据测试用例中的数据设计一个链表,按照价             ******\n");
	printf("    \t ******      格从高到低形成一个链表。请编写链表的插入            ******\n");
	printf("    \t*******      函数,链表的删除函数,链表的查找函数(根据             ******\n");
	printf("    \t ******      购买人编号查找)                                   ******\n");
	printf("    \t ******                 2018-8-11                             ******\n");
	printf("    \t ******             http://www.cnblogs.com/chechen/           ******\n");
	printf("    \t ******                 按任意键继续                           ******\n");


	char c = _getch();//按任意键等待输入

	CList list;
	list.Load();

	while(list.Menu())
		;

	return 0;
}