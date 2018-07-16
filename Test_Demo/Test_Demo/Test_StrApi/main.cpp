#include <stdio.h>
#include <tchar.h>
#include <string.h>//strlen
#include <locale.h>//1.解决_tprintf不显示的问题
#include <stdlib.h>

int main()
{
	_tsetlocale(LC_ALL,_T("chs"));//2.解决_tprintf不显示的问题

	char* str1 = "hello world1";//多字节
	wchar_t* str2 = L"hello world2";//宽字节
	TCHAR* str3 = _T("hello world3");//如果当前项目工程属性为Unicode，它就是宽字节；如果当前项目为多字节，它就是多字节

	printf("打印str1:%s\n",str1);
	printf("打印str2:%ws\n",str2);
	_tprintf(_T("打印str3:%s\n"),str3);

	size_t len1 = strlen(str1);
	size_t len2 = wcslen(str2);
	size_t len3 = _tcslen(str3);

	printf("len1:%d,len2:%d,len3:%d\n",len1,len2,len3);

	char buf1[128]={0};
	wchar_t buf2[128]={0};
	TCHAR buf3[128]={0};

	//strcpy(buf1,str1);//报4996警告,溢出风险,缓冲区溢出
	//strcpy_s(buf1,128,str1);

	/*如果buf1的长度大于len1.说明我们只需拷贝len1的长度，如果buf1小于
	len1,我们只能拷贝buf1长度减去1个字节，因为末尾要放'\0*/
	int min_len1 = sizeof(buf1)/sizeof(char) > len1?len1:sizeof(buf1)/sizeof(char)-1; 
	
	/*函数说名';
	char * _Dst:目标buffer
    _DstSize：buffer长度
     char * _Src:源buffer
   _MaxCount:指定拷贝长度
   */
	strncpy_s(buf1,128,str1,min_len1);
	printf("打印buf1:%s\n",buf1);


	//wcscpy(buf2,str2);//报4996警告
	//wcscpy_s(buf2,128,str2);
	//wcsncpy(buf2,str2,128);//报4996警告
	int min_len2 = sizeof(buf2)/sizeof(wchar_t) > len2?len2:sizeof(buf2)/sizeof(wchar_t)-1;
	wcsncpy_s(buf2,128,str2,min_len2);
	printf("打印buf2:%ws\n",buf2);

	//_tcscpy(buf3,str3);//报4996警告,溢出风险,缓冲区溢出
	//_tcscpy_s(buf3,128,str3);
	int min_len3 = sizeof(buf3)/sizeof(TCHAR) > len3?len3:sizeof(buf3)/sizeof(TCHAR)-1;
	_tcsncpy_s(buf3,128,str3,min_len3);
	_tprintf(_T("打印buf3:%s\n"),buf3);


	/*
	strcmp  比较两个字符串是否相等 
	strncmp 比较两个字符串前n个字符是否相等
	stricmp 比较两个字符串是否相等，忽略大小写，i是ignore
	*/

	char path[260]="D:\\project\\";

	char* filename="mallocfree.txt";
	//strcat(path,filename);报4996警告,溢出风险,缓冲区溢出
	strcat_s(path,260,filename);

	printf("%s\n",path);

	char* p = strchr(path,'.');//从左边开始找 '.'的位置

	if (p != NULL)
	{
		printf("找到扩展名:%s\n",p);
	}
	else
	{
		printf("没有找到扩展名\n");
	}

	char* q = strrchr(path,'\\');
	
	if (q != NULL)
	{
		printf("找到文件名:%s\n",q+1);
	}
	else
	{
		printf("没有找到文件名\n");
	}

	char* s1="hello world!";
	char* sp = strstr(s1,"orl");//从字符串中找子串
	if (sp!= NULL)
	{
		printf("%s\n",sp);
	}
	else
	{
		printf("没找到\n");
	}

	//strtok  拆分字符串

	char ip[]="192.168.100.1";
	const char* delim=".";
	char* next = NULL;
	//char* p2 = strtok(ip,delim);//报4996警告,溢出风险,缓冲区溢出
	char* p2 = strtok_s(ip,delim,&next);
	while (p2!= NULL)
	{
		printf("%s\n",p2);
		p2=strtok_s(NULL,delim,&next);//第二次时第一个参数传NULL，因为strtok内部有一个静态变量来保存拆分剩余的字符串首地址
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