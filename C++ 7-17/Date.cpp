#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

bool Date::operator<(const Date& d)
{
	/*if (_year < d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month < d._month)
			return true;
		else if (_month == d._month)
		{
			if (_day < d._day)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;*/

	//推荐这一种
	if (_year < d._year)
		return true;
	else if (_year == d._year && _month < d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day < d._day)
		return true;
	else
		return false;

	/*return _year < d._year ||
		(_year == d._year && _month < d._month) ||
		(_year == d._year && _month == _month && _day < d._day);*/
}

Date::Date(int year, int month, int day)
{
	if (month > 0 && month < 13 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "输入的日期非法!" << endl;
		exit(-1);
	}
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//获取对应月份的天数
int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);

	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;
	return days[month];
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
		return *this;
	}
	_day += day;
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
}

Date Date::operator+(int day)
{
	Date tmp;
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp;
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

//Date Date::operator!=(int day);

int Date::operator-(Date d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (min < max)
	{
		min++;
		count++;//计算相差多少天
	}
	return flag * count;
}

void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}
