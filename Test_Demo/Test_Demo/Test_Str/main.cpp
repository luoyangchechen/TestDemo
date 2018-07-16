#include<iostream>
using namespace std;
/*
 ����˵��:�ַ����еĴ�д�ַ�ת����Сд��������ĸ�Ĺ��˵�
 ����ֵ:0 �ɹ�;-1 ʧ��
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
		{//��д��ĸ
			*strOutput++=*strInput+32;//strOutput++����һ���ַ�֮��ָ��������һ��λ��
		}

		if (*strInput>='a'&& *strInput<='z')
		{//Сд��ĸ
			*strOutput++=*strInput;//strOutput++����һ���ַ�֮��ָ��������һ��λ��
		}
		strInput++;//ѭ������������ַ�
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


/*�ַ�����д��ĸתСд��ĸ��Сд��ĸת��д
����ֵ:0 �ɹ�; -1ʧ��
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
  �ַ���ƴ��
  ����ֵ:0 �ɹ�; -1 ʧ��
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
  �ַ�����������
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
* ͳ��һ���ַ����ж�γ����ַ��ĸ���
* ����:abddccda   a 2��  b 1��  c 2��  d 3��
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

			cout << *strInput << "����" << cnt <<endl;
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

/*ͳ��ָ���ַ����ֵĸ��� �����ִ�Сд
*param[ in ] strInput  �����ַ���
*param[ in ] chsz      �����ַ�
*return �����ַ����� �ɹ�; -1 ʧ��
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

	printf("�ַ�%c�ĸ���:%d\n",c,num);
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