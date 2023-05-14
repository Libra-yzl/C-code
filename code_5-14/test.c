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

void TestHeap3()
{
	int arr[] = { 15,65,49,34,19,28,37,27,25,18 };
	HP hp;
	HeapInit(&hp);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPrint(&hp);

	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	HeapDestroy(&hp);
}

void TestHeap4()
{
	int minHeap[5];
	int k = 5;

	FILE* pf = fopen("data.txt", "r");
	if (!pf)
	{
		perror("fopen fail");
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		fscanf(pf, "%d", &minHeap[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, k, i);
	}

	int val = 0;
	while (fscanf(pf, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	printf("\n");

	fclose(pf);
	pf = NULL;

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	printf("\n");
}

int main()
{
	//TestHeap1();
	//TestHeap2();
	//TestHeap3();
	TestHeap4();
	return 0;
}