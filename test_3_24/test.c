#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int i = 0;
//							  //��X86������
//	for (i = 0; i <= 15; i++) //i�ĵ�ַ��arr[15]�ĵ�ַһ�����ı�arr[15], �൱�ڸı�i��������ѭ��
//	{
//		arr[i] = 0;
//		printf("hehe\n"); 
//	}
//	return 0;
//}

//ģ��ʵ��strcpy()
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcpy(char* dest, const char* src)
{
	//����
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