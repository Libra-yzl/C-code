#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>



#define MAX_NAME 10
#define MAX_SEX 6
#define MAX_TEL 12
#define MAX_ADDR 30
#define MAX_DATA 100

//结构体声明
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
	struct PeoInfo data[MAX_DATA];
	int sz;
};


//声明
//初始化
void InitContact(struct Contact* pc);

//增加联系人
void AddContact(struct Contact* pc);

//显示联系人信息
void ShowContact(const struct Contact* pc);

//删除联系人信息
void DelContact(struct Contact* pc);

//查找联系人
void SearchContact(const struct Contact* pc);

//修改联系人信息
void ModifyContact(struct Contact* pc);

//对通讯录联系人信息排序
void SortContact(struct Contact* pc);