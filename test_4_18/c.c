#define _CRT_SECURE_NO_WARNINGS 1

#include "c.h"

//内部函数声明
static int check_capacity(struct Contact* pc);
static int FindName(const struct Contact* pc, char* name);



static int check_capacity(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		struct PeoInfo* tmp = (struct PeoInfo*)realloc(pc->data, (pc->capacity + DEFAULT_CAPACITY) * sizeof(struct PeoInfo));
		if (!tmp)
		{
			perror("AddContact:");
			return 0;
		}
		pc->data = tmp;
		pc->capacity += DEFAULT_CAPACITY;
		//printf("扩容\n");
		return 1;
	}
	return 1;
}

void InitContact(struct Contact* pc)
{
	assert(pc);

	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;

	pc->data = (struct PeoInfo*)malloc(pc->capacity * sizeof(struct PeoInfo));
	if (!pc->data)
	{
		perror("InitContact:");
		return;
	}

	//加载--文件形式保存的通讯录
	LoadContact(pc);
}

void AddContact(struct Contact* pc)
{
	assert(pc);

	if (1 == check_capacity(pc))
	{
		printf("姓名:");
		scanf("%s", pc->data[pc->sz].name);
		printf("性别:");
		scanf("%s", pc->data[pc->sz].sex);
		printf("年龄:");
		scanf("%d", &pc->data[pc->sz].age);
		printf("电话:");
		scanf("%s", pc->data[pc->sz].tele);
		printf("住址:");
		scanf("%s", pc->data[pc->sz].addr);

		pc->sz++;
		printf("成功增加联系人\n");
	}
	else
	{
		perror("AddContact:");
		return;
	}
}

void ShowContact(const struct Contact* pc)
{
	assert(pc);

	printf("%-10s\t%-10s\t%-10s\t%-15s\t%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-10s\t%-10d\t%-15s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

void DesContact(struct Contact* pc)
{
	assert(pc);

	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

static int FindName(const struct Contact* pc, char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(struct Contact* pc)
{
	assert(pc);

	if (!pc->sz)
	{
		printf("通讯录中已无联系人 无法删除\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("输入要删除的联系人姓名:");
	scanf("%s", name);

	int ret = FindName(pc, name);
	if (-1 == ret)
	{
		printf("该联系人不存在！\n");
		return;
	}
	else
	{
		//删除
		if (pc->sz == 1)
		{
			pc->sz--;
		}
		else
		{
			memmove(pc->data + ret, pc->data + ret + 1, (pc->data + pc->sz - pc->data + ret) * sizeof(struct PeoInfo));
			pc->sz--;
		}
		printf("删除成功\n");
		//修改的操作
		/*printf("姓名:");
		scanf("%s", pc->data[ret].name);
		printf("性别:");
		scanf("%s", pc->data[ret].sex);
		printf("年龄:");
		scanf("%d", &pc->data[ret].age);
		printf("电话:");
		scanf("%s", pc->data[ret].tele);
		printf("住址:");
		scanf("%s", pc->data[ret].addr);*/
	}
}

static int cmp_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}

static int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

void SortContact(const struct Contact* pc)
{
	assert(pc);

	//qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_age);
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_name);
}

void SaveContact(const struct Contact* pc)
{
	assert(pc);

	//打开文件
	FILE* pf = fopen("c.txt", "w");
	if (!pf)
	{
		perror("SaveContact:");
		return;
	}
	//写入
	for (int i = 0; i < pc->sz; i++)
	{
		fprintf(pf, "%s %s %d %s %s\n", 
			pc->data[i].name, 
			pc->data[i].sex, 
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);

	}
	printf("保存成功！\n");
	//关闭文件
	fclose(pf);
	pf = NULL;
}

void LoadContact(struct Contact* pc)
{
	assert(pc);

	printf("加载文件中...\n");

	//打开文件
	FILE* pf = fopen("c.txt", "r");
	if (!pf)
	{
		perror("InitContact::LoadContact:");
		return;
	}
	//读文件
	struct PeoInfo tmp = {0};
	int i = 0;
	for (int i = 0; i < 3; i++)
	{
		fscanf(pf, "%s %s %d %s %s", tmp.name, tmp.sex, &(tmp.age), tmp.tele, tmp.addr);
		check_capacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	printf("加载成功\n");

	//关闭文件
	fclose(pf);
	pf = NULL;
}