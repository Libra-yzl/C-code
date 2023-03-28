#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	char i = -20;
//	//
//	unsigned char j = 10;
//	printf("i+j = %d\n", i + j);
//	return 0;
//}

#include <stdio.h>

#include <limits.h>
#include <float.h>

//INT_MAX


//int main()
//{
//	int n = 9;
//	//00000000 00000000 00000000 00001001  --原码
//	//                                     --补码
//
//	float* pf = (float*)&n;
//
//	printf("%d\n", n);      //9
//
//	printf("%f\n", *pf);    //0.000000
//	//0  0000000 00000000000000000001001
//	//S  E       M
//	//(-1)^0 * 0.00000000000000000001001 * 2 ^ -126   约等于0
//	//     S     M(只是小数点之后的数字)       E(单精度真实值 + 127  全1和全0除外(特殊))
//	//正数S=0 负数S=-1							(双精度真实值 + 1023 全1和全0除外(特殊))
//
//	*pf = 9.0;
//	//1001.0 = 1.001 * 2^3
//	//(-1)^0 * 1.001 * 2^3
//	//S  E                    M
//	//0  3+127 = 130
//	//0  10000010             00100000000000000000000
//
//	printf("%d\n", n);//
//	//0  10000010             00100000000000000000000   --原码、补码（一个很大的正数）
//	printf("%f\n", *pf);//9.0
//
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	/*char* str[] = { "张三","李四","王五","赵六","钱七" };
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%s\n", str[i]);
//	}*/
//
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	int* arr[] = { arr1, arr2, arr3 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			//printf("%d ", arr[i][j]);
//			printf("%d ", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//void print1(int arr1[3][5], int r, int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			printf("%d ", arr1[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print2(int(*p)[5], int r, int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//void test1()
//{
//	int arr1[3][5] = { {1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7} };
//
//	//print1(arr1, 3, 5);
//	print2(arr1, 3, 5);
//}
//
//int main()
//{
//	test1();
//	return 0;
//}

//#include <stdio.h>
//void test(int arr[])//ok?
//{}
//void test(int arr[10])//ok?
//{}
//void test(int* arr)//ok?
//{}
//void test2(int* arr[20])//ok?
//{}
//void test2(int** arr)//ok?
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	//当一个函数的参数部分为一级指针的时候，函数能接收什么参数？
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}


//#include <stdio.h>
//
//
//void test(int arr[3][5])//ok？
//{}
//void test(int arr[][])//ok？
//{}
//void test(int arr[][5])//ok？
//{}
////总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
////因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
////这样才方便运算。
//void test(int* arr)//ok？
//{}
//void test(int* arr[5])//ok？
//{}
//void test(int(*arr)[5])//ok？
//{}
//void test(int** arr)//ok？
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//}

//( *( void(*)() )0 )()

//void (*signal(int, void(*)(int)))(int);


//用函数指针数组写一个计算器（加减乘除）

#include <stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("*********** 整数计算器 ***********\n");
	printf("       1.add        2.sub\n");
	printf("       3.mul        4.div\n");
	printf("             0.exit\n");
}
//
// //过于冗余
// 
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//
//	int ans = 0;
//
//	do
//	{
//		menu();
//		printf("请选择:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ans = Add(x,y);
//			printf("%d\n", ans);
//			break;
//		case 2:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ans = Sub(x,y);
//			printf("%d\n", ans);
//			break;
//		case 3:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ans = Mul(x,y);
//			printf("%d\n", ans);
//			break;
//		case 4:
//			printf("请输入两个操作数:");
//			scanf("%d %d", &x, &y);
//			ans = Div(x,y);
//			printf("%d\n", ans);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

#define OPTION 5
//
int main()
{
	int input = 0;

	int x = 0;
	int y = 0;

	//函数指针数组
	int (*pfArr[OPTION]) (int, int) = { 0, Add, Sub, Mul, Div };

	do
	{
		menu();

		printf("请选择:");
		scanf("%d", &input);

		if (input == 0)
		{
			printf("退出计算器\n");
			break;
		}

		if (input >= 1 && input < OPTION)
		{
			printf("请输入两个操作数:");
			scanf("%d %d", &x, &y);

			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else
		{
			printf("没有该选项 请重新选择\n");
		}
	} while (input);
	return 0;
}