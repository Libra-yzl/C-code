#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* pc)
{
	assert(pc);
	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (NULL == pc->data)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
}

static int check_capacity(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		struct PeoInfo* p = (struct PeoInfo*)realloc(pc->data, (INC_SZ + pc->capacity) * sizeof(struct PeoInfo));
		if (NULL == p)
		{
			return 0;
		}
		else
		{
			pc->data = p;
			pc->capacity += INC_SZ;
			printf("扩容成功\n");
			return 1;
		}
	}
	else
		return 1;
}

void AddContact(struct Contact* pc)
{
	if (0 == check_capacity(pc))
	{
		perror("AddContact");
		return;
	}
	else
	{
		//增加
		
		printf("请输入联系人姓名:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入联系人性别:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入联系人年龄:>");
		scanf("%d", &pc->data[pc->sz].age);
		printf("请输入联系人电话:>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入联系人住址:>");
		scanf("%s", pc->data[pc->sz].addr);
		printf("成功增加联系人\n");
		pc->sz++;
	}
}

static int FindPeoInfo(struct Contact* pc, char* name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == (strcmp(pc->data[i].name, name)))
			return i;
	}
	return -1;
}

void DelContact(struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要删除的联系人姓名:>");
	scanf("%s", name);
	int ret = FindPeoInfo(pc, name);
	if (-1 == ret)
	{
		printf("该联系人不存在，请重新输入\n");
	}
	else
	{
		//删除
		int j = 0;
		for (j = ret; j < pc->sz-1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("删除联系人成功\n");
	}
}

void ShowContact(const struct Contact* pc)
{
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%-5d\t%-12s\t%-30s\n", pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}


void DestroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
	printf("销毁通讯录成功\n");
}