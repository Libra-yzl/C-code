//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 2023, int month = 7, int day = 17)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	//这里的报错原因是参数过多
//	//bool operator==(const Date& d1, const Date& d2)
//	bool operator==(const Date& d)
//	{
//		return _year == d._year &&
//			_month == d._month &&
//			_day == d._day;
//	}
//
//	bool operator<(const Date& d)
//	{
//		/*if (_year < d._year)
//			return true;
//		else if (_year == d._year)
//		{
//			if (_month < d._month)
//				return true;
//			else if (_month == d._month)
//			{
//				if (_day < d._day)
//					return true;
//				else
//					return false;
//			}
//			else
//				return false;
//		}
//		else
//			return false;*/
//
//		//推荐这一种
//		if (_year < d._year)
//			return true;
//		else if (_year == d._year && _month < d._month)
//			return true;
//		else if (_year == d._year && _month == d._month && _day < d._day)
//			return true;
//		else
//			return false;
//
//		/*return _year < d._year ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == _month && _day < d._day);*/
//	}
//
//	/*Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}*/
//
////private:
//	int _year = 2023;
//	int _month = 7;
//	int _day = 17;
//};
//
////运算符重载
////bool operator==(const Date& d1, const Date& d2)
////{
////	return d1._year == d2._year &&
////		d1._month == d2._month &&
////		d1._day == d2._day;
////}
//
////int main()
////{
////	Date d1;
////	Date d2(d1);
////	d1.Print();
////	d2.Print();
////	cout << "======================" << endl;
////	d1 == d2;
////
////	cout << (d1 == d2) << endl; //这里相当于转换成d1.operator==(d2);
////	cout << d1.operator==(d2) << endl;
////
////	////这种是错误的 <<比==的优先级高
////	//cout << d1 == d2 << endl;
////
////	
////
////	return 0;
////}
//
//int main()
//{
//	//Date d3(2021, 1, 9);
//	//Date d4(2023, 2, 8);
//	//cout << (d3 < d4) << endl;
//	//
//	////实现 <= >= != 等等运算符重载可以进行复用
//
//	//赋值运算符重载
//	Date d1(2023,1,1);
//	Date d2(1, 1, 1);
//	Date d3(2, 2, 2);
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	d3 = d2 = d1;
//	cout << "========================" << endl;
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	return 0;
//}


#include "Date.h"

void TestDate1()
{
	Date d1(2023, 7, 17);
	d1.Print();
	d1 += 100;
	d1.Print();
}

void TestDate2()
{
	Date d1;
	Date d2;
	d1.Print();
	d2 = d1 + 100;
	d2.Print();
}

void TestDate3()
{
	Date d1;
	d1.Print();
	d1 -= 2000;
	d1.Print();
	Date d2;
	d2 = d1 - 2000;
	d2.Print();
}

void TestDate4()
{
	Date d1;
	d1.Print();
	++d1;
	d1.Print();
	d1++;
	d1.Print();
	d1--;
	d1.Print();
	--d1;
	d1.Print();
}

void TestDate5()
{
	Date d1(2002,9,28);
	Date d2(2023,7,17);
	cout << (d2 - d1) << endl;
}

void TestDate6()
{
	Date d;
	Date d1;
	Date d2;
	d1.Print();
	d1 += -100;
	d1.Print();
	d1 = d;
	d1 -= 100;
	d1.Print();
	d1 = d;
	d1 -= -100;
	d1.Print();
	d1 = d;
	d1 += 100;
	d1.Print();
	cout << "================" << endl;
	d2.Print();
	d2 -= -100;
	d2.Print();
	d2 = d;
	d2 += 100;
	d2.Print();
	d2 = d;
	d2 += -100;
	d2.Print();
	d2 = d;
	d2 -= 100;
	d2.Print();
}

int main()
{
	//TestDate1();
	//TestDate2();
	//TestDate3();
	//TestDate4();
	//TestDate5();
	TestDate6();
	return 0;
}