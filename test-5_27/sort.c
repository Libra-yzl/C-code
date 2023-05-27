#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"

void bubbleSort(int* a, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		int flag = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = 0;
			}
		}
		//没有发生交换 说明数据已经完全有序 结束排序
		if (flag == 1)
			break;
	}
}

void sortPrint(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int size)
{
	assert(a);

	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int tmp = a[end+1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end+1] = tmp;
	}
}

void ShellSort(int* a, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++)
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


//void SelectSort(int* a, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i; j < size - 1; j++)
//		{
//			//找最小的数
//			if (a[i] > a[j + 1])
//			{
//				int tmp = a[i];
//				a[i] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//}

void Swap(int* buf1, int* buf2)
{
	int tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
}

//优化的选择排序 O(n^2)
void SelectSort(int* a, int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		/*for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[end], &a[maxi]);*/

		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
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
			break;
	}
}

void HeapSort(int* a, int size)
{
	//向下调整建堆算法 O(N)
	//升序建大堆
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, size, i);
	}

	//堆排序
	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] > a[mid])
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
	else
	{
		if (a[begin] > a[end])
			return begin;
		else if (a[mid] < a[end])
			return mid;
		else
			return end;
	}
}

//Hoare法
int PartSort1(int* a, int begin, int end)
{
	//三数取中
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int left = begin;
	int right = end;
	//选左边为key 右边先走
	int keyi = left;

	while (left < right)
	{
		//右边先走 找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		//左边后走 找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	//最后交换left/right和keyi位置的元素
	Swap(&a[left], &a[keyi]);
	keyi = left;

	return keyi;
}

//挖坑法
int PartSort2(int* a, int begin, int end)
{
	//三数取中
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int left = begin;
	int right = end;
	int hole = begin;
	int key = a[left];
	
	while (left < right)
	{
		//右边先走 找小
		if (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;
		if (left < right && a[left] <= key)
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;

	return hole;
}

int PartSort3(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int keyi = begin;
	int cur = begin + 1;
	int prev = begin;
	//end = size - 1
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && (++prev != cur))
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;

	return keyi;
}

//void QuickSort(int* a, int begin, int end)
//{
//	//递归终止条件
//	if (begin >= end)
//		return;
//
//	//小区间优化 减少递归次数
//	if (end - begin + 1 < 15)
//	{
//		InsertSort(a + begin, end - begin + 1);
//	}
//	else
//	{
//		int keyi = PartSort2(a, begin, end);
//		
//		QuickSort(a, begin, keyi - 1);
//		QuickSort(a, keyi + 1, end);
//	}
//}

void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, left, right);
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

void StackInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//检查扩容
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (!tmp)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	
	return ps->top == 0;
}
int StackSize(ST* ps)
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
	
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] > a[begin2])
			tmp[i++] = a[begin2++];
		else
			tmp[i++] = a[begin1++];
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	
	memcpy(a, tmp, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (!tmp)
	{
		perror("malloc fail");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

void QuickSort(int* a, int begin, int end)
{
	//递归终止条件
	if (begin >= end)
		return;

	//小区间优化 减少递归次数
	if (end - begin + 1 < 15)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		//三路并排
		//
		int mid = GetMidIndex(a, begin, end);
		Swap(&a[mid], &a[begin]);

		int left = begin, right = end;
		int key = a[left];
		int cur = begin + 1;
		while (cur <= right)
		{
			if (a[cur] < key)
			{
				Swap(&a[cur], &a[left]);
				cur++;
				left++;
			}
			else if (a[cur] > key)
			{
				Swap(&a[cur], &a[right]);
				right--;
			}
			else
			{
				cur++;
			}
		}
		//[begin, left-1][left, right][right+1, end]

		QuickSort(a, begin, left - 1);
		QuickSort(a, right + 1, end);
	}
}