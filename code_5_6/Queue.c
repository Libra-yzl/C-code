#define _CRT_SECURE_NO_WARNINGS 1


#include "Queue.h"


//��ʼ�����ͷ�
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

		//�ֲ����� ��ʹ���ÿ�Ҳ���ᱻ����
		//del = NULL;
	}
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//���в���ɾ��
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

//ȡ����ͷ��β��Ԫ��
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

//�ж϶��е�״̬��Ϊ��\��С��
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