#define _CRT_SECURE_NO_WARNINGS 1

////模拟实现memcpy
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	const char* ret = dest;
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return (char*)ret;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	/*memcpy(arr2, arr1, 20);*/
//	my_memcpy(arr2, arr1, 4);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

//模拟实现memcpy
#include <stdio.h>
#include <string.h>
#include <assert.h>

////60分的memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}

//100分的memcpy(memmove)
void* my_memcpy(void* dest, const void* src, size_t num)
{
	char* ret = dest;
	assert(dest && src);
	if (dest < src)
	{
		while (num--)//1、3区域 前->后
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (num--)//2号区域 后->前
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[5] = { 0 };
	//memcpy(arr2, arr1, 8);
	/*float arr1[] = { 1.0f,2.0f,3.0f,4.0f,5.0f };
	float arr2[5] = { 0.0 };*/
	my_memcpy(arr1, arr1 + 2, 8);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}