#include <iostream>
using namespace std;
#include "MyList.h"

int main()
{
	MyList::CMyList list;

	list.AddHead(1);
	list.AddHead(2);
	list.AddHead(3);
	puts("修改前");
	list.PrintALL();
	list.ModifyNode(2,-88);
	puts("修改后");
	list.PrintALL();

	int i = list.FindNode(-88);
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

	return 0;
}