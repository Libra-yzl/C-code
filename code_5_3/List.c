#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

LTNode* BuyLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (!newnode)
	{
		perror("BuyLTNode::malloc");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

LTNode* InitLTNode()
{
	LTNode* phead = BuyLTNode(-1);

	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void PushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	/*LTNode* newnode = BuyLTNode(x);

	LTNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;*/

	LTInsert(phead, x);
}

void PopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* tail = phead->prev;

	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);
}

void PushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	/*LTNode* newnode = BuyLTNode(x);

	newnode->next = phead->next;
	phead->next->prev = newnode;

	phead->next = newnode;
	newnode->prev = phead;*/

	LTInsert(phead->next, x);
}

void PopFront(LTNode* phead)
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

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* newnode = BuyLTNode(x);

	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	pos->prev = newnode;
	newnode->next = pos;
}

void LTErase(LTNode* pos)
{
	assert(pos);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

void LTDestroy(LTNode* phead)
{
	LTNode* cur = phead->next;

	while (cur != phead)
	{
		LTNode* node = cur->next;
		free(cur);
		cur = node;
	}

	free(phead);
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);

	//方法一：
	/*if (phead->next == phead)
		return true;
	else
		return false;*/

	//方法二：
	return phead->next == phead;
}

size_t LTSize(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	size_t count = 0;
	while (cur != phead)
	{
		count++;
		cur = cur->next;
	}
	return count;
}