#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

//动态顺序表
typedef struct SeqList
{
	SLDataType* data;
	SLDataType sz;  //顺序表中的有效数据
	SLDataType capacity; //顺序表的容量
}SL;

//顺序表的初始化
void SLInit(SL* ps);
//顺序表的销毁
void SLDestroy(SL* ps);
//顺序表的打印
void SLPrint(const SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);

//尾删
void SLPopBack(SL* ps);
