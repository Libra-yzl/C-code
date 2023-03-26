#define _CRT_SECURE_NO_WARNINGS 1

//8-1
////输出年份和月份 输出天数
//#include <stdio.h>
//
//int main()
//{
//	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//	int y = 0;
//	int m = 0;
//	while (scanf("%d %d", &y, &m) != EOF)
//	{
//		int day = days[m];
//		//判断闰年
//		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0) && m == 2)
//			day++;
//		printf("%d\n", day);
//	}
//	return 0;
//}


////判断是不是字母
//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	char ch = 0;
//
//	while (scanf("%c", &ch) != EOF)
//	{
//		if (isalpha(ch))
//			printf("%c is alphabet\n", ch);
//		else
//			printf("%c is not alphabet\n", ch);
//
//		//处理缓冲区的\n
//		getchar();
//	}
//	return 0;
//}


////字母大小写转换
//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	char ch = 0;
//
//	while (scanf("%c", &ch) != EOF)
//	{
//		if (islower(ch))
//			printf("%c\n", toupper(ch));
//		else if (isupper(ch))
//			printf("%c\n", tolower(ch));
//	}
//	return 0;
//}


////使用指针打印数组
//#include  <stdio.h>
//
//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	print(arr,sz);
//	return 0;
//}
//


////写一个函数，逆序字符串
//
//#include <stdio.h>
//#include <string.h>
//
//void reverse(char* str)
//{
//	int len = (int)strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char str[20];
//	printf("请输入字符串:>");
//	scanf("%[^\n]", str);
//	printf("逆序前字符串:%s\n", str);
//
//	reverse(str);
//	printf("逆序后字符串:%s\n", str);
//	return 0;
//}


////水仙花数
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10000; i++)
//	{
//		//计算位数
//		int count_i = 1;//个位数全是自幂数
//		int tmp = i;
//		while (tmp /= 10)
//		{
//			count_i++;
//		}
//
//		//计算
//		int sum = 0;
//		tmp = i;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, count_i);
//			tmp /= 10;
//		}
//
//		//判断
//		if (i == sum)
//			printf("%d ", i);
//	}
//	return 0;
//}


////求a的前n项和 如 a+aa+aaa+aaaa+aaaaa+...
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int n = 0;
//	int a = 0;
//	scanf("%d %d", &a, &n);
//
//	int sum = 0;
//	int k = 0;
//	for (int i = 0; i < n; i++)
//	{
//		k = k * 10 + a;
//		sum += k;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//
//	for (int i = 0; i < line)
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    double price = 0;
//    int m = 0;
//    int d = 0;
//    int flag = 0;
//    scanf("%lf %d %d %d", &price, &m, &d, &flag);
//
//    if (m == 11 && d == 11)
//    {
//        price = price * 0.7 - flag * 50;
//    }
//    else if (m == 12 && d == 12)
//    {
//        price = price * 0.8 - flag * 50;
//    }
//    if (price < 0.0)
//        price = 0.0;
//    printf("%.2lf\n", price);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//
//	//打印上半部分
//	for (int i = 0; i < line; i++)
//	{
//		//打印空格
//		for (int j = 0; j < line - i - 1; j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (int j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	//打印下半部分
//	for (int i = 0; i < line - 1; i++)
//	{
//		//打印空格
//		for (int j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (int j = 0; j < 2 * (line - 1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//求最小公倍数
//#include <stdio.h>
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &n, &m);
//
//	//最大公约数
//	int a = n;
//	int b = m;
//	int r = 1;
//	while (r)
//	{
//		r = a % b;
//		a = b;
//		b = r;
//	}
//	printf("%d\n", a);
//
//	//最小公倍数
//	int num = m * n / a;
//	printf("%d\n", num);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//
//	int r = m > n ? m : n;
//	while (1)
//	{
//		if ((r % m == 0) && (r % n == 0))
//			break;
//		else
//			r++;
//	}
//	printf("%d\n", r);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &n, &m);
//
//	int i = 1;
//	while (m * i % n != 0)
//		i++;
//	printf("%d\n", m * i);
//	return 0;
//}

#include <stdio.h>
#include <string.h>

void reverse(char* left, char* right)
{
	//逆置
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char str[20] = {0};
	//gets(str);
	scanf("%[^\n]", str);

	char* tmp = str;
	while (*tmp)
	{
		//逆序每个单词

		//找空格之前且不是'\0'
		char* start = tmp;
		char* end = tmp;
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		//此时end-1就是一个单词的最后一个字母
		reverse(start, end - 1);
		if (*end != '\0')
			tmp = end + 1;
		else
			tmp = end;
	}

	//整体逆置
	int len = (int)strlen(str);
	reverse(str, str + len - 1);
	printf("%s\n", str);

	return 0;
}