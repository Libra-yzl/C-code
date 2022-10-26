#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


////���徲̬˳��� -- ���Ǻ�ʵ��
//#define MAX 100
//
////�����ض���
//typedef int SLDataType;
//
//struct SeqList
//{
//	SLDataType data[MAX];
//	size_t size;  //��Ч�����ݸ���
//};
//

//���嶯̬˳��� -- �����û���Ҫ����

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* data;
	size_t size; //��Ч���ݵĸ���
	size_t capacity; //����
}SL;


//��ʼ��˳���
void SLInit(SL* ps);

//����˳���
void SLDestroy(SL* ps);

//�������� β��βɾ
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

//��ӡ˳���
void SLPrint(SL* ps);