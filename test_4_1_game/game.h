#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3  //���������
#define COL 3  //���������
#include <stdio.h>
#include <stdlib.h>//srand()��ͷ�ļ�
#include <time.h>//time()��ͷ�ļ�
#include <Windows.h>//Sleep(1000)��ͷ�ļ� ��λ�Ǻ���-->windows
//#include <unistd.h>////sleep(1)��ͷ�ļ� ��λ�Ǻ���-->linux
void IntBoard(char board[ROW][COL], int row, int col);//��ʼ������,����λ�����ÿһ��Ԫ�ظ�ֵ�ո�
void DisplayBoard(char board[ROW][COL], int row, int col);//��ʾ����
void PlayerMove(char board[ROW][COL], int row, int col);//�������
void ComputerMove(char board[ROW][COL], int row, int col);//��������

//�ж϶������
//���Ӯ"*"
//����Ӯ"#"
//ƽ��"Q"
//����"C"

char LsWin(char board[ROW][COL], int row, int col);//�ж���������Ӯ
int IsFuli(char board[ROW][COL], int row, int col);//�ж�����״̬

