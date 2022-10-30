#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

//����˳���--��̬
typedef struct SeqList
{
	SLDataType* data;
	SLDataType sz; //��Ч���ݸ���
	SLDataType capacity; //����
}SL;

//��ʼ��
void SeqListInit(SL* ps);
//����˳���
void SLDestroy(SL* ps);

//β��
void SLPushBack(SL* ps, SLDataType x);
//βɾ
void SLPopBack(SL* ps);

//ͷ��
void SLPushFront(SL* ps, SLDataType x);
//ͷɾ
void SLPopFront(SL* ps);

//����
void SLInsert(SL* ps, SLDataType x, SLDataType pos);
//ɾ��
void SLErase(SL* ps, SLDataType pos);

//˳���Ĵ�ӡ
void SLPrint(const SL* ps);