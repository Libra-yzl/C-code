#define _CRT_SECURE_NO_WARNINGS 1


#include "review.h"

void TestSLTNode()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 10);
	SLTPushBack(&plist, 20);
	SLTPushBack(&plist, 30);
	SLTPushBack(&plist, 40);
	SLTPushBack(&plist, 50);
	SLTPushBack(&plist, 60);
	SLTPushBack(&plist, 70);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPushBack(&plist, 100);
	SLTPrint(plist);

	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 5);
	SLTPrint(plist);

	/*SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);*/

	SLTNode* pos = SListFind(plist, 10);
	SListInsertAfter(pos, 1000);
	SLTPrint(plist);

	SListEraseAfter(pos);
	SLTPrint(plist);
	SListEraseAfter(pos);
	SLTPrint(plist);

	SListInsert(&plist, pos, 2000);
	SLTPrint(plist);
	
	pos = SListFind(plist, 5);
	SListInsert(&plist, pos, 5000);
	//SListInsertAfter(pos, 5000);
	SLTPrint(plist);

	pos = SListFind(plist, 5000);
	SListErase(&plist, pos);
	SLTPrint(plist);

	SLTDestroy(&plist);
}

void TestLTNode()
{
	LTNode* plist = LTInit();

	/*LTPushBack(plist, 10);
	LTPushBack(plist, 20);
	LTPushBack(plist, 30);
	LTPushBack(plist, 40);
	LTPushBack(plist, 50);
	LTPrint(plist);

	LTPopBack(plist);
	LTPopBack(plist);
	LTPopBack(plist);
	LTPopBack(plist);
	LTPopBack(plist);
	LTPrint(plist);*/

	/*LTPushFront(plist, 100);
	LTPushFront(plist, 200);
	LTPushFront(plist, 300);
	LTPushFront(plist, 400);
	LTPushFront(plist, 500);
	LTPrint(plist);

	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);
	LTPrint(plist);*/

	LTPushBack(plist, 10);
	LTPushBack(plist, 20);
	LTPushBack(plist, 30);
	LTPushBack(plist, 40);
	LTPushBack(plist, 50);
	LTPrint(plist);

	LTNode* pos = LTFind(plist, 50);
	LTInsert(pos, 100);
	LTPrint(plist);

	pos = LTFind(plist, 20);
	//LTErase(pos);
	LTPrint(plist);

	printf("Size:%d\n", LTSize(plist));
	printf("isEmpty:%d\n", LTEmpty(plist));

	LTDestroy(plist);
}

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 100);
	StackPush(&s, 200);
	StackPush(&s, 300);
	StackPush(&s, 400);
	StackPush(&s, 500);
	for (int i = 0; i < s.top; i++)
	{
		printf("%d ", s.a[i]);
	}
	printf("\n");
	printf("Top:%d\n", StackTop(&s));
	printf("Size:%d\n", StackSize(&s));

	StackPop(&s);
	StackPop(&s);
	for (int i = 0; i < s.top; i++)
	{
		printf("%d ", s.a[i]);
	}
	printf("\n");
	printf("Top:%d\n", StackTop(&s));
	printf("Size:%d\n", StackSize(&s));

	StackPop(&s);
	StackPop(&s);
	//StackPop(&s);
	//printf("Top:%d\n", StackTop(&s));
	printf("isEmpty:%d\n", StackEmpty(&s));

	StackDestroy(&s);
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	
	QueuePush(&q, 100);
	QueuePush(&q, 200);
	QueuePush(&q, 300);
	QueuePush(&q, 400);
	QueuePush(&q, 500);
	
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	printf("Size:%d\n", QueueSize(&q));
	printf("isEmpty:%d\n", QueueEmpty(&q));

	QueueDestroy(&q);
}

void TestHeap1()
{
	Heap hp;
	HeapInit(&hp);

	HeapPush(&hp, 10);
	HeapPush(&hp, 29);
	HeapPush(&hp, 8);
	HeapPush(&hp, 21);
	HeapPush(&hp, 16);
	HeapPush(&hp, 3);
	HeapPush(&hp, 38);
	HeapPush(&hp, 27);
	HeapPush(&hp, 32);
	HeapPush(&hp, 15);
	HeapPrint(&hp);

	printf("É¾³ý¶Ñ¶¥ÔªËØºó:\n");
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);

	HeapPrint(&hp);

	//printf("HeapTop:%d\n", HeapTop(&hp));
	printf("HeapSize:%d\n", HeapSize(&hp));
	printf("HeapEmpty:%d\n", HeapEmpty(&hp));

	HeapDestroy(&hp);
}

void TestHeap2()
{
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap hp;

	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

void TestHeapSort()
{
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	//TestSLTNode();
	//TestLTNode();

	//TestStack();
	//TestQueue();

	//TestHeap1();
	//TestHeap2();
	TestHeapSort();
	return 0;
}