# pragma once

#include <iostream>
#include <stdlib.h>


class Stack
{
public:
	//成员函数(类的方法)
	void Init(int capacity = 4);
	void Push(int x = 1);
	
private:
	//成员变量(类的属性)
	int* _a;
	int _size;
	int _capacity;
};