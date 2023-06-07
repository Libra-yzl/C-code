#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>



void Print(int* a, int sz);
void AdjustDown(int* a, int sz, int parent);

//��������
void InsertSort(int* a, int sz);
void ShellSort(int* a, int sz);

//ѡ������
void SelectSort(int* a, int sz);
void HeapSort(int* a, int sz);

//��������
void BubbleSort(int* a, int sz);

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int beign, int end);
// ���������ڿӷ�
int PartSort2(int* a, int begin, int end);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end);
void QuickSort(int* a, int begin, int end);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int begin, int end);

void MergeSort(int* a, int begin, int end);
void MergeSortNonR(int* a, int sz);

//��������
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