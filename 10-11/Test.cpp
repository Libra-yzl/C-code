#include <iostream>
using namespace std;

//class Base
//{
//public:
//	virtual void func() { cout << "Base()" << endl; }
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	void func() { cout << "Derive()" << endl; }
//	virtual void func2() { cout << "func2()" << endl; }
//private:
//	int _d = 1;
//};

////打印虚函数表
//typedef void(*VF_PTR)();
//
//void PrintVFTable(VF_PTR* table)
//{
//	for (size_t i = 0; table[i] != nullptr; ++i) {
//		printf("[%d]:%p\n", i, table[i]);
//		VF_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Base b;
//	Derive  d;
//
//	//PrintVFTable((VF_PTR*)(*((int*)(&b))));
//	//PrintVFTable((VF_PTR*)(*((int*)(&d))));
//
//	PrintVFTable(*(VF_PTR**)(&b));
//	PrintVFTable(*(VF_PTR**)(&d));
//
//	return 0;
//}


//class Base
//{
//public:
//	virtual void func() { cout << "Base()" << endl; }
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	void func() { cout << "Derive()" << endl; }
//	virtual void func2() { cout << "func2()" << endl; }
//private:
//	int _d = 1;
//};
//
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	int x = 0;
//	static int y = 0;
//	const char* ptr = "hello world";
//	int* m = new int;
//	
//	printf("栈对象:%p\n", &x);
//	printf("堆对象:%p\n", m);
//	printf("静态区(数据段):%p\n", &y);
//	printf("常量区(代码段):%p\n", ptr);
//
//	printf("b对象虚表:%p\n", *((int*)(&b)));
//	printf("d对象虚表:%p\n", *((int*)(&d)));
//	return 0;
//}

//class A
//{
//public:
//	virtual void func() = 0 {}
//
//private:
//	int _a = 1;
//	char _c = 1;
//};
//
//class B : public A
//{
//public:
//	void func() {}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	//A a;
//	B b;
//	printf("%zd\n", sizeof(A));
//	return 0;
//} 

//class A
//{
//public:
//	virtual void func1(int val = 1) { cout << "A->" << val << endl; }
//	virtual void test() { func1(); }
//};
//
//class B : public A
//{
//public:
//	//virtual void func1(int val = 1) override { cout << "A->" << val << endl; }
//	//void func1(int val = 0) override { cout << "B->" << val << endl; }
//	//virtual void test() override { func1(); }
//	/*virtual void test() { 
//		func1();
//		cout << "构成了重写" << endl; 
//	}*/
//};

//class A
//{
//public:
//	virtual void func1(int val = 1) { cout << "A->" << val << endl; }
//	virtual void test() { func1(); }
//};
//
//class B : public A
//{
//public:
//	//void func1(int val) override { cout << "B->" << val << endl; }
//	//void func() override { cout << "1" << endl; }
//	void func1(int val) override { cout << "B->" << val << endl; }
//};
//
//int main()
//{
//	B* ptr = new B;
//	ptr->test();
//	return 0;
//}

class A
{
public:
	virtual void func1(int val = 1) { cout << "A->" << val << endl; }
	//virtual void test() { func1(); }
};

class B : public A
{
public:
	void func1(int val = 0) { cout << "B->" << val << endl; }
	virtual void test() { func1(); }
};

int main()
{
	B* ptr = new B;
	ptr->test();
	return 0;
	return 0;
}