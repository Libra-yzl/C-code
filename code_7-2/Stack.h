# pragma once

#include <iostream>
#include <stdlib.h>


class Stack
{
public:
	//��Ա����(��ķ���)
	void Init(int capacity = 4);
	void Push(int x = 1);
	
private:
	//��Ա����(�������)
	int* _a;
	int _size;
	int _capacity;
};