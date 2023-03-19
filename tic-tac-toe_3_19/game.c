#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;//控制行
	int j = 0;//控制列

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//初始化为空格
			board[i][j] = ' ';
		}
	}
}

void display_board(char board[ROW][COL], int row, int col)
{
	//   |    |           小1
	//---| ---| ---  1    小2
	//   1    2
	//   |    |
	//---| ---| ---  2
	
	//   |    |     3
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印一组
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//
			printf(" %c ", board[i][j]);
			//打印|
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		//打印第三组时不打印 小2
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				//打印---
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	printf("玩家落子:\n");

	//定义坐标
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);

		//判断坐标合法性（1.玩家角度：坐标源点是(1,1)   2.坐标是否已经被占用）
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标是否被占用
			if (board[x - 1][y - 1] != ' ')
			{
				printf("该坐标已被占用，请重新输入\n");
			}
			else
			{
				//坐标合法，玩家落子显示为 '*'
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
			printf("坐标非法,请重新输入\n");
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	printf("电脑落子:\n");
	while (1)
	{
		//产生坐标
		int x = rand() % row;
		int y = rand() % col;

		//判断坐标合法性
		if (x >= 0 && x < row && y >= 0 && y < col)
		{
			//判断坐标是否被占用
			if (board[x][y] == ' ')
			{
				//电脑落子显示为 '#'
				board[x][y] = '#';
				break;
			}
		}
	}
}

//判断棋盘是否已满 已满返回1 否则返回0
static int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;

	//三行判断
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	
	//三列判断
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}

	//对角线判断
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] != ' ')
		return board[1][1];

	//判断棋盘是否已满
	int ret = is_full(board, ROW, COL);
	if (1 == ret)
		return 'Q';
	return 'C';
}


//扫雷

void init(char mine[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = set;
		}
	}
}

void display(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	//打印列号
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		//打印行号
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int count = 0; //统计布置的雷的数量

	while (count < EASY_COUNT)
	{
		//生成雷的坐标
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		//判断合法性
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return ((
		mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1]) - 8 * '0');
}

void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//坐标
	int x = 0;
	int y = 0;

	//统计排雷的数量 若win = row*col-EASY_COUNT 排雷成功 游戏结束
	int win = 0;

	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);

		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标是否被排查过
			if (show[x][y] == '*')
			{
				//判断坐标是否为雷
				if (mine[x][y] == '1')
				{
					display(mine, ROW, COL);
					printf("很遗憾，你被炸死了\n");
					break;
				}
				else
				{
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';
					win++;
					display(show, ROW, COL);
				}
			}
			else
			{
				printf("该坐标已经被排查过\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("排雷成功，游戏结束\n");
	}
}