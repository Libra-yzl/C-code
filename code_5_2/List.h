#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* BuyLTNode(LTDataType x);
LTNode* InitLTNode(LTNode* phead);

void PushBack(LTNode* phead, LTDataType x);
void PopBack(LTNode* phead);

void PushFront(LTNode* phead, LTDataType x);
void PopFront(LTNode* phead);