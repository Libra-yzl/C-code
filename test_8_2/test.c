#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        *(p + i) = 0;
//    }
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("% d, %d\n" ,*pulPtr, *(pulPtr + 3));
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int a = 0x11223344;
//    char* pc = (char*)&a;
//    *pc = 0;
//    printf("%x\n", a);
//    return 0;
//}

////дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
////arr��һ������һά���顣
//#include <stdio.h>
//
//void print(int* arr, int sz)
//{
//	int i = 0;
//	/*for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}*/
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *arr);
//		arr++;
//	}
//}
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//
//void reverse(char* arr)
//{
//	int len = strlen(arr);
//	char* left = arr;
//	char* right = arr + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[20];
//	scanf("%[^\n]", arr);
//	reverse(arr);
//	printf("%s", arr);
//	return 0;
//}
//��ӡ����
//1 3 5 7 9 11 13 11 9 7 5 3 1 *
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 7; i++)
//	{
//		for (j = 1; j <= 7 - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 1; i < 7; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 2 * 7 - 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
//��:153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++)
//	{
//		//1.�����м�λ����
//		int n = 1;  //һ������������һλ��
//		int tmp = i;       //���ʹ��i��ÿ��i��ֵ����䣬���ܻ������ѭ��
//	                       //��˴�����ʱ����
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		//2.�����λ���ֵ�n�η�֮��sum
//		int sum = 0;
//		tmp = i;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		//3.�Ƚ�sum��i
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sum = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	//��ӡ�ϰ벿��
//	for (i = 0; i < line; i++)
//	{
//		int j = 0;
//		//��ӡ�ո�
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		//��ӡ��һ�л���
//		printf("\n");
//	}
//	//��ӡ�°벿��
//	for (i = 0; i < line - 1; i++)
//	{
//		int j = 0;
//			//��ӡ�ո�
//		for (j = 0; j < i + 1; j++)
//		{
//			printf(" ");
//		}
//			//��ӡ*
//		for (j = 0; j < 2 * (line -1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 99; i <= 999; i++)
//	{
//		//�����λ��
//		int tmp = i;
//		int n = 1;
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		//�����λ����n�η�֮��
//		tmp = i;
//		int sum = 0;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		//�Ƚ�i��sum
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//		
//	}
//	return 0;
//}
#include <stdio.h>

int main()
{
	printf("hehe");
	return 0;
}