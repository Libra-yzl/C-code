#define _CRT_SECURE_NO_WARNINGS 1

////模拟实现qsort
//
//#include <stdio.h>
//
//void buttle_sort(void* base, int width, size_t size, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		int j = 0;
//		for (j = 0; j <)
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	bubble_sort(arr, 10, sizeof(arr[0]), cmp);
//	return 0;
//}


#include <stdio.h>

void menu()
{
	printf("1.add             2.sub\n");
	printf("3.mul             4.div\n");
	printf("0.exit                 \n");
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
int div(int x, int y)
{
	return x / y;
}

int main()
{
	int(*pf[5])(int, int) = { 0,add, sub,mul, div };
	int input = 0;
	int x = 0;
	int y = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		if (0 == input)
		{
			printf("退出计算器\n");
			break;
		}
		if (input >= 1 && input <= 4)
		{
			printf("请选择两个操作数:>");
			scanf("%d %d", &x, &y);
			int ret = pf[input](x, y);
			printf("%d\n", ret);
		}
		else
			printf("选择错误，请重新选择\n");
	} while (input);
	return 0;
}