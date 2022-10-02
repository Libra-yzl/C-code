#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//
//int main()
//{
//	int a = -10;
//	//-10
//	//原码:10000000000000000000000000001010
//	//反码:11111111111111111111111111110101
//	//补码:1111 1111 1111 1111 1111 1111 1111 0110
//	//如果存放的是补码，那么内存中存放的就是 fffffff6
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int a = 0x11223344;
//	//这里我用的是十六进制表示
//	//在内存中存放的就是这几个数字
//	return 0;
//}

//#include <stdio.h>
//
//int check_model()
//{
//	int a = 1;
//	//如果返回1那就是小端存储模式
//	//如果返回0那就是大端存储模式
//	return *(char*)&a;
//}
//
//int main()
//{
//	int ret = check_model();//封装一个函数根据返回值确定大小端
//	if (1 == ret)
//		printf("小端存储模式\n");
//	else
//		printf("大端存储模式\n");
//	return 0;
//}

#include <stdio.h>

int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("%d %d %d", a, b, c);
	return 0;
}
