#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SLInit(SL* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->capacity = 0;
	ps->sz = 0;
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->capacity == ps->sz)
	{
		SLDataType newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->data, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("SLPushBack::realloc");
			return; //异常终止
		}
		ps->data = tmp;
		ps->capacity = newCapacity;
	}
	ps->data[ps->sz] = x;
	ps->sz++;
}

void SLPopBack(SL* ps)
{
	//要检查顺序表中是否还有元素
	assert(ps->sz > 0);

	//尾删操作
	//ps->data[ps->sz] = 0; //没有必要，重新赋值会覆盖，不会打印
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

void SLDestroy(SL* ps)
{
	if (ps->data)
	{
		free(ps->data);
		ps->sz = 0;
		ps->capacity = 0;
	}
}