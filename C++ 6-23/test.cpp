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
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}


//struct A 
//{ 
//	int a[10000]; 
//};
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
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
//	////Ȩ�޷Ŵ�
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
//	////Ȩ����С
//	//int c = 1;
//	//const int& d = c;
//
//	//cout << "c = " << d << endl;
//
//	int i = 10;
//
//	cout << (double)i << endl;
//
//	double dd = i; //�����i��ֵ���ȸ�һ��double���͵���ʱ���� Ȼ����������ڸ�ֵ��dd��
//	//����
//	
//	//����i��ֵ����ʱ���� ��ʱ�����ǲ����޸ĵ� �൱��Ȩ�޷Ŵ��� ���Լ���const���ƺ�Ͳ��ᱨ����(Ȩ�ޱ���)
//	//double& rd = i;
//	const double& rd = i;
//	
//	return 0;
//}


//���ȱ�㣺
//1�����ܵ���
//2��û�����Ͱ�ȫ�ļ��
//3����Щ�����Ƚϸ��� ���׳��� ����������

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

//C++��inline����꺯��
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