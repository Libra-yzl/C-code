#define _CRT_SECURE_NO_WARNINGS 1

//����n�Ľ׳�
#include <stdio.h>

//int main()
//{
//	int sum = 0;
//	for (int j = 1; j <= 5; j++)
//	{
//		int ret = 1;
//		for (int i = 1; i <= j; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret *= n;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//��һ�������в�������
//���ֲ���

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int k = 0;
//	scanf("%d", &k);
//	while (left <= right)
//	{
//		//int mid = (left + right) / 2;
//		int mid = left + (right - left) / 2;//��ƽ��ֵ��һ�ַ���
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ���,�±���%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("������Ŷ\n");
//	return 0;
//}

//��ʾ����ַ����м��������ƶ�
#include <string.h>
#include <Windows.h>
#include <stdlib.h>

//int main()
//{
//	char arr1[] = "Welcome to bit !!!";
//	char arr2[] = "##################";
//	int length = (int)strlen(arr2);
//	int left = 0;
//	int right = length - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		Sleep(1000);
//		system("cls");
//		printf("%s\n", arr2);
//		left++;
//		right--;
//	}
//	//printf("%s\n", arr2);
//	return 0;
//}

//ģ���¼��������

//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:>");
//		scanf("%s", password);
//		if (strcmp(password, "bitbit") == 0)
//		{
//			printf("������ȷ����¼�ɹ�\n");
//			break;
//		}
//		else
//			printf("�������������\n");
//	}
//	if (3 == i)
//		printf("��������Ѵ����ޣ��˳�����\n");
//	return 0;
//}

//��������Ϸ
//#include <time.h>
//
//void menu()
//{
//	printf("############################\n");
//	printf("1.play                0.exit\n");
//	printf("############################\n");
//}
//
//void game()
//{
//	int ret = rand() % 100 + 1; //����1-100������
//	int guess = 0;
//	printf("��ʼ�°ɣ�\n");
//	while (1)
//	{
//		printf("������һ������:>");
//		scanf("%d", &guess);
//		if (guess < ret)
//			printf("���С��\n");
//		else if (guess > ret)
//			printf("��´���\n");
//		else
//		{
//			printf("��ϲ�㣬��¶���!\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//���������������
//	do
//	{
//		menu();//�˵�����
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();//��Ϸ����
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("û�и�ѡ�������\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	printf("��������������������Խ�����һ����֮�ڹػ�\n");
again:
	printf("������:>");
	scanf("%s", input);
	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a");
		printf("ȡ���ػ�\n");
		exit(0);
	}
	goto again;
	return 0;
}