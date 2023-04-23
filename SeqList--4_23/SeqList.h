#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



////静态顺序表
//#define N 10
//
//typedef int SLDataType;
//
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size; //记录存储多少个有效数据
//}SL;
//
//void SLInit(SL s);
//void SLPushBack(SL s, SLDataType x);


//
//动态顺序表

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size; //记录存储多少个有效数据
	int capacity; //空间容量大小
}SL;


//初始化
void SLInit(SL* s);
//销毁
void SLDestroy(SL* ps);

SLPrint(const SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);

//指定位置插入
void SLInsert(SL* ps, int pos, SLDataType x);
//指定位置删除
void SLDelete(SL* ps, int pos);