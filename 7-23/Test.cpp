#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;


//class Sum
//{
//public:
//    Sum()
//    {
//        _sum += _i;
//        ++_i;
//    }
//
//    static int GetSum()
//    {
//        return _sum;
//    }
//
//private:
//    static int _i;
//    static int _sum;
//};
//
//int Sum::_i = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        Sum arr[n];
//        return Sum::GetSum();
//    }
//};

//class A
//{
//public:
//    A(int a = 0)
//
//    {
//        cout << "A(int a)" << endl;
//    }
//
//    A(const A& aa)
//    {
//        cout << "A(const A& aa)" << endl;
//    }
//
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//private:
//    int _a;
//};
//
//
//
//A func1()
//{
//    A aa;
//    return aa;
//}
//
//void func2(const A& aa)
//{
//    
//}
//
//int main()
//{
//    ////匿名对象 生命周期只在这一行
//    //cout << A().GetNum() << endl;
//
//    func1();
//    cout << "-----------------" << endl;
//    A a1 = func1();
//    cout << "-----------------" << endl;
//    func1();
//    cout << "-----------------" << endl;
//    func2(2); 
//    cout << "*****************" << endl;
//    func2(A(2));
//    cout << "-----------------" << endl;
//    A a3(func1());
//
//    return 0;
//}

//class A
//{
//public:
//    A(int a = 0)
//        :_a(a)
//    {
//        cout << "A(int a)" << endl;
//    }
//    A(const A& aa)
//        :_a(aa._a)
//    {
//        cout << "A(const A& aa)" << endl;
//    }
//    A& operator=(const A& aa)
//    {
//        cout << "A& operator=(const A& aa)" << endl;
//        if (this != &aa)
//        {
//            _a = aa._a;
//        }
//        return *this;
//    }
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//private:
//    int _a;
//};
//void f1(const A& aa)
//{}
//A f2()
//{
//    A aa;
//    return aa;
//}
//int main()
//{
//    // 传值传参
//    A aa1;
//    f1(aa1);
//    cout << endl;
//    // 传值返回
//    f2();
//    cout << endl;
//    // 隐式类型，连续构造+拷贝构造->优化为直接构造
//    f1(1);
//    // 一个表达式中，连续构造+拷贝构造->优化为一个构造
//    f1(A(2));
//    cout << endl;
//    // 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
//    A aa2 = f2();
//    cout << endl;
//    // 一个表达式中，连续拷贝构造+赋值重载->无法优化
//    aa1 = f2();
//    cout << endl;
//    return 0;
//}


//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* ptr1 = new int;
//	delete ptr1;
//	free(p1);
//	
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* ptr2 = new int[10];
//	delete[] ptr2;
//
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// 这里需要free(p2)吗？
//	free(p3);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;

//int main()
//{
//    int year, month, day;
//    cin >> year >> month >> day;
//
//    int monthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int days = day;
//    int tmp = month;
//    int flag = 1;
//    while (--tmp)
//    {
//        if (flag == 1 && tmp > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//        {
//            monthDay[2] += 1;
//            flag = 0;
//        }
//        days += monthDay[tmp];
//    }
//    cout << days;
//}

//int main()
//{
//	int a = 20110412;
//	int b = a % 100;
//	int c = (a / 100) % 100;
//	int d = a / 100 / 100;
//	cout << b << endl;
//	cout << c << endl;
//	cout << d << endl;
//	/*int max, min;
//	while (cin >> max >> min)
//	{
//		cout << " max = " << max << " min = " << min << endl;
//	}*/
//}

//#include <iostream>
//using namespace std;
//
//int GetMonthDay(int year, int month)
//{
//    int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//        return 29;
//    else
//        return MonthDay[month];
//
//}
//
//
//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {}
//    Date(const Date& d)
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//
//    bool operator<(const Date& d)
//    {
//        if (_year < d._year)
//            return true;
//        else if (_year == d._year && _month < d._month)
//            return true;
//        else if (_year == d._year && _month == d._month && _day < d._day)
//            return true;
//        else
//            return false;
//    }
//
//    bool operator==(const Date& d)
//    {
//        return _year == d._year && _month == d._month && _day == d._day;
//    }
//
//    bool operator!=(const Date& d)
//    {
//        return !(*this == d);
//    }
//
//    Date& operator+=(int day)
//    {
//        _day += day;
//        while (_day > GetMonthDay(_year, _month))
//        {
//            _day -= GetMonthDay(_year, _month);
//
//            ++_month;
//            if (_month == 13)
//            {
//                ++_year;
//                _month = 1;
//            }
//        }
//        return *this;
//    }
//
//
//    Date& operator++()
//    {
//        *this += 1;
//        return *this;
//    }
// 
//
//    int operator-(const Date& d)
//    {
//        Date max(*this);
//        Date min(d);
//        if (max < min)
//        {
//            max = d;
//            min = *this;
//        }
//
//        int n = 0;
//        while (min != max)
//        {
//            ++n;
//            ++min;
//        }
//        return n+1;
//    }
//
//    /*int operator-(const Date& d)
//    {
//        Date max = *this;
//        Date min = d;
//        int flag = 1;
//        if (max < min)
//        {
//            max = d;
//            min = *this;
//            flag = -flag;
//        }
//        int day = 0;
//        while (max != min)
//        {
//            ++day;
//            ++min;
//        }
//        return flag * day;
//    }*/
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//void TestDate2()
//{
//    Date d1(2023, 7, 23);
//    Date d2(1966, 8, 23);
//    cout << d1 - d2 << endl;
//    cout << d2 - d1 << endl;
//}
//
//int main()
//{
//    int max, min;
//    while (cin >> max >> min)
//    {
//        if (max == min)
//        {
//            cout << 0 << endl;
//            continue;
//        }
//        if (max < min)
//        {
//            int tmp = min;
//            min = max;
//            max = tmp;
//        }
//        //分割数据
//        int day1 = max % 100;
//        int day2 = min % 100;
//        int month1 = (max / 100) % 100;
//        int month2 = (min / 100) % 100;
//        int year1 = max / 100 / 100;
//        int year2 = min / 100 / 100;
//
//        Date d1(year1, month1, day1);
//        Date d2(year2, month2, day2);
//        cout << (d1 - d2) << endl;
//
//    }
//    //TestDate2();
//}

#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
public:
    Date(int year = 1, int month = 1, int day = 0)
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

    int GetMonthDay(int year, int month)
    {
        int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
            return 29;
        else
            return MonthDay[month];

    }

    bool operator<(const Date& d)
    {
        if (_year < d._year)
            return true;
        else if (_year == d._year && _month < d._month)
            return true;
        else if (_year == d._year && _month == d._month && _day == d._day)
            return true;
        else
            return false;
    }

    bool operator==(const Date& d)
    {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    bool operator!=(const Date& d)
    {
        return !(*this == d);
    }



    Date& operator+=(int day)
    {
        _day += day;
        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            ++_month;
            if (_month == 13)
            {
                ++_year;
                _month = 1;
            }
        }
        return *this;
    }

    Date& operator++()
    {
        *this += 1;
        return *this;
    }

    int operator-(const Date& d)
    {
        Date max(*this);
        Date min(d);
        if (max < min)
        {
            Date tmp(max);
            max = min;
            min = tmp;
        }

        int n = 0;
        while (min != max)
        {
            ++n;
            ++min;
        }
        return n + 1;
    }

    Date& operator+(int day)
    {
        *this += day;
        return *this;
    }

    friend ostream& operator<<(ostream& out, Date& d);

private:
    int _year;
    int _month;
    int _day;
};

ostream& operator<<(ostream& out, Date& d)
{
    out << d._year << "-" << setw(2) << setfill('0') 
        << d._month << "-" << setw(2) << setfill('0')
        << d._day << endl;
    //out << d._year << "-" << d._month << "-" << d._day << endl;
    return out;
}

int main()
{
    int year, day;
    while (cin >> year >> day)
    {
        Date d(year, 1, 0);
        d += day;
        cout << d;
    }
}