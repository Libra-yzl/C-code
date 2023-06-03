#define _CRT_SECURE_NO_WARNINGS 1


#include "Sort.h"


//int* f1()
//{
//	int* ptr = (int*)malloc(sizeof(int));
//	if (ptr == NULL)
//		return NULL;
//	*ptr = 10;
//	printf("%p\n", ptr);
//	return ptr;
//}
//
//int main()
//{
//	int* tmp = f1();
//	printf("%p\n", tmp);
//	char* str = "abcdef";
//	printf(str);
//	return 0;
//}

//int* f2()
//{
//	int* ptr = 500;
//	*ptr = 10;
//	return ptr;
//}
//
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test()
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}

void TestOP()
{
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	if (!a1)
		return;
	if (!a2)
		return; 
	if (!a3)
		return;
	if (!a4)
		return; 
	if (!a5)
		return;
	if (!a6)
		return; 
	if (!a7)
		return; 
	srand((unsigned)time(NULL));
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();

		/*int x = rand();
		if (x % 7 == 0 && x % 3 == 0 && x % 2 == 0)
		{
			a1[i] = x;
			j++;
		}
		else
			a1[i] = i;*/

		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}
	//printf("%d\n", j);

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	HeapSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	QuickSort(a4, 0, N - 1);
	int end4 = clock();

	int begin5 = clock();
	MergeSort(a5, N);
	int end5 = clock();


	printf("InsertSort:%dms\n", end1 - begin1);
	printf("ShellSort:%dms\n", end2 - begin2);
	printf("HeapSort:%dms\n", end3 - begin3);
	printf("QuickSort:%dms\n", end4 - begin4);
	printf("MergeSort:%dms\n", end5 - begin5);


	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	a1 = a2 = a3 = a4 = a5 = a6 = a7 = NULL;
}

void TestInsertSort()
{
	int a[] = { 9,1,2,8,4,5,6,10,7,3 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("InsertSort:\n");
	InsertSort(a, size);
	Print(a, size);
}

void TestShellSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,1,-1,5,4,4,-1,0,0,2 };
	//int a[] = { 9,1,2,8,4,5,6,10,7,3 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("ShellSort:\n");
	ShellSort(a, size);
	Print(a, size);
}

void TestHeapSort()
{
	int a[] = { 9,1,2,8,4,5,6,10,7,3 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("HeapSort:\n");
	HeapSort(a, size);
	Print(a, size);
}

void TestSelectSort()
{
	int a[] = { 9,1,2,8,4,5,6,10,7,3 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("SelectSort:\n");
	SelectSort(a, size);
	Print(a, size);
}

void TestBubbleSort()
{
	int a[] = { 9,1,2,8,4,5,6,10,7,3 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("BubbleSort:\n");
	BubbleSort(a, size);
	Print(a, size);
}

void TestQuickSort()
{
	//int a[] = { 9,1,2,8,4,5,6,10,7,3 };
	int a[] = { 2,2,2,2,2,2,2,2,3,4,3,3,2 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("QuickSort:\n");
	QuickSort(a, 0, size-1);
	Print(a, size);
}

void TestMergeSort()
{
	int a[] = { 9,1,2,8,4,5,6,10,7,3 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("MergeSort:\n");
	MergeSort(a, size);
	Print(a, size);
}

int main()
{
	//TestOP();
	//TestInsertSort();
	//TestShellSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestQuickSort();
	TestMergeSort();
	return 0;
}