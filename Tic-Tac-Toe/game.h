#pragma once

#define ROW 3
#define COL 3

#include <stdio.h>



//函数声明

//打印棋盘
void display_board(char board[ROW][COL], int row, int col);
//初始化
void init_board(char board[ROW][COL], int row, int col);