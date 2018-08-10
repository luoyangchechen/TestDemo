#include "list.h"
CList::CList()
	:m_pHead(NULL)
{

}

CList::~CList()
{

}

void CList::AddHead(DATA data)
{
	SNode* pNew =  new SNode;
	pNew->data.UserNum =data.UserNum;
	pNew->data.dPrice = data.dPrice;
	pNew->data.uTime = data.uTime;
	pNew->data.iAmount = data.iAmount;

	pNew->pNext = m_pHead;//首先让新节点的pNext指向原先的头节点
	m_pHead = pNew;//再把新节点的地址给 m_pHead;
}

void CList::AddTail(DATA data)
{
	SNode* pNew =  new SNode;
	pNew->data.UserNum =data.UserNum;
	pNew->data.dPrice = data.dPrice;
	pNew->data.uTime = data.uTime;
	pNew->data.iAmount = data.iAmount;

	SNode* p = m_pHead;

	if (p == NULL)//链表为空
	{
		pNew->pNext = m_pHead;
		m_pHead = pNew;

		return;
	}

	while(p->pNext!=NULL)
	{
		p = p->pNext;
	}

	p->pNext=pNew;
}

int CList::DeleteNode(int num)
{
	SNode* p = m_pHead;
	if (!m_pHead)//链表为空的情况
	{
		return 0;
	}
	//头节点要特殊处理
	if (p->data.UserNum == num)
	{
		m_pHead = p->pNext;
		delete p;
		return 1;
	}

	SNode* p1 = NULL;
	while(p)
	{
		if (p->data.UserNum == num)
		{
			p1->pNext=p->pNext;
			delete p;

			return 1;
		}
		p1 = p;
		p = p->pNext;
	}
}

int CList::FindNode(int num)
{
	SNode* p = m_pHead;

	if (!m_pHead)
	{
		return 0;
	}

	puts("用户编号\t价格\t时间\t购买数量");
	while(p)
	{
		if (p->data.UserNum == num)
		{
			printf("%d\t%0.1f\t%ud\t%d\n",p->data.UserNum,p->data.dPrice,p->data.uTime,p->data.iAmount);
		}

		p = p->pNext;
	}
	return 0;
}

void CList::PrintfAll()
{
	SNode* p = m_pHead;
	int i  =0;

	puts("用户编号\t价格\t时间\t购买数量");
	while (p)
	{
		printf("%d\t%0.1f\t%ud\t%d\n",p->data.UserNum,p->data.dPrice,p->data.uTime,p->data.iAmount);
		++i;
		p=p->pNext;
	}
	printf("总共%d条记录\n",i);
	system("pause");
}

