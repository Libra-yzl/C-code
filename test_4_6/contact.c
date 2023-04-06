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
		printf("ͨѶ¼���� �޷��������\n");
		return;
	}

	//����
	printf("��������ϵ������:");
	scanf("%s", pc->data[pc->sz].name);
	printf("��������ϵ������:");
	scanf("%d", &pc->data[pc->sz].age);
	printf("��������ϵ���Ա�:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("��������ϵ�˵绰:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("��������ϵ��סַ:");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("������ϵ�˳ɹ�\n");
}

void ShowContact(const struct Contact* pc)
{
	printf("%-20s\t%-10s\t%-10s\t%-15s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");

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
		printf("�Ѿ�û����ϵ�� ������ɾ��\n");
		return;
	}
	char name[20] = { 0 };
	printf("������Ҫɾ������ϵ������:");
	scanf("%s", name);

	int ret = Find_Name(pc, name);
	if (!(-1 == ret))
	{
		//ɾ��
		int j = 0;
		for (j = ret; j < pc -> sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("ɾ����ϵ�˳ɹ�\n");
	}
	else
	{
		printf("û�и���ϵ��\n");
	}
}