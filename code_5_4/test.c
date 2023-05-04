#define _CRT_SECURE_NO_WARNINGS 1


#include "Stack.h"

void TestStack1()
{
	ST st;
	InitStack(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	StackPrint(&st);
	printf("%d\n", StackSize(&st));
	DestroyStack(&st);
}


//int main()
//{
//	TestStack1();
//	return 0;
//}