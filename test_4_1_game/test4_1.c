#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void menu()//��ʾ����
{
	printf("******************************\n");
	printf("********1.play  0.eixt********\n");
	printf("******************************\n");
}



void game()
{
	char res =0;//״̬����
	char board[ROW][COL] = { 0 };

	//��ʼ������
	IntBoard(board, ROW, COL);

	//��ӡ����
	DisplayBoard(board, ROW, COL);

	//����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		//��ӡ����
		DisplayBoard(board, ROW, COL);
		printf("\n");
		//�жϵ����Ƿ�Ӯ

		res=LsWin(board, ROW, COL);
		if (res != 'C')
		{
			break;
		}


		//��������
		ComputerMove(board, ROW, COL);
		//Sleep(500);//windows 
		//sleep(1)//linux �µ�λ����
		//��ӡ����
		DisplayBoard(board, ROW, COL);
		printf("\n");
		//�жϵ����Ƿ�Ӯ

		res = LsWin(board, ROW, COL);
		if (res != 'C')
		{
			break;
		}
	}
	if (res == '*')
	{
		printf("��ϲ�����ʤ����\n");
	}
	else if (res == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ�֣�\n");
	}
}

void test()//��Ϸ���г���
{
	int input=0;
	srand((unsigned int)time(NULL));//��ȡ��ǰʱ����Ϊʱ���.srand()-->��ʼ��������������ڱ�ͷ <stdlib.h> ����ʹ��rand()����ȡ���ֵ
	do
	{
		menu();//��ӡ��Ϸ����
		scanf(" %d", & input);//��ȡ�û�ѡ��
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("********   �˳���Ϸ   ********\n");
			break;
		default:
		;
		}

	} while (input);


}

int main()
{
	test();




	return 0;
}