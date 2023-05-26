#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>


//ջ
typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);

void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);

bool StackEmpty(ST* ps);
int StackSize(ST* ps);


void sortPrint(int* a, int size);


//��������
void InsertSort(int* a, int size);
void ShellSort(int* a, int size);

//ѡ������
void SelectSort(int* a, int size);
void HeapSort(int* a, int size);

//��������
void bubbleSort(int* a, int size);
void QuickSort(int* a, int begin, int end);
void QuickSortNonR(int* a, int begin, int end);