#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct Stack
{
public:
	//// 构造函数
	//Stack()
	//{
	//	_a = nullptr;
	//	_capacity = _size = 0;
	//}
	//Stack(int n)
	//{
	//	_a = (int*)malloc(sizeof(int) * n);
	//	if (!_a)
	//	{
	//		perror("malloc fail");
	//		exit(-1);
	//	}
	//	_size = 0;
	//	_capacity = n;
	//}
	
	Stack(int n = 4)
	{
		_a = (int*)malloc(sizeof(int) * n);
		if (!_a)
		{
			perror("malloc fail");
			exit(-1);
		}
		_size = 0;
		_capacity = n;
	}
	 
	////成员函数(类的方法)
	//void Init(int capacity = 4)
	//{
	//	_a = (int*)malloc(sizeof(int) * capacity);
	//	if (!_a)
	//	{
	//		perror("malloc fail");
	//		exit(-1);
	//	}
	//	_size = capacity;
	//	_capacity = capacity;
	//}

	void Push(int x = 1)
	{
		//...检查扩容
		_a[_size++] = x;
	}

	// 析构函数
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_capacity = _size = 0;
	}
private:
	//成员变量(类的属性)
	int* _a;
	int _size;
	int _capacity;
};

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}

	//拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	int GetMonthDay(int year, int month)
	{
		int month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//判断闰年2月份天数
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return month_day[month] + 1;
		else
			return month_day[month];
	}

	/*Date GetAfterDate(int days)
	{
		_day += days;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}*/

	Date GetAfterDate(int days)
	{
		Date tmp = *this;
		tmp._day += days;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		{
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
			tmp._month++;
			if (tmp._month > 12)
			{
				tmp._year++;
				tmp._month = 1;
			}
		}
		return tmp;
	}



private:
	//声明位置给的缺省值
	int _year = 1;
	int _month = 1;
	int _day = 1;
};

//int main()
//{
//	//Stack st;
//	/*Stack st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);*/
//	Date d1(2023);
//	// d1.Print();
//	Date d2(d1);
//	Date d3 = d1;
//	d1.Print();
//	d2.Print();
//	return 0;
//}

int main()
{
	Date d1(2023, 7, 4);
	Date d2 = d1.GetAfterDate(100);
	d1.Print();
	d2.Print();
	return 0;
}