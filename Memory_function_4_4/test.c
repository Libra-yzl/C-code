#define _CRT_SECURE_NO_WARNINGS 1


////模拟实现strstr
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//const char* my_strstr(const char* str1, const char* str2)
//{
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//
//	if (!(*str2))
//		return (char*)str1;
//
//	while (*p) //当p为'\0'的时候意味着原字符串已经遍历
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//找到了
//			return (char*)p;
//		p++;
//	}
//	return null;
//}
//
//int main()
//{
//	const char* str1 = "abbbcde";
//	const char* str2 = "";
//	printf("%s\n", my_strstr(str1, str2));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char* p = "yangzhuolin@bit.com";
//	const char* sep = ".@";
//	char arr[20] = { 0 };
//	strcpy(arr, p);
//
//	/*printf("%s\n", strtok(arr, sep));
//	printf("%s\n", strtok(NULL, sep));
//	printf("%s\n", strtok(NULL, sep));
//	printf("%s\n", strtok(NULL, sep));*/
//
//	char* str = NULL;
//	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
//	{
//		printf("%s\n", str);
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//
//
//int main()
//{
//	
//	/*printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//	printf("%s\n", strerror(4));
//	printf("%s\n", strerror(120));*/
//
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		perror("fopen:");
//		//printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//模拟实现memcpy

#include <stdio.h>
#include <string.h>
#include <assert.h>

//void* my_memcpy(void* dest, void* src, size_t num)
//{
//	assert(dest && src);
//
//	void* start = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		(char*)dest = (char*)dest + 1;
//		(char*)src = (char*)src + 1;
//	}
//	return start;
//}


////void* my_memcpy(void* dest, void* src, size_t num)
//void* my_memmove(void* dest, void* src, size_t num)
//{
//	void* start = dest;
//
//	assert(dest && src);
//
//	if (dest < src)
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			(char*)dest = (char*)dest + 1;
//			(char*)src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return start;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int arr2[20];
//
//	my_memmove(arr1, arr1+2, 12);
//
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

//杨辉三角

//#define ROW 5
//#define COL 5
//
//#include <stdio.h>
//
//int main()
//{
//	int arr[ROW][COL] = { 0 };
//	for (int row = 0; row < ROW; row++)
//	{
//		//打印空格
//		for (int i = 0; i < ROW - row - 1; i++)
//		{
//			printf(" ");
//		}
//
//		for (int col = 0; col <= row; col++)
//		{
//			if (col == 0)//第一列为1
//			{
//				arr[row][col] = 1;
//			}
//			if (row == col)//对角线为1
//			{
//				arr[row][col] = 1;
//			}
//			//从第三行，第一列的元素开始，中间的每个元素都等于它上面的两个元素之和
//			if (row >= 2 && col >= 1)
//			{
//				arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];
//			}
//		}
//		//printf("\n");
//	}
//
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


#define ROW 15
#define COL 15

#include <stdio.h>

int main()
{
	int arr[ROW][COL] = { 0 };
	int i = 0;
	int j = 0;
	//第一列和对角线都为1
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0)//第一列为1
			{
				arr[i][j] = 1;
			}
			if (i == j)//对角线为1
			{
				arr[i][j] = 1;
			}
			//从第三行，第一列的元素开始，中间的每个元素都等于它上面的两个元素之和
			if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < ROW - 1 - i; j++)//控制空格数量
		{
			printf("  ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("%-3d ", arr[i][j]);
		}
		printf("\n");//打印完一行后换行
	}
	return 0;
}