#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


////定义静态顺序表 -- 不是很实用
//#define MAX 100
//
////类型重定义
//typedef int SLDataType;
//
//struct SeqList
//{
//	SLDataType data[MAX];
//	size_t size;  //有效的数据个数
//};
//

//定义动态顺序表 -- 根据用户需要扩容

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* data;
	size_t size; //有效数据的个数
	size_t capacity; //容量
}SL;


//初始化顺序表
void SLInit(SL* ps);

//销毁顺序表
void SLDestroy(SL* ps);

//增加数据 尾插尾删
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

//打印顺序表
void SLPrint(SL* ps);