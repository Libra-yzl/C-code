#define _CRT_SECURE_NO_WARNINGS 1

//��������Ϸ
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
//	printf("������:> ");
//	scanf("%d", &input);
//	if (input == 1)
//	{
//		printf("��ʼ��Ϸ");
//	}
//	else if (input == 0)
//	{
//		printf("�˳���Ϸ");
//	}
//	else
//	{
//		printf("�������������:>");
//	}
//}
void game()
{
	//printf("������\n");
	//1.��������� rand()����
	int ret = 0;
	int guess = 0;
	//��ʱ����������������������ʼ��
	
	ret = rand() % 100 + 1; //����1-100֮��������
	//printf("%d\n", ret);
	//2.������
	printf("��ʼ�°ɣ�\n");
	while (1)
	{
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
			continue;
		}
		else if (guess < ret)
		{
			printf("��С��\n");
			continue;
		}
		else
		{
			printf("��ϲ�㣬��¶���!\n");
			break;
		}
	}
	
}
int main()  //������
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��Ϸ����
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	
	return 0;
}

////9*9�˷���
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

////10�������е����ֵ
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

//������� 
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

////��ӡ����1-100֮����ֶ��ٸ�����9
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

////��ӡ100-200֮�������
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 101; i <= 200; i += 2)  //--�㷨���� // for (i = 100 ; i <= 200 ; i++)
//	{
//		int n = 0;
//		for (n = 2; n <= sqrt(i); n++)
//		{				   //�Գ��� (�ж������ķ���֮һ)����i����2��i-1����
//			if (i % n == 0)//���ģΪ0��֤��i���Ա���1�ͱ������������������i��������
//				break;
//		}
//		//���������������
//		//1.break�����
//		//2.�ڶ���ѭ�����������㣬Ҳ����n >= i ��ʱ����������  �������������ʱ��֤��i��������
//		if (n > sqrt(i))
//		{
//			k++;
//			printf("%d ", i);
//		}
//	}
//	printf("\nk = %d", k);
//	return 0;
//}

////��ӡ1000-2000�������
//#include<stdio.h>
//
//int main()
//{
//	int y = 0;
//	int i = 0; //�����ж��ٸ�����
//	printf("1000-2000�����ͨ����Ϊ:> ");
//	for (y = 1000; y <= 2000; y++) //
//	{
//		/*if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//		{
//			printf("%d ", y);
//		}*/    //�����ķ���
//		if (y % 4 == 0 && y % 100 != 0) //������ж� 1
//		{
//			printf("%d ", y);
//			i++;
//		}
//		else if (y % 400 == 0)          //������ж� 2
//		{
//			printf("%d ", y);
//			i++;
//		}
//		
//	}
//	printf("\n1000-2000�����������Ϊ:> ");
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
////�������������Լ��
//int main()
//{
//	int m, n, r;
//	printf("������������:>");
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
//			printf("���ǵ����Լ��Ϊ:%d", n);
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


////�������Ӵ�С���
//#include <stdio.h>
//
//int main()
//{
//	int a,b,c;
//	printf("������������:");
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
//	printf("�������Ӵ�С����:>%d %d %d",a,b,c);
//	return 0;
//}
////�û���½ϵͳ�����������������룬������������˳��������ɹ���¼����ʾ�û���½�ɹ�
//#include <stdio.h>
//int main()
//{
//	int i = 0;//�����¼����
//	char passward[20];
//	printf("����������:> ");
//	
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", passward);
//		//if (pwd == "123456") //err == �����ж��ַ������ ��Ҫ��strcmp()����		
//		if (strcmp(passward ,"123456") == 0)
//		{
//			printf("��½�ɹ�");
//			break;
//		}
//		else
//		{
//			printf("�������������:>");
//		}
//	}
//	if (i == 3)
//	{
//		printf("������������󣬽��˳�����\n");
//	}
//	return 0;
//}

////��ӡһ����ʾ�ַ���ʹ�ô��������м俿£
//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//#include <stdlib.h>
//
//int main()
//{
//	char str1[] = "welcome to our home !!!";
//	char str2[] = "#######################";
//	int left = 0;//�����Ԫ���±�
//	int right = strlen(str1) - 1;
//	//int right = sizeof(str1) / sizeof(str1[0]) - 2;
//	//ע�⣬�ַ����Ľ�β��'\0'��β��sizeof()����ʱ����������ڣ���strlen()����û��
//
//	while (left <= right) //��left <= rightʱ������ѭ��
//	{
//		str2[left] = str1[left];
//		str2[right] = str1[right];
//		left++;
//		right--;
//		Sleep(1000);  //----Sleep() ��msΪ��λ���ӳٴ�ӡ----ͷ�ļ�<Windows.h>
//		system("cls"); //----system()-����ϵͳ����ĺ���  ---cls �����Ļ    ͷ�ļ�<stdlib.h>
//		printf("%s\n", str2);
//	}
//	return 0;
//}


////��һ�������������ҵ�������n(���ֲ���)
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
//			printf("�ҵ��ˣ��±���%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���");
//	}
//	
//	return 0;
//}


////��һ�������������ҵ�������n(ֱ�Ӳ���)
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
//			printf("�ҵ��ˣ��±���%d", i);
//			break;
//		}
//	}
//	if (i >= sz)
//	{
//		printf("�Ҳ���");
//	}
//	return 0;
//}