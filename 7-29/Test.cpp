#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

//int main()
//{
//	char str[] = "±»Ãÿ";
//	cout << sizeof(str) << endl;
//	return 0;
//}

template <class T>
void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template <class T>
T Add(T a, T b)
{
	return a + b;
}

void Test1()
{
	cout << Add<float>(10, 20.8) << endl;
}

int main()
{
	string s1("str");
	char str[] = "bit";
	string s2(str);
	cout << s1 << endl;
	cout << s2 << endl;
	string s3("hello world");
	for (int i = 0; i < s3.size(); ++i)
	{
		++s3[i];
	}
	for (int i = 0; i < s3.size(); ++i)
	{
		cout << s3[i] << " ";
	}
	cout << endl;
	Test1();
	return 0;
}