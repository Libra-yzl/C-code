#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>  //strlen()----���ַ�������
#include<Windows.h> //----�õ���Sleep()����------��Ϣ����
#include<stdlib.h>  //----�õ���system()����-----����ϵͳ�����

//��д���룬��ʾ����ַ��������ƶ������м���
int main()
{
	char str1[] = "welcome to our home!!!!";
	char str2[] = "#######################";
	int left = 0;
	//int right = sizeof(str1) / sizeof(str2) - 1;//���Ǵ���ļ���Ԫ�ظ�����
	//��Ϊ�ַ���������ı�־��'\0'��ʹ��sizeof()�����ַ�������ʱ���Ὣ��������ڣ���Ӧ-2.
	int right = strlen(str1) - 1;
	while (left <= right)
	{
		str2[left] = str1[left];
		str2[right] = str1[right];
		
		left++;
		right--;
		
		Sleep(1000);//Sleep()������һ��ÿ��()ms��ӡ���ݵĺ���----��Ϣ����
		system("cls");//-----system()�ǵ���ϵͳ����ĺ�����cls---�����Ļ����
		printf("%s\n", str2);
	}
	
	return 0;
}

////��һ������������в���һ�����������n
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//���ֲ���
//	int n = 17;
//	int sz = sizeof(arr) / sizeof(arr[0]);//����arr[]�е�Ԫ�ظ���
//	int left = 0; //���Ԫ���±��ʼ��
//	int right = sz - 1; //�ұ�Ԫ���±��ʼ��
//	while (left <= right)
//	{
//		int mid = (left + right) / 2; //�м�Ԫ���±��ʼ��
//		if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] == n)
//		{
//			printf(" �ҵ��ˣ��±���%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
	
	////ֱ�Ӳ���
	//int n = 6;
	//int i = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//for (i = 0; i < sz; i++)
	//{
	//	if (arr[i] == n)
	//	{
	//		printf("�ҵ��ˣ��±���%d", i);
	//		break;
	//	}
	//}
	//if (i >= sz)
	//{
	//	printf("�Ҳ���");
	//}

//	return 0;
//}

////1!+2!+...+10! = ?
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret = ret * n;
//		sum = sum + ret;
//	}
//	printf("sum = %d", sum);
//	return 0;
//}

////����n�Ľ׳�
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	printf("������һ������");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	printf("ret = %d", ret);
//	return 0;
//}