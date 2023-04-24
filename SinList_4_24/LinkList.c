#define _CRT_SECURE_NO_WARNINGS 1


#include "LinkList.h"

SLTNode* BuySLTNode(SLTDataType i)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode)
	{
		perror("BuySLTNode::");
		exit(-1);
	}
	newnode->data = i;
	newnode->next = NULL;
	return newnode;
}

SLTNode* CreateLList(int n)
{
	SLTNode* phead = NULL;
	SLTNode* ptail = NULL;
	while (n--)
	{
		int x = 0;
		scanf("%d", &x);
		SLTNode* newnode = BuySLTNode(x);
		if (phead == NULL)
		{
			phead = newnode;
			ptail = phead;
		}
		else
		{
			ptail->next = newnode;
			ptail = newnode;
		}
	}
	return phead;
}

void PrintLList(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	if (!*pphead)
	{
		*pphead = newnode;
		(*pphead)->next = NULL;
	}
	else
	{
		SLTNode* ptail = *pphead;
		//ÕÒÎ²
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		//²åÈë
		ptail->next = newnode;
		ptail = newnode;
	}
}

void SLTPopBack(SLTNode** pphead)
{
	assert(*pphead);

	if (!(*pphead)->next)
	{
		free(*pphead);
		*pphead= NULL;
	}
	else
	{
		//SLTNode* ptail = *pphead;
		//SLTNode* prev = NULL;
		////ÕÒÎ²
		//while (ptail->next)
		//{
		//	prev = ptail;
		//	ptail = ptail->next;
		//}
		//free(ptail);
		//prev->next = NULL;

		SLTNode* ptail = *pphead;
		while (ptail->next->next)
		{
			ptail = ptail->next;
		}
		//ÊÍ·Å
		free(ptail->next);
		ptail->next = NULL;
	}
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);

	/*SLTNode* head = (*pphead)->next;
	free(*pphead);
	*pphead = head;*/

	SLTNode* head = *pphead;
	*pphead = (*pphead)->next;
	free(head);
	//head->next = NULL;
}