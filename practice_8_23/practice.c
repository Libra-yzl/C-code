#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//double Pow(double n, int k)
//{
//	if (0 == k)
//		return 1;
//	else if (k < 0)
//		return (1.0 / n) * Pow(1.0 / n, -k - 1);
//		//return 1.0 / Pow(n, -k);
//	else
//		return n * Pow(n, k - 1);
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = Pow(n, k);
//	printf("n^k = %lf", ret);
//	return 0;
//}

//#include <stdio.h>

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��

//int DigitSum(int n)
//{
//	if (n < 9)
//		return n;
//	else
//		return (n % 10) + DigitSum(n / 10);
//}
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int ret = DigitSum(n);
//		printf("ret = %d\n", ret);
//	}
//	return 0;
//}

//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������У����������ӡ��
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

//#include <stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void reverse_string(char* str)
//{
//	/*int len = (int)my_strlen(str);
//	char* left = str;
//	char* right = len + str - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}*/
//	int len = (int)my_strlen(str);
//	char tmp = *str;
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str + 1) > 1)
//	{
//		reverse_string(str + 1);
//	}
//	*(str + len - 1) = tmp;
//}
//
//int main()
//{
//	char str[10] = { 0 };
//	scanf("%s", str);
//	printf("%s\n", str);
//	reverse_string(str);
//	printf("%s\n", str);
//	return 0;
//}

//strlen��ģ�⣨�ݹ�ʵ�֣�

//#include <stdio.h>
//
//int my_strlen1(char* str)
//{
//	if (*str)
//		return 1 + my_strlen1(str+1);
//	else
//		return 0;
//}
//
//int my_strlen2(char* str, int count)
//{
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char str[10] = { 0 };
//	scanf("%s", str);
//	int ret = 0;
//	int count = 0;
//	//�ݹ�ʵ��
//	ret = my_strlen1(str);
//	printf("ret = %d\n", ret);
//	//�ǵݹ�ʵ��
//	ret = my_strlen2(str, count);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//
//int Fib1(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib1(n - 1) + Fib1(n - 2);
//}
//
//int Fib2(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
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
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int ret = 0;
//		//�ݹ���쳲���������
//		//ret = Fib1(n);
//		//printf("ret = %d\n", ret);
//		//�ǵݹ�
//		ret = Fib2(n);
//		printf("ret = %d\n", ret);
//	}
//	return 0;
//}