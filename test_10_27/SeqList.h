#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

//��̬˳���
typedef struct SeqList
{
	SLDataType* data;
	SLDataType sz;  //˳����е���Ч����
	SLDataType capacity; //˳��������
}SL;

//˳���ĳ�ʼ��
void SLInit(SL* ps);
//˳��������
void SLDestroy(SL* ps);
//˳���Ĵ�ӡ
void SLPrint(const SL* ps);

//β��
void SLPushBack(SL* ps, SLDataType x);

//βɾ
void SLPopBack(SL* ps);
