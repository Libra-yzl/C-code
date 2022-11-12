#define _CRT_SECURE_NO_WARNINGS 1

#include "func.h"

void CheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->sz == ps->capacity)
	{
		//��������������
		SLDataType NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->data, NewCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("CheckCapacity::realloc");
			return;
		}
		ps->data = tmp;
		ps->capacity = NewCapacity;
	}
}

void SLInit(SL* ps)
{
	assert(ps);
	//����Ƿ�Ϊ��

	ps->data = NULL;
	ps->capacity = 0;
	ps->sz = 0;
}

void SLDestroy(SL* ps)
{
	free(ps->data);
	ps->capacity = 0;
	ps->sz = 0;
}

void SLPushBack(SL* ps, SLDataType x)
{
	//����Ƿ�Ϊ��ָ��
	assert(ps);

	//��ʼβ�壬�ȼ������
	CheckCapacity(ps);
	ps->data[ps->sz] = x; //���±�Ϊsz��λ�ò������ݣ���֤������Ч�洢
	ps->sz++;
}

void SLPrint(const SL* ps)
{
	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void SLPopBack(SL* ps)
{
	//βɾ֮ǰ�ȼ���Ƿ�Ϊ��
	assert(ps);

	////����ļ��
	////���˳������Ƿ������� 
	//if (ps->sz == 0)
	//{
	//	printf("˳���Ϊ�գ����ܽ���ɾ������\n");
	//	return;
	//}
	//�����ļ��
	assert(ps->sz);

	//ps->data[ps->sz] = 0; //û�б�Ҫ��sz�����˳����е���Ч����
	ps->sz--;
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	
	//�������
	CheckCapacity(ps);
	//��˳����е�Ԫ�����������
	//memmove(ps->data + sizeof(SLDataType), ps->data, sizeof(ps->sz) * ps->sz);

	//��˳����е�Ԫ�����������
	for (int i = ps->sz - 1; i >= 0; i--)
	{
		ps->data[i + 1] = ps->data[i];
	}
	ps->data[0] = x;
	ps->sz++;
}

void PopFront(SL* ps)
{
	assert(ps);

	//ͬ���أ��ȼ��˳������Ƿ���Ԫ��
	//�������
	assert(ps->sz > 0);

	//��˳����еĴ��±�Ϊ1��λ�ÿ�ʼ��ǰ�ƶ�
	for (int i = 0; i < ps->sz; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}

void SLInsert(SL* ps, SLDataType pos, SLDataType x)
{
	assert(ps);

	//���pos�Ƿ���Ч
	assert(pos <= ps->sz && pos >= 0);

	CheckCapacity(ps);
	int end = ps->sz - 1;
	//�����±�Ϊpos+1λ�ÿ�ʼ��Ԫ������ƶ�
	while (end > pos)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[pos] = x;
	ps->sz++;
}

void SLErase(SL* ps, SLDataType pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->sz);

	//�Ѵ��±�Ϊpos+1֮���Ԫ����ǰ�ƶ�
	for (int i = pos; i < ps->sz; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}

//void SLTNodeInit(SLTNode* ps)
//{
//	ps->data = 0;
//	ps->next = NULL;
//}

SLTNode* BuySLTNode(SLDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("BuySLTNode::malloc");
		exit(-1); //�쳣��ֹ
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

SLTNode* CreateNewNode(SLDataType n)
{
	SLTNode* phead = NULL;
	SLTNode* ptail = NULL;
	for (int i = 0; i < n; i++)
	{
		SLTNode* newnode = BuySLTNode(i);
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

void SLTPushBack(SLTNode** phead, SLDataType x)
{
	if (*phead == NULL)
	{
		*phead = BuySLTNode(x);
	}
	else
	{
		SLTNode* newnode = BuySLTNode(x);
		SLTNode* ptail = *phead;
		//��β
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
		ptail = newnode;
	}
}

void SLTPopBack(SLTNode** phead)
{
	assert(*phead);

	SLTNode* ptail = *phead;

	if ((*phead)->next == NULL)
	{
		//ֱ���ͷ�
		free(*phead);
		*phead = NULL;
	}
	else
	{
		while (ptail->next->next)
		{
			ptail = ptail->next;
		}
		free(ptail->next);
		ptail->next = NULL;
	}
}

void SLTPrint(const SLTNode* phead)
{
	const SLTNode* ptail = phead;
	while (ptail)
	{
		printf("%d->", ptail->data);
		ptail = ptail->next;
	}
	printf("\n");
}

void SLTPushFront(SLTNode** phead, SLDataType x)
{
	SLTNode* ptail = *phead;
	*phead = BuySLTNode(x);
	(*phead)->next = ptail;
}

void SLTPopFront(SLTNode** phead)
{
	assert(*phead);

	SLTNode* next = (*phead)->next;
	free(*phead);
	*phead = next;
}