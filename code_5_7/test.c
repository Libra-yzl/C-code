#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

//函数声明
void StackInit(Stack* ps);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);

//函数实现
void StackInit(Stack* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	if (ps->capacity == ps->top)
	{
		ps->capacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top != 0);

	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top != 0);

	return ps->a[ps->top - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}
bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}

int main()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 6);
	StackPush(&s, 5);

	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	//StackPop(&s);
	StackPop(&s);

	printf("%d\n", StackSize(&s));
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackEmpty(&s));
	StackDestroy(&s);
	return 0;
}