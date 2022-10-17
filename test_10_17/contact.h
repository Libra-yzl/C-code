#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
#define INC_SZ 2

struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo* data;
	int sz;
	int capacity;//����
};

//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc);

//������ϵ����Ϣ
void AddContact(struct Contact* pc);

//��ʾ��ϵ����Ϣ
void ShowContact(const struct Contact* pc);

//����ͨѶ¼
void DestroyContact(struct Contact* pc);

//����ͨѶ¼
void SaveContact(struct Contact* pc);

//����ͨѶ¼
void LoadContact(struct Contact* pc);
