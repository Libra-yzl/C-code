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

//��pos֮�����x
void InsertAfter(SLT* pos, SLTDataType x);
//ɾ��pos֮�������
void EraseAfter(SLT* pos);

//��posλ�ò���x
void Insert(SLT** pphead, SLT* pos, SLTDataType x);
//��posλ��ɾ��x
void Erase(SLT** pphead, SLT* pos);

//��������
void SLTDestroy(SLT** pphead);