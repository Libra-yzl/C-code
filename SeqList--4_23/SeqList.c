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
	//À©ÈÝ³É¹¦
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
	//²åÈë
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

	////ÎÂÈá¼ì²é
	//if (ps->size == 0)
	//{
	//	//printf("Stop!");
	//	return;
	//}
	
	////±©Á¦¼ì²é
	assert(ps->size > 0);

	//Î²É¾
	ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);

	int ret = check_capacity(ps);
	if (-1 == ret)
	{
		perror("SLInsert::realloc");
		return;
	}
	//²åÈë
	if (ps->size == pos)
	{
		SLPushBack(ps, x);
		return;
	}
	memmove(ps->a + pos + 1, ps->a + pos, ((ps->a + ps->size) - (ps->a + pos)+1) * sizeof(SLDataType));
	ps->a[pos] = x;
	ps->size++;

}

void SLDelete(SL* ps, int pos)
{
	assert(ps);
	assert(ps->size >= 0);

	if (pos == ps->size)
	{
		SLPopBack(ps);
		return;
	}

	//É¾³ý
	memmove(ps->a + pos, ps->a + pos + 1, ((ps->a + ps->size) - (ps->a + pos)) * sizeof(SLDataType));
	ps->size--;
}