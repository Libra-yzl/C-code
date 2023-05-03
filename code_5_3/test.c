#define _CRT_SECURE_NO_WARNINGS 1


#include "List.h"

void TestLTNode1()
{
	LTNode* phead = NULL;
	phead = InitLTNode();

	PushBack(phead, 1);
	PushBack(phead, 2);
	PushBack(phead, 3);
	PushBack(phead, 4);
	PushBack(phead, 5);

	PopBack(phead);
	PopBack(phead);
	PopBack(phead);
	PopBack(phead);
	PopBack(phead);
	PopBack(phead);

	LTPrint(phead);
}

void TestLTNode2()
{
	LTNode* phead = NULL;
	phead = InitLTNode();

	PushFront(phead, 5);
	PushFront(phead, 4);
	PushFront(phead, 3);
	PushFront(phead, 2);
	PushFront(phead, 1);
	LTPrint(phead);

	PopFront(phead);
	LTPrint(phead);
	PopFront(phead);
	LTPrint(phead);
	PopFront(phead);
	LTPrint(phead);
	PopFront(phead);

	LTPrint(phead);
}

void TestLTNode3()
{
	LTNode* phead = NULL;
	phead = InitLTNode();

	PushBack(phead, 1);
	PushBack(phead, 2);
	PushBack(phead, 3);
	PushBack(phead, 4);
	PushBack(phead, 5);
	LTPrint(phead);

	LTNode* pos = LTFind(phead, 2);
	LTInsert(pos, 100);
	LTPrint(phead);

	LTErase(pos);
	LTPrint(phead);
	pos = LTFind(phead, 100);
	LTErase(pos);
	LTPrint(phead);

	bool x = LTEmpty(phead);
	printf("%d\n", x);

	size_t size = LTSize(phead);
	printf("%zd\n", size);

	LTDestroy(phead);
	phead = NULL;
}

int main()
{
	//TestLTNode1();
	//TestLTNode2();
	TestLTNode3();
	return 0;
}