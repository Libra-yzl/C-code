#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#define MAX_NAME 10
#define MAX_SEX 10
#define MAX_TELE 15
#define MAX_ADDR 30
#define MAX 10

//��Ÿ�����Ϣ
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	char addr[MAX_ADDR];
};

//ͨѶ¼
struct Contact
{
	struct PeoInfo data[MAX];
	int sz;
};

//����

//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc);

//������ϵ��
void AddContact(struct Contact* pc);

//��ʾͨѶ¼
void ShowContact(const struct Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(struct Contact* pc);