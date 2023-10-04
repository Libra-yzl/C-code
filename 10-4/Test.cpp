//#include "Test.h"
//#include "Test2.h"
//
//int main()
//{
//	//yzl::list_test2();
//	jwf::vector_test1();
//	return 0;
//}

#include <iostream>
using namespace std;
#include <array>
#include <vector>

// #define N 10

// 非类型模板参数 -- 整型常量(char, short, int, size_t, long, longlong, ...)
//template <class T, bool N>
//class Array
//{
//private:
//	T _a[N];
//};
//
//int main()
//{
//	Array<int, true> a1;
//	Array<double, false> a2;
//	array<int, 10> a3;
//	a3[5]++;
//
//	// 传统的静态数组属于抽查越界行为
//	// 但是array的优势就是检查 (但是他的空间在栈上 而vector的空间在堆上)
//	int arr[10];
//	//arr[15] = 10;
//	//a3[15];
//
//	vector<int> v(10, 0);
//	//v[15];
//	return 0;
//}

//template <class T1, class T2>
//struct less1
//{
//	bool operator()(const T1& x, const T2& y) { return x < y; }
//};

template <class T>
struct less1
{
	bool operator()(const T& x, const T& y) { return x < y; }
};

template <class T>
struct less1<T*>
{
	bool operator()(const T* x, const T* y) { return *x < *y; }
};

//template <class T>
//struct less1
//{
//	bool operator()(const T& x, const T& y) { return x < y; }
//};


int main()
{
	int a = 10;
	int b = 20;
	int* pa = &a;
	int* pb = &b;
	//less1<int> lessthan;
	cout << less1<int*>()(pa, pb) << endl;
	cout << less1<int>() (a, b) << endl;
	cout << less1<int>() (b, a) << endl;
	//cout << less1<int>()(a, b) << endl;
	return 0;
}