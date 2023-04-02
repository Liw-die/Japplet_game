#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void IntBoard(char board[ROW][COL], int row, int col)//��ʼ������,����λ�����ÿһ��Ԫ�ظ�ֵ�ո�
{
	int i = 0, j = 0;
	for (i; i < row; i++)
	{
		for (j=0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//   |   |   
//---|---|---
//   |   |
//---|---|---
//   |   |
//void DisplayBoard(char board[ROW][COL], int row, int col)//��ʾ����
//{
//	int i = 0;
//	for (i; i < row; i++)
//	{
//		//��ӡ��һ�е�����
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//��ӡ�ָ���
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");
//		}
//
//	}
//
//}

void DisplayBoard(char board[ROW][COL], int row, int col)//��ʾ����
{
	int i = 0;
	for (i; i < row; i++)//
	{

		int j;
		for (j=0; j < col; j++)//��ӡ��һ��
		{
			printf(" %c ", board[i][j]);//   |   |   
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");//�ڴ�ӡ��ɺ���

		if (i < row - 1)
		{
			for (j=0; j < col; j++)//��ӡ---|---|---
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");//�ڴ�ӡ��ɺ���
		}

	}

}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("������壺\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж��û������뷶Χ
		{
			if (board[x - 1][y - 1] == ' ')//�ж�����������Ƿ�Ϊ�գ��ո�
			{
				board[x - 1][y - 1] = '*';
				break;//�����������ǰѭ��
			}
			else
			{
				printf("�����걻ռ�ã�\n");
			}
		}
		else
		{
			printf("�Ƿ����꣬���������룡\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)//��������
{
	int x = 0, y = 0;
	printf("��������->\n");

	while (1)
	{
		x = rand() % row;//����0-2֮���ֵ
		y = rand() % col;//����0-2֮���ֵ
		if (board[x][y] == ' ')//�ж�����������Ƿ�Ϊ�գ��ո�
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж�����״̬
//1��ʾ���ˣ�0��ʾû��
int IsFuli(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y] == ' ')//�ҵ��ո�
			{
				return 0;
			}
		}
	}
	return 1;//û���ҵ��ո񷵻�1

}

char LsWin(char board[ROW][COL], int row, int col)//�ж���������Ӯ
{
	int i = 0;
	for (i = 0; i < row; i++)//�жϺ�����
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')//����Ԫ����ȣ������е�Ԫ�ز�Ϊ�ո�
		{
			return board[i][1];//����������Ԫ��
		}
	}

	for (i = 0; i < col; i++)//�ж�������
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')//����Ԫ����ȣ������е�Ԫ�ز�Ϊ�ո�
		{
			return board[1][i];//����������Ԫ��
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//�ж�һ���Խ�����ȣ������е�Ԫ�ز�Ϊ�ո�
	{
		return board[1][1];//����������Ԫ��
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')//�ж�һ���Խ�����ȣ������е�Ԫ�ز�Ϊ�ո�
	{
		return board[1][1];//����������Ԫ��
	}

	//�ж�ƽ��
	if (1 == IsFuli(board, ROW, COL))
	{
		return 'Q';
	}
	else
		return 'C';
}