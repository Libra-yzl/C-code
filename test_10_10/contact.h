#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


#define MAX_DATA 1000
#define MAX_NAME 10
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

//struct Contact
//{
//	struct PeoInfo data[MAX_DATA];
//	int sz;
//};

struct Contact
{
	struct PeoInfo* data;
	int sz;
	int capacity;
};

void InitContact(struct Contact* pc);

//������Ϣ
void AddContact(struct Contact* pc);

//��ʾͨѶ¼
void ShowContact(const struct Contact* pc);

//ɾ����Ϣ
void DelContact(struct Contact* pc);

//����
void SearchContact(const struct Contact* pc);

//�޸�
void ModifyContact(struct Contact* pc);

//����
void SortContact(struct Contact* pc);

//����ͨѶ¼
void DestroyContact(struct Contact* pc);
