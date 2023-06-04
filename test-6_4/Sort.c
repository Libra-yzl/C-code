#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include "Stack.h"


void Swap(int* buf1, int* buf2)
{
	int tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
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

void Print(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//ֱ�Ӳ�������
//ʱ�临�Ӷȣ�O(N^2)
//����������           --O(N^2)(�Ȳ�����)
//��������˳��(�ӽ�����) --O(N)
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
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}


//ϣ������
//ʱ�临�Ӷȣ�O(N^1.3)

void ShellSort(int* a, int size)
{
	int gap = size;
	while (gap > 1)
	{
		//Ԥ����������̻�ʹ���ݲ�������(Ԥ������ʵ����ֱ�Ӳ������� ֻ����gap=1ʱ����һ��ֱ�Ӳ�������)
		//��gap == 1ʱ�������һ�β������� ��ʱ���ݽӽ�����
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
		/*for (int i = 0; i < gap; i++)
		{
			for (int j = i; j < size - gap; j += gap)
			{
				int end = j;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (tmp < a[end])
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
						break;
				}
				a[end + gap] = tmp;
			}
		}*/
		//Print(a, size);
	}
}

void HeapSort(int* a, int size)
{
	//������ �����
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}

	//����
	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

//void SelectSort(int* a, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i + 1; j < size; j++)
//		{
//			if (a[i] > a[j])
//			{
//				Swap(&a[i], &a[j]);
//			}
//		}
//	}
//}

//�κ��������O(N^2) ���������ӽ�����
void SelectSort(int* a, int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

void BubbleSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (1 == flag)
			break;
	}
}

int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}

//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//
//	//С�����Ż� ���ٵݹ���ô���
//	if ((end - begin + 1) < 15)
//	{
//		InsertSort(a + begin, end - begin + 1);
//	}
//	else
//	{
//		int mid = GetMidIndex(a, begin, end);
//		Swap(&a[mid], &a[begin]);
//
//		int left = begin;
//		int right = end;
//		int keyi = left;
//		while (left < right)
//		{
//			//ѡ���Ϊkey �ұ����� ��<key��ֵ
//			while (left < right && a[right] >= a[keyi])
//				right--;
//			//����� ��>key��ֵ
//			while (left < right && a[left] <= a[keyi])
//				left++;
//			Swap(&a[left], &a[right]);
//		}
//		Swap(&a[left], &a[keyi]);
//		keyi = left;
//		QuickSort(a, begin, keyi - 1);
//		QuickSort(a, keyi + 1, end);
//	}
//}

////�ڿӷ�
//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//
//	//С�����Ż� 
//	if ((end - begin + 1) < 15)
//		InsertSort(a + begin, end - begin + 1);
//	else
//	{
//		int mid = GetMidIndex(a, begin, end);
//		Swap(&a[begin], &a[mid]);
//
//		int left = begin;
//		int right = end;
//		int key = a[begin];
//		int hole = begin;
//		while (left < right)
//		{
//			while (left < right && a[right] >= key)
//				right--;
//			a[hole] = a[right];
//			hole = right;
//			while (left < right && a[left] <= key)
//				left++;
//			a[hole] = a[left];
//			hole = left;
//		}
//		a[hole] = key;
//
//		QuickSort(a, begin, hole - 1);
//		QuickSort(a, hole + 1, end);
//	}
//}

////˫ָ�뷨
//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//
//	if ((end - begin + 1) < 15)
//	{
//		InsertSort(a + begin, end - begin + 1);
//	}
//	else
//	{
		/*int mid = GetMidIndex(a, begin, end);
		Swap(&a[mid], &a[begin]);

		int cur = begin;
		int prev = begin + 1;
		int keyi = begin;

		while (cur <= end)
		{
			if (a[cur] < a[keyi] && ++prev != cur)
			{
				Swap(&a[cur], &a[prev]);
			}
			++cur;
		}
		Swap(&a[prev], &a[keyi]);*/
//
//		QuickSort(a, begin, prev - 1);
//		QuickSort(a, prev + 1, end);
//	}
//}

int PartQSort3(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int cur = begin+1;
	int prev = begin;
	int keyi = begin;

	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;

	return keyi;
}

//�ǵݹ�
void QuickSort(int* a, int begin, int end)
{
	ST st;
	InitStack(&st);

	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//һ������
		int mid = GetMidIndex(a, left, right);
		Swap(&a[mid], &a[left]);
		int keyi = left;
		int cur = left + 1;
		int prev = left;
		while (cur <= right)
		{
			if (a[cur] < a[keyi] && ++prev != cur)
				Swap(&a[cur], &a[prev]);
			cur++;
		}
		Swap(&a[prev], &a[keyi]);
		keyi = prev;
		//int keyi = PartQSort3(a, left, right);

		//����ֵ���ֻ��һ��ֵ���߲����� �ǾͲ���ջ
		//ֻ�������ڴ��ڴ�������ֵʱ����ջ
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

	DestroyStack(&st);
}

//void _MergeSort(int* a, int begin, int end, int* tmp)
//{
//	if (begin >= end)
//		return;
//
//	int mid = (begin + end) / 2;
//	//[begin mid][mid+1 end]
//	_MergeSort(a, begin, mid, tmp);
//	_MergeSort(a, mid + 1, end, tmp);
//
//	//�鲢
//	int begin1 = begin, end1 = mid;
//	int begin2 = mid + 1, end2 = end;
//	int i = begin;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//		{
//			tmp[i++] = a[begin1++];
//		}
//		else
//		{
//			tmp[i++] = a[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//		tmp[i++] = a[begin1++];
//	while (begin2 <= end2)
//		tmp[i++] = a[begin2++];
//	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
//}
//
//void MergeSort(int* a, int size)
//{
//	int* tmp = (int*)malloc(sizeof(int) * size);
//	if (!tmp)
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	_MergeSort(a, 0, size - 1, tmp);
//}

void MergeSort(int* a, int size)
{
	int* tmp = (int*)malloc(sizeof(int) * size);
	if (!tmp)
	{
		perror("malloc fail");
		return;
	}

	int rangeN = 1;
	while (rangeN < size)
	{
		for (int i = 0; i < size; i += (rangeN * 2))
		{
			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + rangeN * 2 - 1;

			int j = i;

			if (end1 >= size)
			{
				/*begin1 = size;
				end1 = size - 1;*/
				break;
			}
			else if (begin2 >= size)
			{
				break;
			}
			else if (end2 >= size)
			{
				//�޸�end2���߽�
				end2 = size - 1;
			}

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

			//������ԭ����
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}


		rangeN *= 2;
	}

	free(tmp);
	tmp = NULL;
}