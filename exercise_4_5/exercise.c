#define _CRT_SECURE_NO_WARNINGS 1


////杨辉三角
//#define ROW 10
//#define COL 10
//
//#include <stdio.h>
//
//int main()
//{
//	int arr[ROW][COL] = {0};
//	for (int i = 0; i < ROW; i++)
//	{
//		//输入数字
//		for (int j = 0; j <= i; j++)
//		{
//			if (i == j)
//				arr[i][j] = 1;
//			if (j == 0)
//				arr[i][j] = 1;
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//
//	//打印时打印空格
//	for (int i = 0; i < ROW; i++)
//	{
//		//空格
//		for (int space = 0; space < ROW - i - 1; space++)
//		{
//			printf("  ");
//		}
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%-3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


////杨氏矩阵 中查找指定数字
//
//#include <stdio.h>
//
//void find_num(int arr[3][3], int* px, int* py, int k)
//{
//	int i = 0;
//	int j = *py - 1;
//	int flag = 0;
//
//	while (i < *px && j >= 0)
//	{
//		if (arr[i][j] < k)
//			i++;
//		else if (arr[i][j] > k)
//			j--;
//		else
//		{
//			*px = i;
//			*py = j;
//			flag = 1;
//		}
//	}
//	if (0 == flag)
//	{
//		*px = -1;
//		*py = -1;
//	}
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	scanf("%d", &k);
//	int x = 3;
//	int y = 3;
//	find_num(arr, &x, &y, k);
//	if (x == -1 && y == -1)
//		printf("找不到\n");
//	else
//		printf("找到了 下标是%d %d", x, y);
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
//                {
//                    printf("* ");
//                }
//                else
//                {
//                    printf("  ");
//                }
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}


// #include <stdio.h>

// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     int arr[n+1];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     int k = 0;
//     scanf("%d", &k);

//     int j = n-1;
//     for (; j >= 0; j--)
//     {
//         if (arr[j] > k)
//         {
//             arr[j+1] = arr[j];
//         }
//         else 
//         {
//             break;
//         }
//     }
//     arr[j+1] = k;

//     for (int i = 0; i < n+1; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }
//#define N 5
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//    /*int n = 0;
//    scanf("%d", &n);*/
//    int arr[N + 1];
//    for (int i = 0; i < N; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int k = 0;
//    scanf("%d", &k);
//    arr[N] = k;
//    qsort(arr, N + 1, sizeof(int), cmp);
//    for (int i = 0; i < N + 1; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}


//左旋字符串
#include <stdio.h>
#include <string.h>


//char* left_move(char* str, int k)
//{
//	int len = (int)strlen(str);
//
//	k %= len;
//	for (int i = 0; i < k; i++)
//	{
//		char tmp = *str;
//
//		for (int j = 0; j < len - 1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//
//		*(str + len - 1) = tmp;
//	}
//	return str;
//}

//#include <assert.h>
//
//void reverse(char* str1, char* str2)
//{
//	assert(str1 && str2);
//
//	while (str1 < str2)
//	{
//		char tmp = *str1;
//		*str1 = *str2;
//		*str2 = tmp;
//		str1++;
//		str2--;
//	}
//}
//
//char* left_move(char* str, int k)
//{
//	int len = (int)strlen(str);
//
//	k %= len;
//	reverse(str, str + k - 1);
//	reverse(str + k, str + len - 1);
//	reverse(str, str + len - 1);
//
//	return str;
//}
//
//int main()
//{
//	char str[20] = "ABCDEF";
//	int k = 0;
//	scanf("%d", &k);
//
//	left_move(str, k);
//	printf("%s\n", str);
//	return 0;
//}




//判断是否为左旋字符串

#include <stdio.h>
#include <string.h>
#include <assert.h>

//int is_left_move(char* str1, char* str2)
//{
//	int len1 = (int)strlen(str1);
//	int len2 = (int)strlen(str2);
//
//	if (len1 != len2)
//		return 0;
//
//	for (int i = 0; i < len1; i++)
//	{
//		char tmp = *str1;
//
//		for (int j = 0; j < len1 - 1; j++)
//		{
//			*(str1 + j) = *(str1 + j + 1);
//		}
//
//		*(str1 + len1 - 1) = tmp;
//		if (strcmp(str1, str2) == 0)
//			return 1;
//	}
//	return 0;
//}

//int is_left_move(char* str1, char* str2)
//{
//	int len1 = (int)strlen(str1);
//	int len2 = (int)strlen(str2);
//
//	if (len1 != len2)
//		return 0;
//
//	strncat(str1, str1, len1);
//	char* ret = strstr(str1, str2);
//	if (ret != NULL)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	char str1[20] = "ABCDEF";
//	char str2[] = "CDEFab";
//
//	int ret = is_left_move(str1, str2);
//	if (1 == ret)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int a, b, c;
//    while (scanf("%d %d %d", &a, &b, &c) != EOF)
//    {
//        if (a + b > c && a + c > b && b + c > a)
//        {
//            if (a == b && a == c)
//                printf("Equilateral triangle!\n");
//            else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
//                printf("Isosceles triangle!\n");
//            else
//                printf("Ordinary triangle!\n");
//        }
//        else {
//            printf("Not a triangle!\n");
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int input = 0;
//    while (scanf("%d", &input) != EOF)
//    {
//        switch (input)
//        {
//        case 200:
//            printf("OK\n");
//            break;
//        case 202:
//            printf("Accepted\n");
//            break;
//        case 400:
//            printf("Bad Request\n");
//            break;
//        case 403:
//            printf("Forbidden\n");
//            break;
//        case 404:
//            printf("Not Found\n");
//            break;
//        case 500:
//            printf("Internal Server Error\n");
//            break;
//        case 502:
//            printf("Bad Gateway\n");
//            break;
//        }
//    }
//}

//#include <stdio.h>
//
//int main()
//{
//    int max = 0;
//    int min = 100;
//    int count = 0;
//    int n = 0;
//    int sum = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        if (n > max)
//            max = n;
//        if (n < min)
//            min = n;
//        count++;
//        sum += n;
//        if (count == 7)
//        {
//            printf("%.2lf\n", ((sum - max - min) / 5.0));
//            count = 0;
//            sum = 0;
//            max = 0;
//            min = 100;
//        }
//    }
//    return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    int count = 0;
//    char ch = 0;
//    while ((ch = getchar()) != '0')
//    {
//        if (ch == 'A')
//            count++;
//        else
//            count--;
//    }
//    if (count > 0)
//        printf("A\n");
//    else if (count == 0)
//        printf("E\n");
//    else
//        printf("B\n");
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//
//	if (!*str2)
//		return (char*)str1;
//
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return (char*)p;
//		p++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	const char* str1 = "abbbcdef";
//	const char* str2 = "bcd";
//
//	printf("%s\n", my_strstr(str1, str2));
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Swap(char* buf1, char* buf2, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int num, int sz, int (*cmp) (const void*, const void*))
{
	for (int i = 0; i < num - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < num - i - 1; j++)
		{
			if (cmp(((char*)base + j * sz), ((char*)base + (j + 1) * sz)) > 0)
			{
				flag = 0;
				Swap((char*)base + j * sz, (char*)base + (j + 1) * sz, sz);
			}
		}
		if (1 == flag)
			break;
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void test1()
{
	int arr[10] = { 1,3,5,6,8,4,7,2,10,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//qsort()
	bubble_sort(arr, sz, sizeof(int), cmp_int);
	print(arr, sz);
}

struct Stu
{
	char name[20];
	int age;
};

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int cmp_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void print_s(struct Stu* s, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
}

void test2()
{
	struct Stu s[] = { {"zhangsan", 20}, {"lisi", 40}, {"wangwu", 50} };
	int sz = sizeof(s) / sizeof(s[0]);
	//bubble_sort(s, sz, sizeof(s[0]), cmp_name);
	bubble_sort(s, sz, sizeof(s[0]), cmp_age);
	print_s(s, sz);
}

int main()
{
	//test1();
	test2();
	return 0;
}