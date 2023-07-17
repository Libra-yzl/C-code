#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	Date(int year = 2023, int month = 7, int day = 17);
	Date(const Date& d);
	bool operator<(const Date& d);
	int GetMonthDay(int year, int month);
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	//Date operator!=(int day);
	int operator-(Date d);

	void Print();
private:
	int _year;
	int _month;
	int _day;
};