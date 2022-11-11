#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuyNewNode(SLTDataType x);

SLTNode* CreateNewNode(SLTDataType n);

void SLTPrint(SLTNode* phead);

void SLTPushBack(SLTNode** phead, SLTDataType x);
void SLTPopBack(SLTNode** phead);

void SLTPushFront(SLTNode** phead, SLTDataType x);
void SLTPopFront(SLTNode** phead);