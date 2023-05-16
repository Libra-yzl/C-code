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

//定义一个小堆的数组容量
#define HEAP_MIN 5

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

void TestHeap5()
{
	//随机数生成器
	srand((unsigned)time(NULL));
	FILE* pf = fopen("data.txt", "w");
	if (!pf)
	{
		perror("fopen fail");
		return;
	}
	//将生成的数据写到文件中去
	int k = 1000;
	while (k--)
	{
		int ret = rand();
		fprintf(pf, "%d\n", ret);
	}
	//关闭文件 先观察
	fclose(pf);
	pf = NULL;
	
	//将文件中的数据读出来
	//找topk的数字
	//建立小堆（找最大的Topk）
	
	pf = fopen("data.txt", "r");
	if (!pf)
	{
		perror("fopen fail");
		return;
	}
	int minheap[HEAP_MIN] = { 0 };
	//先读取HEAP_MIN个数据进堆
	int tmp = 5;
	while (tmp--)
	{
		fscanf(pf, "%d", &minheap[tmp]);
	}
	AdjustDown(minheap, HEAP_MIN, 0);

	//将剩下的数挨个进堆
	int val = 0;
	while (fscanf(pf, "%d", &val) != EOF)
	{
		if (val > minheap[0])
		{
			minheap[0] = val;
			AdjustDown(minheap, HEAP_MIN, 0);
		}
	}

	//观察堆的数据
	for (int i = 0; i < HEAP_MIN; i++)
	{
		printf("%d ", minheap[i]);
	}
	printf("\n");

	fclose(pf);
	pf = NULL;
}

int main()
{
	//TestHeap1();
	//TestHeap2();
	//TestHeap3();
	//TestHeap4();
	TestHeap5();
	return 0;
}