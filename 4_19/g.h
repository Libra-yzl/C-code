#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3


//声明
// 初始化
void InitBoard(char board[ROW][COL], int row, int col);

//打印
void PrintBoard(char board[ROW][COL], int row, int col);

//落子
void MovePlayer(char board[ROW][COL], int row, int col);
void MoveComputer(char board[ROW][COL], int row, int col);

//判断
char Win(char board[ROW][COL], int row, int col);