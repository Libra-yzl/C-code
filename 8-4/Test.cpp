#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

using namespace std;

int main()
{
	jwf::string s1;
	const jwf::string s2("hello world");
	jwf::string s3(s2);
	
	s1 = s2;
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;
	for (int i = 0; i < s1.size(); i++)
	{
		//s1++;
		cout << ++s1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < s2.size(); i++)
	{
		//s1++;
		cout << ++s3[i] << " ";
	}
	cout << endl;
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 > s3) << endl;
	cout << (s2 < s3) << endl;

	cout << s1.push_back('x') << endl;
	cout << s1.append("hello world") << endl;

	cout << (s3 += " hello world") << endl;
	cout << (s3 += 'x') << endl;

	for (int i = 0; i < s3.size(); i++)
	{
		cout << s3[i] << " ";
	}
	cout << endl;

	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;

	jwf::string s4;
	s4 = "hello world";
	s4.resize(10, 0);
	cout << s4 << endl;
	
	return 0;
}