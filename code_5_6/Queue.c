#define _CRT_SECURE_NO_WARNINGS 1


#include "Queue.h"


//初始化及释放
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(del);

		//局部变量 即使不置空也不会被访问
		//del = NULL;
	}
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//队列插入删除
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QNode* del = pq->head;
	pq->head = pq->head->next;
	free(del);

	if (pq->head == NULL)
		pq->tail = NULL;

	pq->size--;
}

//取出队头队尾的元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

//判断队列的状态（为空\大小）
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);

	/*QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;*/

	return pq->size;
}

//void QueuePrint(Queue* pq)
//{
//	assert(pq);
//	
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}