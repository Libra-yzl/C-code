#define _CRT_SECURE_NO_WARNINGS 1


#include "heap.h"

void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}
void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* buf1, HPDataType* buf2)
{
	HPDataType tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
}

void AdjustUp(HP* php)
{
	assert(php);

	int child = php->size - 1;
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (php->a[child] > php->a[parent])
		{
			Swap(&php->a[child], &php->a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
		if (!tmp)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->capacity = newCapacity;
		php->a = tmp;
	}
	php->a[php->size] = x;
	php->size++;

	//向上调整
	AdjustUp(php);
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

void AdjustDown(HP* php)
{
	assert(php);

	int parent = 0;
	int leftChild = parent * 2 + 1;
	int rightChild = parent * 2 + 2;
	while (leftChild < php->size && rightChild < php->size)
	{
		if (php->a[leftChild] > php->a[parent] || php->a[rightChild] > php->a[parent])
		{
			if (php->a[leftChild] > php->a[rightChild])
			{
				Swap(&php->a[leftChild], &php->a[parent]);
				parent = leftChild;
			}
			else
			{
				Swap(&php->a[rightChild], &php->a[parent]);
				parent = rightChild;
			}
			leftChild = parent * 2 + 1;
			rightChild = parent * 2 + 2;
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

	//删除 与最后一个元素交换位置 删除最后一个元素
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//删除完之后要保持大堆/小堆 与左儿子和右儿子较大/较小的进行比较
	AdjustDown(php);
}

int HeapSize(const HP* php)
{
	assert(php);

	return php->size;
}

bool HeapEmpty(const HP* php)
{
	assert(php);

	return php->size == 0;
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}