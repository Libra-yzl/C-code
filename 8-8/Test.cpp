#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

int main()
{
	try
	{
		yzl::string s1;
		yzl::string s2("hello world");
		for (int i = 0; i < s2.size(); i++)
		{
			s2[i]++;
		}

		s1 = s2;
		s2 = "hello world xx";
		s2 = s2;

		/*cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;*/
		//yzl::test1();
		//yzl::test2();
		//yzl::test3();
		//yzl::test4();
		//yzl::test5();

		//yzl::test_string1();
		//yzl::test_string2();
		//yzl::test_string3();
		//yzl::test_string4();
		yzl::test_string5();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	
	return 0;
}