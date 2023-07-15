#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	void Init(int year = 2023, int month = 7, int day = 15)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//	void func()
//	{
//		cout << "func()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	/*Date d1;
//	d1.Init(2024);
//	d1.Print();*/
//
//	Date* ptr = nullptr;
//	ptr->func();
//	(*ptr).func();
//
//	//ptr->Init(); //程序崩溃 这里的进行了解引用操作(this->_year = year ...)
//	return 0;
//}

void change(int*& b)
{
	*b = 20;
	cout << "b:" << &b << endl;
}

//int main()
//{
//	int a = 10;
//	cout << a << endl;
//	int* b = &a;
//	cout << "b:" << &b << endl;
//	change(b);
//	cout << a << endl;
//	return 0;
//}

class Date
{
public:
	//构造函数
	Date(int year = 2023, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	
	//拷贝构造函数
	/*Date(Date d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}*/

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date(const Date* d)
	{
		_year = d->_year;
		_month = d->_month;
		_day = d->_day;
	}

	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}

	void func()
	{
		cout << "func()" << endl;
	}

	int GetMonthDay(int year, int month)
	{
		int monthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
			return 29;
		return monthDay[month];
	}

	/*Date GetDay(int x)
	{
		_day += x;
		while (_day > GetMonthDay(_year, _month))
		{
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
			_day -= GetMonthDay(_year, _month);
		}
		return *this;
	}*/

	Date GetDay(int x)
	{
		Date tmp(*this);
		tmp._day += x;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		{
			tmp._month++;
			if (tmp._month == 13)
			{
				tmp._year++;
				tmp._month = 1;
			}
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
		}
		return tmp;
	}

private:
	int _year = 2022;
	int _month = 1;
	int _day = 1;
};

//int main()
//{
//	Date d1;
//	Date d2(d1);
//	Date d3 = d1;
//	Date d4(&d1);
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	d4.Print();
//	return 0;
//}

int main()
{
	Date d1(2023, 7, 15);
	Date d2 = d1.GetDay(200);

	d1.Print();
	d2.Print();
	return 0;
}