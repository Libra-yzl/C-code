#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void init_board(char board[ROW][COL], int row, int col)
{

}

void display_board(char board[ROW][COL], int row, int col)
{
	//    |   |   
	// ---|---|---
	//    |   |   
	// ---|---|---
	//    |   |   
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//´òÓ¡Ò»ÐÐ
		//printf(" %c |  %c | %c ")
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");

	}
}