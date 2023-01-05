#pragma once
//借鉴 （链接见下）一个封装清空缓存区函数 如果不清空缓存区，会导致如果玩家错误输入多个值储存在缓存区中被下一次scanf使用导致bug
//https://blog.csdn.net/qq_26768741/article/details/50933598
#define CLEAR_BUF \
    {\
    int ch; \
while ((ch = getchar()) != EOF && ch != '\n')\
        {\
        ; \
        }\
    }
//头文件
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//定义常量
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Life 2

#define NUM_MINE 80//需要埋雷的个数
//函数声明
void game();//游戏函数

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//初始化棋盘

void SetMine(char board[ROWS][COLS], int row, int col);//埋雷

void DisPlay(char board[ROWS][COLS], int row, int col);//展示棋盘

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排查雷

int CountMine(char board[ROWS][COLS],int x , int y);//计算坐标附近雷的个数

void Eluminate_(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//清除#号
