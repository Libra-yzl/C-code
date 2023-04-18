#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define NAME_MAX 20
#define SEX_MAX 10
#define TELE_MAX 15
#define ADDR_MAX 30

#define SZ 3
#define DEFAULT_SZ 2
#define DEFAULT_CAPACITY 3

struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};

struct Contact
{
	struct PeoInfo* data;
	int sz;
	int capacity;
};

//初始化
void InitContact(struct Contact* pc);

//添加
void AddContact(struct Contact* pc);

//显示
void ShowContact(const struct Contact* pc);

//销毁(释放)
void DesContact(struct Contact* pc);

//删除
void DelContact(struct Contact* pc);

//排序
void SortContact(const struct Contact* pc);

//保存信息--文件形式
void SaveContact(const struct Contact* pc);

//加载信息--从文件中
void LoadContact(struct Contact* pc);