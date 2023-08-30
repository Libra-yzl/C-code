#include <iostream>
using namespace std;

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void func()
//	{
//		cout << "void func()" << endl;
//	}
//private:
//	int _num;
//};
//
//class B : public A
//{
//public:
//	
//	B()
//	{
//		cout << "B()" << endl;
//	}
//
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//
//	void func(int i = 0)
//	{
//		//A::_num = 0;
//		cout << "void func(int i)" << endl;
//	}
//private:
//	int _num;
//};

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "void Print()" << endl;
//	}
//protected:
//	string _name; // 姓名
//	//void Print()
//	//{
//	//	cout << "void Print()" << endl;
//	//}
//private:
//	int _age; // 年龄
//};
//
//
//class Student : protected Person
////class Student : private Person
////class Student : public Person
//{
//public:
//	void func()
//	{
//		_name = "str";
//		cout << _name << endl;
//		Print();
//	}
//protected:
//	int _stunum; // 学号
//};

class Person
{
protected:
	string _name = "小李"; // 姓名
	int _num = 111; // 身份证号
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 身份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 999; // 学号
};
void Test()
{
	Student s1;
	s1.Print();
};
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};

int main()
{
	//B b;
	//b.A::func();
	/*Student s;
	s.func();*/

	//s.Print();
	//cout << s._name << endl;

	B b;
	b.fun(10);
	return 0;
}