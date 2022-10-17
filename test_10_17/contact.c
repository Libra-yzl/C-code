#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void LoadContact(struct Contact* pc)
{
	//���ļ�
	FILE* pfR = fopen("data.txt", "rb");
	if (pfR == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//���ļ�
	struct PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfR))
	{
		//���ݵ�����
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
				//printf("���ݳɹ�\n");
			}
		}
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	//�ر��ļ�
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
	//����ͨѶ¼
	LoadContact(pc);
}



void AddContact(struct Contact* pc)
{
	assert(pc);
	
	if (pc->sz == pc->capacity)
	{
		//��������
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
			printf("���ݳɹ�\n");
		}
	}
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
	pc->sz++;
	printf("������ϵ�˳ɹ�\n");
}

void ShowContact(const struct Contact* pc)
{
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����","�Ա�","����","�绰","סַ");
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
	//printf("�ɹ�����ͨѶ¼\n");
}

void SaveContact(struct Contact* pc)
{
	//���ļ�
	FILE* pfW = fopen("data.txt", "wb");
	if (pfW == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(struct PeoInfo), 1, pfW);
	}
	//�ر��ļ�
	fclose(pfW);
	pfW = NULL;
	printf("�ļ�����ɹ�\n");
}