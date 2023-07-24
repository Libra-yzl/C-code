#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main()
//{
//	int* p1 = new int;//不会初始化
//	int* p = new int(0); //会初始化
//
//	int* a = new int[10]; //申请10个int的数组
//
//	int* p2 = (int*)malloc(sizeof(int) * 4);
//	if (!p2)
//		exit(-1);
//
//	delete p1;
//	delete p;
//	delete[] a;
//	free(p2);
//	p2 = nullptr;
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
		//注意：在申请自定义类型的空间时，new会调用构造函数，delete会调用析构函数，而malloc与free不会。
			
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
//	//A* p1 = (A*)malloc(sizeof(A));
//	//A* p2 = new A(1);
//	//free(p1);
//	//delete p2;
//	//// 内置类型是几乎是一样的
//	//int* p3 = (int*)malloc(sizeof(int)); // C
//	//int* p4 = new int;
//	//free(p3);
//	//delete p4;
//	//A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	//free(p5);
//	delete[] p6;
//	return 0;
//}

//int main()
//{
//	int* p1 = new int[10]{0,0};
//	int* p2 = (int*)malloc(sizeof(int) * 10);
//	if (p2 == nullptr)
//		exit(-1);
//	for (int i = 0; i < 10; ++i)
//	{
//		p2[i] = 0;
//	}
//
//	delete[] p1;
//	free(p2);
//	return 0;
//}

//template <class T1, typename T2>
//void Swap(T1& a, T2& b)
//{
//	T1 tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 1;
//	cout << a << " " << b << endl;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	int i = 1;
//	double d = 2.1;
//	cout << i << " " << d << endl;
//	Swap(i, d);
//	cout << i << " " << d << endl;
//	return 0;
//}

//template <class T>
//T Add(const T& a, const T& b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int i = 1;
//	double d = 2.2;
//	cout << Add<double>(i, d) << endl;
//	return 0;
//}

template <class T>
class Stack
{
public:
	Stack(int capacity = 4)
		:_a(new T[capacity])
		,_size(0)
		,_capacity(capacity)
	{}
	~Stack()
	{
		delete[] _a;
	}
private:
	T* _a;
	int _size;
	int _capacity;
};

int main()
{
	Stack<int> st;
	Stack<double> st2;
	return 0;
}