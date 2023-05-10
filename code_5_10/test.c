#define _CRT_SECURE_NO_WARNINGS 1


#include "heap.h"

void TestHeap1()
{
	int arr[] = { 10,55,65,12,58,95,12,38,56,49 };
	HP hp;
	HeapInit(&hp);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		HeapPush(&hp, arr[i]);
	}

	HeapPrint(&hp);
	
	int k = 5;
	/*while (k--)
	{
		HeapPop(&hp);
	}
	HeapPrint(&hp);*/

	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapEmpty(&hp));

	k = 5;
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	HeapDestroy(&hp);
}

int main()
{
	TestHeap1();
	return 0;
}