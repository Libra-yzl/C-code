#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <assert.h>

//class A
//{
//public:
//	const int& operator[](int i)
//	{
//		assert(i < 10);
//		return _a[i];
//	}
//	/*const int& operator[](int i) const
//	{
//		assert(i < 10);
//		return _a[i];
//	}*/
//private:
//	int _a[10];
//	int _size;
//};
//
//int main()
//{
//	A a;
//	for (int i = 0; i < 10; ++i)
//	{
//		//a[i] = i;
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}
	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};

int main() {
	A aa(1);
	aa.Print();
}