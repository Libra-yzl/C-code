#define _CRT_SECURE_NO_WARNINGS 1

//��д���룬����������ʱ���������ַ�������
	//1.
//#include <stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0; //������
//
//	while (1)
//	{
//		if (*str != '\0')
//		{
//			count++;
//			str++;
//		}
//		else
//			break;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//	//2.�ݹ鷽��
//#include <stdio.h>
//
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return  0;
//}


//��n�Ľ׳�
//	//1.
//
//#include <stdio.h>
//
//int fac(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fac(n));
//	return 0;
//}
	
//	//2.�ݹ�
//
//#include <stdio.h>
//
//int fac(int n)
//{
//	if (n < 2)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fac(n));
//	return 0;
//}


//��쳲��������еĵ�n����

//	//�ݹ�
//#include <stdio.h>
//
//int Fib(int n)
//{
//	if (n < 3)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fib(n));
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	//����Fib���е�ǰ����
//	int a = 1;
//	int b = 1;
//
//	int n = 0;
//	scanf("%d", &n);
//
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b; 
//		b = c;
//
//		n--;
//	}
//	printf("%d\n", c);
//	return 0;
//}


//��������Ϸ

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("***********************************\n");
	printf("***** 1.��ʼ��Ϸ   0.�˳���Ϸ *****\n");
	printf("***********************************\n");
}

void game()
{
	int ret = rand() % 100 + 1; //����һ��1-100������
	int guess = 0;

	printf("��ʼ�°ɣ�\n");
	while (1)
	{
		printf("���һ������:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("��´���\n");
		}
		else if (guess < ret)
		{
			printf("���С��\n");
		}
		else
		{
			printf("��ϲ��,��¶��ˣ�\n");
			break;
		}
	}
}

int main()
{
	//���������
	srand((unsigned)time(NULL));
	
	int input = 0;

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("û�����ѡ��,������ѡ��\n");
		}
	} while (input);
	return 0;
}