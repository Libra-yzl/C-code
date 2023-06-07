#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"

void TestInsertSort()
{
	int a[] = { 4,8,5,6,9,2,2,3,7,10,1 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("InsertSort:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	InsertSort(a, sz);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestShellSort()
{
	int a[] = { 4,8,5,6,9,2,2,3,7,10,1 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("\nShellSort:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	ShellSort(a, sz);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestSelectSort()
{
	int a[] = { 4,8,5,6,9,2,2,3,7,10,1 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("SelectSort:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	SelectSort(a, sz);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestHeapSort()
{
	int a[] = { 4,8,5,6,9,2,2,3,7,10,1,88,6,1,4,4,1651,6511,1,561,15,1848,488,4984,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("\nHeapSort:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	HeapSort(a, sz);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestBubbleSort()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1,-5,80,52,65,8,4,5,2,62,2,5,2,5,5,84,1,4,1,16,46,15,4,1,6546,16,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("BubbleSort:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	BubbleSort(a, sz);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestQuickSort()
{
	int a[] = { 4,8,5,6,9,2,2,3,7,10,1,88,6,1,4,4,1651,6511,1,561,15,1848,488,4984,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("\nQuickSort:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	QuickSort(a, 0, sz-1);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestQuickSortNonR()
{
	int a[] = { 4,8,5,6,9,2,2,3,7,10,1,88,6,1,4,4,1651,6511,1,561,15,1848,488,4984,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("\nQuickSortNonR:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	QuickSortNonR(a, 0, sz - 1);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestMergeSort()
{
	int a[] = { 4,8,5,6,9,2,2,3,7,10,1,88,6,1,4,4,1651,6511,1,561,15,1848,488,4984,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("MergeSort:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	MergeSort(a, 0, sz - 1);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestMergeSortNonR()
{
	int a[] = { 4,8,5,6,9,2,2,3,7,10,1,88,6,1,4,4,1651,6511,1,561,15,1848,488,4984,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("\nMergeSortNonR:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	MergeSortNonR(a, sz);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestCountSort()
{
	int a[] = { 4,8,5,6,9,2,2,3,7,10,1,-2,-3,-2,-5,-5,-3,-2,-2 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("\nCountSort:\n");
	printf("排序前数组:\n");
	Print(a, sz);
	CountSort(a, sz);
	printf("排序后数组:\n");
	Print(a, sz);
}

void TestTime()
{
	int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	if (!a1)
		return;
	int* a2 = (int*)malloc(sizeof(int) * N);
	if (!a2)
		return;
	int* a3 = (int*)malloc(sizeof(int) * N);
	if (!a3)
		return;
	int* a4 = (int*)malloc(sizeof(int) * N);
	if (!a4)
		return;
	int* a5 = (int*)malloc(sizeof(int) * N);
	if (!a5)
		return;
	int* a6 = (int*)malloc(sizeof(int) * N);
	if (!a6)
		return;
	int* a7 = (int*)malloc(sizeof(int) * N);
	if (!a7)
		return;

	for (int i = 0; i < N; i++)
	{
		int x = rand()+i;

		a1[i] = x;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	ShellSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	HeapSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	QuickSort(a3, 0, N-1);
	int end3 = clock();

	int begin4 = clock();
	MergeSort(a4, 0, N-1);
	int end4 = clock();

	int begin5 = clock();
	QuickSortNonR(a5, 0, N-1);
	int end5 = clock();

	int begin6 = clock();
	MergeSortNonR(a6, N);
	int end6 = clock();

	int begin7 = clock();
	CountSort(a7, N);
	int end7 = clock();

	printf("ShellSort:%dms\n", end1 - begin1);
	printf("HeapSort:%dms\n", end2 - begin2);
	printf("QuickSort:%dms\n", end3 - begin3);
	printf("MergeSort:%dms\n", end4 - begin4);
	printf("QuickSortNonR:%dms\n", end5 - begin5);
	printf("MergeSortNonR:%dms\n", end6 - begin6);
	printf("CountSort:%dms\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	a1 = a2 = a3 = a4 = a5 = a6 = a7 = NULL;
}

int main()
{
	//TestInsertSort();
	//TestShellSort();

	//TestSelectSort();
	//TestHeapSort();

	//TestBubbleSort();
	//TestQuickSort();
	//TestQuickSortNonR();

	TestMergeSort();
	TestMergeSortNonR();

	TestCountSort();

	//TestTime();
	return 0;
}