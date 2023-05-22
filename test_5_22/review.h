#pragma once


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef int SLTDataType;

//typedef struct SLTNode
//{
//	SLTDataType* a;
//	int size; //��Ч���ݸ���
//	int capacity; //����
//}SL;
//
//
//void SLPrint(const SL* ps);
//void SLInit(SL* ps);
//void SLDestroy(SL* ps);
//
//void SLPushBack(SL* ps, SLTDataType x);
//void SLPopBack(SL* ps);
//
//void SLPushFront(SL* ps, SLTDataType x);
//void SLPopFront(SL* ps);
//
////�м�λ�ò���ɾ��
////��posλ�ò���
//void SLInsert(SL* ps, int pos, SLTDataType x);
////ɾ��posλ������
//void SLErase(SL* ps, int pos);
//
//int SLFind(SL* ps, SLTDataType x, int begin);


////����
//
//typedef struct SLTNode
//{
//	SLTDataType data;
//	struct SLTNode* next;
//}SLTNode;
//
//SLTNode* BuySLTNode(SLTDataType x);
//SLTNode* CreateSList(int n);
//void SLTPrint(SLTNode* phead);
//
//void SLTPushBack(SLTNode** pphead, SLTDataType x);
//void SLTPopBack(SLTNode** pphead);
//
//void SLTPushFront(SLTNode** pphead, SLTDataType x);
//void SLTPopFront(SLTNode** pphead);
//
//SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
//
//void SLTInsertAfter(SLTNode* pos, SLTDataType x);
//void SLTEraseAfter(SLTNode* pos);
//
//void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//void SListErase(SLTNode** pphead, SLTNode* pos);
//
//void SLTDestroy(SLTNode** pphead);


//˫���ͷѭ������
typedef struct ListNode
{
	SLTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

LTNode* BuyListNode(SLTDataType x);
LTNode* LTInit();
void LTDestroy(LTNode* phead);
void LTPrint(LTNode* phead);

void LTPushBack(LTNode* phead, SLTDataType x);
void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, SLTDataType x);
void LTPopFront(LTNode* phead);

LTNode* LTFind(LTNode* phead, SLTDataType x);

void LTInsert(LTNode* pos, SLTDataType x);
void LTErase(LTNode* pos);

bool Empty(LTNode* phead);
int LTSize(LTNode* phead);
