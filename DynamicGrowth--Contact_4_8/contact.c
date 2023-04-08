#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

////��̬
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
//		printf("ͨѶ¼���� �޷������ϵ��\n");
//		return;
//	}
//	else
//	{
//		printf("����������:");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("�������Ա�:");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("����������:");
//		scanf("%d", &pc->data[pc->sz].age);
//		printf("������绰:");
//		scanf("%s", pc->data[pc->sz].tele);
//		printf("������סַ:");
//		scanf("%s", pc->data[pc->sz].addr);
//		pc->sz++;
//		printf("��ӳɹ�\n");
//	}
//	Sleep(1000);
//	system("cls");
//}



static int check_capacity(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//����
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + DEFAULT_CAPACITY) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += DEFAULT_CAPACITY;
			//printf("���ݳɹ�\n");
			return 1;
		}
		else
		{
			perror("AddContact():");
			return 0;
		}
	}
	//����Ҫ����
	return 1;
}

void AddContact(struct Contact* pc)
{
	assert(pc);
	check_capacity(pc);
	if ( 1 == check_capacity(pc))
	{
		printf("����������:");
		scanf("%s", pc->data[pc->sz].name);
		printf("�������Ա�:");
		scanf("%s", pc->data[pc->sz].sex);
		printf("����������:");
		scanf("%d", &pc->data[pc->sz].age);
		printf("������绰:");
		scanf("%s", pc->data[pc->sz].tele);
		printf("������סַ:");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;
		printf("��ӳɹ�\n");
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

	printf("%-20s\t%-10s\t%-10s\t%-15s\t%-25s\n", "����","�Ա�","����","�绰","סַ");

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
		printf("ͨѶ¼������ϵ�� �޷�ɾ��\n");
		return;
	}
	else
	{
		printf("������Ҫɾ������ϵ������:");
		scanf("%s", name);
		int ret = Find_Name(pc, name);
		if (-1 == ret)
		{
			printf("����ϵ�˲�����\n");
			return;
		}
		else
		{
			//�ƶ�ͨѶ¼�����Ԫ��
			if (ret == pc->sz)
			{
				pc->sz--;
				printf("ɾ���ɹ�\n");
				return;
			}
			else
			{
				memmove(pc->data + ret, pc->data + ret + 1, ((pc->data+pc->sz) - pc->data) * sizeof(struct PeoInfo));
				pc->sz--;
				printf("ɾ���ɹ�\n");
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
	printf("������Ҫ���ҵ���ϵ������:");
	scanf("%s", name);

	int ret = Find_Name(pc, name);

	if (-1 == ret)
	{
		printf("û�и���ϵ��\n");
		return;
	}
	else
	{
		//�ҵ���
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
	printf("������Ҫ�޸ĵ���ϵ������:");
	scanf("%s", name);

	int ret = Find_Name(pc, name);
	if (-1 == ret)
	{
		printf("��ϵ�˲�����\n");
		return;
	}
	else
	{
		printf("����������:");
		scanf("%s", pc->data[ret].name);
		printf("�������Ա�:");
		scanf("%s", pc->data[ret].sex);
		printf("����������:");
		scanf("%d", &pc->data[ret].age);
		printf("������绰:");
		scanf("%s", pc->data[ret].tele);
		printf("������סַ:");
		scanf("%s", pc->data[ret].addr);
		printf("�޸ĳɹ�\n");
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
	printf("����������ɹ�\n");
	Sleep(1000);
	system("cls");
}