#ifndef _LIST_H_
#define _LIST_H_
#include <atlstr.h>

struct SInfo
{
	int UserNum;//购买人员编号
	double dPrice;//价格
	UINT32 uTime;//时间
	int iAmount;//购买量
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