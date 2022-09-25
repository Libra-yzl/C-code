#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <Windows.h>




#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
////姓名、性别、年龄、电话、住址

struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo data[MAX];
	int sz;
};

//初始化通讯录
void InitContact(struct Contact* pc);

//增加联系人
void add_Contact(struct Contact* pa);

//显示通讯录联系人信息
void show_contact(const struct Contact* ps);

//删除指定联系人
void del_contact(struct Contact* pd);

//查找指定的联系人信息
void search_contact(const struct Contact* ps);

//修改指定联系人信息
void modify_contact(struct Contact* pm);

//按指定方式对联系人排序
void sort_contact(struct Contact* ps);

//清空联系人
void clear_contact(struct Contact* pc);
