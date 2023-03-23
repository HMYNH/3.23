

#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROW][COL], int row, int col);               //初始化棋盘
void DispiayBoard(char board[ROW][COL], int row, int col);             //打印棋盘
void PlayerMove(char board[ROW][COL], int row, int col);               //玩家下棋
void ComputerMove(char board[ROW][COL], int row, int col);             //电脑下棋
char IsWin(char board[ROW][COL], int row, int col);           //判断  玩家赢输出‘*’电脑赢输出‘+’平局输出‘Q’继续输出‘C’