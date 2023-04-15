#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 15
#define MAX_ADDR 30

#define DEFAULT_SZ 0
#define DE_CAPACITY 2

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
	int capacity;
};

void InitContact(struct Contact* pc);

void AddContact(struct Contact* pc);

void ShowContact(const struct Contact* pc);

void Destroy(struct Contact* pc);

void DelContact(struct Contact* pc);

void Sort(const struct Contact* pc);

void Save(const struct Contact* pc);

void Load(struct Contact* pc);