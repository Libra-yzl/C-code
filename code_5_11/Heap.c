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

	//���ϵ���ֻ��Ҫ�жϸýڵ������
	//�����Ƚڵ���бȽϽ���
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

	//��Ҫ����
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
	//��������
	php->a[php->size] = x;
	php->size++;

	//�������ݺ�Ҫ���ִ��/С��
	//���ϵ���
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
		//ȷ��child�����Һ����д��һ��
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
	//ɾ��������˼�룺
	//��Ҫɾ����Ԫ�������һ��Ԫ�ؽ���λ��
	//Ȼ��ɾ�����һ��λ�õ�Ԫ�� �ڽ������µ��� ���������ƻ������ѵĽṹ

	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//���µ���
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
		//ȷ��child�����Һ����д��һ��
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

	//(���µ�������)�����㷨 --O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDownCreate(php,i);
	}

	////(���ϵ�������)�����㷨 --O(N*logN)
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