#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);
	int monthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
		return monthDay[month];
}

//构造函数（日期类其实可以不需要）
Date::Date(int year, int month, int day)
{
	if (month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "输入的日期非法" << endl;
		exit(-1);
	}
}

//拷贝构造
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}


//这里不需要析构函数
void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;
}

bool Date::operator>=(const Date& d)
{
	return *this == d || *this > d;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
		_day -= GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
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


Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -flag;
	}
	int day = 0;
	while (max != min)
	{
		++day;
		++min;
	}
	return flag * day;
}

//ostream& operator<<(ostream& out, const Date& d)
//{
//	//out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//	out << d._year << "年" << d._month << "月" << d._day << "日";
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}

