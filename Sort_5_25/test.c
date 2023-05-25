#define _CRT_SECURE_NO_WARNINGS 1


#include "sort.h"

void testTime()
{
	srand((unsigned)time(NULL));
	int ret = 10000000;
	int* a = (int*)malloc(sizeof(int) * ret);
	if (!a)
		return;
	for (int i = 0; i < ret; i++)
	{
		a[i] = rand() + i;
	}
	//int size = ret;
	int bubbleSort_begin = clock();
	//bubbleSort(a, ret);
	//sortPrint(a, size);
	int bubbleSort_end = clock();
	printf("BubbleSort:%dms\n", bubbleSort_end - bubbleSort_begin);

	int InsertSort_begin = clock();
	//InsertSort(a, ret);
	int InsertSort_end = clock();
	printf("InsertSort:%dms\n", InsertSort_end - InsertSort_begin);

	int ShellSort_begin = clock();
	//ShellSort(a, ret);
	int ShellSort_end = clock();
	printf("ShellSort:%dms\n", ShellSort_end - ShellSort_begin);

	int SelectSort_begin = clock();
	//SelectSort(a, ret);
	int SelectSort_end = clock();
	printf("SelectSort:%dms\n", SelectSort_end - SelectSort_begin);

	int QuickSort_begin = clock();
	QuickSort(a, 0, ret-1);
	int QuickSort_end = clock();
	printf("QuickSort:%dms\n", QuickSort_end - QuickSort_begin);

	int HeapSort_begin = clock();
	//HeapSort(a, ret);
	int HeapSort_end = clock();
	printf("HeapSort:%dms\n", HeapSort_end - HeapSort_begin);

	//ÊÍ·ÅÊý×é
	free(a);
	a = NULL;
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

int main()
{
	testTime();
	//testSort();
	//test_select();
	//test_quick();
	//test_heap();
	return 0;
}