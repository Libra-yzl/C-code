#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, 100 * sizeof(struct PeoInfo));
}

void AddContact(struct Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX_DATA)
	{
		printf("通讯录已满，无法进行此操作\n");
	}
	else
	{
		//增加
		printf("请输入联系人的姓名:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入联系人的性别:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入联系人的年龄:>");
		scanf("%d", &pc->data[pc->sz].age);
		printf("请输入联系人的电话:>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入联系人的住址:>");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;
		printf("增加联系人成功\n");
	}
}

void ShowContact(const struct Contact* pc)
{
	printf("\t\t\t\t通讯录\n\n");
	printf("%-10s\t%-5s\t%-10s\t%-12s\t%-30s\n", "姓名","性别","年龄","电话","住址");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%-10d\t%-12s\t%-30s\n", 
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

static int FindPeoInfo(const struct Contact* pc, char* name)
{
	int i = 0;
	/*int flag = pc->sz;
	while (flag--)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}*/
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
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
		printf("该联系人不存在，请重新输入\n");
	else
	{
		//删除
		int i = 0;
		for (i = ret; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("成功删除该联系人\n");
	}
}

void SearchContact(const struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要查找的联系人姓名:>");
	scanf("%s", name);
	int ret = FindPeoInfo(pc, name);
	if (-1 == ret)
	{
		printf("要查找的联系人不存在\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-10d\t%-12s\t%-30s\n",
			pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tele,
			pc->data[ret].addr);
		printf("查找成功\n");
	}
}

void ModifyContact(struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要修改的联系人姓名:>");
	scanf("%s", name);
	int ret = FindPeoInfo(pc, name);
	if (-1 == ret)
	{
		printf("该联系人不存在，请重新输入\n");
	}
	else
	{
		//修改
		printf("请输入联系人的姓名:>");
		scanf("%s", pc->data[ret].name);
		printf("请输入联系人的性别:>");
		scanf("%s", pc->data[ret].sex);
		printf("请输入联系人的年龄:>");
		scanf("%d", &pc->data[ret].age);
		printf("请输入联系人的电话:>");
		scanf("%s", pc->data[ret].tele);
		printf("请输入联系人的住址:>");
		scanf("%s", pc->data[ret].addr);
		printf("修改联系人信息成功\n");
	}
}

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct Contact*)e1)->data->name, ((struct Contact*)e2)->data->name);
}

void SortContact(struct Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_name);
	printf("排序成功\n");
}