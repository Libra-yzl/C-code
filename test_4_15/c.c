#define _CRT_SECURE_NO_WARNINGS 1

#include "c.h"

static int check_capacity(struct Contact* pc);




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

	//����
	Load(pc);
}

void Load(struct Contact* pc)
{
	assert(pc);

	FILE* pf = fopen("con.txt", "r");

	if (!pf)
	{
		perror("Load");
		return;
	}

	struct PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pf))
	{
		check_capacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	fclose(pf);
	pf = NULL;
}

void Destroy(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void Save(const struct Contact* pc)
{
	FILE* pf = fopen("con.txt", "w");
	if (!pf)
	{
		perror("Save:");
		return;
	}

	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data+i, sizeof(struct PeoInfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

static int check_capacity(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		struct PeoInfo* tmp = (struct PeoInfo*)realloc((struct PeoInfo*)pc->data, DE_CAPACITY * sizeof(struct PeoInfo));
		if (!tmp)
		{
			return -2;
		}
		pc->data = tmp;
		pc->capacity += DE_CAPACITY;
		return 1;
	}
	return 1;
}

void AddContact(struct Contact* pc)
{
	assert(pc);

	//�������
	check_capacity(pc);
	if (-2 == check_capacity(pc))
	{
		perror("AddContact:");
		return;
	}
	else
	{
		printf("��������:");
		scanf("%s", pc->data[pc->sz].name);
		printf("�����Ա�:");
		scanf("%s", pc->data[pc->sz].sex);
		printf("��������:");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("����绰:");
		scanf("%s", pc->data[pc->sz].tele);
		printf("����סַ:");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;
		printf("�������\n");
	}
}

void ShowContact(const struct Contact* pc)
{
	assert(pc);

	printf("%-10s\t%-10s\t%-10s\t%-15s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");

	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-10s\t%-10d\t%-15s\t%-30s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr
		);
	}
}

static int FindName(const struct Contact* pc, char* name)
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
	char name[MAX_NAME];

	//�����ϵ���Ƿ����
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�� �޷�ɾ��\n");
		return;
	}
	else
	{
		printf("����Ҫɾ��������:");
		scanf("%s", name);
		int ret = FindName(pc, name);
		if (-1 == ret)
		{
			printf("��ϵ�˲����� �޷�ɾ��\n");
		}
		else
		{
			if (pc->sz == ret)
			{
				pc->sz--;
				printf("ɾ���ɹ�\n");
			}
			else
			{
				memmove(pc->data + ret, pc->data + ret + 1, sizeof(struct PeoInfo) * ((pc->data + pc->sz) - (pc->data + ret)));
				pc->sz--;
				printf("ɾ���ɹ�\n");
			}
		}
	}
}

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

void Sort(const struct Contact* pc)
{
	assert(pc);

	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_name);
	printf("����ɹ�\n");
}