#define _CRT_SECURE_NO_WARNINGS 1

//#include "Heap.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>


//void TestHeap1()
//{
//	int arr[] = { 12,58,65,42,56,34,26,18,48,55 };
//	struct Heap hp;
//	HeapInit(&hp);
//
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		HeapPush(&hp, arr[i]);
//	}
//	HeapPrint(&hp);
//
//	int k = 10;
//	while (k--)
//	{
//		HeapPop(&hp);
//	}
//	HeapPrint(&hp);
//
//	HeapDestroy(&hp);
//}
//
//void TestHeap2()
//{
//	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
//	struct Heap hp;
//
//	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]));
//	HeapPrint(&hp);
//
//	HeapSort(&hp);
//	HeapPrint(&hp);
//
//	HeapDestroy(&hp);
//}


void TestHeap3()
{
	srand((unsigned)time(NULL));
	while (1)
	{
		int ret = rand()%100000+1;
		printf("%d\n", ret);
		Sleep(1000);
	}
}

int main()
{
	//TestHeap1();

	//TestHeap2();

	TestHeap3();
	return 0;
}