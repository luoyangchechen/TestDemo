#ifndef _MYLIST_H_
#define _MYLIST_H_
#include <windows.h>
#include <iostream>
using namespace std;

namespace MyList
{
	typedef int DATA;

	struct SNode
	{
		DATA data;
		SNode* pNext;
	};

	class CMyList
	{
	public:
		CMyList();
		~CMyList();

		//��ͷ�����
		void AddHead(DATA nNum);
		//��β�����
		void AddTail(DATA nNum);

		//���ҽڵ�
		//return �ڼ����ڵ�ɹ��ҵ�;-1û�ҵ�
		int FindNode(DATA nNum);

		//ɾ���ڵ�
		//ɾ���ɹ� ����1; ʧ�� ����0
		int DeleteNode(DATA nNum);

		//�޸Ľڵ�
		void ModifyNode(DATA oldNum,DATA newNum);

		//��ӡ�ڵ�
		void PrintALL();

	private:
		SNode* m_pHead;//ͷ�ڵ�
	};
};

#endif//_MYLIST_H_