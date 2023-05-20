#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>



typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;


//����
//��ʼ�����ͷ�
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//���в���ɾ��
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

//ȡ����ͷ��β��Ԫ��
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//�ж϶��е�״̬��Ϊ��\��С��
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
