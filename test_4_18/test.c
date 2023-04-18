#define _CRT_SECURE_NO_WARNINGS 1

#include "c.h"
#include <stdio.h>

void menu()
{
	printf("****************************************\n");
	printf("         1.add         2.del\n");
	printf("         3.mod         4.sear\n");
	printf("         5.show        6.sort\n");
	printf("****************************************\n");

}

enum Options
{
	EXIT,
	ADD,
	DEL,
	MOD,
	SEAR,
	SHOW,
	SORT
};

int main()
{
	int input = 0;
	//创建
	struct Contact con;
	//初始化
	InitContact(&con);
	do
	{
		menu();
		printf("输入选择:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case MOD:
			break;
		case SEAR:
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DesContact(&con);
			printf("退出\n");
			break;
		default:
			printf("重新选择\n");
			break;
		}
	} while (input);
	return 0;
}