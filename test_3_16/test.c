#define _CRT_SECURE_NO_WARNINGS 1

////дһ�������ж��ǲ�������
//	//����������1�����Ƿ���0
//
//#include <stdio.h>
//#include <math.h>
//
//int is_prime(int num)
//{
//	int i = 0;
//	for (i = 2; i < sqrt(num); i++)
//	{
//		if (num % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0; //������
//	//100-200�������ҳ�����
//	for (i = 100; i < 200; i++)
//	{
//		int ret = is_prime(i);
//		if (1 == ret)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}



////дһ�������ж��ǲ�������
//
//#include <stdio.h>
//
//int is_leap_year(int year)
//{
//	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0; //������
//
//	//1000-2000�����
//	for (i = 1000; i <= 2000; i++)
//	{
//		//�ж��ǲ�������
//		int ret = is_leap_year(i);
//		//����1˵��������
//		if (1 == ret)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}


////дһ��������ʵ��һ����������Ķ��ֲ���
//
//#include <stdio.h>
//
//int binary_search(int* arr, int sz, int k)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	//���ֲ���
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	scanf("%d", &k);
//
//	//ʵ�ֶ��ֲ���
//	int ret = binary_search(arr, sz, k);
//	if (ret != -1)
//		printf("�ҵ��ˣ��±���%d\n", ret);
//	else
//		printf("�����������\n");
//	return 0;
//}


////дһ����������һ�����������num��ֵ��1
//
//#include <stdio.h>
//
//int num_add(int* num)
//{
//	return ++(*num);
//}
//
//int main()
//{
//	int num = 0;
//
//	int ret = 0;
//	num_add(&num);
//	num_add(&num);
//	num_add(&num);
//	num_add(&num);
//	ret = num_add(&num);
//
//	printf("ret = %d\n", ret);
//	return 0;
//}


//����һ���޷������ͣ����ÿһλ ���磺���룺1234   �����1 2 3 4

#include <stdio.h>

void print(int num)
{
	if (num > 9)
		print(num / 10);
	printf("%d ", num % 10);
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	print(num);
	return 0;
}


////����Сд��ĸ��ת��Ϊ��д��ĸ�������ASCIIֵ
//#include <stdio.h>
//
//int main()
//{
//	char input = 0;
//	printf("������һ��Сд��ĸ:>");
//	scanf("%c", &input);
//	printf("��д��ĸ:%c\nASCIIֵ:%d\n", input - 32, input);
//	return 0;
//}