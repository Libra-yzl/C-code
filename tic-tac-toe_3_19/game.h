#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


////定义大小可变棋盘
//#define ROW 3
//#define COL 3


////初始化棋盘
//void init_board(char board[ROW][COL], int row, int col);
//
////打印棋盘
//void display_board(char board[ROW][COL], int row, int col);
//
////玩家下棋
//void player_move(char board[ROW][COL], int row, int col);
//
////电脑下棋
//void computer_move(char board[ROW][COL], int row, int col);
//
////判断游戏状态
//char is_win(char board[ROW][COL], int row, int col);

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

//初始化
void init(char mine[ROWS][COLS], int rows, int cols, char set);
//void init(char show[ROWS][COLS], int rows, int cols, char set);

//打印界面
void display(char mine[ROWS][COLS], int row, int col);

//设置雷
void set_mine(char mine[ROWS][COLS], int row, int col);

//排雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);