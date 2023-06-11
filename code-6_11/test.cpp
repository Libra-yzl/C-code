#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>

using namespace std;


namespace yzl
{
	int Add(int a, int b)
	{
		cout << "Add(int a, int b)" << endl;

		return a + b;
	}
}

//using namespace yzl;

double Add(double a, double b)
{
	cout << "Add(double a, double b)" << endl;

	return a + b;
}

//int main()
//{
//	yzl::Add(1, 2);
//	Add(1.1, 1.2);
//}

//int main()
//{
//	int i = 0;
//	int& k = i;//引用
//
//	int j = i;
//
//	cout << &i << endl;
//	cout << &k << endl;
//	cout << &j << endl;
//
//	cout << sizeof(i) << endl;
//
//	++k;
//	++j;
//
//	cout << "++k = " << k << endl;
//	cout << "++j = " << j << endl;
//}

void Swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

typedef struct Node
{
	int val;
	struct Node* next;
}*PNode;

////void PushBack(PNode& s, int x)
//void PushBack(Node*& s, int x)
//{
//	s->val = x;
//	s->next = NULL;
//}

typedef struct SeqList
{
	int* a;
	int top;
	int capacity;
}SL;

//void PushBack(SL& s, int x)
//{
//	s.a = NULL;
//	s.top = s.capacity = 0;
//}

void PushBack(SL* ps, int x)
{
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

int main()
{
	int i = 0;
	int j = 1;

	cout << "交换前 i = " << i << " j = " << j << endl;

	Swap(i, j);

	cout << "交换后 i = " << i << " j = " << j << endl;

	int* p = &i;
	int*& rp = p;

	return 0;
}