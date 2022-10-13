#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("1.加法            2.减法\n");
	printf("3.乘法            4.除法\n");
	printf("0.退出                  \n");
}

void calc(int(*pf)(int x, int y))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数>:");
	scanf("%d %d", &x, &y);
	int ret = pf(x, y);
	printf("%d\n", ret);
}

//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(add);
//			break;
//		case 2:
//			calc(sub);
//			break;
//		case 3:
//			calc(mul);
//			break;
//		case 4:
//			calc(div);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int (*pf[5])(int, int) = { 0, add, sub, mul, div };
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出计算器\n");
//			break;
//		}
//		if (input >= 1 && input <= 4)
//		{
//			printf("请选择两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = pf[input](x, y);
//			printf("%d\n", ret);
//		}
//		else
//			printf("选择错误，请重新选择\n");
//	} while (input);
//	return 0;
//}

//模拟实现qsort

//void bubble_sort(int arr[10], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}

//void swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}

void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//交换
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void print1(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int cmp(const void* e1, const void* e2)
{
	return *((char*)e1) - *((char*)e2);
}

struct tag
{
	char name[10];
	int age;
	char addr[50];
};

void test1()
{
	struct tag t[] = { {"zhangsan", 20, "lanzhou"}, {"lisi", 19, "xian"}, {.age = 22, .name = "wangwu", .addr = "zhengzhou"} };
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//bubble_sort(arr, sz);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp);
	print1(arr, sz);
}

int cmp_age(const void* e1, const void* e2)
{
	return ((struct tag*)e1)->age - ((struct tag*)e2)->age;
}

void print2(struct tag *pt)
{
	int i = 0;
	for (i = 0; i < 3; i++)
		printf("%-10s %-10d %-10s\n", pt[i].name, pt[i].age, pt[i].addr);
}
#include <string.h>

int cmp_name(const void* e1, const void* e2)
{
	return strcmp((char*)e1, (char*)e2);
}

void test2()
{
	struct tag t[] = { {"zhangsan", 20, "lanzhou"}, 
		{"lisi", 19, "xian"}, {.age = 22, .name = "wangwu", .addr = "zhengzhou"} };
	int sz = sizeof(t) / sizeof(t[0]);
	bubble_sort(t, sz, sizeof(t[0]), cmp_name);
	/*int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%-10s %-10d %-10s", t[i].name, t[i].age, t[i].addr);
		printf("\n");
	}*/
	print2(&t);
}

int cmp_float(const void* e1, const void* e2)
{
	return *(float*)e1 - *(float*)e2;
}

void print3(float* pf, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%.2f ", *(pf + i));
	}
}

void test3()
{
	float f[10] = { 1.0f,2.0f,4.0f,8.0f,6.0f,3.0f,5.0f,7.0f,10.0f,9.0f };
	int sz = sizeof(f) / sizeof(f[0]);
	bubble_sort(f, sz, sizeof(f[0]), cmp_float);
	print3(f, sz);
}

int main()
{
	//测试bubble_sort
	//test1();//整型数据测试
	test2();//结构体测试
	//test3();//浮点数测试
	return 0;
}