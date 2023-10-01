#include "Test.h"

int Date::GetMonthDay(int year, int month)
{
	int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 29;
	return MonthDay[month];
}

bool Date::operator !=(const Date& d)
{
	return _year != d._year || _month != d._month || _day != d._day;
}

bool Date::operator<(const Date& d)
{
	return _year < d._year || _year == d._year && _month < d._month || _year == d._year && _month == d._month &&
		_day < d._day;
}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}
	return tmp;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp._day -= day;
	while (tmp._day <= 0)
	{
		--tmp._month;
		if (tmp._month == 0)
		{
			--tmp._year;
			tmp._month = 12;
		}
		tmp._day += GetMonthDay(tmp._year, tmp._month);
	}
	return tmp;
}

int Date::operator-(const Date& d)
{
	int day_count = 0;
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (max < min)
	{
		flag = -1;
		max = d;
		min = *this;
	}
	while (min != max)
	{
		++min;
		++day_count;
	}
	return day_count * flag;
}

Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this = *this + 1;
	return tmp;
}

Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this = *this - 1;
	return tmp;
}

Date& Date::operator+=(int day)
{
	*this = *this + day;
	return *this;
}

Date& Date::operator-=(int day)
{
	*this = *this - day;
	return *this;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "Äê" << d._month << "ÔÂ" << d._day << "ÈÕ";
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}