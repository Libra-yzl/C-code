#define _CRT_SECURE_NO_WARNINGS 1


#include "Contact.h"

void InitContact(struct Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, MAX * sizeof(struct PeoInfo));
}

void add_Contact(struct Contact* pa)
{
	assert(pa);
	if (pa->sz == MAX)
	{
		printf("通讯录已满，无法添加数据\n");
		return;
	}
	//增加人的信息
	printf("请输入姓名:>");
	scanf("%s", pa->data[pa->sz].name);
	printf("请输入性别:>");
	scanf("%s", pa->data[pa->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &pa->data[pa->sz].age);
	printf("请输入电话:>");
	scanf("%s", pa->data[pa->sz].tele);
	printf("请输入住址:>");
	scanf("%s", pa->data[pa->sz].addr);
	pa->sz++;
	printf("成功增加联系人\n");
	/*Sleep(1000);
	system("cls");*/
}

void show_contact(const struct Contact* ps)
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (i = 0; i < ps->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			ps->data[i].name,
			ps->data[i].sex,
			ps->data[i].age,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}

static int find_Contact(const struct Contact* pf, char name[])
{
	int i = 0;
	for (i = 0; i < pf->sz; i++)
	{
		if (0 == strcmp(pf->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//没找到
}

void del_contact(struct Contact* pd)
{
	char name[MAX_NAME];
	printf("请选择要删除的联系人姓名:>");
	scanf("%s", name);
	//查找指定人是否存在
	int ret = find_Contact(pd, name);
	if (ret == -1)
		printf("该联系人不存在\n");
	else
	{
		//删除
		//memmove(&pd->data[ret], &pd->data[ret+1], sizeof(str))
		int i = 0;
		for (i = ret; i < pd->sz - 1; i++)
		{
			pd->data[i] = pd->data[i + 1];
		}
		pd->sz--;
		printf("成功删除指定联系人\n");
	}
}

//查找指定联系人
void search_contact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的联系人姓名:>");
	scanf("%s", name);
	int ret = find_Contact(ps, name);
	if (-1 == ret)
		printf("要查找的联系人不存在\n");
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			ps->data[ret].name,
			ps->data[ret].sex,
			ps->data[ret].age,
			ps->data[ret].tele,
			ps->data[ret].addr);
	}
}

void modify_contact(struct Contact* pm)
{
	printf("请输入要修改的联系人姓名:>");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = find_Contact(pm, name);
	if (-1 == ret)
		printf("该联系人不存在\n");
	else
	{
		printf("请输入姓名:>");
		scanf("%s", pm->data[ret].name);
		printf("请输入性别:>");
		scanf("%s", pm->data[ret].sex);
		printf("请输入年龄:>");
		scanf("%d", &pm->data[ret].age);
		printf("请输入电话:>");
		scanf("%s", pm->data[ret].tele);
		printf("请输入住址:>");
		scanf("%s", pm->data[ret].addr);
		printf("成功修改联系人信息\n");
	}
}

int cmp_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name , ((struct PeoInfo*)e2)->name);
}

//按照年龄来排序
void sort_contact(struct Contact* ps)
{
	//qsort(ps->data, ps->sz, sizeof(struct PeoInfo), cmp_age);
	qsort(ps->data, ps->sz, sizeof(struct PeoInfo), cmp_name);
}

void clear_contact(struct Contact* pc)
{
	//重新set结构体的初始化
	pc->sz = 0;
	memset(pc->data, 0, MAX * sizeof(struct PeoInfo));
}