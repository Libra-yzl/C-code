#define _CRT_SECURE_NO_WARNINGS 1


#include "Sort.h"

void InsertSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	int len = sizeof(a) / sizeof(a[0]);
	InsertSort(a, len);
}

void ShellSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	int len = sizeof(a) / sizeof(a[0]);
	ShellSort(a, len);
}

int main()
{
	InsertSortTest();
	ShellSortTest();
	return 0;
}