#define _CRT_SECURE_NO_WARNINGS 1

////��ӡ100-200֮�������
//
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0; //������
//	for (i = 101; i < 200; i += 2)
//	{
//		//�ж�����
//		int flag = 1; //��־������
//		for (int j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (1 == flag)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

////���������Ӵ�С���
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	int tmp = 0;//��ʱ���� ��ת
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

////�ж�����(1000 - 2000)
////�ܱ�4�������ܱ�100����
////�ܱ�400����
//#include <stdio.h>
//
//int main()
//{
//	int year = 0;
//	int count = 0;//������
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			count++;
//			printf("%d ", year);
//		}
//	}
//	printf("\n�ܹ���%d������\n", count);
//	return 0;
//}

//���Լ�������ַ�����

////��һ�ַ���
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = a < b ? a : b;
//	while (1)
//	{
//		if (a % min == 0 && b % min == 0)
//		{
//			printf("%d\n", min);
//			break;
//		}
//		min--;
//	}
//	return 0;
//}

////շת�����
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int r = 0;//����
//	while (r = a % b)
//	{
//		a = b;
//		b = r;
//	}
//	printf("%d\n", b);
//	return 0;
//}

////�˷���
//
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", j, i, i * j);
//		}
//		printf("\n");//һ�д�ӡ�����
//	}
//	return 0;
//}

////��С������ (a * b / k) k��a��b�����Լ��
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = a < b ? a : b;
//	while (1)
//	{
//		if (a % min == 0 && b % min == 0)
//			break;
//		min--;
//	}
//	printf("%d\n", a * b / min);
//	return 0;
//}

//��10����������

#include <stdio.h>

int main()
{
	int arr[] = { 2,5,4,6,8,9,6,99,4,10,56,79 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int max = arr[0];
	for (int i = 0; i < sz; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	printf("%d\n", max);
	return 0;
}