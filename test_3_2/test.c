#define _CRT_SECURE_NO_WARNINGS 1

//输出1-100的奇数

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}


#include <stdio.h>

int main()
{
	char password[20];
	char a = 0;
	printf("请输入密码:");
	scanf("%s", password);
	while ((a = getchar()) != '\n');
	printf("请确认密码 Y/N:");
	int ch = getchar();
	if (ch == 'Y')
		printf("确认成功\n");
	else
		printf("确认失败\n");
	return 0;
}