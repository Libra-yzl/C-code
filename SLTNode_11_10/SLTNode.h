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

//����һ���ṹ��
SLTNode* BuyNewNode(SLTtype x);
//����������
SLTNode* CreateNewNode(SLTtype n);//n��Ԫ������

//��ӡ����
void SLTPrint(SLTNode* phead);

//β��
void SLTPushBack(SLTNode** phead, SLTtype x);
//βɾ
void SLTPopBack(SLTNode** phead);

//ͷ��
void SLTPushFront(SLTNode** phead, SLTtype x);
//ͷɾ
void SLTPopFront(SLTNode** phead);