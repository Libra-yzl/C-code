#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3


//����
// ��ʼ��
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ
void PrintBoard(char board[ROW][COL], int row, int col);

//����
void MovePlayer(char board[ROW][COL], int row, int col);
void MoveComputer(char board[ROW][COL], int row, int col);

//�ж�
char Win(char board[ROW][COL], int row, int col);