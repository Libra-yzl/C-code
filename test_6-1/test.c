#define _CRT_SECURE_NO_WARNINGS 1


#include "sort.h"

void TestInsertSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(a) / sizeof(a[0]);
	InsertSort(a, size);
	printf("InsertSort:\n");
	Print(a, size);
}

int main()
{
	TestInsertSort();
	return 0;
}