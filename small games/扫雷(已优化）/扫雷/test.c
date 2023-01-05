#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//打印菜单
void menu()
{
	printf("*********************\n");
	printf("*********************\n");
	printf("********1.paly*******\n");
	printf("********0.exit*******\n");
	printf("*********************\n");
	printf("*********************\n");
}
//进入游戏
void game()
{
	//定义mine数组用于存储棋盘的信息，show数组用于显示排雷后得到的信息
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	//先对两数组棋盘进行初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//埋雷
	SetMine(mine, ROW, COL);
	//展示当前棋盘（可以将两棋盘都展示，后期完成后屏蔽mine，只展示show）
	//DisPlay(mine, ROW, COL);
	DisPlay(show, ROW, COL);
	//开始排雷,操作一次后看变化
	FindMine(mine, show, ROW, COL);

 }
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (input);
}