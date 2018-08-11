#ifndef _LIST_H_
#define _LIST_H_
#include <atlstr.h>
#include <string>
using namespace std;

struct SInfo
{
	int UserNum;//购买人员编号
	int dPrice;//价格
	time_t t;//Unix时间戳
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


	int Menu();
	void Load();
protected:

	//头部插入节点
	void AddHead(DATA data);
	//尾部插入节点
	void AddTail(DATA data);

	//删除节点
	int DeleteNode(int num);

	//通过价格排序
	void SortByPrice();

	//通过人员编号查找
	int FindNode(int num);

	//打印信息
	void PrintAll();

	void Input(int nDir);//添加节点输入

	//删除所有节点
	void ReMoveAll();

	void Save();

	std::string UnicodeToUTF8( const wstring& wstr );

private:
	SNode* m_pHead;
};

#endif//_LIST_H_