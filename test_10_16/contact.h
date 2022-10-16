#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_TEL 12
#define MAX_ADDR 30
#define DEFAULT 3
#define DEFAULT_SZ 3
#define INC_SZ 2

struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TEL];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo* data;
	int sz;
	int capacity;//增容
};



//初始化通讯录
void InitContact(struct Contact* pc);

//增加联系人消息
void AddContact(struct Contact* pc);

//删除联系人信息
void DelContact(struct Contact* pc);

//显示联系人信息
void ShowContact(const struct Contact* pc);

//销毁通讯录
void DestroyContact(struct Contact* pc);