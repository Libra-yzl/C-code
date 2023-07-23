#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

void TestDate1()
{
	Date d1;
	d1.Print();
	Date d2(2023, 7, 1);
	d2.Print();
	cout << (d1 > d2) << endl;
	cout << "=================" << endl;
	d1.Print();
	d1--;
	d1.Print();
	d2.Print();
	d2--;
	d2.Print();
}

void TestDate2()
{
	Date d1(2023, 7, 23);
	Date d2(1966, 8, 23);
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;
}

void TestDate3()
{
	Date d1;
	d1.Print();
	Date d2(d1);
	//调用赋值重载
	d2 = d1 - 2000;
	d1 -= 2000;
	d1.Print();
	d2.Print();
}

void TestDate4()
{
	Date d1;
	d1++;
	d1.Print();
}

void TestDate5()
{
	Date d1;
	//d1.Print();
	Date d2(2002, 9, 28);
	//d2.Print();
	cout << d1 << " " <<  d2 << endl;
	cout << typeid(d1).name() << endl;
	//int i = 1;
	//double k = 2;
	//cout << i << k << endl;
	Date d3;
	cin >> d3;
	cout << d3;
}

int main()
{
	//TestDate1();
	TestDate2();
	//TestDate3();
	//TestDate4();
	//TestDate5();
	return 0;
}