#include<iostream>
using namespace std;
/*
 功能说明:字符串中的大写字符转换成小写，不是字母的过滤掉
 返回值:0 成功;-1 失败
*/

int StringProcess(char* strInput,char * strOutput)
{
	if (strInput == NULL || strOutput == NULL)
	{
		return -1;
	}

	while(*strInput!='\0')
	{
		if(*strInput>='A'&& *strInput<='Z')
		{//大写字母
			*strOutput++=*strInput+32;//strOutput++保存一个字符之后指针往后移一个位置
		}

		if (*strInput>='a'&& *strInput<='z')
		{//小写字母
			*strOutput++=*strInput;//strOutput++保存一个字符之后指针往后移一个位置
		}
		strInput++;//循环遍历输入的字符
	}
	*strOutput++='\0';
	return 0;
}

int ProcessString(char* strInput, char* strOutput)
{
	if (strInput == NULL || strOutput == NULL)
	{
		return -1;
	}

	int temp = 0;

	for (int i = 0; i < (int)strlen(strInput); i++)
	{
		if (strInput[i] >= 'A' && strInput[i] <= 'Z')
		{
			strOutput[temp++] = strInput[i]+32;
		}	

		if (strInput[i] >= 'a' && strInput[i] <= 'z')
		{
			strOutput[temp++] = strInput[i];
		}
	}

	strOutput[temp+1]= '\0';

	return 0;

}


/*字符串大写字母转小写字母，小写字母转大写
返回值:0 成功; -1失败
*/
int Upper2LowerProcess(char* strInput,char* strOutput)
{
	if (strInput == NULL || strOutput == NULL)
	{
		return -1;
	}

	while(*strInput != '\0')
	{
		if (*strInput >= 'A'&& *strInput <= 'Z')
		{
			*strOutput++= *strInput+32;
		}
		if (*strInput >= 'a'&& *strInput <= 'z')
		{
			*strOutput++= *strInput-32;
		}
		strInput++;
	}
	return 0;
}

/*
  字符串拼接
  返回值:0 成功; -1 失败
*/
int StringCatProcess(char* str1, char* str2, char* strOutput)
{
	if (str1 == strOutput || str2 == NULL || strOutput == NULL)
	{
		return -1;
	}

	while(*str1 != '\0')
	{
		*strOutput++=*str1;
		str1++;
	}

	while(*str2 != '\0')
	{
		*strOutput++=*str2;
		str2++;
	}

	*strOutput++='\0';
	return 0;
}

/*
  字符串遍历方法
*/
void StringWhile()
{
	char* str = "hello world";
	while (*str != '\0')
	{
		printf("%c",*str);
		str++;
	}
	printf("\n");
}

void StringFor()
{
	char* str = "hello world";
	for(;*str != '\0';str++)
	{
		printf("%c",*str);
	}
	printf("\n");
}

void Stringfor1()
{
	char* str = "hello world";
	for(size_t i=0; i< strlen(str);i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}

void TestStringprocess()
{
	char strin[]="ABCD!@#$%HHJ)*nml&OPUYT";
	char test[256]={0};
	//StringProcess(strin,test1);
	ProcessString(strin,test);
	printf("StringProcess:%s\n",test);
}

void TestUpper2Lower()
{
	char strin1[]="ABCDefdhIGkilmn";
	char test[256]={0};

	Upper2LowerProcess(strin1,test);

	printf("Upper2LowerProcess:%s\n",test);
}

void TestCatProcess()
{
	char str[7]="";
	char* str1="abc";
	char* str2="def";

	StringCatProcess(str1,str2,str);
	printf("StringCatProcess:%s\n",str);
}

/*
* 统计一个字符串中多次出现字符的个数
* 例如:abddccda   a 2次  b 1次  c 2次  d 3次
*/
int StringCountchar(char* strInput)
{
	if (strInput == NULL || *strInput== '\0')
	{
		return -1;
	}

	int cnt = 1;
	char cCurrent;
	cCurrent = *strInput;

	while (*strInput != '\0')
	{
		if (*strInput == cCurrent)
		{
			++cnt;

			cout << *strInput << "出现" << cnt <<endl;
		}
		else
		{
			cCurrent = *strInput;
			cnt = 1;
		}

		++strInput;
	}

	return 0;
}

/*统计指定字符出现的个数 不区分大小写
*param[ in ] strInput  输入字符串
*param[ in ] chsz      输入字符
*return 返回字符个数 成功; -1 失败
*/
int StringCount(char* strInput,char chsz)
{
	if (strInput == NULL)
	{
		return -1;
	}

	int count = 0;
	while (*strInput != '\0')
	{
		if (*strInput ==chsz+32 || *strInput == chsz -32 || *strInput==chsz)
		{
			count++;
		}
		strInput++;
	}
	return count;
}

void TestStringCountchar()
{
	char* str="aabadecfaddccghi";

	StringCountchar(str);
}

void TestCount()
{
	char str[]="aBCDFAFafjksfj";
	char c = 'a';

	int num = StringCount(str,c);

	printf("字符%c的个数:%d\n",c,num);
}

int main()
{
	//TestStringprocess();
	//TestUpper2Lower();
	//TestCatProcess();

	//StringWhile();
	//StringFor();
	//Stringfor1();

	//TestStringCountchar();

	TestCount();
	return 0;
}