#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

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

void QuickSort(int* a, int size)
{
	
}