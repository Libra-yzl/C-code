#define _CRT_SECURE_NO_WARNINGS 1


#include "Heap.h"

void HeapInit(struct Heap* php)
{
	assert(php);

	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapDestroy(struct Heap* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

static void Swap(HPDataType* buf1, HPDataType* buf2)
{
	HPDataType tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
}

static AdjustUp(struct Heap* php)
{
	assert(php);

	//向上调整只需要判断该节点的祖先
	//与祖先节点进行比较交换
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

void HeapPush(struct Heap* php, HPDataType x)
{
	assert(php);

	//需要扩容
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (!tmp)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->capacity = newCapacity;
		php->a = tmp;
	}
	//增加数据
	php->a[php->size] = x;
	php->size++;

	//插入数据后要保持大堆/小堆
	//向上调整
	AdjustUp(php);
}

static AdjustDown(struct Heap* php)
{
	assert(php);

	/*int parent = 0;
	int leftChild = parent * 2 + 1;
	int rightChild = parent * 2 + 2;

	while (leftChild < php->size && rightChild < php->size)
	{
		if (leftChild > rightChild)
		{
			if (php->a[leftChild] > php->a[parent])
			{
				Swap(&php->a[leftChild], &php->a[parent]);
				parent = leftChild;
				leftChild = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (php->a[rightChild] > php->a[parent])
			{
				Swap(&php->a[rightChild], &php->a[parent]);
				parent = rightChild;
				rightChild = parent * 2 + 2;
			}
			else
			{
				break;
			}
		}
	}*/

	int parent = 0;
	int child = parent * 2 + 1;

	while (child < php->size)
	{
		//确保child是左右孩子中大的一个
		if (child+1 < php->size && php->a[child] > php->a[child + 1])
		{
			child++;
		}
		if (php->a[child] < php->a[parent])
		{
			Swap(&php->a[child], &php->a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(struct Heap* php)
{
	//删除操作的思想：
	//将要删除的元素与最后一个元素交换位置
	//然后删除最后一个位置的元素 在进行向下调整 这样不会破坏整个堆的结构

	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//向下调整
	AdjustDown(php);
}
HPDataType HeapTop(struct Heap* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

int HeapSize(const struct Heap* php)
{
	assert(php);

	return php->size;
}
bool HeapEmpty(const struct Heap* php)
{
	assert(php);

	return php->size == 0;
}

void HeapPrint(const struct Heap* php)
{
	assert(php);
	
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

void AdjustDownCreate(struct Heap* php, int i)
{
	assert(php);

	int parent = i;
	int child = parent * 2 + 1;

	while (child < php->size)
	{
		//确保child是左右孩子中大的一个
		if (child + 1 < php->size && php->a[child] > php->a[child + 1])
		{
			child++;
		}
		if (php->a[child] < php->a[parent])
		{
			Swap(&php->a[child], &php->a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUpCreate(struct Heap* php, int i)
{
	assert(php);

	int child = i;
	int parent = (child - 1) / 2;
	while (child < php->size)
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

void HeapCreate(struct Heap* php, HPDataType* a, int n)
{
	assert(php);

	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (!php->a)
	{
		perror("malloc fail");
		exit(-1);
	}
	memcpy(php->a, a, n * sizeof(HPDataType));
	php->size = php->capacity = n;

	//(向下调整建堆)建堆算法 --O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDownCreate(php,i);
	}

	////(向上调整建堆)建堆算法 --O(N*logN)
	//for (int i = 0; i < php->size; i++)
	//{
	//	AdjustUpCreate(php, i);
	//}

	
}

void HeapSort(struct Heap* php)
{
	assert(php);

	int n = php->size;
	while (php->size > 0)
	{
		Swap(&php->a[php->size-1], &php->a[0]);
		php->size--;
		AdjustDown(php);
	}
	php->size = n;
}