#define _CRT_SECURE_NO_WARNINGS 1

#include "func.h"

void CheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->sz == ps->capacity)
	{
		//容量已满，扩容
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
	//检查是否为空

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
	//检查是否为空指针
	assert(ps);

	//开始尾插，先检查容量
	CheckCapacity(ps);
	ps->data[ps->sz] = x; //在下标为sz的位置插入数据，保证数据有效存储
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
	//尾删之前先检查是否为空
	assert(ps);

	////温柔的检查
	////检查顺序表中是否还有数据 
	//if (ps->sz == 0)
	//{
	//	printf("顺序表为空，不能进行删除操作\n");
	//	return;
	//}
	//暴力的检查
	assert(ps->sz);

	//ps->data[ps->sz] = 0; //没有必要，sz会控制顺序表中的有效个数
	ps->sz--;
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	
	//检查容量
	CheckCapacity(ps);
	//将顺序表中的元素整体向后移
	//memmove(ps->data + sizeof(SLDataType), ps->data, sizeof(ps->sz) * ps->sz);

	//将顺序表中的元素整体向后移
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

	//同样地，先检查顺序表中是否还有元素
	//暴力检查
	assert(ps->sz > 0);

	//将顺序表中的从下标为1的位置开始向前移动
	for (int i = 0; i < ps->sz; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}

void SLInsert(SL* ps, SLDataType pos, SLDataType x)
{
	assert(ps);

	//检查pos是否有效
	assert(pos <= ps->sz && pos >= 0);

	CheckCapacity(ps);
	int end = ps->sz - 1;
	//将从下标为pos+1位置开始的元素向后移动
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

	//把从下标为pos+1之后的元素向前移动
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
		exit(-1); //异常终止
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
		//找尾
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
		//直接释放
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