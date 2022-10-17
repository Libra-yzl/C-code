#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void LoadContact(struct Contact* pc)
{
	//打开文件
	FILE* pfR = fopen("data.txt", "rb");
	if (pfR == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//读文件
	struct PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfR))
	{
		//扩容的问题
		if (pc->sz == pc->capacity)
		{
			struct PeoInfo* p = (struct PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(struct PeoInfo));
			if (p == NULL)
			{
				perror("AddContact");
				return;
			}
			else
			{
				pc->data = p;
				pc->capacity += INC_SZ;
				//printf("增容成功\n");
			}
		}
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	//关闭文件
	fclose(pfR);
	pfR = NULL;
}

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
	//加载通讯录
	LoadContact(pc);
}



void AddContact(struct Contact* pc)
{
	assert(pc);
	
	if (pc->sz == pc->capacity)
	{
		//增加容量
		struct PeoInfo* p = (struct PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(struct PeoInfo));
		if (p == NULL)
		{
			perror("AddContact");
			return;
		}
		else
		{
			pc->data = p;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
	}
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
	pc->sz++;
	printf("增加联系人成功\n");
}

void ShowContact(const struct Contact* pc)
{
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名","性别","年龄","电话","住址");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%-5d\t%-12s\t%-30s\n", 
			pc->data[i].name,
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
	//printf("成功销毁通讯录\n");
}

void SaveContact(struct Contact* pc)
{
	//打开文件
	FILE* pfW = fopen("data.txt", "wb");
	if (pfW == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//写文件
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(struct PeoInfo), 1, pfW);
	}
	//关闭文件
	fclose(pfW);
	pfW = NULL;
	printf("文件保存成功\n");
}