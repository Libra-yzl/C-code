#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL],int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void Player_Board(char board[ROW][COL], int row, int col);
void Computer_Board(char board[ROW][COL], int row, int col);
char Is_Win(char board[ROW][COL], int row, int col);
//void Exit();