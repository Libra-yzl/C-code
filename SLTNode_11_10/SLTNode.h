#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTtype;

typedef struct SListNode
{
	SLTtype data;
	struct SListNode* next;
}SLTNode;

//创建一个结构体
SLTNode* BuyNewNode(SLTtype x);
//创建单链表
SLTNode* CreateNewNode(SLTtype n);//n是元素数量

//打印链表
void SLTPrint(SLTNode* phead);

//尾插
void SLTPushBack(SLTNode** phead, SLTtype x);
//尾删
void SLTPopBack(SLTNode** phead);

//头插
void SLTPushFront(SLTNode** phead, SLTtype x);
//头删
void SLTPopFront(SLTNode** phead);