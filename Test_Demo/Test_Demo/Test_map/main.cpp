#include <map>
#include <iostream>
#include <string>
using namespace std;

//delete map element
//����һ:
//int main()
//{
//	std::map<string,int>  m;
//	m["a"]=1;
//	m["b"]=2;
//	m["c"]=3;
//	map<string,int>::iterator it;
//	for(it=m.begin();it!=m.end();)
//	{
//		if(it != m.end())
//		{
//			cout << it->first << endl;
//			m.erase(it++);
//		}
//	}
//	return 0;
//}

//������:

//int main()
//{
//	std::map<string,int>  m;
//	m["a"]=1;
//	m["b"]=2;
//	m["c"]=3;
//	map<string,int>::iterator it;
//	for(it=m.begin();it!=m.end();)
//	{
//		map<string,int>::iterator it_back = it;
//		if(it_back != m.end())
//		{
//			cout << it->first << endl;
//			it++;
//			m.erase(it_back);
//		}
//	}
//	return 0;
//}


//find element delete

//int main()
//{
//	map<string,int>  m;
//	m["a"]=1;
//	m["b"]=2;
//	m["c"]=3;
//	map<string,int>::iterator iter;
//
//	iter = m.find("a");
//
//	if(iter!=m.end())//�ҵ���
//	{
//		cout << iter->first << endl;
//		m.erase(iter);
//	}
//	return   0;
//}

#include <time.h>

int main()
{
	//map<int,int> m;
	//srand((unsigned)time(NULL));

	//for (int i =0; i< 100; i++)
	//{
	//	//printf("%d , %d\n",rand()%100+1,i+1);//�������100ȡ�� �������� 0~100 ������� �������1~100�������������������+1����

	//	//printf("0~100֮��������%d\n", i%100);

	//	//printf("%d\n",rand()%2);
	//	int key = rand()%100+1;//1~100�������
	//	int value = rand()%2;//0��1�����
	//	printf("��%d�β���ǰ��key=%d, value=%d\n",i+1,key,value);
	//	m.insert(pair<int,int>(key,value));
	//}
	//printf("\n");


	//map<int,int>::iterator iter;

	//for (iter = m.begin(); iter != m.end(); iter++)
	//{
	//	printf("key:%d, value:%d\n",iter->first,iter->second);
	//}
	//printf("\n");

	srand((unsigned)time(NULL));

	printf("�������λ��%d\n",rand()%9000+1000);//�������4λ��
	map<char,int> mc;
	//char r;

	for (char c='z'; c >= 'a'; c--)
	{
		//printf("%c\n",c);
		int num = rand()%2;
		printf("%c,  %d\n",c,num);
		mc.insert(pair<char,int>(c,num));
	}

	printf("\n");


	map<char,int>::iterator iter;

	for (iter = mc.begin(); iter!=mc.end(); iter++)
	{
		printf("key= %c, value=%d\n",iter->first,iter->second);
	}

	printf("\n");
	return 0;
}
