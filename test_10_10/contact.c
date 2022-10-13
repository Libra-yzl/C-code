#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//静态版本
//void InitContact(struct Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, 1000 * sizeof(struct PeoInfo));
//}

//动态版本
void InitContact(struct Contact* pc)
{
	assert(pc);
	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (pc->data == NULL)
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
		struct PeoInfo* p = (struct PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(struct PeoInfo));
		if (p == NULL)
		{
			perror("AddContact");
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
	else//不需要扩容
	{
		return 1;
	}
}

void AddContact(struct Contact* pc)
{
	assert(pc);
	//
	/*if (pc->sz == MAX_DATA)
	{
		printf("通讯录已满，无法进行此操作\n");
		return;
	}*/
	//
	if (0 == check_capacity(pc))
	{
		return;
	}
	else
	{
		//增加人的消息
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
		printf("成功增加联系人\n");
	}
}

void ShowContact(const struct Contact* pc)
{
	int i = 0;
	printf("%-10s\t""%-5s\t""%-5s\t""%-12s\t""%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%-5d\t%-12s\t%-30s\n", pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

static int FindName(const struct Contact* pc, char* name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		return i;
	}
	return -1;
}

void DelContact(struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请选择要删除的联系人姓名:>");
	scanf("%s", name);
	//查找该联系人是否存在
	int ret = FindName(pc, name);
	if (-1 == ret)
	{
		printf("该联系人不存在，请重新输入\n");
	}
	else
	{
		//删除
		int j = 0;
		for (j = ret; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];

		}
		pc->sz--;
		printf("删除联系人成功\n");
	}
}

void SearchContact(const struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请选择要查找的联系人姓名:>");
	scanf("%s", name);
	//查找该联系人是否存在
	int ret = FindName(pc, name);
	if (-1 == ret)
	{
		printf("该联系人不存在，请重新输入\n");
	}
	else
	{
		printf("%-10s\t""%-5s\t""%-5s\t""%-12s\t""%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
		printf("%-10s\t%-5s\t%-5d\t%-12s\t%-30s\n", pc->data[ret].name,
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
	printf("请选择要修改的联系人姓名:>");
	scanf("%s", name);
	//查找该联系人是否存在
	int ret = FindName(pc, name);
	if (-1 == ret)
	{
		printf("该联系人不存在，请重新输入\n");
	}
	else
	{
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
		printf("修改成功\n");
	}
}

int cmp_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}

void SortContact(struct Contact* pc)
{
	//按照年龄排序
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_age);
	printf("排序成功\n");
}


void DestroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
	printf("销毁通讯录成功\n");
}