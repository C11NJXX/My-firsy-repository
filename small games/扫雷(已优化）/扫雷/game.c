#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//初始化棋盘，根据set的值来确定如何初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = rows;
	int j = cols;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < rows; j++)
		{
			board[i][j] = set;
		}
	}
}
//埋雷
void SetMine(char board[ROWS][COLS], int row, int col)//只需要处理可能埋雷区，不需要传rows，cols
{
	int count = NUM_MINE;
	while(count)
	{ 
		//生成随机数字范围是1到9，即rand随机值对9求余数得到0-8再加1
		int x = rand() % row + 1;//rand（）需要stdlib.h  再用srand初始化 ,time需要time.h
		int y = rand() % col + 1;
		//判断此处是否已经有雷
		if (board[x][y] != '1')
		{
			board[x][y] = '1';//需要循环，埋满NUM_MINE个雷
			count -= 1;
		}
	}
}
//展示棋盘
 void DisPlay(char board[ROWS][COLS], int row, int col)
{
	 int i = row;
	 int j = col;
	 printf("--------这是一条分界线--------\n");
	 for (i = 0; i <= col; i++)
	 {
		 printf("%d ", i);
	 }
	 printf("\n");
	 for (i = 1; i <= row; i++)
	 {
		 printf("%d ", i);
		 for (j = 1; j <=col; j++)
		 {
			 printf("%c ", board[i][j]);
		 }
		 printf("\n");
	 }
	 printf("--------这是一条分界线--------\n");
}
 //计算坐标附近雷的个数
 int CountMine(char board[ROWS][COLS], int x, int y)
 {
	 int count_ = 0;
	 int i = 0;
	 int j = 0;
	 for (i = x - 1; i <= x+1; i++)
	 {
		 for (j = y - 1; j <= y+1; j++)
		 {
			 if (board[i][j] == '1')
			 {
				 count_ += 1;
			 }
		 }
	 }
	 return count_;
	 //return (board[x - 1][y] +
		// board[x - 1][y - 1] +
		// board[x][y - 1] +
		// board[x + 1][y - 1] +
		// board[x + 1][y] +
		// board[x + 1][y + 1] +
		// board[x][y + 1] +
		// board[x - 1][y + 1] - 8 * '0');//先统计周围所有的ASCII码之和，再减去总共8个‘0’的ASCII码得到的就是几个一相加
 }
 //该坐标周围都没有炸弹，展开一片
 void ReJudge(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int row,int col,int win)
 {
	 int count = 0;
	 count = CountMine(mine, x, y);//因为CountMine没有在主函数中使用，所以不需要函数声明
	 show[x][y] = count + '0';
	 win++;
	 int m = 0;
	 int n = 0;
	 if (count == 0)//当该坐标周围都没有炸弹，展开一片，如果其中之一有炸弹就不能随意展开
	 {
		 mine[x][y] = '#';
		 for (m = x - 1; m < x + 1; m++)
		 {
			 for (n = y - 1; n < y + 1; n++)
			 {
				 if (m >= 1 && m <= row && n >= 1 && n <= col && mine[m][n] == '0' && show[m][n] == '*')//设置递归条件,新的坐标不能超出棋盘，而且新坐标没有炸弹，并且新坐标在show棋盘里仍是未知量*
				 {
					 ReJudge(mine, show, m, n, row, col, win);//递归!!!
				 }
			 }
		 }
	 }
 }
 //查找雷
 void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
 {
	 int life = Life;
	 int win = 0;
	 while (win < row * col - NUM_MINE)
	 {
		 int input = 3;
		 do
		 {
			 printf("输入1来排查坐标，输入0来标注此处有可能有雷,输入-1来解除标注\n");
			 scanf("%d", &input);
			 CLEAR_BUF
		 } while (input != 1 && input != 0 && input !=-1);
		 //获取排查点的坐标
		 int x = 0;
		 int y = 0;
		 if (input == 1)//排查坐标
		 {
			int count = 0;
			again: do
			 {
				 printf("请输入要排查的坐标(输入两个合法数字)\n");
				 scanf("%d%d", &x, &y);
				 CLEAR_BUF
			 } while (x<1 || x>row || y<1 || y>col);
			 if (mine[x][y] == '1')
			 { 
				 life -= 1;
				 printf("啊哦不小心踩雷了！可以复活！请输入作者的幸运数字>");
				 int LuckyNum = 0;
				 int CsLuckyNum = 3;
				 scanf("%d", &LuckyNum);
				 if (LuckyNum == CsLuckyNum)
				 {
					 if (life == 0)
					 {
						 printf("BOOMMMMMMM\n");
						 Eluminate_(mine, show, ROW, COL);
						 printf("虽然你输对了数字但是命没了，寄了，看看哪里有炸弹吧！\n");
						 DisPlay(mine, ROW, COL);
						 break;
					 }
					 else
					 {
						 printf("复活！你还有%d条命\n", life);
						 goto again;
					 }
					
				 }
				 else
				 {
					 printf("BOOMMMMMMM\n");
					 Eluminate_(mine, show, ROW, COL);
					 printf("你寄了，看看哪里有炸弹吧！");
					 DisPlay(mine, ROW, COL);
					 break;
				 }
			 }
			 //获得坐标后，如果没有炸弹，判断坐标周围的雷的总和,存到count中
			 //如果有炸弹，提示失败，退出循环
			 else if (mine[x][y] == '0'&&show[x][y]=='*')
			 {
				 count = CountMine(mine, x, y);//因为CountMine没有在主函数中使用，所以不需要函数声明
				 show[x][y] = count + '0';
				 win++;
				 int m = 0;
				 int n = 0;
				 if (count == 0)
				 {
					 mine[x][y] = '#';
					 for (m = x - 1; m < x + 1; m++)
					 {
						 for (n = y - 1; n < y + 1; n++)
						 {
							 if (m >= 1 && m <= row && n >= 1 && n <= col && mine[m][n] == '0' && show[m][n] == '*')
							 {
								 ReJudge(mine, show, m, n, row, col, win);
							 }
						 }
					 }
				 }
				 DisPlay(show, ROW, COL);
			 }
			 else
			 {
				 printf("这里已经被查过了哦！\n");
			 }
		 }
		 //!!!此处还需修改，只能在第一次标记雷！！！而且标记后就直接退出game函数了！
		 //修改完成，把上述所有操作全部放到循环中，只要排雷没结束，就要一直输入input，再根据input进行相对应的操作
		 else if (input == 0)//标记坐标
		 {
			 do
			 {
				 printf("请输入要标记的坐标(输入两个合法数字)\n");
				 scanf("%d%d", &x, &y);
				 CLEAR_BUF
			 } while (x<1 || x>row || y<1 || y>col);
			 //获得坐标后，标记此处为！
			 if (show[x][y] == '*')
			 {
				 show[x][y] = '!';
				 DisPlay(show, ROW, COL);
			 }
			 else if (show[x][y] == '!')
			 {
				 printf("已经标记过了哦\n");
			 }
			 else
			 {
				 printf("这里没炸弹看看数字吧！判断周围炸弹哦！\n");
			 }
		 }
		 else if (input == -1)
		 {
			 do
			 {
				 printf("请输入要解除标记的坐标(输入两个合法数字)\n");
				 scanf("%d%d", &x, &y);
				 CLEAR_BUF
			 } while (x<1 || x>row || y<1 || y>col);
			 //获得坐标后，标记此处为*
			 if (show[x][y] == '!')
			 {
				 show[x][y] = '*';
				 DisPlay(show, ROW, COL);
			 }
			 else if (show[x][y] == '*')
			 {
				 printf("这里没标记过哦！\n");
			 }
			 else
			 {
				 printf("这里没炸弹看看数字吧！判断周围炸弹哦！\n");
			 }
			
		 }
	 }
	 if (win == row * col - NUM_MINE)
	 {
		 printf("Win！！！！！！！！\n");
		 Eluminate_(mine, show, ROW, COL);
		 printf("你赢了！来看看炸弹分布吧！\n");
		 DisPlay(mine, ROW, COL);
	 }
 }
 //因为在上面优化过程中，使用了#所以在最后输出时，清除这些#号
 void Eluminate_(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
 {
	 int i = 0;
	 int j = 0;
	 for (i = 1; i <= row; i++)
	 {
		 for (j = 1; j <= col; j++)
		 {
			 if (mine[i][j] == '#')
			 {
				 mine[i][j] = '0';
			 }
		 }
	 }
 }