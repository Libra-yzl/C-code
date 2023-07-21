#pragma once


#include <iostream>
#include <assert.h>
using namespace std;


class Date
{
public:

	//��Ԫ����
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

	//���캯������������ʵ���Բ���Ҫ��
	Date(int year = 2023, int month = 7, int day = 21);
	
	//��������
	Date(const Date& d);
	
	//���ﲻ��Ҫ��������
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
	//out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	out << d._year << "��" << d._month << "��" << d._day << "��";
	return out;
}

inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}