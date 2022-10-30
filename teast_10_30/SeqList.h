#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

//创建顺序表--动态
typedef struct SeqList
{
	SLDataType* data;
	SLDataType sz; //有效数据个数
	SLDataType capacity; //容量
}SL;

//初始化
void SeqListInit(SL* ps);
//销毁顺序表
void SLDestroy(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);

//头插
void SLPushFront(SL* ps, SLDataType x);
//头删
void SLPopFront(SL* ps);

//插入
void SLInsert(SL* ps, SLDataType x, SLDataType pos);
//删除
void SLErase(SL* ps, SLDataType pos);

//顺序表的打印
void SLPrint(const SL* ps);