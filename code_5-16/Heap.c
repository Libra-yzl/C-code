#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapCreate(HP* php, HPDataType* a, int n)
{
	assert(php);

	php->a = (HPDataType*)malloc(n * sizeof(HPDataType));
	if (!php->a)
	{
		perror("malloc fail");
		return;
	}
	memcpy(php->a, a, n*sizeof(HPDataType));
	php->size = php->capacity = n;

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, n, i);
	}
}

void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	//检查扩容
	if (php->size == php->capacity)
	{
		int NewCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * NewCapacity);
		if (!tmp)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity = NewCapacity;
	}
	php->a[php->size] = x;
	php->size++;

	//向上调整
	AdjustUp(php->a, php->size - 1);
}

void Swap(HPDataType* buf1, HPDataType* buf2)
{
	HPDataType tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	//删除操作
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//向下调整
	AdjustDown(php->a, php->size, 0);
}

void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//确保child指向大的孩子节点
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

bool HeapEmpty(const HP* php)
{
	assert(php);

	return php->size == 0;
}
int HeapSize(const HP* php)
{
	assert(php);

	return php->size;
}

void HeapPrint(const HP* php)
{
	assert(php);

	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);

	}
	printf("\n");
}