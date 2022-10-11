#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>



#define MAX_NAME 10
#define MAX_SEX 6
#define MAX_TEL 12
#define MAX_ADDR 30
#define MAX_DATA 100

//�ṹ������
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TEL];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo data[MAX_DATA];
	int sz;
};


//����
//��ʼ��
void InitContact(struct Contact* pc);

//������ϵ��
void AddContact(struct Contact* pc);

//��ʾ��ϵ����Ϣ
void ShowContact(const struct Contact* pc);

//ɾ����ϵ����Ϣ
void DelContact(struct Contact* pc);

//������ϵ��
void SearchContact(const struct Contact* pc);

//�޸���ϵ����Ϣ
void ModifyContact(struct Contact* pc);

//��ͨѶ¼��ϵ����Ϣ����
void SortContact(struct Contact* pc);