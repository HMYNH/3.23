#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)                  //初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)                   
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DispiayBoard(char board[ROW][COL], int row, int col)                   //打印棋盘
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
int IsFULL(char board[ROW][COL], int row, int col)                            //棋盘是否满了，0表示未满，1表示满了
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
void PlayerMove(char board[ROW][COL], int row, int col)                          //玩家下棋
{
	int i = 0;
	int j = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>\n");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= row && j >= 1 && j <= col)
		{
			if (board[i-1][j-1] == ' ')
			{
				board[i-1][j-1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入:>\n");
			}
		}
		else
		{
			printf("该坐标非法，请重新输入:>\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)             //电脑下棋
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '+';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)                                           //判断是否赢了
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')           //三横行
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')              //三竖行
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')             //左对角
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')               //右对角
	{
		return board[1][1];
	}
	if (1==IsFULL(board, ROW, COL))                                 //棋盘是否满了
	{
		return 'Q';
	}
	return 'C';
}