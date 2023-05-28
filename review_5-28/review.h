#pragma once


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType val;
	struct SListNode* next;
}SLTNode;

SLTNode* BuySLTNode(SLTDataType x);
SLTNode* CreateSLTNode(int n);
void SLTPrint(SLTNode* phead);
void SLTDestroy(SLTNode** pphead);

void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPopBack(SLTNode** pphead);

void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLTPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* plist, SLTDataType x);

void SListInsertAfter(SLTNode* pos, SLTDataType x);
void SListEraseAfter(SLTNode* pos);

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pos);

//双向带头循环链表
typedef int LTDataType;

typedef struct LTNode
{
	struct LTNode* next;
	struct LTNode* prev;
	LTDataType val;
}LTNode;

LTNode* LTBuyNode(LTDataType x);
LTNode* LTInit();

void LTPrint(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);

LTNode* LTFind(LTNode* phead, LTDataType x);

void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);

bool LTEmpty(LTNode* phead);
int LTSize(LTNode* phead);
void LTDestroy(LTNode* phead);

//栈
typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);

bool StackEmpty(Stack* ps);
int StackSize(Stack* ps);

//队列
typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

//堆
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HeapCreate(Heap* php, HPDataType* a, int n);

void HeapPrint(Heap* php);
void HeapInit(Heap* php);
void HeapDestroy(Heap* php);

void HeapPush(Heap* php, HPDataType x);

void HeapPop(Heap* php);

HPDataType HeapTop(Heap* php);

int HeapSize(Heap* php);

bool HeapEmpty(Heap* php);

void HeapSort(int* a, int size);