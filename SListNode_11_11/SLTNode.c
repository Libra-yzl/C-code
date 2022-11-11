#define _CRT_SECURE_NO_WARNINGS 1

#include "SLTNode.h"


SLTNode* BuyNewNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("BuyNewNode::malloc");
		exit(-1);//Òì³£ÖÕÖ¹
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	return newnode;
}

SLTNode* CreateNewNode(SLTDataType n)
{
	SLTNode* phead = NULL;
	SLTNode* ptail = NULL;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		SLTNode* newnode = BuyNewNode(i);
		if (phead == NULL)
		{
			phead = newnode;
			ptail = newnode;
		}
		else
		{
			ptail->next = newnode;
			ptail = newnode;
		}
	}
	return phead;
}

void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void SLTPushBack(SLTNode** phead, SLTDataType x)
{
	SLTNode* newnode = BuyNewNode(x);
	SLTNode* tmp_phead = *phead;
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		while (tmp_phead->next)
		{
			tmp_phead = tmp_phead->next;
		}
		tmp_phead->next = newnode;
		tmp_phead = newnode;
	}
}

void SLTPopBack(SLTNode** phead)
{
	assert(*phead);
	SLTNode* tmp_phead = *phead;
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		while (tmp_phead->next->next)
		{
			tmp_phead = tmp_phead->next;
		}
		free(tmp_phead->next);
		tmp_phead->next = NULL;
	}
	/*else
	{
		SLTNode* cur = *phead;
		while (cur->next)
		{
			tmp_phead = cur;
			cur = cur->next;
		}
		free(tmp_phead->next);
		tmp_phead->next = NULL;
	}*/
}

void SLTPushFront(SLTNode** phead, SLTDataType x)
{
	SLTNode* tmp = *phead;
	*phead = BuyNewNode(x);
	(*phead)->next = tmp;
}

void SLTPopFront(SLTNode** phead)
{
	assert(*phead);

	SLTNode* next = (*phead)->next;
	free(*phead);
	*phead = next;
}