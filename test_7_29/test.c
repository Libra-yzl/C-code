#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;
//	b = ++c, c++, ++a, a++;
//	b += a++ + c;
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	//^��λ���
//	//��ͬΪ0������Ϊ1
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("a = %d, b = %d\n", a, b);
//	a = a ^ b;
//	b = b ^ a;
//	a = a ^ b;
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}
//дһ���������ز����������� 1 �ĸ�����
//#include <stdio.h>
//
//int binary(int n)
//{
//	int count = 0;
//	int flag = 1;
//	while (flag != 0)
//	{
//		if ((n & flag) != 0) //flag��ֵ�ı䣬��λ��Ľ����ֻ��1��0
//		{
//			count++;
//		}
//		flag = flag << 1;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = binary(n);
//	printf("%d", num);
//	return 0;
//}
//���������������в�ͬλ�ĸ���
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int flag = 1;
//	int count = 0;
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((m & flag) != (n & flag))
//		{
//			count++;
//		}
//		flag = flag << 1;
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int count = 0;
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((m >> i) != (n >> i))
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//����n��k�η�
//#include <stdio.h>
//
//double pow(int n, int k)
//{
//	if (k == 0)
//		return 1;
//	else if (k < 0)
//		return 1.0 / pow(n, -k);
//	else
//		return n * pow(n, k - 1);
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = pow(n, k);
//	printf("%lf", ret);
//	return 0;
//}
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//#include <stdio.h>
//int DigitSum(int n)
//{
//	//1234
//	//(123)+4
//	//(12)+3+4
//	//(1)+2+3+4
//	if (n < 10)
//		return n;
//	else
//		return DigitSum(n / 10) + n % 10;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = DigitSum(n);
//	printf("%d", sum);
//	return 0;
//}
//��дһ������ reverse_string(char* string)���ݹ�ʵ�֣�
//#include <stdio.h>
//int my_strlen(char* str)
//{
//	int count = 0;
//	while ((*str) != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//void reverse_string(char* str)
//{
//	int len = my_strlen(str);
//	char tmp = *str;
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str + 1) > 1)
//	{
//		reverse_string(str + 1);
//	}
//	*(str + len - 1) = tmp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}
//�ݹ�ʵ��n�Ľ׳�
//#include <stdio.h>
//int fac(int n)
//{
//	if (n > 1)
//		return n * fac(n - 1);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("%d", ret);
//	return 0;
//}
//����n��k�η�
//#include <stdio.h>
//double pow(int n, int k)
//{
//	if (k == 0)
//		return 1;
//	else if (k < 0)
//		return 1.0 / pow(n, -k);
//	else
//		return n * pow(n, k - 1);
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = pow(n, k);
//	printf("%lf", ret);
//	return 0;
//}
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//#include <stdio.h>
//int DigitSum(int n)
//{
//	//1234
//	//(123)+4
//	//(12)+3+4
//	//(1)+2+3+4   n%10
//	if (n < 10)
//		return n;
//	else
//		return DigitSum(n / 10) + n % 10;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = DigitSum(n);
//	printf("%d", sum);
//	return 0;
//}
//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//#include <stdio.h>
//
//int my_strlen(char* string)
//{
//	int count = 0;
//	while ((*string) != '\0')
//	{
//		string++;
//		count++;
//	}
//	return count;
//}
//void reverse_string(char* string)
//{
//	int len = my_strlen(string);
//	char tmp = *string;
//	*string = *(string + len - 1);
//	*(string + len - 1) = '\0';
//	if (my_strlen(string + 1) > 1)
//		reverse_string(string + 1);
//	*(string + len - 1) = tmp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int k = 0;
//    int sum = 0;
//    scanf("%d", &n);
//    for (i = 0; i <= n; i++)
//    {
//        scanf("%d ", k);
//        sum += k;
//    }
//    printf("%d", sum);
//    return 0;
//}
////����쳲���������
//#include <stdio.h>
////�ݹ�ʵ��
//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	//�ǵݹ�
//	int k = 0;
//	scanf("%d", &k);
//	long long a = 1;
//	long long b = 1;
//	long long c = 0;
//	int i = 0;
//	if (k <= 2)
//	{
//		printf("%lld", a);
//	}
//	else
//	{
//		for (i = 2; i < k; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		printf("%lld", c);
//	}
//	return 0;
//}
//#include <stdio.h>
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//void reverse_string(char* str)
//{
//	int len = my_strlen(str);
//	char tmp = *str;
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str + 1) > 1)
//		reverse_string(str + 1);
//	*(str + len - 1) = tmp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}
//#include <stdio.h>
//int DigitSum(int n)
//{
//	if (n < 10)
//		return n;
//	else
//		return DigitSum(n / 10) + n % 10;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = DigitSum(n);
//	printf("%d", ret);
//	return 0;
//}
//strlen��ģ��
//#include <stdio.h>
//int len_str(char* arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		arr++;
//		count++;
//	}
//	return count;
//}
//int lens_str(char* arr)
//{
//	if (*arr == '\0')
//		return 0;
//	else 
//		return 1+lens_str(arr + 1);
//}
//int main()
//{
//	int ret = 0;
//	int rec = 0;
//	char arr[] = "abcdef";
//	int len = strlen(arr);
//	printf("%d\n", len);
//	//�ǵݹ�
//	ret = len_str(arr);
//	printf("%d\n", ret);
//	//�ݹ�
//	rec = lens_str(arr);
//	printf("%d", rec);
//	return 0;
//}