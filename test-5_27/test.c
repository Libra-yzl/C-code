#define _CRT_SECURE_NO_WARNINGS 1


#include "sort.h"

void testTime()
{
	srand((unsigned)time(NULL));
	const int ret = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * ret);
	if (!a1)
		return; 
	int* a2 = (int*)malloc(sizeof(int) * ret);
	if (!a2)
		return;
	int* a3 = (int*)malloc(sizeof(int) * ret);
	if (!a3)
		return;
	int* a4 = (int*)malloc(sizeof(int) * ret);
	if (!a4)
		return;
	int* a5 = (int*)malloc(sizeof(int) * ret);
	if (!a5)
		return;
	int* a6 = (int*)malloc(sizeof(int) * ret);
	if (!a6)
		return;
	int* a7 = (int*)malloc(sizeof(int) * ret);
	if (!a7)
		return;
	int* a8 = (int*)malloc(sizeof(int) * ret);
	if (!a8)
		return;
	for (int i = 0; i < ret; i++)
	{
		a1[i] = rand() + i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}
	//int size = ret;
	int bubbleSort_begin = clock();
	//bubbleSort(a, ret);
	//sortPrint(a, size);
	int bubbleSort_end = clock();
	printf("BubbleSort:%dms\n", bubbleSort_end - bubbleSort_begin);

	int InsertSort_begin = clock();
	//InsertSort(a1, ret);
	int InsertSort_end = clock();
	printf("InsertSort:%dms\n", InsertSort_end - InsertSort_begin);

	int ShellSort_begin = clock();
	ShellSort(a2, ret);
	int ShellSort_end = clock();
	printf("ShellSort:%dms\n", ShellSort_end - ShellSort_begin);

	int SelectSort_begin = clock();
	//SelectSort(a, ret);
	int SelectSort_end = clock();
	printf("SelectSort:%dms\n", SelectSort_end - SelectSort_begin);

	int QuickSort_begin = clock();
	QuickSort(a3, 0, ret-1);
	int QuickSort_end = clock();
	printf("QuickSort:%dms\n", QuickSort_end - QuickSort_begin);

	int QuickSortNonR_begin = clock();
	QuickSortNonR(a5, 0, ret - 1);
	int QuickSortNonR_end = clock();
	printf("QuickSortNonR:%dms\n", QuickSortNonR_end - QuickSortNonR_begin);

	int HeapSort_begin = clock();
	HeapSort(a4, ret);
	int HeapSort_end = clock();
	printf("HeapSort:%dms\n", HeapSort_end - HeapSort_begin);

	int MergeSort_begin = clock();
	MergeSort(a8, ret);
	int MergeSort_end = clock();
	printf("MergeSort:%dms\n", MergeSort_end - MergeSort_begin);

	//ÊÍ·ÅÊý×é
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	a1 = NULL;
	a2 = NULL;
	a3 = NULL;
	a4 = NULL;
	a5 = NULL;
	a6 = NULL;
	a7 = NULL;
}


void testSort()
{
	int Bubble_arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int size = sizeof(Bubble_arr) / sizeof(Bubble_arr[0]);
	printf("Ã°ÅÝÅÅÐò:");
	bubbleSort(Bubble_arr, 10);
	sortPrint(Bubble_arr, 10);

	int Insert_arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	printf("²åÈëÅÅÐò:");
	InsertSort(Insert_arr, 10);
	sortPrint(Insert_arr, 10);

	int ShellSort_arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	printf("Ï£¶ûÅÅÐò:");
	ShellSort(ShellSort_arr, 10);
	sortPrint(ShellSort_arr, 10);

	int SelectSort_arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	printf("Ñ¡ÔñÅÅÐò:");
	SelectSort(SelectSort_arr, 10);
	sortPrint(SelectSort_arr, 10);
}

void test_select()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(a) / sizeof(a[0]);
	SelectSort(a, size);
	sortPrint(a, size);
}

void test_quick()
{
	int a[] = { 6,1,2,7,9,3,4,5,8,10 };
	int size = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, size - 1);
	sortPrint(a, size);
}

void test_heap()
{
	int a[] = { 6,1,2,7,9,3,4,5,8,10 };
	int size = sizeof(a) / sizeof(a[0]);
	HeapSort(a, size);
	sortPrint(a, size);
}

void test_stack()
{
	ST s1;
	StackInit(&s1);
	StackPush(&s1, 1);
	StackPush(&s1, 2);
	StackPush(&s1, 3);
	StackPush(&s1, 4);
	StackPush(&s1, 5);

	StackPop(&s1);
	StackPop(&s1);
	StackPop(&s1);
	StackPop(&s1);
	//StackPop(&s1);

	//printf("top:%d\n", StackTop(&s1));
	printf("isEmpty:%d\n", StackEmpty(&s1));
	for (int i = 0; i < s1.top; i++)
	{
		printf("%d ", s1.a[i]);
	}
	printf("\n");

	StackDestroy(&s1);
}

void test_quicknonR()
{
	int a[] = { 6,1,2,7,9,3,4,5,8,10 };
	int size = sizeof(a) / sizeof(a[0]);
	QuickSortNonR(a, 0, size - 1);
	sortPrint(a, size);
}

void test_merge()
{
	int a[] = { 6,1,2,7,9,3,4,5,8,10 };
	int size = sizeof(a) / sizeof(a[0]);
	MergeSort(a, size);
	sortPrint(a, size);
}

int main()
{
	testTime();
	//testSort();
	//test_select();
	//test_quick();
	//test_heap();
	//test_stack();
	//test_quicknonR();
	//test_merge();
	return 0;
}