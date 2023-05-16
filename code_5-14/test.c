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

//����һ��С�ѵ���������
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
	//�����������
	srand((unsigned)time(NULL));
	FILE* pf = fopen("data.txt", "w");
	if (!pf)
	{
		perror("fopen fail");
		return;
	}
	//�����ɵ�����д���ļ���ȥ
	int k = 1000;
	while (k--)
	{
		int ret = rand();
		fprintf(pf, "%d\n", ret);
	}
	//�ر��ļ� �ȹ۲�
	fclose(pf);
	pf = NULL;
	
	//���ļ��е����ݶ�����
	//��topk������
	//����С�ѣ�������Topk��
	
	pf = fopen("data.txt", "r");
	if (!pf)
	{
		perror("fopen fail");
		return;
	}
	int minheap[HEAP_MIN] = { 0 };
	//�ȶ�ȡHEAP_MIN�����ݽ���
	int tmp = 5;
	while (tmp--)
	{
		fscanf(pf, "%d", &minheap[tmp]);
	}
	AdjustDown(minheap, HEAP_MIN, 0);

	//��ʣ�µ�����������
	int val = 0;
	while (fscanf(pf, "%d", &val) != EOF)
	{
		if (val > minheap[0])
		{
			minheap[0] = val;
			AdjustDown(minheap, HEAP_MIN, 0);
		}
	}

	//�۲�ѵ�����
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