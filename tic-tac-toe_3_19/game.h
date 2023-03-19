#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


////�����С�ɱ�����
//#define ROW 3
//#define COL 3


////��ʼ������
//void init_board(char board[ROW][COL], int row, int col);
//
////��ӡ����
//void display_board(char board[ROW][COL], int row, int col);
//
////�������
//void player_move(char board[ROW][COL], int row, int col);
//
////��������
//void computer_move(char board[ROW][COL], int row, int col);
//
////�ж���Ϸ״̬
//char is_win(char board[ROW][COL], int row, int col);

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

//��ʼ��
void init(char mine[ROWS][COLS], int rows, int cols, char set);
//void init(char show[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void display(char mine[ROWS][COLS], int row, int col);

//������
void set_mine(char mine[ROWS][COLS], int row, int col);

//����
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);