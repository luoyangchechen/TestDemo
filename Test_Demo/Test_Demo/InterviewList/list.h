#ifndef _LIST_H_
#define _LIST_H_
#include <atlstr.h>
#include <string>
using namespace std;

struct SInfo
{
	int UserNum;//������Ա���
	int dPrice;//�۸�
	time_t t;//Unixʱ���
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


	int Menu();
	void Load();
protected:

	//ͷ������ڵ�
	void AddHead(DATA data);
	//β������ڵ�
	void AddTail(DATA data);

	//ɾ���ڵ�
	int DeleteNode(int num);

	//ͨ���۸�����
	void SortByPrice();

	//ͨ����Ա��Ų���
	int FindNode(int num);

	//��ӡ��Ϣ
	void PrintAll();

	void Input(int nDir);//��ӽڵ�����

	//ɾ�����нڵ�
	void ReMoveAll();

	void Save();

	std::string UnicodeToUTF8( const wstring& wstr );

private:
	SNode* m_pHead;
};

#endif//_LIST_H_