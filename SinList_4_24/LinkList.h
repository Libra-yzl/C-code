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


SLTNode* BuySLTNode(SLTDataType i);

SLTNode* CreateLList(int n);
void PrintLList(SLTNode* phead);

//β��βɾ
void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPopBack(SLTNode** pphead);

//ͷ��ͷɾ
void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLTPopFront(SLTNode** pphead);