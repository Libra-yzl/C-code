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
			printf("���ݳɹ�\n");
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
		//����
		
		printf("��������ϵ������:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("��������ϵ���Ա�:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("��������ϵ������:>");
		scanf("%d", &pc->data[pc->sz].age);
		printf("��������ϵ�˵绰:>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("��������ϵ��סַ:>");
		scanf("%s", pc->data[pc->sz].addr);
		printf("�ɹ�������ϵ��\n");
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
	printf("������Ҫɾ������ϵ������:>");
	scanf("%s", name);
	int ret = FindPeoInfo(pc, name);
	if (-1 == ret)
	{
		printf("����ϵ�˲����ڣ�����������\n");
	}
	else
	{
		//ɾ��
		int j = 0;
		for (j = ret; j < pc->sz-1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("ɾ����ϵ�˳ɹ�\n");
	}
}

void ShowContact(const struct Contact* pc)
{
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");
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
	printf("����ͨѶ¼�ɹ�\n");
}