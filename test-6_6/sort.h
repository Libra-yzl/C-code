#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>



void Print(int* a, int sz);
void AdjustDown(int* a, int sz, int parent);

//插入排序
void InsertSort(int* a, int sz);
void ShellSort(int* a, int sz);

//选择排序
void SelectSort(int* a, int sz);
void HeapSort(int* a, int sz);

//交换排序
void BubbleSort(int* a, int sz);

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int beign, int end);
// 快速排序挖坑法
int PartSort2(int* a, int begin, int end);
// 快速排序前后指针法
int PartSort3(int* a, int begin, int end);
void QuickSort(int* a, int begin, int end);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int begin, int end);

void MergeSort(int* a, int begin, int end);
void MergeSortNonR(int* a, int sz);

//计数排序
void CountSort(int* a, int sz);

typedef struct Stack
{
	int* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps, int x);
void StackPop(Stack* ps);

int StackTop(Stack* ps);
bool StackEmpty(Stack* ps);
int StackSize(Stack* ps);