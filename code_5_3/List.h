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
//��posǰ����
void LTInsert(LTNode* pos, LTDataType x);
//ɾ��posλ��
void LTErase(LTNode* pos);

void LTPrint(LTNode* phead);
void LTDestroy(LTNode* phead);

//�ж������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead);
//�ж������С
size_t LTSize(LTNode* phead);