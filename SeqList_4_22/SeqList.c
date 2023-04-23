#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLDestroy(SL* ps)
{
	assert(ps);
	
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

static int check_capacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int new_capacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, new_capacity * sizeof(SLDataType));
		if (!tmp)
		{
			//perror("SLPushBack::realloc");
			return -1;
		}
		ps->a = tmp;
		ps->capacity = new_capacity;
	}
	//扩容成功
	return 1;
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	int ret = check_capacity(ps);

	if (ret == -1)
	{
		perror("SLPushBack::realloc");
		return;
	}
	//插入
	ps->a[ps->size] = x;
	ps->size++;
}

SLPrint(const SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

void SLPopBack(SL* ps)
{
	assert(ps);

	////温柔检查
	//if (ps->size == 0)
	//{
	//	//printf("Stop!");
	//	return;
	//}
	
	////暴力检查
	assert(ps->size > 0);

	//尾删
	ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos <= ps->size);

	//检查扩容
	check_capacity(ps);
	//插入
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->size++;
	ps->a[pos] = x;
	////插入
	//memmove(ps->a + pos + 1, ps->a + pos, ((ps->a + ps->size) - (ps->a + pos)+1) * sizeof(SLDataType));
	//ps->a[pos] = x;
	//ps->size++;

}

void SLDelete(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos < ps->size);
	assert(ps->size > 0);

	int begin = pos;
	while (begin < ps->size)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
	////删除
	//memmove(ps->a + pos, ps->a + pos + 1, ((ps->a + ps->size) - (ps->a + pos)) * sizeof(SLDataType));
	//ps->size--;
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	check_capacity(ps);

	//memmove(ps->a + 1, ps->a, (ps->size) * sizeof(SLDataType));
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end+1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size>0);

	//挪动数据
	//memmove(ps->a, ps->a + 1, (ps->size - 1) * sizeof(SLDataType));
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

int SLFind(SL* ps, SLDataType x, int begin)
{
	assert(ps);

	for (int i = begin; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}