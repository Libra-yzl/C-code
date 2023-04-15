#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int a = 1;
//    int b = 1;
//    int c = a + b;
//    while (1)
//    {
//        if (n == a || n == b)
//        {
//            printf("%d\n", 0);
//            break;
//        }
//        if (n < b)
//        {
//            if ((n - a) <= (b - n))
//            {
//                printf("%d\n", n - a);
//                break;
//            }
//            else
//            {
//                printf("%d\n", b - n);
//                break;
//            }
//        }
//        a = b;
//        b = c;
//        c = a + b;
//    }
//    return 0;
//}

#include "c.h"

void menu()
{
	printf("*************************************\n");
	printf("     1.Add                 2.Del\n");
	printf("     3.Mod                 4.Seh\n");
	printf("     5.Show                6.Sort\n");
	printf("                0.exit          \n");
	printf("**************************************\n");
}

enum Options
{
	EXIT,
	ADD,
	DEL,
	MOD,
	SEH,
	SHOW,
	SORT
};

int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请输入:");
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
		case SEH:
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			Sort(&con);
			break;
		case EXIT:
			Save(&con);
			Destroy(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("请重试\n");
			break;
		}
	} while (input);
	return 0;
}