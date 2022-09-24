#define _CRT_SECURE_NO_WARNINGS 1

//模拟实现strlen
// 
//#include <stdio.h>
//#include <assert.h>
//
//size_t my_strlen(const char* str)
//{
//	assert(str);
//	const char* start = str;
//	const char* end = str;
//	while (*end)
//	{
//		end++;
//	}
//	return end - start;
//}
//
//int main()
//{
//	char str1[] = "abcdef";
//	printf("%d\n", (int)my_strlen(str1));
//	return 0;
//}


////模拟实现strcmp
//// 
//#include <stdio.h>
//#include <assert.h>
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//	return *s1 - *s2;
//}
//
//int main()
//{
//	char str1[] = "";
//	char str2[] = "";
//	printf("%d\n", my_strcmp(str1, str2));
//	return 0;
//}
//模拟实现strcpy
// 
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* s = dest;
//	while (*s++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char str1[] = "abcdef";
//	char str2[10];
//	printf("%s\n", my_strcpy(str2, str1));
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
//	char* s = dest;
//	while (*s)
//	{
//		s++;
//	}
//	while (*s++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char str1[10] = "abcdef";
//	char str2[] = "ghi";
//	printf("%s\n", my_strcat(str1, str2));
//	return 0;
//}
////模拟实现strstr
//// 
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
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
//	char str1[] = "abbbcdef";
//	char str2[] = "bcdf";
//	printf("%s\n", my_strstr(str1, str2));
//	return 0;
//}
//模拟实现memcpy
// 
//#include <stdio.h>
//#include <assert.h>
//
//void* my_memecpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* s = (char*)dest;
//	while (num--)
//	{
//		*s = *(char*)src;
//		s++;
//		src = (char*)src + 1;
//	}
//	return (char*)dest;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[5] = { 0 };
//	my_memecpy(arr2, arr1, 16);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}
// 
//#include <stdio.h>
//#include <assert.h>
//
//void* my_memecpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* s = dest;
//	while (num--)
//	{
//		*s = *(char*)src;
//		s++;
//		src = (char*)src + 1;
//	}
//	return dest;
//}
//
//int main()
//{
//	float arr1[] = { 1.0f,2.0f,3.0f,4.0f,5.0f };
//	float arr2[5] = { 0.0 };
//	my_memecpy(arr2, arr1, 8);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%f ", arr2[i]);
//	}
//	return 0;
//}
//模拟实现memmove
//#include <stdio.h>
//#include <assert.h>
//
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* s = dest;
//	//从前向后
//	if (dest < src)
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else//从后向前
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return s;
//}
//
//int main()
//{
//	/*int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[5] = { 0 };*/
//	float arr1[] = { 1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f };
//	//my_memmove(arr1, arr1 + 2, 20);
//	my_memmove(arr1 + 2, arr1, 20);
//	/*int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}*/
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%f ", arr1[i]);
//	}
//	return 0;
//}

//memset

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	memset(arr, 0, 9);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}