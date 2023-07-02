#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main()
//{
//	int a = 0;
//	auto b = a;
//	auto c = &a;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0;
//}

//typedef char* pstring;
//
//int main()
//{
//	const pstring p1 = NULL;
//	const pstring* p2;
//}

//int main()
//{
//	int a = 0;
//	auto b = &a;
//	auto* c = &a;
//	auto& d = a;
//
//	int array[] = { 1,2,3,4,5,6 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
//	{
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	// 范围for -- 语法糖
//	// 自动依次取数组中数据赋值给e对象 自动判断结束
//	for (auto& e : array)
//	{
//		e *= 2;
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto x : array)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

void fun(int)
{
	cout << "fun(int)" << endl;
}

void fun(int*)
{
	cout << "fun(int*)" << endl;
}

//int main()
//{
//	fun(0);
//	fun(NULL);
//	fun(nullptr);
//
//	return 0;
//}

//struct Stack
//{
//	//成员函数(类的方法)
//	void Init(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (!_a)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		_size = capacity;
//		_capacity = capacity;
//	}
//
//	void Push(int x = 1)
//	{
//		//...检查扩容
//		_a[_size++] = x;
//	}
//
//
//	//成员变量(类的属性)
//	int* _a;
//	int _size;
//	int _capacity;
//};

#include "Stack.h"

class Date
{
public:
	void fun()
	{
		cout << "fun()" << endl;
	}

	void Init(int year = 2023, int month = 7, int day = 2)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	/*Stack st;
	st.Init();
	st.Push(1);
	st.Push(2);
	st.Push(3);*/

	Date d1;
	Date d2;
	d1.fun();
	d2.Init();

	Date* ptr = nullptr;
	//正常运行
	ptr->fun();
	(*ptr).fun();

	//程序崩溃 (这里将ptr(指针)传过去,this指针解引用操作导致错误)
	ptr->Init();

	return 0;
}