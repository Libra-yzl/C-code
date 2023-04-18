#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define NAME_MAX 20
#define SEX_MAX 10
#define TELE_MAX 15
#define ADDR_MAX 30

#define SZ 3
#define DEFAULT_SZ 2
#define DEFAULT_CAPACITY 3

struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};

struct Contact
{
	struct PeoInfo* data;
	int sz;
	int capacity;
};

//��ʼ��
void InitContact(struct Contact* pc);

//���
void AddContact(struct Contact* pc);

//��ʾ
void ShowContact(const struct Contact* pc);

//����(�ͷ�)
void DesContact(struct Contact* pc);

//ɾ��
void DelContact(struct Contact* pc);

//����
void SortContact(const struct Contact* pc);

//������Ϣ--�ļ���ʽ
void SaveContact(const struct Contact* pc);

//������Ϣ--���ļ���
void LoadContact(struct Contact* pc);