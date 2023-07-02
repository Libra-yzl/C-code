#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void Stack::Init(int capacity)
{
	_a = (int*)malloc(sizeof(int) * capacity);
	if (!_a)
	{
		perror("malloc fail");
		exit(-1);
	}
	_size = capacity;
	_capacity = capacity;
}

void Stack::Push(int x)
{
	//...ºÏ≤È¿©»›
	_a[_size++] = x;
}