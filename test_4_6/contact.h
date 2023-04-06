#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#define MAX_NAME 10
#define MAX_SEX 10
#define MAX_TELE 15
#define MAX_ADDR 30
#define MAX 10

//存放个人信息
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	char addr[MAX_ADDR];
};

//通讯录
struct Contact
{
	struct PeoInfo data[MAX];
	int sz;
};

//声明

//初始化通讯录
void InitContact(struct Contact* pc);

//增加联系人
void AddContact(struct Contact* pc);

//显示通讯录
void ShowContact(const struct Contact* pc);

//删除指定联系人
void DelContact(struct Contact* pc);