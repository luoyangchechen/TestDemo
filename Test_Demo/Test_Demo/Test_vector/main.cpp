#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	vector<string> vetvalues;
	vetvalues.push_back("4");
	vetvalues.push_back("5");
	vetvalues.push_back("6");
	vetvalues.push_back("7");
	vetvalues.push_back("8");

	vector<string> vetLines;

	vetLines.resize(10);
	//vectorµÄÓÃ·¨
	for (int j = 0;  j< 5;++j)
	{
		for (int i= 0; i < 10; ++i)
		{
			vetLines[i]+=vetvalues[j];
			vetLines[i]+=",";
		}
	}

	

	for (auto iter = vetLines.begin(); iter != vetLines.end();++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}