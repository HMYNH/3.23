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
	InitBoard(board, ROW, COL);    //��ʼ������
	DispiayBoard(board, ROW, COL);     //��ӡ����
	while (1)
	{
		PlayerMove(board, ROW, COL);     //�������
		DispiayBoard(board, ROW, COL);
		A = IsWin(board, ROW, COL);
		if (A != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);     //��������
		DispiayBoard(board, ROW, COL);
		A = IsWin(board, ROW, COL);
		if (A != 'C')
		{
			break;
		}
	}
	if (A == '*')
	{
		printf("���Ӯ\n");
	}
	else if (A=='+')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int M = 0;
	srand((unsigned int)time(NULL));
	do
	{
		H();
		printf("��ѡ��>");
		scanf("%d", &M);
		switch (M)
		{
		case 1:
			/*	printf("������\n");*/
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (M);
}
int main()
{
	test();
	return 0;
}