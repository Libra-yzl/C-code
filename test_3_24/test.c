#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int i = 0;
//							  //在X86环境下
//	for (i = 0; i <= 15; i++) //i的地址与arr[15]的地址一样，改变arr[15], 相当于改变i，导致死循环
//	{
//		arr[i] = 0;
//		printf("hehe\n"); 
//	}
//	return 0;
//}

//模拟实现strcpy()
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcpy(char* dest, const char* src)
{
	//断言
	assert(dest && src);

	const char* start = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return (char*)start;
}

int main()
{
	char str1[] = "###################";
	char str2[] = "hello";

	my_strcpy(str1, str2);
	printf("%s\n", str1);
	return 0;
}