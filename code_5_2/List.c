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

LTNode* InitLTNode(LTNode* phead)
{
	assert(phead);

	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void PushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyLTNode(x);
	LTNode* tail = phead->prev;

	newnode->prev = tail;
	tail->next = newnode;

	newnode->next = phead;
	phead->prev = newnode;
}

void PopBack(LTNode* phead)
{
	assert(phead);

	LTNode* tail = phead->prev;

	tail->next = phead;
	phead->prev = tail->prev;
	free(tail);
}

void PushFront(LTNode* phead, LTDataType x)
{
	LTNode* newnode = BuyLTNode(x);
	
	newnode->next = phead->next;
	phead->next->prev = newnode;

	phead->next = newnode;
	newnode->prev = phead;
}

void PopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//еп╤он╙©у

	LTNode* nextnode = phead->next->next;
	phead->next->next->prev = phead;
	free(phead->next);
	phead->next = nextnode;
}