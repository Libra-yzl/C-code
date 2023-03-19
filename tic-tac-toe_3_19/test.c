#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("*************************************\n");
	printf("**** 1.开始游戏       0.退出游戏 ****\n");
	printf("*************************************\n");
}

//void game()
//{
//	//设置时间戳 产生随机数
//	srand((unsigned)time(NULL));
//	char ret = 0;
//
//	//创建数组存放棋子
//	char board[ROW][COL] = { 0 };
//	
//	//初始化棋盘（打印空格 棋盘整齐）
//	init_board(board, ROW, COL);
//	//打印棋盘
//	display_board(board, ROW, COL);
//
//	//判断游戏状态 
//	//1.玩家获胜    '*'
//	//2.电脑获胜    '#'
//	//3.平局        'Q'
//	//4.游戏继续    'C'
//	while (1)
//	{
//		//玩家下棋
//		player_move(board, ROW, COL);
//		display_board(board, ROW, COL);
//		ret = is_win(board, ROW, COL);
//		if (ret != 'C')
//			break;
//
//		/*Sleep(3000);
//		system("cls");*/
//
//		//电脑下棋
//		computer_move(board, ROW, COL);
//		display_board(board, ROW, COL);
//		ret = is_win(board, ROW, COL);
//		if (ret != 'C')
//			break;
//
//		/*Sleep(3000);
//		system("cls");*/
//	}
//
//	//游戏结束
//	system("cls");
//	if (ret == '*')
//		printf("游戏结束！恭喜玩家获胜\n");
//	else if (ret == '#')
//		printf("游戏结束！恭喜电脑获胜\n");
//	else
//		printf("游戏结束！平局\n");
//	
//	display_board(board, ROW, COL);
//}
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		//菜单
//		menu();
//
//		printf("请输入选项>:");
//		scanf("%d", &input);
//		switch(input)
//		{
//		case 1:
//			game();//开始游戏
//			break;
//		case 0:
//			printf("退出游戏");
//			break;
//		default:
//			printf("没有该选项，请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


void game()
{
	//设置随机数生成器
	srand((unsigned)time(NULL));

	//mine数组存放雷
	//show数组展示排雷

	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化数组(mine 初始化全'0'    show 初始化全'*')
	init(mine, ROWS, COLS, '0');
	init(show, ROWS, COLS, '*');

	//打印界面
	//display(mine, ROW, COL);
	display(show, ROW, COL);

	//布置雷
	set_mine(mine, ROW, COL);
	//display(mine, ROW, COL);

	//排雷
	//display(mine, ROW, COL);
	find_mine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;

	do
	{
		menu();

		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("没有该选项，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}