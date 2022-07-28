#pragma once

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//初始化
void init_board(char board[ROW][COL], int row, int col);
//打印
void print_board(char board[ROW][COL],int row, int col);
//下棋
void player_move(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL], int row, int col);
//判断游戏状态
char win(char board[ROW][COL], int row, int col);