#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, MAX*sizeof(struct PeoInfo));
}

void AddContact(struct Contact* pc)
{
	assert(pc);

	if (pc->sz == MAX)
	{
		printf("通讯录已满 无法添加数据\n");
		return;
	}

	//增加
	printf("请输入联系人姓名:");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入联系人年龄:");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入联系人性别:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入联系人电话:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入联系人住址:");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("增加联系人成功\n");
}

void ShowContact(const struct Contact* pc)
{
	printf("%-20s\t%-10s\t%-10s\t%-15s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");

	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-10s\t%-10d\t%-15s\t%-30s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

static int Find_Name(struct Contact* pc, char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

void DelContact(struct Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("已经没有联系人 不能再删除\n");
		return;
	}
	char name[20] = { 0 };
	printf("请输入要删除的联系人姓名:");
	scanf("%s", name);

	int ret = Find_Name(pc, name);
	if (!(-1 == ret))
	{
		//删除
		int j = 0;
		for (j = ret; j < pc -> sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("删除联系人成功\n");
	}
	else
	{
		printf("没有该联系人\n");
	}
}