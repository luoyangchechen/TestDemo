#include <iostream>
#include <fstream>//ofstream
#include <sstream>//stringstream
#include <atlstr.h>
using namespace std;

//Unicode ---> UTF-8
std::string UnicodeToUTF8( const wstring& wstr )
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

//UTF-8 ---> Unicode
std::wstring UTF8ToUnicode(const string& str)
{
	int Length = ::MultiByteToWideChar( CP_UTF8,0,str.c_str(),-1,NULL,0 ); 

	if(Length == 0) return NULL;

	wchar_t *  pUnicode = new  wchar_t[Length+1]; 

	memset(pUnicode,0,(Length+1) * sizeof(wchar_t)); 

	::MultiByteToWideChar( CP_UTF8,0,str.c_str(),-1,(LPWSTR)pUnicode,Length);

	pUnicode[Length] = 0;

	wstring  wstr= ( wchar_t* )pUnicode;

	delete[]  pUnicode;
	pUnicode = NULL;

	return  wstr;
}


int main()
{
	//Unicode的方法
	TCHAR text[MAX_PATH];
	//方法一:
	GetModuleFileName(NULL, text, MAX_PATH);//得到工作路径 例如:C:\\TestDemo\\Debug\\Service.exe
	PathRemoveFileSpec(text);//C:\\TestDemo\\Debug

	CString path(text);

	CString filePath = path +_T("\\text.txt");

	ofstream of;
	of.open(UnicodeToUTF8(filePath.GetBuffer()).c_str());
	if(of.is_open())
	{
		cout << "打开成功！" << endl;
	}


	stringstream ss;

	ss << "你好" << endl;

	of << ss.str() << endl;

	of.close();
	return 0;
}