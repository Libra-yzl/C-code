#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bubble_sort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 1;//数据有序的标志
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//数据还未完全有序
			}
		}
		if (1 == flag)
			break;//此时数据完全有序，跳出循环
	}
}

void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test1()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	print(arr, sz);
}

int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}

void test2()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
}

void menu()
{
	printf("1.add 2.sub 3.mul 4.div\n");
}

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

int Div(int x, int y)
{
	return x / y;
}

void calc(int (*p)(int, int))
{
	int x = 0;
	int y = 0;

	printf("请输入两个操作数:");
	scanf("%d %d", &x, &y);

	printf("%d\n", p(x, y));
}

void test3()
{
	int input = 0;

	do
	{
		menu();

		printf("请选择:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			calc(add);
			break;
		case 2:
			calc(sub);
			break;
		case 3:
			calc(mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("没有该选项 请重新选择\n");
			break;
		}
	} while (input);
}

void Swap(char* buf1, char* buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort1(void* base, int num, int sz, int (*cmp)(const void*, const void*))
{
	for (int i = 0; i < num - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < num - 1 - i; j++)
		{
			//判断
			if (cmp((char*)base + j * sz, (char*)base + (j + 1) * sz) > 0)
			{
				//交换
				Swap((char*)base + j * sz, (char*)base + (j + 1) * sz, sz);
			}
		}
	}
}

void test4()
{
	int arr[] = { 2,4,5,8,7,6,9,1,3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	//bubble_sort1(void* base, size_t num, size_t sz, int(*)(const void*, const void*));
	bubble_sort1(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
}

struct Stu
{
	char name[20];
	int age;
};

int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}


void print1(struct Stu *s, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
}

int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void test5()
{
	struct Stu s[] = {{"zhangsan", 20}, {"lisi", 40}, {"wangwu", 50}};
	int sz = sizeof(s) / sizeof(s[0]);

	//printf("%s %d\n", s[0].name, s[0].age);
	bubble_sort1(s, sz, sizeof(s[0]), cmp_by_name);

	//bubble_sort1(s, sz, sizeof(s[0]), cmp_by_age);

	//print1(&s,sz);//数组名s就是数组元素首地址
	print1(s,sz);
}

int main()
{
	//test1();
	//test2();

	//test3();

	//test4();

	test5();
	return 0;
}