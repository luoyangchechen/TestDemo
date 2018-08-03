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

	//从头部添加
	void CMyList::AddHead(DATA nNum)
	{
		//SNode* p = (SNode*)malloc(sizeof(SNode));//C语言的方式
		SNode* p = new SNode;//C++ 方式
		p->data = nNum;
		p->pNext = m_pHead;

		m_pHead = p;
	}
	//从尾部添加
	void CMyList::AddTail(DATA nNum)
	{
		SNode* pNew = new SNode;//C++ 方式
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

		//跳出循环时，p1记录的时最后一个节点,让最后一个节点的pNext指向新创建的节点
		p = p1;
		p->pNext = pNew;


		//另一种写法
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
		SNode* p1 = NULL;//记录前一个节点

		if (p == NULL)//当前链表为空
		{
			return -1;
		}

		//头节点没有前一个节点，要特殊处理
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
				//删除当前节点时，让当前节点的前一个节点的pNext指向当前节点的后一个节点
				p1->pNext = p->pNext;
				delete p;
				return 1;
			}
			p1= p;//记录前节点
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
			printf("当前链表为空\n");
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

		SNode* pNew = new SNode;//C++ 方式
		pNew->data = nNum;
		pNew->pNext = NULL;
	

		SNode* p = m_pHead;

		//if (p->data == npos)//头结点
		//{
		//	pNew->pNext=p->pNext;//头节点指向的下一个节点指针放到新节点的pNext
		//	p->pNext=pNew;//头节点pNext指向新节点

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
