#define _CRT_SECURE_NO_WARNINGS 1

#include "SLTNode.h"

SLTNode* BuyNewNode(SLTtype x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("BuyNewNode::malloc");
		exit(-1); //�쳣��ֹ
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

SLTNode* CreateNewNode(SLTtype n)
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
	//ptail->next = NULL;//û�б�Ҫ����BuyNewNode�д�����ͬʱ�Ѿ���ΪNULL

	return phead;
}

void SLTPrint(SLTNode* phead)
{
	SLTNode* tmp = phead;
	while (tmp)
	{
		//printf("[%d|%p]->", tmp->data, tmp->next);
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void SLTPushBack(SLTNode** pphead, SLTtype x)//Ҫ�ı�ͷָ�룬��Ҫ����ַ��Ȼ����в����������βα仯����Ӱ��ʵ��
{
	SLTNode* ptail = *pphead;
	if (*pphead == NULL)
	{
		*pphead = BuyNewNode(x);
	}
	else
	{
		SLTNode* newnode = BuyNewNode(x);
		while (ptail->next) //��β
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
		ptail = newnode;
	}
}

void SLTPopBack(SLTNode** phead)
{
	assert(*phead);//���������ٽ���ɾ������
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SLTNode* ptail = *phead;
		//while (ptail->next->next)//��β
		//{
		//	ptail = ptail->next;
		//}
		//free(ptail->next);
		//ptail->next = NULL;
		SLTNode* cur = *phead;
		while (cur->next)
		{
			ptail = cur;
			cur = cur->next;
		}
		free(ptail->next);
		ptail->next = NULL;
	}
}

void SLTPushFront(SLTNode** phead, SLTtype x)
{
	SLTNode* newnode = BuyNewNode(x);
	newnode->next = *phead;
	*phead = newnode;
}

void SLTPopFront(SLTNode** phead)
{
	assert(*phead);
	SLTNode* next = (*phead)->next;
	free(*phead);
	*phead = next;
}