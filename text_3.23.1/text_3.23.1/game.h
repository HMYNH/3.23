

#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROW][COL], int row, int col);               //��ʼ������
void DispiayBoard(char board[ROW][COL], int row, int col);             //��ӡ����
void PlayerMove(char board[ROW][COL], int row, int col);               //�������
void ComputerMove(char board[ROW][COL], int row, int col);             //��������
char IsWin(char board[ROW][COL], int row, int col);           //�ж�  ���Ӯ�����*������Ӯ�����+��ƽ�������Q�����������C��