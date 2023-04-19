#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

////na1 + n*(n-1)*d / 2
////等差数组-数组求和
//
//int missingNumber(int* nums, int numsSize)
//{
//    int sum = 0;
//    //数组求和
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    int ret = (numsSize + 1) * numsSize / 2 - sum;
//    return ret;
//}

////异或运算
//int missingNumber(int* nums, int numsSize)
//{
//    int num = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        num ^= nums[i];
//    }
//    for (int i = 0; i < numsSize + 1; i++)
//    {
//        num ^= i;
//    }
//    return num;
//}
//
//int main()
//{
//    int arr[9] = { 0,1,3,5,4,6,7,9,8 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int ret = missingNumber(arr, sz);
//    printf("%d\n", ret);
//	return 0;
//}

#include "g.h"

void menu()
{
	printf("                       1.play\n");
	printf("                       0.exit\n");
}

enum Options
{
	EXIT,
	PLAY
};

void game()
{
	//存放
	char board[ROW][COL];

	//初始化
	InitBoard(board, ROW, COL);

	//打印
	PrintBoard(board, ROW, COL);

	char ret = 0;
	while (1)
	{
		//落子
		MovePlayer(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = Win(board, ROW, COL);
		if (ret != 'C')
			break;

		MoveComputer(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = Win(board, ROW, COL);
		if (ret != 'C')
			break;
	}

	//获胜
	if (ret == '*')
		printf("玩家胜\n");
	else if (ret == '#')
		printf("电脑胜\n");
	else if (ret == 'Q')
		printf("平局\n");
	//PrintBoard(board, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("输入选择:");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("退出\n");
			break;
		case PLAY:
			game();
			break;
		default:
			printf("重新选择\n");
			break;
		}
	} while (input);
	return 0;
}