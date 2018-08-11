#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
CList::CList()
	:m_pHead(NULL)
{

}

CList::~CList()
{
	ReMoveAll();
}

void CList::AddHead(DATA data)
{
	SNode* pNew =  new SNode;
	pNew->data.UserNum =data.UserNum;
	pNew->data.dPrice = data.dPrice;
	pNew->data.t = data.t;
	pNew->data.iAmount = data.iAmount;

	pNew->pNext = m_pHead;//�������½ڵ��pNextָ��ԭ�ȵ�ͷ�ڵ�
	m_pHead = pNew;//�ٰ��½ڵ�ĵ�ַ�� m_pHead;
}

void CList::AddTail(DATA data)
{
	SNode* pNew =  new SNode;
	pNew->data.UserNum =data.UserNum;
	pNew->data.dPrice = data.dPrice;
	pNew->data.t = data.t;
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

	return 0;
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
			printf("%d\t%0.1f\t%ud\t%d\n",p->data.UserNum,p->data.dPrice,p->data.t,p->data.iAmount);
		}

		p = p->pNext;
	}
	return 0;
}

void CList::PrintAll()
{
	SortByPrice();
	SNode* p = m_pHead;
	
	int i  =0;

	puts("�û����\t�۸�\tʱ��   \t��������");
	while (p)
	{
		printf("%d       \t%d\t%d  \t%d\n",p->data.UserNum,p->data.dPrice,(int)p->data.t,p->data.iAmount);
		++i;
		p=p->pNext;
	}
	printf("�ܹ�%d����¼\n",i);
	system("pause");
}

void CList::SortByPrice()
{
	SNode* p = m_pHead;

	if (!p)
	{
		return;
	}

	while(p->pNext)//�ӵڶ����ڵ�
	{
		SNode* q = p->pNext;
		SNode* m  = p;

		while(q)
		{
			if (q->data.dPrice > m->data.dPrice)
			{
				m = q;
			}

			q = q->pNext;
		}


		if (m!=p)
		{
			DATA t = p->data;

			p->data = m->data;
			m->data = t;
		}

		p = p->pNext;
	}
}

int CList::Menu()
{
	system("cls");
	int i =0;

	puts("\n\t\t1����ӽڵ�");
	puts("\t\t2�����ҽڵ�");
	puts("\t\t3��ɾ���ڵ�");
	puts("\t\t4����ӡ��Ϣ");
	puts("\t\t0���˳�");

	scanf_s("%d",&i);


	switch(i)
	{
	case 1:	
	case 2:
		Input(i);
		break;
	case 4:
		PrintAll();
		break;
	}
	return i;
}

void CList::Input(int nDir)
{
	DATA data;

	printf("�����빺���˱��:");
	scanf_s("%d",&data.UserNum);

	printf("������۸�:");
	scanf_s("%d",&data.dPrice);


	printf("������ʱ��:");
	scanf_s("%d",&data.t);

	printf("�����빺����:");
	scanf_s("%d",&data.iAmount);

	if (1 ==nDir )
	{
		AddTail(data);
	}
	else
	{
		AddTail(data);
	}
	Save();

	PrintAll();
}

void CList::ReMoveAll()
{
	SNode* p = m_pHead;


	if (!p)
	{
		return ;
	}

	SNode* p1 = NULL;
	while(p)
	{
		p1 = p;
		p = p->pNext;
		delete p1;
	}

	m_pHead = NULL;
}

void CList::Load()
{
	//Unicode�ķ���
	TCHAR text[MAX_PATH];
	//����һ:
	GetModuleFileName(NULL, text, MAX_PATH);//�õ�����·�� ����:C:\\TestDemo\\Debug\\Service.exe
	PathRemoveFileSpec(text);//C:\\TestDemo\\Debug

	CString path(text);

	CString filePath = path +_T("\\study.dat");

	//FILE* fp = fopen(UnicodeToUTF8(filePath.GetBuffer()).c_str(),"r");
	FILE* fp = fopen("study.dat","r");

	if (!fp)
	{
		return;
	}
	DATA data;

	while(fread(&data,1,sizeof(data),fp)==sizeof(data))
		AddTail(data);	

	fclose(fp);
}

void CList::Save()
{
	//Unicode�ķ���
	TCHAR text[MAX_PATH];
	//����һ:
	GetModuleFileName(NULL, text, MAX_PATH);//�õ�����·�� ����:C:\\TestDemo\\Debug\\Service.exe
	PathRemoveFileSpec(text);//C:\\TestDemo\\Debug

	CString path(text);

	CString filePath = path +_T("\\study.dat");

	//FILE* fp = fopen(UnicodeToUTF8(filePath.GetBuffer()).c_str(),"w");
	FILE* fp = fopen("study.dat","w");
	if (!fp)
	{
		return;
	}
	SNode* p = m_pHead;
	while(p)
	{
		//fwrite(&p->data,1,sizeof(p->data),fp);
		fwrite(p,1,sizeof(p->data),fp );
		p = p->pNext;
	}

	fclose(fp);
}

//Unicode ---> UTF-8
std::string CList::UnicodeToUTF8( const wstring& wstr )
{
	int  Length = ::WideCharToMultiByte( CP_UTF8,0,wstr.c_str(),-1,NULL, 0 ,NULL ,NULL );

	if(Length == 0) return std::string("");

	char* unicodeLen = new char[Length+1];

	memset( unicodeLen, 0, sizeof( char ) * ( Length + 1 ) );

	::WideCharToMultiByte( CP_UTF8,0,wstr.c_str(),-1,unicodeLen,Length, NULL ,NULL );

	unicodeLen[Length] = 0;

	string str = unicodeLen;

	delete[] unicodeLen;

	unicodeLen = NULL;

	return str;
}

