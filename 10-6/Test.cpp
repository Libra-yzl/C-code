//#include <iostream>
//using std::cout;
//using std::endl;
//
//extern void func();
//extern int g_val;
//
//int main()
//{
//	cout << g_val << endl;
//	func();
//	return 0;
//}


//#include <iostream>
//using namespace std;
//#include <iomanip>

int GetMonthDay(int year, int month) {
    int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return 29;
    return MonthDay[month];
}

//int main() {
//    int m = 0;
//    cin >> m;
//    int _year = 0, _month = 0, _day = 0, day = 0;
//    while (m-- && cin >> _year >> _month >> _day >> day) {
//        _day += day;
//        while (_day > GetMonthDay(_year, _month)) {
//            _day -= GetMonthDay(_year, _month);
//            ++_month;
//            if (_month == 13) {
//                ++_year;
//                _month = 1;
//            }
//        }
//        cout << _year << "-" << setw(2) << setfill('0') << _month << "-" << setw(2) << setfill('0') << _day << endl;
//    }
//    return 0;
//}

//int main()
//{
//    char* p = new char[100];
//    delete p;
//}

#include <iostream>
using namespace std;
#include <string>


class A
{
public:
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
private:
    int _a=0;
};

class B
{
public:
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
private:
    int _b=0;
};

class C
{
public:
    C() { cout << "C()" << endl; }
    ~C() { cout << "~C()" << endl; }
private:
    int _c=0;
};

class D
{
public:
    D() { cout << "D()" << endl; }
    ~D() { cout << "~D()" << endl; }
private:
    int _d=0;
};

//C c;

//int main()
//{
//    A();
//    A* pa = new A();
//    B b;
//    static D d;
//    delete pa;
//    return 0;
//}


//int main()
//{
//
//	string a = "hello world";
//	string b = a;
//
//	if (a.c_str() == b.c_str()) { cout << "true" << endl; }
//	else cout << "false" << endl;
//
//	string c = b;
//	c = "";
//
//	if (a.c_str() == b.c_str()) { cout << "true" << endl; }
//	else cout << "false" << endl;
//
//	a = "";
//
//	if (a.c_str() == b.c_str()) { cout << "true" << endl; }
//	else cout << "false" << endl;
//
//	return 0;
//}
// 

//int main()
//{
//
//    string str("Hello Bit.");
//
//    str.reserve(111);
//
//    str.resize(5);
//
//    str.reserve(50);
//
//    cout << str.size() << ":" << str.capacity() << endl;
//
//    return 0;
//
//}

int main()

{

	string strText = "How are you?";

	string strSeparator = " ";

	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;

	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

		size_prev_pos = ++size_pos;

	}

	if (size_prev_pos != strText.size())

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

	}

	cout << endl;

	return 0;

}