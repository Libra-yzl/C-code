#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef int SLDataType;

typedef struct SqList
{
	SLDataType* data;
	SLDataType sz; //��Ч����
	SLDataType capacity; //����
}SL;

//��ʼ��˳���
void SLInit(SL* ps);

//����˳���
void SLDestroy(SL* ps);

//��ӡ˳���
void SLPrint(const SL* ps);

//β��
void SLPushBack(SL* ps, SLDataType x);
//βɾ
void SLPopBack(SL* ps);

//ͷ��
void SLPushFront(SL* ps, SLDataType x);
//ͷɾ
void PopFront(SL* ps);

//ָ��λ�ò���
void SLInsert(SL* ps, SLDataType pos, SLDataType x);//pos��ָ��Ҫ�������ݵ�λ�ã�x�ǲ��������

//ָ��λ��ɾ��
void SLErase(SL* ps, SLDataType pos);

//�������ʵ��

typedef struct SListTNode
{
	SLDataType data;
	struct SListTNode* next;
}SLTNode;

//���������Ԫ��
SLTNode* BuySLTNode(SLDataType x);
SLTNode* CreateNewNode(SLDataType n); //n������Ԫ�صĸ���

//void SLTNodeInit(SLTNode* ps);
void SLTPrint(const SLTNode* phead);

//β��
void SLTPushBack(SLTNode** phead, SLDataType x);
//βɾ
void SLTPopBack(SLTNode** phead);

//ͷ��
void SLTPushFront(SLTNode** phead, SLDataType x);
//ͷɾ
void SLTPopFront(SLTNode** phead);