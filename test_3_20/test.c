#define _CRT_SECURE_NO_WARNINGS 1

////�ݹ����n��k�η�
//#include <stdio.h>
//
//double Pow(int n, int k)
//{
//	if (k < 0)
//		return 1.0 / Pow(n, -k);
//	else if (0 == k)
//		return 1;
//	else
//		return n * Pow(n, k - 1);
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//
//	//����n��k�η�
//	double ret = Pow(n, k);
//	printf("n^k = %lf\n", ret);
//	return 0;
//}


////дһ���ݹ麯��DigitSum(n) ����һ���Ǹ����� ���������������֮��
//#include <stdio.h>
//
//int DigitSum(int n)
//{
//	if (n > 9)
//		return DigitSum(n / 10) + n % 10;
//	else
//		return n;
//}
//
//int main()
//{
//	int n = 0;
//	printf("������һ���Ǹ�����:>");
//	scanf("%d", &n);
//
//	//DigitSum����
//	int ret = DigitSum(n);
//	printf("%d��ÿλ��֮��Ϊ%d\n", n, ret);
//	return 0;
//}

//��дһ������reverse_string(char* string)
//�������ַ����е��ַ���������
//����ʹ��C�������е��ַ�����������
//
//#include <stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;//�ַ�������
//
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//
//void reverse_string(char* str, int sz)
//{
//	char* left = str;
//	char* right = str + sz - 1;
//
//	while (left < right)
//	{
//		//������һλ�����һλ
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}

//void reverse_string(char* str, int sz)
//{
//	char left = 0;
//	char right = sz - 1;
//
//	while (left < right)
//	{
//		char tmp = *(left + str);
//		*(left + str) = *(right + str);
//		*(right + str) = tmp;
//		left++;
//		right--;
//	}
//}

////�ݹ�
//void reverse_string(char* str)
//{
//	int sz = my_strlen(str);
//	char* left = str;
//	char* right = str + sz - 1;
//
//	char tmp = *left;
//	*left = *right;
//	*right = '\0';
//
//	if (my_strlen(str) > 1)
//		reverse_string(str + 1);
//
//	*right = tmp;
//}
//
//int main()
//{
//	char str[] = "abcdef";
//	int sz = my_strlen(str);
//
//	reverse_string(str);
//	printf("%s\n", str);
//	return 0;
//}

////�ݹ� �ǵݹ�ʵ����쳲���������
//#include <stdio.h>
//
//int count = 0;//ͳ��ĳ�����Ĵ���
//
//int Fib_rec(int n)
//{
//	if (n == 4)
//		count++;
//	if (n <= 2)
//		return 1;
//	else
//		return Fib_rec(n - 1) + Fib_rec(n - 2);
//}
//
//int Fib_cir(int n)
//{
//	//쳲��������е�ǰ����
//	int a = 1;
//	int b = 1;
//	int c = 1;
//
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;//쳲�������������
//	printf("������Ҫ���쳲��������е�����:>");
//	scanf("%d", &n);
//
//	Fib_rec(n);//�ݹ�
//	Fib_cir(n);//ѭ��
//
//	printf("�ݹ���쳲��������е�n��:%d\nѭ����쳲��������е�n��:%d\n", Fib_rec(n), Fib_cir(n));
//	printf("�ݹ����쳲���������nΪ3ʱ�Ĵ�����%d", count);
//	return 0;
//}


////������A������B�е����ݽ��� Swap����ʵ��
//#include <stdio.h>
//
//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Swap(int* arr1, int* arr2, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//
//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//
//	printf("����ǰarr1���飺");
//	print(arr1, sz);
//	printf("����ǰarr2���飺");
//	print(arr2, sz);
//
//	Swap(arr1, arr2, sz);
//	
//	printf("\n������arr1���飺");
//	print(arr1, sz);
//	printf("������arr2���飺");
//	print(arr2, sz);
//
//	return 0;
//}


//����һ���������� ��ɶ�����Ĳ���
//ʵ�ֺ���init() �������ʼ��Ϊȫ0
//ʵ�ֺ���print() ��ӡ������ÿ��Ԫ��
////ʵ�ֺ���reverse() �����������Ԫ�ص�����
//#include <stdio.h>
//
//void init(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = i + 1;
//	}
//}
//
//void reverse(int* arr, int sz)
//{
//	int* left = arr;
//	int* right = arr + sz - 1;
//
//	while (left < right)
//	{
//		int tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	init(arr, sz);
//	printf("����ǰ�����飺");
//	print(arr, sz);
//
//	reverse(arr, sz);
//	printf("���ú�����飺");
//	print(arr, sz);
//
//	return 0;
//}


////ð������
//#include <stdio.h>
//
//int count = 0;//ͳ��ð����������˶��ٴ�
//
//void bubble_sort(int* arr, int sz)
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//��������ı�־
//		//count++;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			count++;
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;//��ʱ���ݻ�δ��ȫ����
//			}
//		}
//		if (1 == flag)//˵�������е������Ѿ���ȫ���� ����ѭ��
//			break;
//	}
//}
//
//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	
//	printf("����ǰ������:");
//	print(arr, sz);
//
//	bubble_sort(arr, sz);
//
//	printf("����������:");
//	print(arr, sz);
//
//	//printf("�˴�ð�������������Ĵ���Ϊ%d��\n", count);
//	return 0;
//}


////���л��� -- ת�þ���
//#include <stdio.h>
//
//#define n 2
//#define m 3
//
//int main()
//{
//	int arr[n][m];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	printf("ԭ����:\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	printf("ת�þ���:\n");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//��һ���������ڴ��д洢��1�ĸ���
#include <stdio.h>

int main()
{
	int flag = 1; //��λ��1
	int n = 0;
	int k = 32;
	printf("������һ������:>");
	scanf("%d", &n);
	int tmp = n;

	int count = 0;//ͳ�ƶ�����1�ĸ���
	while (k)
	{
		if ((n & flag) == 1)
			count++;
		n >>= 1;
		k--;
	}
	printf("%d�Ķ�������1�ĸ���Ϊ%d��", tmp, count);
	return 0;
}
