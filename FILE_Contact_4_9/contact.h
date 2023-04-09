#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>


#define NAME_MAX 20
#define SEX_MAX 20
#define TELE_MAX 20
#define ADDR_MAX 20
#define MAX 30

#define DEFAULT_SZ 3
#define DEFAULT_CAPACITY 2

struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};

////静态
//struct Contact
//{
//	struct PeoInfo data[MAX];
//	int sz;
//};

struct Contact
{
	struct PeoInfo *data;
	int sz;
	int capacity;
};

//函数声明

//初始化通讯录
void InitContact(struct Contact* pc);

//增加联系人
void AddContact(struct Contact* pc);

void ShowContact(const struct Contact* pc);

void DelContact(struct Contact* pc);

void SearchContact(const struct Contact* pc);

void ModifyContact(struct Contact* pc);

void SortContact(struct Contact* pc);

void DestroyContact(struct Contact* pc);