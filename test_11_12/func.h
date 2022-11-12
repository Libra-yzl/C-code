#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef int SLDataType;

typedef struct SqList
{
	SLDataType* data;
	SLDataType sz; //有效个数
	SLDataType capacity; //容量
}SL;

//初始化顺序表
void SLInit(SL* ps);

//销毁顺序表
void SLDestroy(SL* ps);

//打印顺序表
void SLPrint(const SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);

//头插
void SLPushFront(SL* ps, SLDataType x);
//头删
void PopFront(SL* ps);

//指定位置插入
void SLInsert(SL* ps, SLDataType pos, SLDataType x);//pos是指定要插入数据的位置，x是插入的数据

//指定位置删除
void SLErase(SL* ps, SLDataType pos);

//单链表的实现

typedef struct SListTNode
{
	SLDataType data;
	struct SListTNode* next;
}SLTNode;

//创建链表的元素
SLTNode* BuySLTNode(SLDataType x);
SLTNode* CreateNewNode(SLDataType n); //n是链表元素的个数

//void SLTNodeInit(SLTNode* ps);
void SLTPrint(const SLTNode* phead);

//尾插
void SLTPushBack(SLTNode** phead, SLDataType x);
//尾删
void SLTPopBack(SLTNode** phead);

//头插
void SLTPushFront(SLTNode** phead, SLDataType x);
//头删
void SLTPopFront(SLTNode** phead);