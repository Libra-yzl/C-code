#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

////静态
//void InitContact(struct Contact* pc)
//{
//	assert(pc);
//	pc->sz = 0;
//	memset(pc->data, 0, MAX * sizeof(struct PeoInfo));
//}

void InitContact(struct Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = (struct PeoInfo*)malloc(pc->capacity * sizeof(struct PeoInfo));
}

void DestroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//void AddContact(struct Contact* pc)
//{
//	assert(pc);
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满 无法添加联系人\n");
//		return;
//	}
//	else
//	{
//		printf("请输入姓名:");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("请输入性别:");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("请输入年龄:");
//		scanf("%d", &pc->data[pc->sz].age);
//		printf("请输入电话:");
//		scanf("%s", pc->data[pc->sz].tele);
//		printf("请输入住址:");
//		scanf("%s", pc->data[pc->sz].addr);
//		pc->sz++;
//		printf("添加成功\n");
//	}
//	Sleep(1000);
//	system("cls");
//}



static int check_capacity(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//增容
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + DEFAULT_CAPACITY) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += DEFAULT_CAPACITY;
			//printf("增容成功\n");
			return 1;
		}
		else
		{
			perror("AddContact():");
			return 0;
		}
	}
	//不需要扩容
	return 1;
}

void AddContact(struct Contact* pc)
{
	assert(pc);
	check_capacity(pc);
	if ( 1 == check_capacity(pc))
	{
		printf("请输入姓名:");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入性别:");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入年龄:");
		scanf("%d", &pc->data[pc->sz].age);
		printf("请输入电话:");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入住址:");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;
		printf("添加成功\n");
	}
	else
	{
		perror("AddContact()");
		return;
	}
	Sleep(1000);
	system("cls");
}

void ShowContact(const struct Contact* pc)
{
	assert(pc);

	printf("%-20s\t%-10s\t%-10s\t%-15s\t%-25s\n", "姓名","性别","年龄","电话","住址");

	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-10s\t%-10d\t%-15s\t%-25s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr
		);
	}
	Sleep(5000);
	system("cls");
}

static int Find_Name(const struct Contact* pc, char* name)
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

	char name[NAME_MAX];
	if (pc->sz == 0)
	{
		printf("通讯录已无联系人 无法删除\n");
		return;
	}
	else
	{
		printf("请输入要删除的联系人姓名:");
		scanf("%s", name);
		int ret = Find_Name(pc, name);
		if (-1 == ret)
		{
			printf("该联系人不存在\n");
			return;
		}
		else
		{
			//移动通讯录后面的元素
			if (ret == pc->sz)
			{
				pc->sz--;
				printf("删除成功\n");
				return;
			}
			else
			{
				memmove(pc->data + ret, pc->data + ret + 1, ((pc->data+pc->sz) - pc->data) * sizeof(struct PeoInfo));
				pc->sz--;
				printf("删除成功\n");
			}
		}
	}
	Sleep(1000);
	system("cls");
}

void SearchContact(const struct Contact* pc)
{
	assert(pc);

	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名:");
	scanf("%s", name);

	int ret = Find_Name(pc, name);

	if (-1 == ret)
	{
		printf("没有该联系人\n");
		return;
	}
	else
	{
		//找到了
		printf("%-20s\t%-10s\t%-10d\t%-15s\t%-25s\n",
			pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tele,
			pc->data[ret].addr
		);
	}
	Sleep(1000);
	system("cls");
}

void ModifyContact(struct Contact* pc)
{
	assert(pc);

	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名:");
	scanf("%s", name);

	int ret = Find_Name(pc, name);
	if (-1 == ret)
	{
		printf("联系人不存在\n");
		return;
	}
	else
	{
		printf("请输入姓名:");
		scanf("%s", pc->data[ret].name);
		printf("请输入性别:");
		scanf("%s", pc->data[ret].sex);
		printf("请输入年龄:");
		scanf("%d", &pc->data[ret].age);
		printf("请输入电话:");
		scanf("%s", pc->data[ret].tele);
		printf("请输入住址:");
		scanf("%s", pc->data[ret].addr);
		printf("修改成功\n");
	}
	Sleep(1000);
	system("cls");
}

static int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

void SortContact(struct Contact* pc)
{
	assert(pc);

	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_name);
	printf("按名字排序成功\n");
	Sleep(1000);
	system("cls");
}