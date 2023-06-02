#define _CRT_SECURE_NO_WARNINGS 1


#include "Heap.h"

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(a) / sizeof(a[0]);
	Heap hp;
	HeapCreate(&hp, a, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");

	/*printf("HeapTop:%d\n", HeapTop(&hp));
	HeapPop(&hp);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");
	printf("HeapTop:%d\n", HeapTop(&hp));
	HeapPop(&hp);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");
	printf("HeapTop:%d\n", HeapTop(&hp));
	HeapPop(&hp);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");
	printf("HeapTop:%d\n", HeapTop(&hp));
	HeapPop(&hp);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");*/

	HeapPush(&hp, 100);
	for (int i = 0; i < hp.size; i++)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");

	printf("HeapTop:%d\n", HeapTop(&hp));
	printf("HeapSize:%d\n", HeapSize(&hp));
	printf("isEmpty:%d\n", HeapEmpty(&hp));

	HeapPop(&hp);
	for (int i = 0; i < hp.size; i++)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");

	HeapDestory(&hp);
	return 0;
}