#include <iostream>
// using namespace std;

//class A
//{
//public:
//	explicit A(int a)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& a)
//		:_a1(a._a1)
//	{
//		cout << "A(const A& a)" << endl;
//	}
//private:
//	int _a1;
//};
//
//int main()
//{
//	A aa(1);
//	A aa1 = 1; // ����+��������+�Ż�->����
//	return 0;
//}

//// ����һ������ʵ�������˶��������
//using std::cout;
//using std::endl;
//
//// int count = 0;
//class A
//{
//public:
//	A(int a = 0)
//	{
//		++count;
//	}
//	A(const A& aa)
//	{
//		++count;
//	}
//
//	static int GetCount() { return count; }
//
//private:
//	static int count; // ����
//};
//
//int A::count = 0; // �����ʼ��


//class Sum {
//public:
//	Sum()
//	{
//		_sum += _i;
//		++_i;
//	}
//
//	static int ret() { return _sum; }
//
//private:
//	static int _sum;
//	static int _i;
//};
//int Sum::_sum = 0;
//int Sum::_i = 1;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		Sum cnt[n];
//		return Sum::ret();
//	}
//};

using std::cout;
using std::endl;

int main()
{
	/*A a(1);
	A b(a);
	cout << A::GetCount() << endl;*/
	int* p = new int;
	//int* p = new int(10);
	cout << *p << endl;
	return 0;
}