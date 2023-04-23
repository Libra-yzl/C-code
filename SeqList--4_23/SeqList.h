#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



////��̬˳���
//#define N 10
//
//typedef int SLDataType;
//
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size; //��¼�洢���ٸ���Ч����
//}SL;
//
//void SLInit(SL s);
//void SLPushBack(SL s, SLDataType x);


//
//��̬˳���

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size; //��¼�洢���ٸ���Ч����
	int capacity; //�ռ�������С
}SL;


//��ʼ��
void SLInit(SL* s);
//����
void SLDestroy(SL* ps);

SLPrint(const SL* ps);

//β��
void SLPushBack(SL* ps, SLDataType x);
//βɾ
void SLPopBack(SL* ps);

//ָ��λ�ò���
void SLInsert(SL* ps, int pos, SLDataType x);
//ָ��λ��ɾ��
void SLDelete(SL* ps, int pos);