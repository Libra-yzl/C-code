#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);

	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (!hp->a)
	{
		perror("malloc fail");
		return;
	}
	memcpy(hp->a, a, sizeof(HPDataType) * n);
	hp->capacity = hp->size = n;
	
	for (int i = (hp->size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, hp->size, i);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);

	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

void Swap1(int* buf1, int* buf2)
{
	int tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap1(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	//检查扩容
	if (hp->capacity == hp->size)
	{
		int newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newCapacity);
		if (!tmp)
		{
			perror("malloc fail");
			return;
		}
		hp->a = tmp;
		hp->capacity = newCapacity;
	}
	hp->a[hp->size++] = x;

	AdjustUp(hp->a, hp->size-1);
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);

	Swap1(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->a, hp->size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);

	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}