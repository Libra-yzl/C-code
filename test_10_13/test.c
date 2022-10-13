#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	//int*p = (int*)malloc(INT_MAX + 1);
//	int* p = (int*)calloc(40, sizeof(int));
//	int i = 0;
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	int* ptr = realloc(p, 80);
//	if (ptr != NULL)
//	{
//		p = ptr;
//		ptr = NULL;
//	}
//	for (i = 0; i < 20; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


////一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//
////编写一个函数找出这两个只出现一次的数字。
//
//#include <stdio.h>
//
//void FindNum(int* arr, int sz)
//{
//	int i = 0;
//	//int count = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int j = 0;
//		int flag = 1;
//		for (j = 0; j < sz; j++)
//		{
//			if (i != j)
//			{
//				if (arr[i] == arr[j])
//				{
//					flag = 0;
//					break;
//				}
//			}
//		}
//		if (flag == 0)
//		{
//			continue;
//		}
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[20] = { 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,11 };
//	int sz = sizeof(arr) / sizeof (arr[0]);
//	FindNum(arr, sz);
//	return 0;
//}


////模拟实现strcpy
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[] = "cdefgh";
//	char str2[10] = "ab";
//	printf("%s\n", my_strcpy(str2, str1));
//	return 0;
//}

//模拟实现strncpy
// 
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (num--)
//	{
//		if (*src == '\0')
//		{
//			*dest = 0;
//		}
//		else
//		{
//			*dest++ = *src++;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[] = "cdefgh";
//	char str2[10] = "ab";
//	printf("%s\n", my_strncpy(str2, str1, 9));
//	return 0;
//}

////模拟实现strcat
//// 
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[10] = "abcde";
//	char str2[] = "fgh";
//	printf("%s\n", my_strcat(str1, str2));
//	return 0;
//}

////模拟实现strncat
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncat(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (num--)
//	{
//		*dest++ = *src++;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[10] = "abcde";
//	char str2[] = "fgh";
//	printf("%s\n", my_strncat(str1, str2, 2));
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	char str1[] = "123+4a56.78";
//	printf("%d\n", atoi(str1));
//	return 0;
//}

////模拟实现atoi
//
//#include <stdio.h>
//#include <ctype.h>
//
//int my_atoi(const char* str)
//{
//	while (isspace(str))
//	{
//		str++;
//	}
//}
//
//int main()
//{
//	char str1[] = " 123456.78";
//	printf("%d\n", my_atoi(str1));
//	return 0;
//}