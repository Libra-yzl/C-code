#define _CRT_SECURE_NO_WARNINGS 1


#include "review.h"

//void SLInit(SL* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
//
//void SLDestroy(SL* ps)
//{
//	assert(ps);
//
//	free(ps->a);
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
//
//void SLPushBack(SL* ps, SLTDataType x)
//{
//	assert(ps);
//
//	//检查扩容
//	if (ps->capacity == ps->size)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SLTDataType* tmp = (SLTDataType*)realloc(ps->a, newCapacity * sizeof(SLTDataType));
//		if (!tmp)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//	//插入数据
//	ps->a[ps->size] = x;
//	ps->size++;
//
//}
//void SLPopBack(SL* ps)
//{
//	assert(ps);
//	assert(ps->size > 0);
//
//	//删除
//	ps->size--;
//}
//
//void SLPushFront(SL* ps, SLTDataType x)
//{
//	assert(ps);
//
//	//检查扩容
//	if (ps->capacity == ps->size)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SLTDataType* tmp = (SLTDataType*)realloc(ps->a, newCapacity * sizeof(SLTDataType));
//		if (!tmp)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//		ps->capacity = newCapacity;
//		ps->a = tmp;
//	}
//	//插入数据
//	memmove(ps->a + 1, ps->a, sizeof(SLTDataType) * ps->size);
//	ps->a[0] = x;
//	ps->size++;
//}
//void SLPopFront(SL* ps)
//{
//	assert(ps);
//	assert(ps->size > 0);
//
//	//删除
//	memmove(ps->a, ps->a + 1, (ps->size - 1) * sizeof(SLTDataType));
//	ps->size--;
//}
//
////中间位置插入删除
////在pos位置插入
//void SLInsert(SL* ps, int pos, SLTDataType x)
//{
//	assert(ps);
//	assert(pos <= ps->size);
//
//	//扩容
//	if (ps->capacity == ps->size)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SLTDataType* tmp = (SLTDataType*)realloc(ps->a, newCapacity * sizeof(SLTDataType));
//		if (!tmp)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//		ps->capacity = newCapacity;
//		ps->a = tmp;
//	}
//	//插入数据
//	memmove(ps->a + pos + 1, ps->a + pos, (ps->size - pos) * sizeof(SLTDataType));
//	ps->a[pos] = x;
//	ps->size++;
//}
//
////删除pos位置数据
//void SLErase(SL* ps, int pos)
//{
//	assert(ps);
//	assert(ps->size > 0);
//	assert(pos < ps->size);
//
//	//删除
//	memmove(ps->a + pos, ps->a + pos + 1, sizeof(SLTDataType) * (ps->size - pos - 1));
//	ps->size--;
//}
//
//int SLFind(SL* ps, SLTDataType x, int begin)
//{
//	assert(ps);
//
//	for (int i = begin; i < ps->size; i++)
//	{
//		if (ps->a[i] == x)
//			return i;
//	}
//	return -1;
//}
//
//void SLPrint(const SL* ps)
//{
//	for (int i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//}


////链表
//SLTNode* BuySLTNode(SLTDataType x)
//{
//	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
//	if (!newnode)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//	return newnode;
//}
//SLTNode* CreateSList(int n)
//{
//	SLTNode* phead = NULL, * ptail = NULL;
//	int x = 0;
//	for (int i = 0; i < n; i++)
//	{
//		SLTNode* newnode = BuySLTNode(i);
//		if (phead == NULL)
//		{
//			phead = ptail = newnode;
//		}
//		else
//		{
//			ptail->next = newnode;
//			ptail = newnode;
//		}
//	}
//	return phead;
//}
//
//void SLTDestroy(SLTNode** pphead)
//{
//	SLTNode* cur = *pphead;
//	while (cur)
//	{
//		SLTNode* node = cur->next;
//		free(cur);
//		cur = node;
//	}
//}
//
//void SLTPrint(SLTNode* phead)
//{
//	SLTNode* cur = phead;
//	while (cur)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//}
//
//void SLTPushBack(SLTNode** pphead, SLTDataType x)
//{
//	SLTNode* newnode = BuySLTNode(x);
//	if (*pphead == NULL)
//	{
//		*pphead = newnode;
//	}
//	else
//	{
//		SLTNode* tail = *pphead;
//		//找尾
//		while (tail->next)
//		{
//			tail = tail->next;
//		}
//		tail->next = newnode;
//		//tail = newnode;
//	}
//}
//void SLTPopBack(SLTNode** pphead)
//{
//	assert(*pphead);
//
//	if ((*pphead)->next == NULL)
//	{
//		free(*pphead);
//		*pphead = NULL;
//	}
//	else
//	{
//		SLTNode* tail = *pphead;
//		while (tail->next->next)
//		{
//			tail = tail->next;
//		}
//		free(tail->next);
//		tail->next = NULL;
//	}
//}
//
//void SLTPushFront(SLTNode** pphead, SLTDataType x)
//{
//	/*SLTNode* newnode = BuySLTNode(x);
//	if (*pphead == NULL)
//	{
//		*pphead = newnode;
//	}
//	else
//	{
//		SLTNode* node = *pphead;
//		(*pphead) = newnode;
//		(*pphead)->next = node;
//	}*/
//
//	SLTNode* newnode = BuySLTNode(x);
//	newnode->next = *pphead;
//	*pphead = newnode;
//}
//void SLTPopFront(SLTNode** pphead)
//{
//	assert(*pphead);
//
//	SLTNode* node = (*pphead)->next;
//	free(*pphead);
//	*pphead = node;
//}
//
//SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
//{
//	SLTNode* cur = phead;
//	while (cur)
//	{
//		if (cur->data == x)
//			return cur;
//		cur = cur->next;
//	}
//	return NULL;
//}
//
//void SLTInsertAfter(SLTNode* pos, SLTDataType x)
//{
//	assert(pos);
//
//	SLTNode* newnode = BuySLTNode(x);
//	newnode->next = pos->next;
//	pos->next = newnode;
//}
//
//void SLTEraseAfter(SLTNode* pos)
//{
//	assert(pos);
//
//	SLTNode* node = pos->next;
//	pos->next = pos->next->next;
//	free(node);
//}
//
//void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
//{
//	assert(pos);
//
//	if (*pphead == pos)
//	{
//		SLTPushFront(pphead, x);
//	}
//	else
//	{
//		SLTNode* newnode = BuySLTNode(x);
//		SLTNode* cur = *pphead;
//		while (cur->next != pos)
//		{
//			cur = cur->next;
//		}
//		cur->next = newnode;
//		newnode->next = pos;
//	}
//}
//
//void SListErase(SLTNode** pphead, SLTNode* pos)
//{
//	assert(pos);
//	assert(*pphead);
//
//	if (*pphead == pos)
//	{
//		SLTPopFront(pphead);
//		/*SLTNode* node = (*pphead)->next;
//		free(*pphead);
//		*pphead = node;*/
//	}
//	else
//	{
//		SLTNode* cur = *pphead;
//		while (cur->next != pos)
//		{
//			cur = cur->next;
//		}
//		cur->next = pos->next;
//		free(pos);
//	}
//}


//双向链表

LTNode* BuyListNode(SLTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (!newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
LTNode* LTInit()
{
	//哨兵位头节点
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* node = phead->next;
		free(phead);
		phead = node;
	}
	free(phead);
}

void LTPushBack(LTNode* phead, SLTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);
	phead->prev->next = newnode;
	newnode->prev = phead->prev;
	phead->prev = newnode;
	newnode->next = phead;
}
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* node = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(node);
}

void LTPushFront(LTNode* phead, SLTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);
	phead->next->prev = newnode;
	newnode->next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
}
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* node = phead->next;
	phead->next = phead->next->next;
	phead->next->next->prev = phead;
	free(node);
}

void LTPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

LTNode* LTFind(LTNode* phead, SLTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void LTInsert(LTNode* pos, SLTDataType x)
{
	assert(pos);

	LTNode* newnode = BuyListNode(x);
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

bool Empty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

int LTSize(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	int size = 0;
	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}
	return size;
}