#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//����ʵ���������ȴ�С
int Max(int x, int y) {
	if (x > y)
		return x;
	else
		return y;
}
////��ʵ���������Ƚϴ�С
//#define Max(x, y) (x>y?x:y)
int main()
{
	int a = 10;
	int b = 50;
	int max = Max(a, b);
	extern int Add(int, int);
	int add = Add(a, b);
	printf("max = %d\n", max);
	printf("add = %d\n", add);
	return 0;
}
//int main()
//{
//	printf("%d\n",strlen("c:\test\32\test.c"));
//	return 0;
//}
//int main()
//{
//	int num1, num2, sum;
//	num1 = 0;
//	num2 = 0;
//	sum = 0;
//	printf("��������������\n");
//	scanf("%d %d", &num1, &num2);
//	sum = num1 + num2;
//	printf("sum = %d \n", sum);
//	return 0;
//}