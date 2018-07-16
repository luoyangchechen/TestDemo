#include <stdio.h>
#include <tchar.h>
#include <string.h>//strlen
#include <locale.h>//1.���_tprintf����ʾ������
#include <stdlib.h>

int main()
{
	_tsetlocale(LC_ALL,_T("chs"));//2.���_tprintf����ʾ������

	char* str1 = "hello world1";//���ֽ�
	wchar_t* str2 = L"hello world2";//���ֽ�
	TCHAR* str3 = _T("hello world3");//�����ǰ��Ŀ��������ΪUnicode�������ǿ��ֽڣ������ǰ��ĿΪ���ֽڣ������Ƕ��ֽ�

	printf("��ӡstr1:%s\n",str1);
	printf("��ӡstr2:%ws\n",str2);
	_tprintf(_T("��ӡstr3:%s\n"),str3);

	size_t len1 = strlen(str1);
	size_t len2 = wcslen(str2);
	size_t len3 = _tcslen(str3);

	printf("len1:%d,len2:%d,len3:%d\n",len1,len2,len3);

	char buf1[128]={0};
	wchar_t buf2[128]={0};
	TCHAR buf3[128]={0};

	//strcpy(buf1,str1);//��4996����,�������,���������
	//strcpy_s(buf1,128,str1);

	/*���buf1�ĳ��ȴ���len1.˵������ֻ�追��len1�ĳ��ȣ����buf1С��
	len1,����ֻ�ܿ���buf1���ȼ�ȥ1���ֽڣ���ΪĩβҪ��'\0*/
	int min_len1 = sizeof(buf1)/sizeof(char) > len1?len1:sizeof(buf1)/sizeof(char)-1; 
	
	/*����˵��';
	char * _Dst:Ŀ��buffer
    _DstSize��buffer����
     char * _Src:Դbuffer
   _MaxCount:ָ����������
   */
	strncpy_s(buf1,128,str1,min_len1);
	printf("��ӡbuf1:%s\n",buf1);


	//wcscpy(buf2,str2);//��4996����
	//wcscpy_s(buf2,128,str2);
	//wcsncpy(buf2,str2,128);//��4996����
	int min_len2 = sizeof(buf2)/sizeof(wchar_t) > len2?len2:sizeof(buf2)/sizeof(wchar_t)-1;
	wcsncpy_s(buf2,128,str2,min_len2);
	printf("��ӡbuf2:%ws\n",buf2);

	//_tcscpy(buf3,str3);//��4996����,�������,���������
	//_tcscpy_s(buf3,128,str3);
	int min_len3 = sizeof(buf3)/sizeof(TCHAR) > len3?len3:sizeof(buf3)/sizeof(TCHAR)-1;
	_tcsncpy_s(buf3,128,str3,min_len3);
	_tprintf(_T("��ӡbuf3:%s\n"),buf3);


	/*
	strcmp  �Ƚ������ַ����Ƿ���� 
	strncmp �Ƚ������ַ���ǰn���ַ��Ƿ����
	stricmp �Ƚ������ַ����Ƿ���ȣ����Դ�Сд��i��ignore
	*/

	char path[260]="D:\\project\\";

	char* filename="mallocfree.txt";
	//strcat(path,filename);��4996����,�������,���������
	strcat_s(path,260,filename);

	printf("%s\n",path);

	char* p = strchr(path,'.');//����߿�ʼ�� '.'��λ��

	if (p != NULL)
	{
		printf("�ҵ���չ��:%s\n",p);
	}
	else
	{
		printf("û���ҵ���չ��\n");
	}

	char* q = strrchr(path,'\\');
	
	if (q != NULL)
	{
		printf("�ҵ��ļ���:%s\n",q+1);
	}
	else
	{
		printf("û���ҵ��ļ���\n");
	}

	char* s1="hello world!";
	char* sp = strstr(s1,"orl");//���ַ��������Ӵ�
	if (sp!= NULL)
	{
		printf("%s\n",sp);
	}
	else
	{
		printf("û�ҵ�\n");
	}

	//strtok  ����ַ���

	char ip[]="192.168.100.1";
	const char* delim=".";
	char* next = NULL;
	//char* p2 = strtok(ip,delim);//��4996����,�������,���������
	char* p2 = strtok_s(ip,delim,&next);
	while (p2!= NULL)
	{
		printf("%s\n",p2);
		p2=strtok_s(NULL,delim,&next);//�ڶ���ʱ��һ��������NULL����Ϊstrtok�ڲ���һ����̬������������ʣ����ַ����׵�ַ
	}


	char *value = "3.1415";
	double d = atof(value);
	printf("%lf\n",d);

	char * vi = "123";
	int i = atoi(vi);
	printf("%d\n",i);

	TCHAR* v2 = _T("678");
	int i2 = _ttol(v2);
	printf("%d\n",i2);
	return 0;
}