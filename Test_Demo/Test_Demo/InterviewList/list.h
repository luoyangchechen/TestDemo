#ifndef _LIST_H_
#define _LIST_H_
#include <atlstr.h>

struct SInfo
{
	int UserNum;//������Ա���
	double dPrice;//�۸�
	UINT32 uTime;//ʱ��
	int iAmount;//������
};

typedef SInfo DATA;

struct SNode
{
	DATA data;
	SNode* pNext;

	SNode()
	{
		pNext = NULL;
	}
};

class CList
{
public:
	CList();
	~CList();

	void AddHead(DATA data);
	void AddTail(DATA data);

	int DeleteNode(int num);

	int FindNode(int num);

	void PrintfAll();

private:
	SNode* m_pHead;
};

#endif//_LIST_H_