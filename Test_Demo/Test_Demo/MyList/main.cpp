#include <iostream>
using namespace std;
#include "MyList.h"

int main()
{
	MyList::CMyList list;

	list.DeleteNode(999);

	list.AddHead(1);
	list.AddHead(2);
	list.AddHead(3);
	puts("修改前");
	list.PrintALL();
	list.ModifyNode(2,-88);
	puts("修改后");
	list.PrintALL();

	int i = list.FindNodeIndex(-88);
	if (i >= 0)
	{
		cout << "第" << i+1 << "个节点找到" <<endl;
	}

	//删除节点

	i = list.DeleteNode(3);//头部删除要特殊处理
	
	if (i == 1)
	{
		cout << "删除节点成功!" << endl;
	}
	else
	{
		cout << "删除节点失败!" << endl;
	}
	list.PrintALL();

	puts("尾部添加");
	list.AddTail(4);
	list.PrintALL();

	//修改节点
	list.ModifyNode(-88,0);

	puts("插入节点3");
	//插入节点
	i = list.InsertNode(4,3);


	list.PrintALL();

	puts("清空链表");
	list.DeleteAll();
	list.PrintALL();

	return 0;
}