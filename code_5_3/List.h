#pragma once


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

LTNode* BuyLTNode(LTDataType x);

LTNode* InitLTNode();

void PushBack(LTNode* phead, LTDataType x);
void PopBack(LTNode* phead);

void PushFront(LTNode* phead, LTDataType x);
void PopFront(LTNode* phead);

LTNode* LTFind(LTNode* phead, LTDataType x);
//在pos前插入
void LTInsert(LTNode* pos, LTDataType x);
//删除pos位置
void LTErase(LTNode* pos);

void LTPrint(LTNode* phead);
void LTDestroy(LTNode* phead);

//判断链表是否为空
bool LTEmpty(LTNode* phead);
//判断链表大小
size_t LTSize(LTNode* phead);