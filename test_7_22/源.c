#define _CRT_SECURE_NO_WARNINGS 1


//#include <graphics.h>
//#include <mmsystem.h>
//#pragma comment(lib, "winmm.lib")
//
//int main()
//{
//	initgraph(1024, 494);
//	loadimage(0, L"src/bj.jpg");
//	mciSendString(L"play src/bj.mp3 repeat", 0, 0, 0);
//	system("pause");
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int sum = 0;
//	int i = 0;
//	int tmp = 1;
//	for (i = 1; i <= 10; i++)
//	{
//		tmp = tmp * i;
//		sum = tmp + sum;
//	}
//	printf("sum = %d ", sum);
//	return 0;
//}
// 
// ���ַ�
//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 10;
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
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
//			printf("�ҵ��ˣ��±���%d\n", mid);
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


//�ػ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char input[20] = {0};
	system("shutdown -s -t 60");
	while (1)
	{
		printf("��ĵ��Խ���һ����֮�ڹػ����������������ͻ�ȡ���ػ�\n������:> ");
		scanf("%s", input);
		if (strcmp(input, "������") == 0)
		{
			system("shutdown -a");
			break;
		}
	}
	return 0;
}