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
	puts("�޸�ǰ");
	list.PrintALL();
	list.ModifyNode(2,-88);
	puts("�޸ĺ�");
	list.PrintALL();

	int i = list.FindNodeIndex(-88);
	if (i >= 0)
	{
		cout << "��" << i+1 << "���ڵ��ҵ�" <<endl;
	}

	//ɾ���ڵ�

	i = list.DeleteNode(3);//ͷ��ɾ��Ҫ���⴦��
	
	if (i == 1)
	{
		cout << "ɾ���ڵ�ɹ�!" << endl;
	}
	else
	{
		cout << "ɾ���ڵ�ʧ��!" << endl;
	}
	list.PrintALL();

	puts("β�����");
	list.AddTail(4);
	list.PrintALL();

	//�޸Ľڵ�
	list.ModifyNode(-88,0);

	puts("����ڵ�3");
	//����ڵ�
	i = list.InsertNode(4,3);


	list.PrintALL();

	puts("�������");
	list.DeleteAll();
	list.PrintALL();

	return 0;
}