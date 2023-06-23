#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <time.h>
#include <assert.h>

using namespace std;

//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = b;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//
//	return 0;
//}

//struct A 
//{ 
//	int a[10000]; 
//};
//
//void TestFunc1(A a) 
//{}
//
//void TestFunc2(A& a) 
//{}
//
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}


//struct A 
//{ 
//	int a[10000]; 
//};
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}


//int main()
//{
//	TestRefAndValue();
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int& b = a;
//	//int c = 2;
//
//	////权限放大
//	//const int c = 1;
//	//int& d = c;
//
//	/*const int* p1 = &a;
//	int const* p2 = p1;
//	int* const p3 = &a;
//
//	*p3 = 10;
//
//	cout << "a = " << a << endl;*/
//
//
//	////权限缩小
//	//int c = 1;
//	//const int& d = c;
//
//	//cout << "c = " << d << endl;
//
//	int i = 10;
//
//	cout << (double)i << endl;
//
//	double dd = i; //这里的i赋值是先给一个double类型的临时变量 然后这个变量在赋值给dd的
//	//例子
//	
//	//这里i赋值给临时变量 临时变量是不可修改的 相当于权限放大了 所以加上const限制后就不会报错了(权限保持)
//	//double& rd = i;
//	const double& rd = i;
//	
//	return 0;
//}


//宏的缺点：
//1、不能调试
//2、没有类型安全的检查
//3、有些场景比较复杂 容易出错 不容易掌握

////err
////#define Add(x, y) x+y
////#define Add(x, y) (x+y)
////...
//
//#define ADD(x, y) ((x)+(y))
//
//int main()
//{
//	ADD(1, 2) * 3;
//	return 0;
//}

//C++用inline替代宏函数
inline int Add(int x, int y)
{
	int z = x + y;
	return z;
}

int main()
{
	cout << "Add(1,2) = " << Add(1, 2) << endl;
	return 0;
}