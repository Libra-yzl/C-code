#define _CRT_SECURE_NO_WARNINGS 1


#include "Stack.h"

void InitStack(ST* ps)
{
	assert(ps);

	ps->a = (STDataType*)malloc(4*sizeof(STDataType));
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->capacity = 4;
	ps->top = -1;
}

void DestroyStack(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top + 1 == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
		if (!tmp)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->top++;
	ps->a[ps->top] = x;
}

void StackPrint(const ST* ps)
{
	assert(ps);

	for (int i = 0; i < ps->top+1; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

bool StackEmpty(const ST* ps)
{
	assert(ps);

	return ps->top == -1;
}

STDataType StackTop(const ST* ps)
{
	assert(ps);

	return ps->a[ps->top];
}

int StackSize(const ST* ps)
{
	assert(ps);

	return ps->top + 1;
}