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
		printf("ͨѶ¼�������޷����д˲���\n");
	}
	else
	{
		//����
		printf("��������ϵ�˵�����:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("��������ϵ�˵��Ա�:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("��������ϵ�˵�����:>");
		scanf("%d", &pc->data[pc->sz].age);
		printf("��������ϵ�˵ĵ绰:>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("��������ϵ�˵�סַ:>");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;
		printf("������ϵ�˳ɹ�\n");
	}
}

void ShowContact(const struct Contact* pc)
{
	printf("\t\t\t\tͨѶ¼\n\n");
	printf("%-10s\t%-5s\t%-10s\t%-12s\t%-30s\n", "����","�Ա�","����","�绰","סַ");
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
	printf("������Ҫɾ������ϵ������:>");
	scanf("%s", name);
	int ret = FindPeoInfo(pc, name);
	if (-1 == ret)
		printf("����ϵ�˲����ڣ�����������\n");
	else
	{
		//ɾ��
		int i = 0;
		for (i = ret; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("�ɹ�ɾ������ϵ��\n");
	}
}

void SearchContact(const struct Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ���ϵ������:>");
	scanf("%s", name);
	int ret = FindPeoInfo(pc, name);
	if (-1 == ret)
	{
		printf("Ҫ���ҵ���ϵ�˲�����\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-10d\t%-12s\t%-30s\n",
			pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tele,
			pc->data[ret].addr);
		printf("���ҳɹ�\n");
	}
}

void ModifyContact(struct Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ������:>");
	scanf("%s", name);
	int ret = FindPeoInfo(pc, name);
	if (-1 == ret)
	{
		printf("����ϵ�˲����ڣ�����������\n");
	}
	else
	{
		//�޸�
		printf("��������ϵ�˵�����:>");
		scanf("%s", pc->data[ret].name);
		printf("��������ϵ�˵��Ա�:>");
		scanf("%s", pc->data[ret].sex);
		printf("��������ϵ�˵�����:>");
		scanf("%d", &pc->data[ret].age);
		printf("��������ϵ�˵ĵ绰:>");
		scanf("%s", pc->data[ret].tele);
		printf("��������ϵ�˵�סַ:>");
		scanf("%s", pc->data[ret].addr);
		printf("�޸���ϵ����Ϣ�ɹ�\n");
	}
}

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct Contact*)e1)->data->name, ((struct Contact*)e2)->data->name);
}

void SortContact(struct Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_name);
	printf("����ɹ�\n");
}