#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//��̬�汾
//void InitContact(struct Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, 1000 * sizeof(struct PeoInfo));
//}

//��̬�汾
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
			printf("���ݳɹ�\n");
			return 1;
		}
	}
	else//����Ҫ����
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
		printf("ͨѶ¼�������޷����д˲���\n");
		return;
	}*/
	//
	if (0 == check_capacity(pc))
	{
		return;
	}
	else
	{
		//�����˵���Ϣ
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
		printf("�ɹ�������ϵ��\n");
	}
}

void ShowContact(const struct Contact* pc)
{
	int i = 0;
	printf("%-10s\t""%-5s\t""%-5s\t""%-12s\t""%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");
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
	printf("��ѡ��Ҫɾ������ϵ������:>");
	scanf("%s", name);
	//���Ҹ���ϵ���Ƿ����
	int ret = FindName(pc, name);
	if (-1 == ret)
	{
		printf("����ϵ�˲����ڣ�����������\n");
	}
	else
	{
		//ɾ��
		int j = 0;
		for (j = ret; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];

		}
		pc->sz--;
		printf("ɾ����ϵ�˳ɹ�\n");
	}
}

void SearchContact(const struct Contact* pc)
{
	char name[MAX_NAME];
	printf("��ѡ��Ҫ���ҵ���ϵ������:>");
	scanf("%s", name);
	//���Ҹ���ϵ���Ƿ����
	int ret = FindName(pc, name);
	if (-1 == ret)
	{
		printf("����ϵ�˲����ڣ�����������\n");
	}
	else
	{
		printf("%-10s\t""%-5s\t""%-5s\t""%-12s\t""%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");
		printf("%-10s\t%-5s\t%-5d\t%-12s\t%-30s\n", pc->data[ret].name,
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
	printf("��ѡ��Ҫ�޸ĵ���ϵ������:>");
	scanf("%s", name);
	//���Ҹ���ϵ���Ƿ����
	int ret = FindName(pc, name);
	if (-1 == ret)
	{
		printf("����ϵ�˲����ڣ�����������\n");
	}
	else
	{
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
		printf("�޸ĳɹ�\n");
	}
}

int cmp_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}

void SortContact(struct Contact* pc)
{
	//������������
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_age);
	printf("����ɹ�\n");
}


void DestroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
	printf("����ͨѶ¼�ɹ�\n");
}