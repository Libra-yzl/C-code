#pragma once
#include <iostream>
using namespace std;

namespace yzl
{
	class Date
	{
	public:
		Date(int year = 1, int month = 1, int day = 1)
			:_year(year)
			,_month(month)
			,_day(day)
		{}

		void print()
		{
			cout << _year << "Äê" << _month << "ÔÂ" << _day << "ÈÕ" << endl;
		}

		int getMonthDay(int year, int month)
		{
			int getMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
			if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return 29;
			return getMonth[month];
		}

		Date& GetAfterDay(int x)
		{
			_day += x;
			while (_day > getMonthDay(_year, _month))
			{
				_day -= getMonthDay(_year, _month);
				++_month;
				if (_month == 13)
				{
					++_year;
					_month = 1;
				}
			}
			return *this;
		}

	private:
		int _year;
		int _month;
		int _day;
	};

	void date_test1()
	{
		Date d1(2023, 2, 3);
		d1.print();
		d1.GetAfterDay(150);
		d1.print();
	}
}