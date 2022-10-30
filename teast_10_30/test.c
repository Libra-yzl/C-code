#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SeqListTest1()
{
	SL s;
	/*int x = 0;
	scanf("%d", &x);*/
	SeqListInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPrint(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);

	SLPrint(&s);
	SLDestroy(&s);
}

void SeqListTest2()
{
	SL s;
	SeqListInit(&s);

	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPushFront(&s, 5);

	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	//SLPopFront(&s);
	
	SLPrint(&s);

	SLDestroy(&s);
}

void SeqListTest3()
{
	SL s;
	SeqListInit(&s);

	SLInsert(&s, 1, 0);
	SLInsert(&s, 2, 1);
	SLInsert(&s, 3, 2);
	SLInsert(&s, 4, 3);
	SLInsert(&s, 5, 4);
	SLPrint(&s);
	
	SLErase(&s, 2);
	SLErase(&s, 2);
	SLErase(&s, 2);
	SLPrint(&s);
	
	SLDestroy(&s);

}

//int main()
//{
//	//SeqListTest1(); //测试尾插尾删
//	//SeqListTest2(); //测试头插头删
//	//SeqListTest3(); //测试插入删除
//	return 0;
//}

typedef enum Options
{
	EXIT = -1,
	SLPUSHBACK = 1,
	SLPOPBACK,
	SLPUSHFRONT,
	SLPOPFRONT,
	SLPRINT
}Options;

void menu()
{
	printf("**************************************************\n");
	printf("1、尾插     2、尾删\n");
	printf("3、头插     4、头删\n");
	printf("5、打印     -1、退出\n");
	printf("**************************************************\n");
}

int main()
{
	Options options = 0;
	SL s;
	SeqListInit(&s); //初始化
	int input = 0;
	do
	{
		menu();
		printf("请输入操作:>");
		scanf("%d", &options);
		switch (options)
		{
		case EXIT:
			printf("退出顺序表\n");
			break;
		case SLPUSHBACK:
			printf("请输入要插入的数字，以0结束:>\n");
			while (input != 0)
			{
				if (input != 0)
				{
					scanf("%d", &input);
					SLPushBack(&s, input);
				}
				else
					break;
			}
			break;
		case SLPOPBACK:
			break;
		case SLPUSHFRONT:
			break;
		case SLPOPFRONT:
			break;
		case SLPRINT:
			SLPrint(&s);
			SLDestroy(&s);
			break;
		default:
			printf("没有此操作，请重新选择\n");
			break;
		}
	} while (options != EXIT);
	return 0;
}