
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int main()
//{
//	int i = 1;
//	const double& d = i;
//	return 0;
//}

class A
{
public:
	A()
		:_a(0)
	{
		cout << "A()" << endl;
	}

	A(const A& a)
		:_a(a._a)
	{
		cout << "A(const A& a)" << endl;
	}

	A& operator=(const A& a)
	{
		_a = a._a;
		cout << "A& operator=(const A& a)" << endl;
		return *this;
	}

private:
	int _a;
};

//int main()
//{
//	A a1;
//	A a2 = a1; // 这里发生了1次拷贝构造
//	A a3;
//	a3 = a2;
//	A a4 = A();
//	return 0;
//}
//#include <string.h>
//#include <errors.h>
int main()
{
	/*char str[] = "hello";
	char* ps = str;
	printf("%s\n", ps);*/
	for (int i = 0; i < 200; ++i) printf("%d:%s\n", i, strerror(i));
	return 0;
}