#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef int SLTDataType;

typedef struct SingLinkList
{
	SLTDataType data;
	struct SingLinkList* next;
}SLT;

SLT* BuySLTNode(SLTDataType n);

SLT* CreateSLT(int n);

void Print(const SLT* phead);

void PushBack(SLT** pphead, SLTDataType x);
void PopBack(SLT** pphead);

void PushFront(SLT** pphead, SLTDataType x);
void PopFront(SLT** pphead);

SLT* SLTFind(SLT* phead, SLTDataType x);

//在pos之后插入x
void InsertAfter(SLT* pos, SLTDataType x);
//删除pos之后的数据
void EraseAfter(SLT* pos);

//在pos位置插入x
void Insert(SLT** pphead, SLT* pos, SLTDataType x);
//在pos位置删除x
void Erase(SLT** pphead, SLT* pos);

//销毁链表
void SLTDestroy(SLT** pphead);