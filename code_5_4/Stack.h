#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int capacity;
	int top;
}ST;

void InitStack(ST* ps);
void DestroyStack(ST* ps);

void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(const ST* ps);

void StackPrint(const ST* ps);
bool StackEmpty(const ST* ps);
int StackSize(const ST* ps);