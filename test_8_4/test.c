#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("%d\n%d", ret, sum);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 0; //Ҫ���ҵ���
//	scanf("%d", &n);
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//   //����һ�ֲ�������ļ����м�ֵ�ķ���
//   // int mid = left + (right - left)
//	int right = sz - 1;
// //��������飬ʹ�ö��ֲ���
//	while (left <= right)
//	{
//		int mid = (left + right) / 2; //���ַ������ܻ����
//   // int mid = left + (right - left)
// 
//		if (arr[mid] == n)
//		{
//			printf("�ҵ��ˣ��±���%d\n", mid);
//			break;
//		}
//		else if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//	}
//	if (left > right)
//	{
//		printf("û�и�����\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//int main()
//{
//	char arr[] = "Welcome to bit!!!!";
//	char arr1[] = "##################";
//	int sz = (int)strlen(arr);
//	int i = 0;
//  int left = 0;
//  int right = (int)strlen(arr)
// 
//  while (left <= right)
//  {
//		arr1[left] = arr[left];
//      arr1[right] = arr[right];
//		left++;
//		right--;
//  } 
//	for (i = 0; i <= sz / 2; i++)
//	{
//		arr1[i] = arr[i];
//		arr1[sz - i] = arr[sz - i];
//		Sleep(1000); //Sleep��������λ��ms
//		system("cls"); //system�ǵ���ϵͳ�����ĺ�����cls��ʾ����
//		printf("%s\n", arr1);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <Windows.h>
//
//
//void menu()
//{
//	printf("*******************************\n");
//	printf("********1.play    0.exit*******\n");
//	printf("*******************************\n");
//}
//void game()
//{
//	int guess = 0;
//	//���������
//	int ret = rand() % 100 + 1; //rand()������Χ 0 - 32767   ����1 - 100֮��������
//	while (1)
//	{
//		printf("������һ������:> ");
//		scanf("%d", &guess);
//		if (guess == ret)
//		{
//			printf("��ϲ�㣬��¶���\n");
//			break;
//		}
//		else if (guess > ret)
//		{
//			printf("��´���\n");
//		}
//		else if (guess < ret)
//		{
//			printf("���С��\n");
//		}
//	}
//	Sleep(1000);
//	system("cls");
//}
//int main()
//{
//	int input = 0;
//	//�����������������
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��:> ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		default:
//			printf("ѡ�����������ѡ��\n");
//		case 1:
//		{
//			game();
//			break;
//		}
//		case 0:
//		{
//			printf("�˳���Ϸ\n");
//			break;
//		}
//		}
//	} while (input);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char passward[10] = { 0 };
//	system("shutdown -s -t 60");
////flag:
//	while (1)
//	{
//		printf("���Խ���60s��ػ����������\"������\",ȡ���ػ�\n");
//		scanf("%s", passward);
//		if (strcmp(passward, "������") == 0)
//		{
//			system("shutdown -a");
//			printf("�ػ�ȡ��\n");
//			break;
//		}
//	}
//	/*else
//	{
//		goto flag;
//	}*/
//	return 0;
//}