#define _CRT_SECURE_NO_WARNINGS 1


#include "Heap.h"

void TestHeap1()
{
	int arr[] = { 15,65,49,34,19,28,37,27,25,18 };
	HP hp;
	HeapInit(&hp);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPrint(&hp);

	for (int i = 0; i < 5; i++)
	{
		HeapPop(&hp);
	}
	HeapPrint(&hp);
	printf("%d\n", HeapEmpty(&hp));
	printf("%d\n", HeapSize(&hp));

	HeapDestroy(&hp);
}

void TestHeap2()
{
	int arr[] = { 15,65,49,34,19,28,37,27,25,18 };
	HP hp;
	HeapInit(&hp);

	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

int main()
{
	//TestHeap1();
	TestHeap2();
	return 0;
}