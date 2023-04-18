#define _CRT_SECURE_NO_WARNINGS 1

#include "c.h"

//�ڲ���������
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
		//printf("����\n");
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

	//����--�ļ���ʽ�����ͨѶ¼
	LoadContact(pc);
}

void AddContact(struct Contact* pc)
{
	assert(pc);

	if (1 == check_capacity(pc))
	{
		printf("����:");
		scanf("%s", pc->data[pc->sz].name);
		printf("�Ա�:");
		scanf("%s", pc->data[pc->sz].sex);
		printf("����:");
		scanf("%d", &pc->data[pc->sz].age);
		printf("�绰:");
		scanf("%s", pc->data[pc->sz].tele);
		printf("סַ:");
		scanf("%s", pc->data[pc->sz].addr);

		pc->sz++;
		printf("�ɹ�������ϵ��\n");
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

	printf("%-10s\t%-10s\t%-10s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
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
		printf("ͨѶ¼��������ϵ�� �޷�ɾ��\n");
		return;
	}

	char name[NAME_MAX] = { 0 };
	printf("����Ҫɾ������ϵ������:");
	scanf("%s", name);

	int ret = FindName(pc, name);
	if (-1 == ret)
	{
		printf("����ϵ�˲����ڣ�\n");
		return;
	}
	else
	{
		//ɾ��
		if (pc->sz == 1)
		{
			pc->sz--;
		}
		else
		{
			memmove(pc->data + ret, pc->data + ret + 1, (pc->data + pc->sz - pc->data + ret) * sizeof(struct PeoInfo));
			pc->sz--;
		}
		printf("ɾ���ɹ�\n");
		//�޸ĵĲ���
		/*printf("����:");
		scanf("%s", pc->data[ret].name);
		printf("�Ա�:");
		scanf("%s", pc->data[ret].sex);
		printf("����:");
		scanf("%d", &pc->data[ret].age);
		printf("�绰:");
		scanf("%s", pc->data[ret].tele);
		printf("סַ:");
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

	//���ļ�
	FILE* pf = fopen("c.txt", "w");
	if (!pf)
	{
		perror("SaveContact:");
		return;
	}
	//д��
	for (int i = 0; i < pc->sz; i++)
	{
		fprintf(pf, "%s %s %d %s %s\n", 
			pc->data[i].name, 
			pc->data[i].sex, 
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);

	}
	printf("����ɹ���\n");
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

void LoadContact(struct Contact* pc)
{
	assert(pc);

	printf("�����ļ���...\n");

	//���ļ�
	FILE* pf = fopen("c.txt", "r");
	if (!pf)
	{
		perror("InitContact::LoadContact:");
		return;
	}
	//���ļ�
	struct PeoInfo tmp = {0};
	int i = 0;
	for (int i = 0; i < 3; i++)
	{
		fscanf(pf, "%s %s %d %s %s", tmp.name, tmp.sex, &(tmp.age), tmp.tele, tmp.addr);
		check_capacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	printf("���سɹ�\n");

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}