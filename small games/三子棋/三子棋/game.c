#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//打印菜单
void menu()
{
	printf("**************************\n");
	printf("**************************\n");
	printf("********1.play************\n");
	printf("********2.exit************\n");
	printf("**************************\n");
	printf("**************************\n");
}

//棋盘格初始化
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘格
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("玩家下棋\n");
	int x = 0;
	int y = 0;
	//判断坐标的合法性
	while (1)
	{
		printf("请输入下棋位置\n");
		scanf("%d%d", &x, &y);//获取玩家输入的坐标(x,y),利用while（1）循环直到输入合法值
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//此处可以下棋
			{
				board[x-1][y-1] = '*';
				break;//坐标合法，退出循环
			}
			else
			{
				printf("该位置已有棋子\n");
			}
		}
		else//坐标不合法
		{
			printf("坐标不合法，请重新输入\n");
		}
	}

}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int x = 0;
	int y = 0;
	
	while (1)
	{
		x = rand() % row;//一定要把生成值放到while循环内部
		y = rand() % col;
			if (board[x][y] == ' ')//此处可以下棋,注意电脑坐标不需要考虑用户
			{
				board[x][y] = '#';
				break;//坐标合法，退出循环
			}	
	}
}

//判断棋盘是否满了
int IsFull(char board[ROW][COL], int row, int col)
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

//判断游戏状态
/*规定ret为*时为玩家赢
* ret为#时电脑赢
* ret为Q时平局
* ret为C时结果未分
*/
char IsWin(char board[ROW][COL], int row, int col)//可改进推广至更多列（未改进）
{
	int i = 0;
	//判断横行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];//体会这个返回值
		}
	}
	//判断竖列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];//体会这个返回值
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局，就看棋盘有没有满,满了返回1，不满返回0
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}
//实现游戏功能
void game()
{
	//创建变量用于判断游戏状态
	char ret = 0;
	//先为创立棋盘格内的元素,定义一个数组
	char board[ROW][COL];
	//初始化棋盘格
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//----------利用while（1）再通过ret返回值确定是否需要继续游戏
	while(1)
	{ 
		//开始下棋(玩家先下）
		PlayerMove(board, ROW, COL);
		//展示此时棋盘状态
		DisplayBoard(board, ROW, COL);
		//判断此时是否已经出现游戏结果
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//游戏结束了
		{
			break;
		}
		//电脑下
		ComputerMove(board, ROW, COL);
		//展示此时棋盘状态
		DisplayBoard(board, ROW, COL);
		//判断此时是否已经出现游戏结果
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//游戏结束了
		{
			break;
		}
	}
	//while循环退出后检查ret的值，判断游戏结果
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}

}