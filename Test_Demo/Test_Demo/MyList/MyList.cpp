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

		if (!m_pHead)
		{
			m_pHead = pNew;
			return;
		}

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


		//��һ��д��
		//while(p->pNext != NULL)
		//	p=p->pNext;

		//p->pNext = pNew;
	
	}

	int CMyList::FindNodeIndex(DATA nNum)
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

		if (p == NULL)//��ǰ����Ϊ��
		{
			return -1;
		}

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
		if (p == NULL)
		{
			printf("��ǰ����Ϊ��\n");
			return;
		}
		while(p)//
		{
			cout << p->data << endl;
			p = p->pNext;
		}
	}

	int CMyList::FindNode(DATA nNum)
	{
		SNode* p = m_pHead;
		while (p)
		{
			if (p->data == nNum)
			{
				return 0;
			}

			p=p->pNext;
		}
		return -1;
	}

	int CMyList::InsertNode(DATA npos,DATA nNum)
	{

		SNode* pNew = new SNode;//C++ ��ʽ
		pNew->data = nNum;
		pNew->pNext = NULL;
	

		SNode* p = m_pHead;

		//if (p->data == npos)//ͷ���
		//{
		//	pNew->pNext=p->pNext;//ͷ�ڵ�ָ�����һ���ڵ�ָ��ŵ��½ڵ��pNext
		//	p->pNext=pNew;//ͷ�ڵ�pNextָ���½ڵ�

		//	return 0;
		//}

		while(p)
		{
			if (p->data == npos)
			{
				pNew->pNext = p->pNext;
				p->pNext=pNew;

				return 0;
			}
			p = p->pNext;
		}

		return -1;
	}

	void CMyList::DeleteAll()
	{
		SNode* p = m_pHead;
		SNode* p1 = NULL;
		while(p)
		{
			p1=p;
			p= p->pNext;

			delete p1;
		}

		m_pHead = NULL;
	}

};
