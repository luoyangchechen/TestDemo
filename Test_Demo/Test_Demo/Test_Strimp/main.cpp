/**************************************************************
*
* File Name      :
*
* Created        : 2018-6-5 20:6:08
*
* Author         :
*
* Model          : �Զ���ʵ��C���Ժ���
*
* Description    : [CN]      [CN]
*
**************************************************************/

#include "stdafx.h"
#include <string.h>
#include <assert.h>

#define IF_RETURN(in) {if (!in){return 0;}}

size_t mystrlen(const char* str)
{
	IF_RETURN(str);
	size_t count= 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}

	return count;
}

size_t mystrlen2(const char* str)
{
	IF_RETURN(str);
	const char*  eos = str;
	while(*eos++);//������ĺ�����*eos��Ϊ'\0'��Ȼ��eosָ������ƶ�һλ��ֱ������'\0'

	return (size_t)(eos- str -1);
}

size_t mystrlen3(const char* str)
{
	IF_RETURN(str);
	if (str == NULL || *str == '\0')
	{
		return 0;
	}

	return 1+mystrlen3(str+1);
}

size_t mystrlen4(const char* str)
{
	IF_RETURN(str);
	return (str == NULL || *str == '\0') ? 0 :1+mystrlen4(str+1);//��Ŀ�������a>b ?a:b
}

char* mystrcpy(char* dest,const char* src)
{
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}

	char* s = dest;//����Ŀ���׵�ַ

	while(*s++ = *src);

	return dest;
}


int mystrcmp(const char* s1,const char* s2)
{
	assert(s1 !=NULL &&  s2!=NULL);//���� Debug��Ч ����һ��Ϊ�վ͵�����ʾ
	//if (s1 == NULL || s2 == NULL)
	//{
	//	return 0;
	//}
		
	while (*s1&&*s2&&(*s1==*s2))
	{//s1��Ϊ'\0' s2��Ϊ'\0' ���� s1��s2���
		s1++;
		s2++;
	}

	return (*s1-*s2);
}


int _tmain(int argc, _TCHAR* argv[])
{
	char * p = "hello world!";

	printf("strlen:%u\nmystrlen:%u\nmystrlen2:%u\nmystrlen3:%u\nmystrlen4:%u\n",strlen(p),mystrlen(p),mystrlen2(p),mystrlen3(p),mystrlen4(p));

	char* s = "hello world";
	char text[128]= {0};
	char text1[128]= {0};


	printf("strcpy:%s\n mystrcpy:%s\n",strcpy_s(text,128,s),mystrcpy(text1,s));

	char* s1 = "hello world";
	char* s2 = "hello world";
	//char* s2 = NULL;

	if (mystrcmp(s1,s2) == 0)
	{
		printf("%s==%s\n",s1,s2);
	}
	else
	{
		printf("%s!=%s\n",s1,s2);
	}
	return 0;
}

