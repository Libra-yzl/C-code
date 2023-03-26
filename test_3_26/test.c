#define _CRT_SECURE_NO_WARNINGS 1

//简述大端字节序和小端字节序的概念

//大端字节序：把一个数据的低位保存在内存的高地址处，高位保存在内存的低地址处

//小端字节序：把一个数据的低位保存在内存的低地址处，高位保存在内存的高地址处


//设计一个小程序来判断当前机器的字节序
#include <stdio.h>

//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//	{
//		printf("小端\n");
//	}
//	else
//		printf("大端\n");
//	return 0;
//}

//int a = 1 
//如果将a的地址强制类型转换为char* 解引用得到的数字如果是1说明低地址存放的是数据的低位 就是小端字节序
//反之 就是大端字节序

int check_sys()
{
	int a = 1;
	return *(char*)&a;
}

int main()
{
	if (check_sys() == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}