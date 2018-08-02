#include "MyList.h"
#include <malloc.h>
namespace MyList
{

	CMyList::CMyList():m_pHead(NULL)
	{

	}

	CMyList::~CMyList()
	{

	}

	//��ͷ�����
	void CMyList::AddHead(DATA nNum)
	{
		//SNode* p = (SNode*)malloc(sizeof(SNode));//C���Եķ�ʽ
		SNode* p = new SNode;//C++ ��ʽ
		p->data = nNum;
		p->pNext = m_pHead;

		m_pHead = p;
	}
	//��β�����
	void CMyList::AddTail(DATA nNum)
	{
		SNode* pNew = new SNode;//C++ ��ʽ
		pNew->data = nNum;
		pNew->pNext = NULL;

		SNode* p = m_pHead;
		SNode* p1 = NULL;
		while (p)
		{
			p1 = p;
			p= p->pNext;
		}

		//����ѭ��ʱ��p1��¼��ʱ���һ���ڵ�,�����һ���ڵ��pNextָ���´����Ľڵ�
		p = p1;
		p->pNext = pNew;
	
	}

	int CMyList::FindNode(DATA nNum)
	{
		SNode* p = m_pHead;
		int i =0;
		while(p)
		{
			if (p->data == nNum)
			{
				return i;
			}
			
			p = p->pNext;
			++i;
		}

		return -1;
	}

	int CMyList::DeleteNode(DATA nNum)
	{
		SNode* p = m_pHead;
		SNode* p1 = NULL;//��¼ǰһ���ڵ�

		//ͷ�ڵ�û��ǰһ���ڵ㣬Ҫ���⴦��
		if (p->data == nNum)
		{
			m_pHead = p->pNext;
			delete p;
			return 1;
		}
		while(p)
		{

			if (p->data == nNum)
			{
				//ɾ����ǰ�ڵ�ʱ���õ�ǰ�ڵ��ǰһ���ڵ��pNextָ��ǰ�ڵ�ĺ�һ���ڵ�
				p1->pNext = p->pNext;
				delete p;
				return 1;
			}
			p1= p;//��¼ǰ�ڵ�
			p = p->pNext;

		}

		return 0;
	}

	void CMyList::ModifyNode(DATA oldNum,DATA newNum)
	{
		SNode* p = m_pHead;
		while(p)//
		{
			if (p->data == oldNum)
			{
				p->data = newNum;
			}
			p = p->pNext;
		}
	}

	void CMyList::PrintALL()
	{
		SNode* p = m_pHead;
		while(p)//
		{
			cout << p->data << endl;
			p = p->pNext;
		}
	}

};
