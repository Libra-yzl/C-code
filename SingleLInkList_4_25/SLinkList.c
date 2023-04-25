#define _CRT_SECURE_NO_WARNINGS 1

#include "SLinkList.h"


SLT* BuySLTNode(SLTDataType n)
{
	SLT* newnode = (SLT*)malloc(sizeof(SLT));
	if (!newnode)
	{
		perror("BuySLTNode::");
		exit(-1);
	}
	newnode->data = n;
	newnode->next = NULL;

	return newnode;
}

SLT* CreateSLT(int n)
{
	SLT* phead = NULL;
	SLT* ptail = phead;

	int x = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		SLT* newnode = BuySLTNode(x);
		if (phead == NULL)
		{
			ptail = phead = newnode;
			//phead->next = NULL;
		}
		else
		{
			ptail->next = newnode;
			ptail = newnode;
		}
	}
	return phead;
}

void PushBack(SLT** pphead, SLTDataType x)
{
	SLT* newnode = BuySLTNode(x);
	if (!*pphead)
	{
		*pphead = newnode;
		(*pphead)->next = NULL;
	}
	else
	{
		SLT* ptail = *pphead;
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

void PopBack(SLT** pphead)
{
	assert(*pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead= NULL;
	}
	else
	{
		SLT* ptail = *pphead;

		while (ptail->next->next)
		{
			ptail = ptail->next;
		}

		free(ptail->next);
		ptail->next = NULL;

		/*SLT* prev = NULL;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		prev->next = NULL;*/
	}
}

void Print(const SLT* phead)
{
	const SLT* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void PushFront(SLT** pphead, SLTDataType x)
{
	SLT* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void PopFront(SLT** pphead)
{
	assert(*pphead);

	SLT* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}


SLT* SLTFind(SLT* phead, SLTDataType x)
{
	SLT* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void InsertAfter(SLT* pos, SLTDataType x)
{
	SLT* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void EraseAfter(SLT* pos)
{
	assert(pos);
	if (!(pos->next))
	{
		return;
	}
	else
	{
		SLT* nextNode = pos->next;
		pos->next = pos->next->next;
		free(nextNode);
	}
}

void Insert(SLT** pphead, SLT* pos, SLTDataType x)
{
	assert(pos);

	SLT* newnode = BuySLTNode(x);
	if (*pphead == pos)
	{
		PushFront(pphead, x);
	}
	else
	{
		SLT* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		newnode->next = pos;
	}
}

void Erase(SLT** pphead, SLT* pos)
{
	assert(pos);
	assert(*pphead);

	if (pos == *pphead)
	{
		PopFront(pphead);
	}
	else
	{
		SLT* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}

void SLTDestroy(SLT** pphead)
{
	SLT* cur = *pphead;
	while (cur)
	{
		SLT* nextNode = cur->next;
		free(cur);
		cur = nextNode;
	}
	*pphead = NULL;
}