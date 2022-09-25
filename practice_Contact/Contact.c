#define _CRT_SECURE_NO_WARNINGS 1


#include "Contact.h"

void InitContact(struct Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, MAX * sizeof(struct PeoInfo));
}

void add_Contact(struct Contact* pa)
{
	assert(pa);
	if (pa->sz == MAX)
	{
		printf("ͨѶ¼�������޷��������\n");
		return;
	}
	//�����˵���Ϣ
	printf("����������:>");
	scanf("%s", pa->data[pa->sz].name);
	printf("�������Ա�:>");
	scanf("%s", pa->data[pa->sz].sex);
	printf("����������:>");
	scanf("%d", &pa->data[pa->sz].age);
	printf("������绰:>");
	scanf("%s", pa->data[pa->sz].tele);
	printf("������סַ:>");
	scanf("%s", pa->data[pa->sz].addr);
	pa->sz++;
	printf("�ɹ�������ϵ��\n");
	/*Sleep(1000);
	system("cls");*/
}

void show_contact(const struct Contact* ps)
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");
	for (i = 0; i < ps->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			ps->data[i].name,
			ps->data[i].sex,
			ps->data[i].age,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}

static int find_Contact(const struct Contact* pf, char name[])
{
	int i = 0;
	for (i = 0; i < pf->sz; i++)
	{
		if (0 == strcmp(pf->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//û�ҵ�
}

void del_contact(struct Contact* pd)
{
	char name[MAX_NAME];
	printf("��ѡ��Ҫɾ������ϵ������:>");
	scanf("%s", name);
	//����ָ�����Ƿ����
	int ret = find_Contact(pd, name);
	if (ret == -1)
		printf("����ϵ�˲�����\n");
	else
	{
		//ɾ��
		//memmove(&pd->data[ret], &pd->data[ret+1], sizeof(str))
		int i = 0;
		for (i = ret; i < pd->sz - 1; i++)
		{
			pd->data[i] = pd->data[i + 1];
		}
		pd->sz--;
		printf("�ɹ�ɾ��ָ����ϵ��\n");
	}
}

//����ָ����ϵ��
void search_contact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ���ϵ������:>");
	scanf("%s", name);
	int ret = find_Contact(ps, name);
	if (-1 == ret)
		printf("Ҫ���ҵ���ϵ�˲�����\n");
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			ps->data[ret].name,
			ps->data[ret].sex,
			ps->data[ret].age,
			ps->data[ret].tele,
			ps->data[ret].addr);
	}
}

void modify_contact(struct Contact* pm)
{
	printf("������Ҫ�޸ĵ���ϵ������:>");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = find_Contact(pm, name);
	if (-1 == ret)
		printf("����ϵ�˲�����\n");
	else
	{
		printf("����������:>");
		scanf("%s", pm->data[ret].name);
		printf("�������Ա�:>");
		scanf("%s", pm->data[ret].sex);
		printf("����������:>");
		scanf("%d", &pm->data[ret].age);
		printf("������绰:>");
		scanf("%s", pm->data[ret].tele);
		printf("������סַ:>");
		scanf("%s", pm->data[ret].addr);
		printf("�ɹ��޸���ϵ����Ϣ\n");
	}
}

int cmp_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name , ((struct PeoInfo*)e2)->name);
}

//��������������
void sort_contact(struct Contact* ps)
{
	//qsort(ps->data, ps->sz, sizeof(struct PeoInfo), cmp_age);
	qsort(ps->data, ps->sz, sizeof(struct PeoInfo), cmp_name);
}

void clear_contact(struct Contact* pc)
{
	//����set�ṹ��ĳ�ʼ��
	pc->sz = 0;
	memset(pc->data, 0, MAX * sizeof(struct PeoInfo));
}