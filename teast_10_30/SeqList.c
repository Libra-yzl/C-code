#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void CheckCapacity(SL* ps)
{
	if (ps->sz == ps->capacity)
	{
		SLDataType NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
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


void SeqListInit(SL* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps); //检查容量
	ps->data[ps->sz] = x;
	ps->sz++;
}

void SLDestroy(SL* ps)
{
	assert(ps);
	if (ps->data != NULL)
	{
		free(ps->data);
		ps->sz = 0;
		ps->capacity = 0;
	}
}

void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->sz > 0); //检查顺序表中是否还有数据

	ps->sz--;
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	int end = ps->sz;
	while (end > 0)
	{
		ps->data[end] = ps->data[end - 1];
		end--;
	}
	ps->data[0] = x;
	ps->sz++;
}

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->sz > 0);
	int begin = 0;
	while (begin < ps->sz - 1)
	{
		ps->data[begin] = ps->data[begin + 1];
		begin++;
	}
	ps->sz--;
}

void SLInsert(SL* ps, SLDataType x, SLDataType pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->sz);
	CheckCapacity(ps);
	int end = ps->sz;
	while (end > pos)
	{
		ps->data[end] = ps->data[end - 1];
		end--;
	}
	ps->data[pos] = x;
	ps->sz++;

}

void SLErase(SL* ps, SLDataType pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->sz);
	int begin = pos;
	while (begin < ps -> sz)
	{
		ps->data[begin] = ps->data[begin + 1];
		begin++;
	}
	ps->sz--;
}

void SLPrint(const SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}