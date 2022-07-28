#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	double sum1 = 0.0;
//	double sum2 = 0.0;
//	double sum = 0.0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 != 0)
//		{
//			sum1 += 1.0 / i; 
//		}
//		else
//		{
//			sum2 += 1.0 / i;
//		}
//	}
//	printf("%lf", sum = sum1 - sum2);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d", count);
//	return 0;
//}
//
//
//
//#include <stdio.h>
//void swap(int* m, int* n)
//{
//	int tmp = *m;
//	*m = *n;
//	*n = tmp;
//}
//int main()
//{
//	int m, n;
//	scanf("%d %d", &m, &n);
//	printf("m = %d,n = %d\n", m, n);
//	swap(&m, &n);
//	printf("m = %d,n = %d", m, n);
//	return 0;
//}
//#include <stdio.h>
//int Is_leap(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	int ret = 0;
//	while (1)
//	{
//		scanf("%d", &year);
//		ret = Is_leap(year);
//		if (year == 0)
//			break;
//		if (ret == 1)
//		{
//			printf("是闰年\n");
//		}
//		else if (ret == 0)
//		{
//			printf("不是闰年\n");
//		}
//	}
//	return 0;
//}
//#include <stdio.h>
//#include <math.h>
//
//int prime(int n)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			break;
//		}
//	}
//	if (i > sqrt(n))
//		return 1;
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int count = 0;
//	int ret = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		ret = prime(n);
//		if (n == 0)
//		{
//			break;
//		}
//		if (ret == 1)
//		{
//			printf("%d是素数\n", n);
//		}
//		else
//		{
//			printf("%d不是素数\n", n);
//		}
//	}
//	for (i = 100; i <= 200; i++)
//	{
//		int k = prime(i);
//		if (k == 1)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d", count);
//	return 0;
//}
//#include <stdio.h>
//int Fun(int n)
//{
//    if (n == 5)
//        return 2;
//    else
//    {
//        int k = 2 * Fun(n + 1);
//        return k;
//    }
//}
//int main()
//{
//    printf("%d", Fun(2));
//    return 0;
//}
//#include <stdio.h>
//int fac(int n)
//{
//	if (n > 1)
//	{
//		n *= fac(n - 1);
//	}
//	else
//		n = 1;
//	return n;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int ret1 = 1;
//	//非递归
//	for (i = 1; i <= n; i++)
//	{
//		ret1 *= i;
//	}
//	printf("%d\n", ret1);
//	//函数递归
//	int ret2 = fac(n);
//	printf("%d", ret2);
//	return 0;
//}
//#include <stdio.h>
//void print(int n)
//{
//	printf("%d", n % 10);
//	if (n > 9)
//	{
//		print(n / 10);	
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}
//#include <stdio.h>
//int pow(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if (k == 1)
//	{
//		return n;
//	}
//	else
//	{
//		k--;
//		n *= pow(n, k);
//		return n;
//	}
//}
//int main()
//{
//	int n, k;
//	scanf("%d %d", &n, &k);
//	int ret = pow(n, k);
//	printf("%d", ret);
//	return 0;
//}
//#include <stdio.h>
//int DigitSum(int n)
//{
//	int total = 0;
//	total += n % 10;
//	if (n > 9)
//	{
//		n /= 10;
//		total += DigitSum(n);
//	}
//	return total;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = DigitSum(n);
//	printf("%d", ret);
//	return 0;
//}
#include <stdio.h>
int print(int n)
{
	int i = 0;
	int r = 0;
	r = n % 10;
	r = r * r;
	if (n > 9)
	{
		print(n / 10);
		return r;
	}
	
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = print(n);
	printf("%d", ret);
	return 0;
}