#define _CRT_SECURE_NO_WARNINGS 1

//计算器 (回调函数实现)
//#include <stdio.h>
//
//void menu()
//{
//	printf("*****************************************\n");
//	printf("********    1. Add      2. Sub   ********\n");
//	printf("********    3. Mul      4. Div   ********\n");
//	printf("***************** 0.exit ****************\n");
//	printf("*****************************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void calc(int (*p)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数:>");
//	scanf("%d %d", &x, &y);
//	int ret = p(x, y);
//	printf("%d\n", ret);
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:> ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

////冒泡排序实现
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void bubble_sort(int arr[], int sz)
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
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void test1()
//{
//	int arr[10] = { 0,5,8,4,7,9,6,3,1,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	print(arr, sz);
//}
//
////测试qsort排序整形数据
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
////测试qsort排序结构体数据
//struct stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//
//void test3()
//{
//	struct stu s[] = { {"zhangsan", 20}, {"lisi", 50}, {"wangwu", 40} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
//	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//}
//void test2()
//{
//	int arr[10] = { 0,5,8,4,7,9,6,3,1,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print(arr, sz);
//}
//
//void Swap(char* buf1, char* buf2, int width)
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
//void bubble_sort2(void* base, int sz, int width, int (*cmp)(const void* e1, const void*e2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//比较
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				//交换
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//void test4()
//{
//	int arr[10] = { 0,5,8,4,7,9,6,3,1,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort2(arr, sz, sizeof(arr[0]), cmp_int);
//	print(arr, sz);
//}
//
//void test5()
//{
//	struct stu s[] = { {"zhangsan", 20}, {"lisi", 50}, {"wangwu", 40} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//bubble_sort2(s, sz, sizeof(s[0]), cmp_stu_by_age);
//	bubble_sort2(s, sz, sizeof(s[0]), cmp_stu_by_name);
//}
//
//int main()
//{
//	//test1();//冒泡排序
//	//test2();//测试qsort对整形数据排序
//	//test3();//测试qsort对结构体数据排序
//	//test4();
//	test5();
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//void print_arr(int(*arr), int row, int col)
//{
//
//}
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	print_arr(arr, 3, 5);
//}

//int main()
//{
//	int a[5] = { 5, 4, 3, 2, 1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}

//使用qsort函数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2; //升序
	//return *(int*)e2 - *(int*)e1; //降序
}

print_int(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//void test1()
//{
//	int arr[10] = { 1,2,0,3,5,8,4,7,6,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_int(arr, sz);
//}

struct S
{
	char name[20];
	double height;
	int age;
	double weight;
};

int cmp_S_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct S*)e1)->name, ((struct S*)e2)->name);
}

int cmp_S_by_age(const void* e1, const void* e2)
{
	return ((struct S*)e1)->age - ((struct S*)e2)->age;
}

int cmp_S_by_height(const void* e1, const void* e2)
{
	return (int)(((struct S*)e1)->height - ((struct S*)e2)->height);
}

int cmp_S_by_weight(const void* e1, const void* e2)
{
	return (int)(((struct S*)e1)->weight - ((struct S*)e2)->weight);
}

void print_stu(struct S* s, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("name:%s      ", s->name);
		printf("age:%d       ", s->age);
		printf("height:%lf   ", s->height);
		printf("weight:%lf\n", s->weight);
		s++;
	}
	printf("\n");
}

//void test2()
//{
//	struct S s[] = { {"zhangsan",172.5,20,69.5},{"lisi",178.5,38,66.5},\
//	{"wangwu",175,34,60} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_S_by_name);
//	printf("指定name为排序对象:\n");
//	print_stu(s, sz);
//	qsort(s, sz, sizeof(s[0]), cmp_S_by_age);
//	printf("指定age为排序对象:\n");
//	print_stu(s, sz);
//	qsort(s, sz, sizeof(s[0]), cmp_S_by_height);
//	printf("指定height为排序对象:\n");
//	print_stu(s, sz);
//	qsort(s, sz, sizeof(s[0]), cmp_S_by_weight);
//	printf("指定weight为排序对象:\n");
//	print_stu(s, sz);
//}

void Swap(char* buf1, char* buf2, int width)
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
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void test3_bubble_sort()
{
	int arr[10] = { 2,4,5,1,3,8,6,9,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print_int(arr, sz);
}

void test4_bubble_sort()
{
	struct S s[] = { {"zhangsan",172.5,20,69.5},{"lisi",178.5,38,66.5},\
	{"wangwu",175,34,60} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_S_by_name);
	printf("指定name为排序对象:\n");
	print_stu(s, sz);
	bubble_sort(s, sz, sizeof(s[0]), cmp_S_by_age);
	printf("指定age为排序对象:\n");
	print_stu(s, sz);
	bubble_sort(s, sz, sizeof(s[0]), cmp_S_by_height);
	printf("指定height为排序对象:\n");
	print_stu(s, sz);
	bubble_sort(s, sz, sizeof(s[0]), cmp_S_by_weight);
	printf("指定weight为排序对象:\n");
	print_stu(s, sz);
}

int main()
{
	//test1();//使用qsort函数对整型数据排序
	//test2();//使用qsort函数对结构体数据排序
	test3_bubble_sort();//模拟实现qsort函数对整形数据排序
	test4_bubble_sort();//模拟实现qsort函数对结构体数据排序
	return 0;
}