#pragma once
//��� �����Ӽ��£�һ����װ��ջ��������� �������ջ��������ᵼ�������Ҵ���������ֵ�����ڻ������б���һ��scanfʹ�õ���bug
//https://blog.csdn.net/qq_26768741/article/details/50933598
#define CLEAR_BUF \
    {\
    int ch; \
while ((ch = getchar()) != EOF && ch != '\n')\
        {\
        ; \
        }\
    }
//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//���峣��
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Life 2

#define NUM_MINE 80//��Ҫ���׵ĸ���
//��������
void game();//��Ϸ����

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//��ʼ������

void SetMine(char board[ROWS][COLS], int row, int col);//����

void DisPlay(char board[ROWS][COLS], int row, int col);//չʾ����

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//�Ų���

int CountMine(char board[ROWS][COLS],int x , int y);//�������긽���׵ĸ���

void Eluminate_(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//���#��
