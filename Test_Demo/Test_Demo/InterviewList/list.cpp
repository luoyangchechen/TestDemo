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

	pNew->pNext = m_pHead;//�������½ڵ��pNextָ��ԭ�ȵ�ͷ�ڵ�
	m_pHead = pNew;//�ٰ��½ڵ�ĵ�ַ�� m_pHead;
}

void CList::AddTail(DATA data)
{
	SNode* pNew =  new SNode;
	pNew->data.UserNum =data.UserNum;
	pNew->data.dPrice = data.dPrice;
	pNew->data.uTime = data.uTime;
	pNew->data.iAmount = data.iAmount;

	SNode* p = m_pHead;

	if (p == NULL)//����Ϊ��
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
	if (!m_pHead)//����Ϊ�յ����
	{
		return 0;
	}
	//ͷ�ڵ�Ҫ���⴦��
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

	puts("�û����\t�۸�\tʱ��\t��������");
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

	puts("�û����\t�۸�\tʱ��\t��������");
	while (p)
	{
		printf("%d\t%0.1f\t%ud\t%d\n",p->data.UserNum,p->data.dPrice,p->data.uTime,p->data.iAmount);
		++i;
		p=p->pNext;
	}
	printf("�ܹ�%d����¼\n",i);
	system("pause");
}

