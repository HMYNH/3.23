#include"game.h"

void H()
{
	printf("******************************\n");
	printf("***     1. piay   0. exit   **\n");
	printf("******************************\n");
}
void game()
{
	char A = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);    //初始化棋盘
	DispiayBoard(board, ROW, COL);     //打印棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);     //玩家下棋
		DispiayBoard(board, ROW, COL);
		A = IsWin(board, ROW, COL);
		if (A != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);     //电脑下棋
		DispiayBoard(board, ROW, COL);
		A = IsWin(board, ROW, COL);
		if (A != 'C')
		{
			break;
		}
	}
	if (A == '*')
	{
		printf("玩家赢\n");
	}
	else if (A=='+')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int M = 0;
	srand((unsigned int)time(NULL));
	do
	{
		H();
		printf("请选择：>");
		scanf("%d", &M);
		switch (M)
		{
		case 1:
			/*	printf("三子棋\n");*/
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (M);
}
int main()
{
	test();
	return 0;
}