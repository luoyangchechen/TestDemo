#include <map>
#include <iostream>
#include <string>
using namespace std;

//delete map element
//方法一:
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

//方法二:

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
//	if(iter!=m.end())//找到了
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
	//	//printf("%d , %d\n",rand()%100+1,i+1);//随机数对100取余 即可生产 0~100 的随机数 ；如果是1~100的随机数，即对运算结果+1操作

	//	//printf("0~100之间的随机数%d\n", i%100);

	//	//printf("%d\n",rand()%2);
	//	int key = rand()%100+1;//1~100的随机数
	//	int value = rand()%2;//0或1随机数
	//	printf("第%d次插入前：key=%d, value=%d\n",i+1,key,value);
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

	printf("随机的四位数%d\n",rand()%9000+1000);//随机生成4位数
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
