#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);

void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);

bool HeapEmpty(const HP* php);
int HeapSize(const HP* php);

void HeapPrint(const HP* php);

void HeapCreate(HP* php, HPDataType* a, int n);

//实现向上调整/向下调整
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);