#define _CRT_SECURE_NO_WARNINGS 1

//猜数字游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//RAND_MAX 0-0x777f(32767)
int menu() 
{
	printf("***************************************************\n");
	printf("***************************************************\n");
	printf("******     1.play             0.exit    ***********\n");
	printf("***************************************************\n");
	printf("***************************************************\n");
	return 0;
};

//void game()
//{
//	
//	int input = 0;
//	printf("请输入:> ");
//	scanf("%d", &input);
//	if (input == 1)
//	{
//		printf("开始游戏");
//	}
//	else if (input == 0)
//	{
//		printf("退出游戏");
//	}
//	else
//	{
//		printf("输入错误，请重试:>");
//	}
//}
void game()
{
	//printf("猜数字\n");
	//1.生成随机数 rand()函数
	int ret = 0;
	int guess = 0;
	//拿时间戳来设置随机数的生成起始点
	
	ret = rand() % 100 + 1; //生成1-100之间的随机数
	//printf("%d\n", ret);
	//2.猜数字
	printf("开始猜吧！\n");
	while (1)
	{
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
			continue;
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
			continue;
		}
		else
		{
			printf("恭喜你，你猜对了!\n");
			break;
		}
	}
	
}
int main()  //主函数
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//游戏函数
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	
	return 0;
}

////9*9乘法表
//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ",i,j,i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////10个整数中的最大值
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { -1,-2,-4,-3,-5,-6,-7,-8,-9,-10 };
//	int i = 0;
//	int max = arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//	printf("max = %d", max);
//	return 0;
//}

//分数求和 
//#include<stdio.h>

//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("sum = %lf", sum);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	double sum1 = 0.0;
//	double sum2 = 0.0;
//	for (i = 1; i <= 100; i += 2)
//	{
//		sum1 = sum1 + 1.0 / i;
//	}
//	for (i = 2; i <= 100; i += 2)
//	{
//		sum2 = sum2 + 1.0 / i;
//	}
//	printf("sum = %lf", sum = sum1 - sum2);
//	return 0;
//}

////打印整数1-100之间出现多少个数字9
//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9) 
//		{
//			printf("%d ", i);
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount = %d", count);
//	return 0;
//}

////打印100-200之间的素数
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 101; i <= 200; i += 2)  //--算法更优 // for (i = 100 ; i <= 200 ; i++)
//	{
//		int n = 0;
//		for (n = 2; n <= sqrt(i); n++)
//		{				   //试除法 (判断素数的方法之一)即用i除以2到i-1的数
//			if (i % n == 0)//如果模为0，证明i可以被除1和本身以外的数整除，即i不是素数
//				break;
//		}
//		//有两种情况到这里
//		//1.break到这里；
//		//2.第二个循环条件不满足，也就是n >= i 的时候，跳到这里  当遇到这种情况时，证明i就是素数
//		if (n > sqrt(i))
//		{
//			k++;
//			printf("%d ", i);
//		}
//	}
//	printf("\nk = %d", k);
//	return 0;
//}

////打印1000-2000年的闰年
//#include<stdio.h>
//
//int main()
//{
//	int y = 0;
//	int i = 0; //计算有多少个闰年
//	printf("1000-2000年的普通闰年为:> ");
//	for (y = 1000; y <= 2000; y++) //
//	{
//		/*if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//		{
//			printf("%d ", y);
//		}*/    //更简便的方法
//		if (y % 4 == 0 && y % 100 != 0) //闰年的判断 1
//		{
//			printf("%d ", y);
//			i++;
//		}
//		else if (y % 400 == 0)          //闰年的判断 2
//		{
//			printf("%d ", y);
//			i++;
//		}
//		
//	}
//	printf("\n1000-2000年的世纪闰年为:> ");
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (y % 400 == 0 && y % 100 == 0)
//		{
//			printf("%d ", y);
//		}
//	}
//	printf("\n%d", i);
//	return 0;
//}

//#include <stdio.h>
////求两个数的最大公约数
//int main()
//{
//	int m, n, r;
//	printf("请输入两个数:>");
//	scanf("%d %d", &m, &n);
//	/*while (r = m % n)
//	{
//		m = n;
//		n = r;
//	}
//	printf("%d", n);*/
//	/*if (m < n)
//	{
//		int tmp = m;
//		m = n;
//		n = tmp;
//	}*/
//	while (1)
//	{
//		if (m % n == 0)
//		{
//			printf("它们的最大公约数为:%d", n);
//			break;
//		}
//		else
//		{
//			int tmp = m % n;
//			m = n;
//			n = tmp;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


////三个数从大到小输出
//#include <stdio.h>
//
//int main()
//{
//	int a,b,c;
//	printf("请输入三个数:");
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("三个数从大到小排列:>%d %d %d",a,b,c);
//	return 0;
//}
////用户登陆系统，最多可输入三次密码，若均输入错误，退出程序，若成功登录，提示用户登陆成功
//#include <stdio.h>
//int main()
//{
//	int i = 0;//定义登录次数
//	char passward[20];
//	printf("请输入密码:> ");
//	
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", passward);
//		//if (pwd == "123456") //err == 不能判断字符串相等 而要用strcmp()函数		
//		if (strcmp(passward ,"123456") == 0)
//		{
//			printf("登陆成功");
//			break;
//		}
//		else
//		{
//			printf("密码错误，请重试:>");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码均错误，将退出程序\n");
//	}
//	return 0;
//}

////打印一组演示字符，使得从两边向中间靠拢
//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//#include <stdlib.h>
//
//int main()
//{
//	char str1[] = "welcome to our home !!!";
//	char str2[] = "#######################";
//	int left = 0;//最左边元素下标
//	int right = strlen(str1) - 1;
//	//int right = sizeof(str1) / sizeof(str1[0]) - 2;
//	//注意，字符串的结尾以'\0'结尾，sizeof()计算时将其包括在内，而strlen()函数没有
//
//	while (left <= right) //当left <= right时，进入循环
//	{
//		str2[left] = str1[left];
//		str2[right] = str1[right];
//		left++;
//		right--;
//		Sleep(1000);  //----Sleep() 以ms为单位，延迟打印----头文件<Windows.h>
//		system("cls"); //----system()-调用系统命令的函数  ---cls 清空屏幕    头文件<stdlib.h>
//		printf("%s\n", str2);
//	}
//	return 0;
//}


////在一个有序数组中找到具体数n(二分查找)
//#include <stdio.h>
//
//int main()
//{
//	int n = 8;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] == n)
//		{
//			printf("找到了，下标是%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到");
//	}
//	
//	return 0;
//}


////在一个有序数组中找到具体数n(直接查找)
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int n = 10;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == n)
//		{
//			printf("找到了，下标是%d", i);
//			break;
//		}
//	}
//	if (i >= sz)
//	{
//		printf("找不到");
//	}
//	return 0;
//}