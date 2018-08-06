#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
using namespace std;

struct SUser
{
	int nNum;
	char sName[20];
	float fMath;
};

typedef SUser DATA;

struct SNode
{
	DATA data;//28个字节
	SNode* pNext;//指针变量，4个字节
};

SNode* g_Head = NULL;

void AddHeand(DATA data)
{
	SNode* pNew = (SNode*)malloc(sizeof(SNode));
	pNew->data = data;
	pNew->pNext = g_Head;

	g_Head = pNew;
}

void AddTail(DATA data)
{
	SNode* pNew =(SNode*)malloc(sizeof(SNode));
	pNew->data =data;
	pNew->pNext = NULL;
	if (!g_Head)//链表为空时
	{
		g_Head = pNew;
		return;
	}

	SNode* p = g_Head;
	while(p->pNext!=NULL)
	{
		p = p->pNext;
	}
	p->pNext = pNew;
}


void Save()
{
	FILE* fp = fopen("study.dat","w");
	if (!fp)
	{
		return;
	}
	SNode* p = g_Head;
	while(p)
	{
		//fwrite(&p->data,1,sizeof(p->data),fp);
		fwrite(p,1,sizeof(p->data),fp );
		p = p->pNext;
	}

	fclose(fp);
}

void Load()
{

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

void PrintAll()
{
	SNode* p = g_Head;
	int i  =0;
	/*if (!p)
	{
		printf("当前链表为空！\n");
		return;
	}*/
	puts("学号\t姓名\t数学");
	while (p)
	{
		printf("%d\t%s\t%0.1f\n",p->data.nNum,p->data.sName,p->data.fMath);
		++i;
		p=p->pNext;
	}
	printf("总共%d条记录\n",i);
	system("pause");
}

void Input(int nDir)
{
	DATA data;
	printf("请输入学号:");
	scanf_s("%d",&data.nNum);

	printf("请输入姓名:");
	scanf_s("%s",data.sName,sizeof(data.sName));

	printf("请输入数学成绩:");
	scanf_s("%f",&data.fMath);
	if (nDir == 1)
	{
		AddHeand(data);
	}
	else
	{
		AddTail(data);
	}
	Save();
	PrintAll();
	
}

int AddMenu()
{
	system("cls");
	puts("\n\n\t\t1、向头部插入:");
	puts("\t\t2、向尾部插入:");
	puts("\t\t0、回到主菜单:");

	int i = 0;

	scanf_s("%d",&i);

	switch(i)
	{
	case 1:
	case 2:
		Input(i);
		break;
	}
	return i;
}

int Judge(SNode* q,SNode* m,int index)
{
	switch(index)
	{
	case 1://姓名
		return strcmp(q->data.sName,m->data.sName)<0;
	case 2://学号
		return q->data.nNum < m->data.nNum;
	case 3://成绩
		return q->data.fMath < m->data.fMath;
	}

	return 0;
}

void Sort(int index)
{
	SNode* p = g_Head;
	if (!p)
	{
		return;
	}

	while (p->pNext)
	{
		SNode* q = p->pNext;
		SNode* m = p;
		while(q)
		{
			if (Judge(q,m,index))
			{
				m = q;
			}
			q = q->pNext;
		}

		if (m != p)//不等时交换
		{
			DATA t = p->data;

			p->data=m->data;
			m->data = t;
		}
		p = p->pNext;
	}

	system("pause");
}

void SortByNum()
{
	SNode* p = g_Head;
	if (!p)
	{
		return;
	}

	while (p->pNext)
	{
		SNode* q = p->pNext;
		SNode* m = p;
		while(q)
		{
			if (q->data.nNum < m->data.nNum)
			{
				m = q;
			}
			q = q->pNext;
		}

		if (m != p)//不等时交换
		{
			DATA t = p->data;

			p->data=m->data;
			m->data = t;
		}
		p = p->pNext;
	}

	system("pause");
}

void SortByName()
{
	SNode* p = g_Head;
	if (!p)
	{
		return;
	}

	while (p->pNext)
	{
		SNode* q = p->pNext;
		SNode* m = p;
		while(q)
		{
			if (strcmp(q->data.sName, m->data.sName)<0)
			{
				m = q;
			}
			q = q->pNext;
		}

		if (m != p)//不等时交换
		{
			DATA t = p->data;

			p->data=m->data;
			m->data = t;
		}
		p = p->pNext;
	}

	system("pause");
}

void SortByMath()
{
	SNode* p = g_Head;
	if (!p)
	{
		return;
	}

	while (p->pNext)
	{
		SNode* q = p->pNext;
		SNode* m = p;
		while(q)
		{
			if (q->data.fMath > m->data.fMath)
			{
				m = q;
			}
			q = q->pNext;
		}

		if (m != p)//不等时交换
		{
			DATA t = p->data;

			p->data=m->data;
			m->data = t;
		}
		p = p->pNext;
	}

	system("pause");
}

int SortMenu()
{
	system("cls");
	puts("\n\n\t\t1、按姓名排序:");
	puts("\t\t2、按学号排序:");
	puts("\t\t3、按成绩排序:");
	puts("\t\t0、退出排序:");

	int i = 0;

	scanf_s("%d",&i);

	switch(i)
	{
		case 1:
			break;
			SortByName();
		case 2:
			SortByNum();
			break;
		case 3:
			SortByMath();
			break;
		default:
			return i;
	}
	PrintAll();

	return i;
}

int DeleteByName()
{
	PrintAll();

	char name[20];
	printf("请输入姓名:");

	scanf("%s",name);

	SNode* p = g_Head;
	SNode* p1 = NULL;//记录前一个节点
	if (!p)
	{
		return 0;
	}

	//如果是头节点要特殊处理
	if(strcmp(p->data.sName,name)== 0)
	{
		g_Head = p->pNext;
		delete p;
		return 1;
	}
	while(p)
	{
		if (strcmp(p->data.sName,name)== 0)
		{
			p1->pNext=p->pNext;
			free(p);
			return 1;
		}
		p1=p;
		p=p->pNext;
	}

	return 0;
}

int DeleteByNum()
{
	PrintAll();
	int iNum =0;
	printf("请输入学号:");

	scanf_s("%d",&iNum);

	SNode* p = g_Head;
	SNode* p1 = NULL;//记录前一个节点
	if (!p)
	{
		return 0;
	}

	//如果是头节点要特殊处理
	if(p->data.nNum== iNum)
	{
		g_Head = p->pNext;
		delete p;
		return 1;
	}
	while(p)
	{
		if (p->data.nNum== iNum)
		{
			p1->pNext=p->pNext;
			free(p);
			return 1;
		}
		p1=p;
		p=p->pNext;
	}
	return 0;
}

int DeleteMenu()
{
	system("cls");
	puts("\n\n\t\t1、按姓名删除:");
	puts("\t\t2、按学号删除:");
	puts("\t\t0、退出回主菜单:");

	int i = 0,j=0;

	scanf_s("%d",&i);

	switch(i)
	{
	case 1:
		j = DeleteByName();
		if(j>0)
		{
			printf("删除成功!");
		}
		else
		{
			printf("删除失败!");
		}
		break;
	case 2:
		j = DeleteByNum();
		if(j>0)
		{
			printf("删除成功!");
		}
		else
		{
			printf("删除失败!");
		}
		break;
	default:
		return i;
	}
	PrintAll();

	return i;
}

int FindByName()
{
	char name[20];
	printf("请输入姓名:");

	scanf("%s",name);

	SNode* p = g_Head;
	while (p)
	{
		if (strcmp(p->data.sName,name)==0)
		{
			puts("学号\t姓名\t数学");
			
			printf("%d\t%s\t%0.1f\n",p->data.nNum,p->data.sName,p->data.fMath);
			return 1;
		}

		p=p->pNext;
	}
	return 0;
}

int FindByNum()
{
	int iNum =0;
	printf("请输入学号:");

	scanf_s("%d",&iNum);

	SNode* p = g_Head;
	while (p)
	{
		if (p->data.nNum == iNum)
		{
			puts("学号\t姓名\t数学");

			printf("%d\t%s\t%0.1f\n",p->data.nNum,p->data.sName,p->data.fMath);
			return 1;
		}

		p=p->pNext;
	}
	return 0;
}

int FindMenu()
{
	system("cls");
	puts("\n\n\t\t1、按姓名查找:");
	puts("\t\t2、按学号查找:");
	puts("\t\t0、退出回主菜单:");

	int i = 0;

	scanf_s("%d",&i);

	switch(i)
	{
	case 1:
		FindByName();
		break;
	case 2:
		FindByNum();
		break;
	default:
		return i;
	}
	system("pause");
	return i;
}
int ModifyByName()
{
	char name[20];
	float fmath =0.0;
	printf("请输入姓名:");
	scanf("%s",name);
	printf("请输入新成绩:");
	scanf("%f",&fmath);

	SNode* p = g_Head;
	while (p)
	{
		if (strcmp(p->data.sName,name)==0)
		{
			printf("修改前:%d\t%s\t%0.1f\n",p->data.nNum,p->data.sName,p->data.fMath);
			p->data.fMath=fmath;

			puts("学号\t姓名\t数学");

			printf("修改后:%d\t%s\t%0.1f\n",p->data.nNum,p->data.sName,p->data.fMath);
			return 1;
		}

		p=p->pNext;
	}
	return 0;
}

int ModifyByNum()
{
	float fmath =0.0;
	int iNum =0;
	printf("请输入学号:");
	scanf_s("%d",&iNum);
	printf("请输入新成绩:");
	scanf("%f",&fmath);

	SNode* p = g_Head;
	while (p)
	{
		if (p->data.nNum == iNum)
		{
			printf("修改前:%d\t%s\t%0.1f\n",p->data.nNum,p->data.sName,p->data.fMath);
			p->data.fMath=fmath;
			puts("学号\t姓名\t数学");

			printf("修改后:%d\t%s\t%0.1f\n",p->data.nNum,p->data.sName,p->data.fMath);
			return 1;
		}

		p=p->pNext;
	}
	return 0;
}

//只能修改成绩
int ModifyMenu()
{
	system("cls");
	puts("\n\n\t\t1、按姓名修改:");
	puts("\t\t2、按学号修改:");
	puts("\t\t0、退出回主菜单:");

	int i = 0;

	scanf_s("%d",&i);

	switch(i)
	{
	case 1:
		ModifyByName();
		break;
	case 2:
		ModifyByNum();
		break;
	default:
		return i;
	}
	system("pause");
	return i;
}

int Menu()
{
	system("cls");//clear screen
	puts("\n\t\t1、浏览所有信息");
	puts("\t\t2、添加信息");
	puts("\t\t3、删除信息");
	puts("\t\t4、修改信息");
	puts("\t\t5、查找信息");
	puts("\t\t6、颜色设置");
	puts("\t\t0、退出");
	printf("\t\t请选择：");
	int i = 0;
	scanf_s("%d",&i);
	switch(i)
	{
	case 1:
		//PrintAll();
		while(SortMenu());
		break;
	case 2:
		while(AddMenu())
			;
		break;
	case 3:
		while(DeleteMenu())
			;
		break;
	case 4:
		while(ModifyMenu())
			;
		break;
	case 5:
		while(FindMenu())
			;
		break;
	case 6:
		break;

	}

	return i;
}
int main()
{
	system("color 1f");

	printf("\n\n");
	printf("    \t *******************************************************************\n");
	printf("    \t ******                                                       ******\n");
	printf("    \t ******                员工工管理信息系统                      ******\n");
	printf("    \t ******                                                       ******\n");
	printf("    \t ******                 2018-8-5                              ******\n");
	printf("    \t ******             http://www.cnblogs.com/chechen/           ******\n");
	printf("    \t ******                 按任意键继续                           ******\n");

	char c = _getch();

	Load();
	while(Menu())
		;
	return 0;
}