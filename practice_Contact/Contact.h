#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <Windows.h>




#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
////�������Ա����䡢�绰��סַ

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
	struct PeoInfo data[MAX];
	int sz;
};

//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc);

//������ϵ��
void add_Contact(struct Contact* pa);

//��ʾͨѶ¼��ϵ����Ϣ
void show_contact(const struct Contact* ps);

//ɾ��ָ����ϵ��
void del_contact(struct Contact* pd);

//����ָ������ϵ����Ϣ
void search_contact(const struct Contact* ps);

//�޸�ָ����ϵ����Ϣ
void modify_contact(struct Contact* pm);

//��ָ����ʽ����ϵ������
void sort_contact(struct Contact* ps);

//�����ϵ��
void clear_contact(struct Contact* pc);
