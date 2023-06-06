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

int main()
{
	//TestInsertSort();
	//TestShellSort();

	//TestSelectSort();
	//TestHeapSort();

	/*TestBubbleSort();
	TestQuickSort();
	TestQuickSortNonR();*/

	TestMergeSort();
	TestMergeSortNonR();
	return 0;
}