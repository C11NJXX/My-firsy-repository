#pragma once
//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//define����ֵ
#define ROW 3
#define COL 3


//��������

void menu();//��ӡ�˵�

void game();//ʵ����Ϸ����

void InitBoard(char board[ROW][COL], int row, int col);//��ʼ�����̸�

void DisplayBoard(char board[ROW][COL], int row, int col);//��ӡ���̸�

void PlayerMove(char board[ROW][COL], int row, int col);//�������

void ComputerMove(char board[ROW][COL], int row, int col);//��������

int IsFull(char board[ROW][COL], int row, int col);//�ж������Ƿ�����

char IsWin(char board[ROW][COL], int row, int col);//�жϵ�ǰ��Ϸ״̬