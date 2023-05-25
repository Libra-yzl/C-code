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
		//û�з������� ˵�������Ѿ���ȫ���� ��������
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
//			//����С����
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

//�Ż���ѡ������ O(n^2)
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
	//���µ��������㷨 O(N)
	//���򽨴��
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, size, i);
	}

	//������
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

void QuickSort(int* a, int begin, int end)
{
	//�ݹ���ֹ����
	if (begin >= end)
		return;

	if (end - begin + 1 < 15)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int mid = GetMidIndex(a, begin, end);
		int left = begin;
		int right = end;
		//ѡ���Ϊkey �ұ�����

		//����ȡ��
		//int keyi = left;
		int keyi = GetMidIndex(a, begin, end);

		while (left < right)
		{
			//�ұ����� ��С
			while (left < right && a[right] >= a[keyi])
			{
				--right;
			}
			//��ߺ��� �Ҵ�
			while (left < right && a[left] <= a[keyi])
			{
				++left;
			}
			Swap(&a[left], &a[right]);
		}
		//��󽻻�left/right��keyiλ�õ�Ԫ��
		Swap(&a[left], &a[keyi]);
		keyi = left;

		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
}