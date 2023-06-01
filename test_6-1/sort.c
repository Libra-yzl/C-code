#define _CRT_SECURE_NO_WARNINGS 1


#include "Sort.h"

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Print(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				Swap(&a[end], &a[end + 1]);
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int size);