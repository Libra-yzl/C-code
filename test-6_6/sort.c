#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"

void Print(int* a, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* buf1, int* buf2)
{
	int tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
}

void InsertSort(int* a, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int sz)
{
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < sz - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}

void SelectSort(int* a, int sz)
{
	int begin = 0;
	int end = sz - 1;
	while (begin < end)
	{
		int left = begin;
		int right = end;

		int maxi = left;
		int mini = left;
		while (left <= right)
		{
			if (a[maxi] < a[left])
			{
				maxi = left;
			}
			if (a[mini] > a[left])
			{
				mini = left;
			}
			left++;
		}

		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int sz, int parent)
{
	int child = parent * 2 + 1;
	while (child < sz)
	{
		//保证child是左右孩子节点中大的
		if (child + 1 < sz && a[child] < a[child + 1])
			child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int sz)
{
	//建堆--大堆排升序
	for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, sz, i);
	}

	//排序
	int end = sz - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		//数据有序的标志
		int flag = 1;
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		//此时flag == 1说明数据已经有序
		if (1 == flag)
			break;
	}
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] > a[right])
	{
		if (a[left] < a[mid])
			return left;
		else if (a[right] > a[mid])
			return right;
		else
			return mid;
	}
	else //a[left] < a[right]
	{
		if (a[right] < a[mid])
			return right;
		else if (a[left] > a[mid])
			return left;
		else
			return mid;
	}
}

// 快速排序hoare版本
int PartSort1(int* a, int begin, int end)
{
	//三数取中 交换begin
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin;
	int right = end;
	int keyi = begin;
	while (left < right)
	{
		//选左边为key 右边先走 找小
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//左边走 找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		//交换a[left] a[right]
		Swap(&a[left], &a[right]);
	}
	//left与right相遇后 交换keyi
	Swap(&a[left], &a[keyi]);
	keyi = left;

	return keyi;
}
// 快速排序挖坑法
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin;
	int right = end;
	int key = a[left];
	int hole = begin;
	while (left < right)
	{
		while (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;

	return hole;
}
// 快速排序前后指针法
int PartSort3(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int cur = begin + 1;
	int prev = begin;
	int keyi = begin;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;

	return keyi;
}

//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//	if (end - begin + 1 < 15)
//	{
//		//小区间优化 减少递归调用次数
//		InsertSort(a + begin, end - begin + 1);
//	}
//	else
//	{
//		int keyi = PartSort3(a, begin, end);
//
//		QuickSort(a, begin, keyi - 1);
//		QuickSort(a, keyi + 1, end);
//	}
//}

//三路并排
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	if (end - begin + 1 < 15)
	{
		//小区间优化 减少递归调用次数
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int mid = GetMidIndex(a, begin, end);
		Swap(&a[begin], &a[mid]);

		int cur = begin + 1;
		int left = begin;
		int right = end;
		int key = a[begin];
		while (cur <= right)
		{
			if (a[cur] <= key)
				Swap(&a[cur++], &a[left++]);

			if (a[cur] == key)
				cur++;

			if (a[cur] > key)
				Swap(&a[cur], &a[right--]);
		}

		QuickSort(a, begin, left - 1);
		QuickSort(a, right + 1, end);
	}
}

void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//一趟排
		int keyi = PartSort3(a, left, right);

		//入栈[left keyi - 1] keyi [keyi + 1, right]
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}

	StackDestroy(&st);
}

void StackInit(Stack* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void StackDestroy(Stack* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void StackPush(Stack* ps, int x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		int* tmp = (int*)realloc(ps->a, sizeof(int) * newCapacity);
		if (!tmp)
		{
			perror("malloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top++] = x;
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

int StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top);

	return ps->a[ps->top - 1];
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;

	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	//拷贝回原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int begin, int end)
{
	int* tmp = (int*)malloc(sizeof(int) * (end - begin + 1));
	if (!tmp)
	{
		perror("malloc fail");
		exit(-1);
	}
	
	_MergeSort(a, begin, end, tmp);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int sz)
{
	int* tmp = (int*)malloc(sizeof(int) * sz);
	if (!tmp)
	{
		perror("malloc fail");
		return;
	}

	int rangeN = 1;
	while (rangeN < sz)
	{
		for (int i = 0; i < sz; i += 2 * rangeN)
		{
			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;

			if (end1 >= sz)
			{
				break;
			}
			else if (begin2 >= sz)
			{
				break;
			}
			else if (end2 >= sz)
			{
				end2 = sz - 1;
			}

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		rangeN *= 2;
	}

	free(tmp);
	tmp = NULL;
}