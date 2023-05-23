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
	bubbleSort(a, ret);
	//sortPrint(a, size);
	int bubbleSort_end = clock();
	printf("BubbleSort:%dms\n", bubbleSort_end - bubbleSort_begin);

	int InsertSort_begin = clock();
	InsertSort(a, ret);
	int InsertSort_end = clock();
	printf("InsertSort:%dms\n", InsertSort_end - InsertSort_begin);

	int ShellSort_begin = clock();
	ShellSort(a, ret);
	int ShellSort_end = clock();
	printf("ShellSort:%dms\n", ShellSort_end - ShellSort_begin);

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
}

int main()
{
	testTime();
	//testSort();
	return 0;
}