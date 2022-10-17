#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
#define INC_SZ 2

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
	struct PeoInfo* data;
	int sz;
	int capacity;//容量
};

//初始化通讯录
void InitContact(struct Contact* pc);

//增加联系人信息
void AddContact(struct Contact* pc);

//显示联系人信息
void ShowContact(const struct Contact* pc);

//销毁通讯录
void DestroyContact(struct Contact* pc);

//保存通讯录
void SaveContact(struct Contact* pc);

//加载通讯录
void LoadContact(struct Contact* pc);
