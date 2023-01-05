#pragma once
//头文件
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//define定义值
#define ROW 3
#define COL 3


//函数声明

void menu();//打印菜单

void game();//实现游戏功能

void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘格

void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘格

void PlayerMove(char board[ROW][COL], int row, int col);//玩家下棋

void ComputerMove(char board[ROW][COL], int row, int col);//电脑下棋

int IsFull(char board[ROW][COL], int row, int col);//判断棋盘是否满了

char IsWin(char board[ROW][COL], int row, int col);//判断当前游戏状态