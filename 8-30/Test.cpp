//#include <iostream>
//using namespace std;
//
////class A
////{
////public:
////	A()
////	{
////		cout << "A()" << endl;
////	}
////
////	~A()
////	{
////		cout << "~A()" << endl;
////	}
////
////	void func()
////	{
////		cout << "void func()" << endl;
////	}
////private:
////	int _num;
////};
////
////class B : public A
////{
////public:
////	
////	B()
////	{
////		cout << "B()" << endl;
////	}
////
////	~B()
////	{
////		cout << "~B()" << endl;
////	}
////
////	void func(int i = 0)
////	{
////		//A::_num = 0;
////		cout << "void func(int i)" << endl;
////	}
////private:
////	int _num;
////};
//
////class Person
////{
////public:
////	void Print()
////	{
////		cout << "void Print()" << endl;
////	}
////protected:
////	string _name; // ����
////	//void Print()
////	//{
////	//	cout << "void Print()" << endl;
////	//}
////private:
////	int _age; // ����
////};
////
////
////class Student : protected Person
//////class Student : private Person
//////class Student : public Person
////{
////public:
////	void func()
////	{
////		_name = "str";
////		cout << _name << endl;
////		Print();
////	}
////protected:
////	int _stunum; // ѧ��
////};
//
//class Person
//{
//protected:
//	string _name = "С��"; // ����
//	int _num = 111; // ����֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ����֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
//// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//int main()
//{
//	//B b;
//	//b.A::func();
//	/*Student s;
//	s.func();*/
//
//	//s.Print();
//	//cout << s._name << endl;
//
//	B b;
//	b.fun(10);
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> prices;
	prices.push_back(7);
	prices.push_back(1);
	prices.push_back(5);
	prices.push_back(3);
	prices.push_back(6);
	prices.push_back(4);

	//int min = 0;
	//int min_index = 0;
	////�ҵ���Сֵ
	//for (int i = 0; i < v.size(); ++i)
	//{
	//	if (v[i] < min)
	//	{
	//		min = v[i];
	//		min_index = i;
	//	}
	//}
	//cout << min << endl;

	//for (int e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	/*int inf = 1e9;
	cout << inf << endl;
	int minprice = inf, maxprofit = 0;
	for (int price : v) {
		maxprofit = max(maxprofit, price - minprice);
		minprice = min(price, minprice);
	}
	return maxprofit;*/

	/*int _min = prices[0];
	size_t i = 0;
	int max = 0;
	int ans = 0;
	while (i < prices.size())
	{
		_min = min(prices[i], _min);
		if (max < prices[i] - _min)
		{
			ans += prices[i] - _min;
			_min = prices[i];
		}
		++i;
	}
	cout << ans << endl;*/

	int ans = 0;
	for (size_t i = 1; i < prices.size(); ++i)
	{
		ans += max(0, prices[i] - prices[i - 1]);
	}
	cout << ans << endl;

	return 0;
}