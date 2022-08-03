#pragma once

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//函数声明，先声明，再使用
void init_board(char board[ROW][COL], int row, int col);
void print_board(char board[ROW][COL], int row, int col);
void player_move(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL], int row, int col);
char win(char board[ROW][COL], int row, int col);