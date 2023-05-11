#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>



typedef int HPDataType;

struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
};

void HeapPrint(const struct Heap* php);
void HeapInit(struct Heap* php);
void HeapDestroy(struct Heap* php);

void HeapPush(struct Heap* php, HPDataType x);
void HeapPop(struct Heap* php);
HPDataType HeapTop(struct Heap* php);

int HeapSize(const struct Heap* php);
bool HeapEmpty(const struct Heap* php);

void HeapCreate(struct Heap* php, HPDataType* a, int n);
void HeapSort(struct Heap* php);