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

		//从头部添加
		void AddHead(DATA nNum);
		//从尾部添加
		void AddTail(DATA nNum);

		/*插入节点
		*param npos 插入节点位置 例如:插入到3 的后面
		*param nNum 新节点
		*return 成功 0;-1 失败
		*/
		int InsertNode(DATA npos,DATA nNum);

		//查找节点位置
		//return 第几个节点成功找到;-1没找到
		int FindNodeIndex(DATA nNum);

		/*查到节点
		* return 0 找到;-1没有找到
		*/
		int FindNode(DATA nNum);

		//删除节点
		//删除成功 返回1; 失败 返回0
		int DeleteNode(DATA nNum);

		//修改节点
		void ModifyNode(DATA oldNum,DATA newNum);

		//打印节点
		void PrintALL();

		//删除所有节点
		void DeleteAll();

	private:
		SNode* m_pHead;//头节点
	};
};

#endif//_MYLIST_H_