#define _CRT_SECURE_NO_WARNINGS 1

//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�

//#include <stdio.h>
//
//struct point
//{
//	int x;
//	int y;
//};
//
//struct point find(int arr[3][3], int row, int col, int key)
//{
//	int x = 0;
//	int y = col - 1;
//	struct point ret = { -1, -1 };
//	while ((x <= 2) && (y >= 0))
//	{
//		if (arr[x][y] == key)
//		{
//			ret.x = x;
//			ret.y = y;
//			return ret;
//		}
//		else if (arr[x][y] > key)
//		{
//			y--;
//		}
//		else
//		{
//			x++;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	//1 2 3
//	//4 5 6
//	//7 8 9
//	struct point ret = find(arr, 3, 3, 10);
//	if ((ret.x != -1) && (ret.y != -1))
//	{
//		printf("�ҵ���:%d %d\n", ret.x, ret.y);
//	}
//	else
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//
////ʱ�临�Ӷ�С��O(N)
////�(ѭ����������)�������ʱ�临�Ӷȵ���O(N)
//
//int find(int arr[3][3], int* row, int* col, int key)
//{
//	int x = 0;   //�����Ͻǿ�ʼ��
//	int y = *col - 1;//
//	while ((x <= *row - 1) && (y >= 0))
//	{
//		if (arr[x][y] == key)
//		{
//			*row = x;
//			*col = y;
//			return 1;
//		}
//		else if (arr[x][y] < key)
//		{
//			//����һ������Ԫ�ش��Ҹ�Ԫ�ص���һ�У�������+1
//			x++;
//		}
//		else
//		{	
//			//����һ������Ԫ��С���Ҹ�Ԫ�ص���һ�У�������-1
//			y--;
//		}
//	}
//	/**row = -1;
//	*col = -1;*/
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	//�������е����Ͼ���
//	int x = 3;
//	int y = 3;
//	int key = 0;
//	printf("������Ҫ���ҵ���:> ");
//	scanf("%d", &key);
//	//��x��y ���е�ַ����
//	//������淵�ز���ֵ���±� (�����Ͳ���)
//	int ret = find(arr, &x, &y, key);
//	//if ((x != -1) && (y != -1))
//	if (1 == ret)
//	{
//		printf("�ҵ���:%d %d", x, y);
//	}
//	else
//		printf("�Ҳ���\n");
//	return 0;
//}

//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//#include <stdio.h>
//#include <string.h>
//
//void left_rot(char* str, int k)
//{
//	int i = 0;
//	int len = (int)strlen(str);
//	//char* arr = str;
//	//����ѭ�����������ַ��ĸ���
//	for (i = 0; i < k; i++)
//	{
//		char* arr = str;
//		while (arr < str + len - 1)  
//		{
//			//����ת���ַ� ����������Ԫ��˳�򽻻� ֱ�����Ԫ�ص�λ��
//			char tmp = *arr;
//			*arr = *(arr + 1);
//			*(arr + 1) = tmp;
//			arr++;
//		}
//	}
//}
//
//int main()
//{
//	char str[100] = {0};
//	printf("�������ַ���:> ");
//	scanf("%[^\n]", str);
//	int k = 0;
//	printf("������Ҫ�������ַ�����:> ");
//	scanf("%d", &k);
//	printf("����ǰ���ַ���:> %s\n", str);
//	left_rot(str, k);
//	printf("��������ַ���:> %s\n", str);
//	return 0;
//}

//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//����s1 =AABCD��s2 = BCDAA������1 ,����s1 = abcd��s2 = ACBD������0.

//#include <stdio.h>
//#include <string.h>
//
//int judge(char* s1, char* s2)
//{
//	int len1 = (int)strlen(s1);
//	int len2 = (int)strlen(s2);
//	if (len1 == len2)
//	{
//		int i = 0;
//		for (i = 0; i < len1; i++)
//		{
//			char* str = s1;
//			while (str < (s1 + len1 - 1))
//			{
//				if (strcmp(s1, s2) == 0)
//					return 1;
//				char tmp = *str;
//				*str = *(str + 1);
//				*(str + 1) = tmp;
//				str++;
//			}
//			if (strcmp(s1, s2) == 0)
//				break;
//		}
//	}
//	if (len1 != len2)
//		return 0;
//}
//
//int main()
//{
//	char s1[10];
//	char s2[10];
//	printf("�������ַ���s1:> ");
//	scanf("%s", s1);
//	printf("�������ַ���s2:> ");
//	scanf("%s", s2);
//	int ret = judge(s1, s2);
//	if (1 == ret)
//		printf("1");
//	else
//		printf("0");
//	return 0;
//}

//���Ͼ���
//#include <stdio.h>
//
//struct point
//{
//	int x;
//	int y;
//};
//
//struct point find(int arr[3][3], int row, int col, int key)
//{
//	struct point ret = { -1, -1 };
//	int x = 0;
//	int y = col - 1;
//	while ((x <= 2) && (y >= 0))
//	{
//		if (arr[x][y] == key)
//		{
//			ret.x = x;
//			ret.y = y;
//			return ret;
//		}
//		else if (arr[x][y] < key)
//		{
//			x++;
//		}
//		else
//		{
//			y--;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int key = 0;
//	printf("������Ҫ���ҵ�Ԫ��:> ");
//	while (scanf("%d", &key) != EOF)
//	{
//		struct point ret = find(arr, 3, 3, key);
//		if ((-1 != ret.x) && (-1 != ret.y))
//		{
//			printf("�ҵ���:> %d %d\n", ret.x, ret.y);
//			printf("������Ҫ���ҵ�Ԫ��:> ");
//		}
//		else
//		{
//			printf("�Ҳ���\n");
//			printf("������Ҫ���ҵ�Ԫ��:> ");
//		}
//	}
//	return 0;
//}

#include <stdio.h>

void find(int arr[3][3], int* row, int* col, int key)
{
	int x = 0;
	int y = *col - 1;
	while ((x <= *row - 1) && (y >= 0))
	{
		if (arr[x][y] == key)
		{
			*row = x;
			*col = y;
			return;
		}
		else if (arr[x][y] > key)
		{
			y--;
		}
		else
		{
			x++;
		}
	}
	*row = -1;
	*col = -1;
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = 3;
	int y = 3;
	int key = 0;
	printf("������Ҫ���ҵ�����:> ");
	scanf("%d", &key);
	find(arr, &x, &y, key);
	if ((x != -1) && (y != -1))
	{
		printf("�ҵ���:> %d %d", x, y);
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}