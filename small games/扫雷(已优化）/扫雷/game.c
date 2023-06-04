#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//��ʼ�����̣�����set��ֵ��ȷ����γ�ʼ��
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
//����
void SetMine(char board[ROWS][COLS], int row, int col)//ֻ��Ҫ�������������������Ҫ��rows��cols
{
	int count = NUM_MINE;
	while(count)
	{ 
		//����������ַ�Χ��1��9����rand���ֵ��9�������õ�0-8�ټ�1
		int x = rand() % row + 1;//rand������Ҫstdlib.h  ����srand��ʼ�� ,time��Ҫtime.h
		int y = rand() % col + 1;
		//�жϴ˴��Ƿ��Ѿ�����
		if (board[x][y] != '1')
		{
			board[x][y] = '1';//��Ҫѭ��������NUM_MINE����
			count -= 1;
		}
	}
}
//չʾ����
 void DisPlay(char board[ROWS][COLS], int row, int col)
{
	 int i = row;
	 int j = col;
	 printf("--------����һ���ֽ���--------\n");
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
	 printf("--------����һ���ֽ���--------\n");
}
 //�������긽���׵ĸ���
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
		// board[x - 1][y + 1] - 8 * '0');//��ͳ����Χ���е�ASCII��֮�ͣ��ټ�ȥ�ܹ�8����0����ASCII��õ��ľ��Ǽ���һ���
 }
 //��������Χ��û��ը����չ��һƬ
 void ReJudge(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int row,int col,int win)
 {
	 int count = 0;
	 count = CountMine(mine, x, y);//��ΪCountMineû������������ʹ�ã����Բ���Ҫ��������
	 show[x][y] = count + '0';
	 win++;
	 int m = 0;
	 int n = 0;
	 if (count == 0)//����������Χ��û��ը����չ��һƬ���������֮һ��ը���Ͳ�������չ��
	 {
		 mine[x][y] = '#';
		 for (m = x - 1; m < x + 1; m++)
		 {
			 for (n = y - 1; n < y + 1; n++)
			 {
				 if (m >= 1 && m <= row && n >= 1 && n <= col && mine[m][n] == '0' && show[m][n] == '*')//���õݹ�����,�µ����겻�ܳ������̣�����������û��ը����������������show����������δ֪��*
				 {
					 ReJudge(mine, show, m, n, row, col, win);//�ݹ�!!!
				 }
			 }
		 }
	 }
 }
 //������
 void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
 {
	 int life = Life;
	 int win = 0;
	 while (win < row * col - NUM_MINE)
	 {
		 int input = 3;
		 do
		 {
			 printf("����1���Ų����꣬����0����ע�˴��п�������,����-1�������ע\n");
			 scanf("%d", &input);
			 CLEAR_BUF
		 } while (input != 1 && input != 0 && input !=-1);
		 //��ȡ�Ų�������
		 int x = 0;
		 int y = 0;
		 if (input == 1)//�Ų�����
		 {
			int count = 0;
			again: do
			 {
				 printf("������Ҫ�Ų������(���������Ϸ�����)\n");
				 scanf("%d%d", &x, &y);
				 CLEAR_BUF
			 } while (x<1 || x>row || y<1 || y>col);
			 if (mine[x][y] == '1')
			 { 
				 life -= 1;
				 printf("��Ŷ��С�Ĳ����ˣ����Ը�����������ߵ���������>");
				 int LuckyNum = 0;
				 int CsLuckyNum = 3;
				 scanf("%d", &LuckyNum);
				 if (LuckyNum == CsLuckyNum)
				 {
					 if (life == 0)
					 {
						 printf("BOOMMMMMMM\n");
						 Eluminate_(mine, show, ROW, COL);
						 printf("��Ȼ����������ֵ�����û�ˣ����ˣ�����������ը���ɣ�\n");
						 DisPlay(mine, ROW, COL);
						 break;
					 }
					 else
					 {
						 printf("����㻹��%d����\n", life);
						 goto again;
					 }
					
				 }
				 else
				 {
					 printf("BOOMMMMMMM\n");
					 Eluminate_(mine, show, ROW, COL);
					 printf("����ˣ�����������ը���ɣ�");
					 DisPlay(mine, ROW, COL);
					 break;
				 }
			 }
			 //�����������û��ը�����ж�������Χ���׵��ܺ�,�浽count��
			 //�����ը������ʾʧ�ܣ��˳�ѭ��
			 else if (mine[x][y] == '0'&&show[x][y]=='*')
			 {
				 count = CountMine(mine, x, y);//��ΪCountMineû������������ʹ�ã����Բ���Ҫ��������
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
				 printf("�����Ѿ��������Ŷ��\n");
			 }
		 }
		 //!!!�˴������޸ģ�ֻ���ڵ�һ�α���ף��������ұ�Ǻ��ֱ���˳�game�����ˣ�
		 //�޸���ɣ����������в���ȫ���ŵ�ѭ���У�ֻҪ����û��������Ҫһֱ����input���ٸ���input�������Ӧ�Ĳ���
		 else if (input == 0)//�������
		 {
			 do
			 {
				 printf("������Ҫ��ǵ�����(���������Ϸ�����)\n");
				 scanf("%d%d", &x, &y);
				 CLEAR_BUF
			 } while (x<1 || x>row || y<1 || y>col);
			 //�������󣬱�Ǵ˴�Ϊ��
			 if (show[x][y] == '*')
			 {
				 show[x][y] = '!';
				 DisPlay(show, ROW, COL);
			 }
			 else if (show[x][y] == '!')
			 {
				 printf("�Ѿ���ǹ���Ŷ\n");
			 }
			 else
			 {
				 printf("����ûը���������ְɣ��ж���Χը��Ŷ��\n");
			 }
		 }
		 else if (input == -1)
		 {
			 do
			 {
				 printf("������Ҫ�����ǵ�����(���������Ϸ�����)\n");
				 scanf("%d%d", &x, &y);
				 CLEAR_BUF
			 } while (x<1 || x>row || y<1 || y>col);
			 //�������󣬱�Ǵ˴�Ϊ*
			 if (show[x][y] == '!')
			 {
				 show[x][y] = '*';
				 DisPlay(show, ROW, COL);
			 }
			 else if (show[x][y] == '*')
			 {
				 printf("����û��ǹ�Ŷ��\n");
			 }
			 else
			 {
				 printf("����ûը���������ְɣ��ж���Χը��Ŷ��\n");
			 }
			
		 }
	 }
	 if (win == row * col - NUM_MINE)
	 {
		 printf("Win����������������\n");
		 Eluminate_(mine, show, ROW, COL);
		 printf("��Ӯ�ˣ�������ը���ֲ��ɣ�\n");
		 DisPlay(mine, ROW, COL);
	 }
 }
 //��Ϊ�������Ż������У�ʹ����#������������ʱ�������Щ#��
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