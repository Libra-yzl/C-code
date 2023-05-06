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


//声明
//初始化及释放
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//队列插入删除
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

//取出队头队尾的元素
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//判断队列的状态（为空\大小）
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
