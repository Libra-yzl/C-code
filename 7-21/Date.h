#pragma once


#include <iostream>
#include <assert.h>
using namespace std;


class Date
{
public:

	//友元函数
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

	//构造函数（日期类其实可以不需要）
	Date(int year = 2023, int month = 7, int day = 21);
	
	//拷贝构造
	Date(const Date& d);
	
	//这里不需要析构函数
	void Print();

	int GetMonthDay(int year, int month);

	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator-=(int day);
	Date operator-(int day);
	int operator-(const Date& d);


private:
	int _year = 2023;
	int _month = 7;
	int _day = 21;
};

//ostream& operator<<(ostream& out, const Date& d);
//istream& operator>>(istream& in, Date& d);

inline ostream& operator<<(ostream& out, const Date& d)
{
	//out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	out << d._year << "年" << d._month << "月" << d._day << "日";
	return out;
}

inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}