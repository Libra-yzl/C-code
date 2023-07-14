#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main()
//{
//	int a = 0;
//	double b = 5.80;
//	cout << a << " " << b << endl;
//	return 0;
//
//}

//int Count()
//{
//	//static int n = 0;
//	int n = 0;
//	n++;
//	
//	return n;
//}
//
//int main()
//{
//	int ret = Count();
//
//	cout << "n=" << ret << endl;
//	return 0;
//}

#define ADD(x,y) ((x)+(y))

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = ADD(a,b);
//	cout << "c=" << c << endl;
//	return 0;
//}

inline int Add(int x, int y)
{
	int z = x + y;
	z = x + y;
	z += x + y;
	z -= x + y;
	z *= x + y;
	z /= x + y;
	z = x + y;
	z = x + y;
	z += x + y;
	z += x + y;
	z -= x + y;
	return z;
}

//int main()
//{
//	int a = 10, b = 10;
//	int c = Add(a,b);
//	cout << "c=" << c << endl;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	auto b = a;
//	auto c = &a;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto& x : a)
//	{
//		x *= 2;
//		cout << x << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	f(nullptr);
//	return 0;
//}

class Date
{
public:
	void Init(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "Äê" << _month << "ÔÂ" << _day << "ÈÕ" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Init();
	//d1.Init(2023, 7, 14);
	d1.Print();
	return 0;
}