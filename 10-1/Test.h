#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& out, Date& d);

	Date(int year=1, int month=1, int day=1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	int GetMonthDay(int year, int month);

	bool operator !=(const Date& d);
	bool operator<(const Date& d);
	Date operator+(int day);
	Date operator-(int day);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	Date& operator+=(int day);
	Date& operator-=(int day);

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& out, Date& d);