#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//��ӡ�˵�
void menu()
{
	printf("**************************\n");
	printf("**************************\n");
	printf("********1.play************\n");
	printf("********2.exit************\n");
	printf("**************************\n");
	printf("**************************\n");
}

//���̸��ʼ��
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
//��ӡ���̸�
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

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("�������\n");
	int x = 0;
	int y = 0;
	//�ж�����ĺϷ���
	while (1)
	{
		printf("����������λ��\n");
		scanf("%d%d", &x, &y);//��ȡ������������(x,y),����while��1��ѭ��ֱ������Ϸ�ֵ
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//�˴���������
			{
				board[x-1][y-1] = '*';
				break;//����Ϸ����˳�ѭ��
			}
			else
			{
				printf("��λ����������\n");
			}
		}
		else//���겻�Ϸ�
		{
			printf("���겻�Ϸ�������������\n");
		}
	}

}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������\n");
	int x = 0;
	int y = 0;
	
	while (1)
	{
		x = rand() % row;//һ��Ҫ������ֵ�ŵ�whileѭ���ڲ�
		y = rand() % col;
			if (board[x][y] == ' ')//�˴���������,ע��������겻��Ҫ�����û�
			{
				board[x][y] = '#';
				break;//����Ϸ����˳�ѭ��
			}	
	}
}

//�ж������Ƿ�����
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

//�ж���Ϸ״̬
/*�涨retΪ*ʱΪ���Ӯ
* retΪ#ʱ����Ӯ
* retΪQʱƽ��
* retΪCʱ���δ��
*/
char IsWin(char board[ROW][COL], int row, int col)//�ɸĽ��ƹ��������У�δ�Ľ���
{
	int i = 0;
	//�жϺ���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];//����������ֵ
		}
	}
	//�ж�����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];//����������ֵ
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//�ж��Ƿ�ƽ�֣��Ϳ�������û����,���˷���1����������0
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}
//ʵ����Ϸ����
void game()
{
	//�������������ж���Ϸ״̬
	char ret = 0;
	//��Ϊ�������̸��ڵ�Ԫ��,����һ������
	char board[ROW][COL];
	//��ʼ�����̸�
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//----------����while��1����ͨ��ret����ֵȷ���Ƿ���Ҫ������Ϸ
	while(1)
	{ 
		//��ʼ����(������£�
		PlayerMove(board, ROW, COL);
		//չʾ��ʱ����״̬
		DisplayBoard(board, ROW, COL);
		//�жϴ�ʱ�Ƿ��Ѿ�������Ϸ���
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//��Ϸ������
		{
			break;
		}
		//������
		ComputerMove(board, ROW, COL);
		//չʾ��ʱ����״̬
		DisplayBoard(board, ROW, COL);
		//�жϴ�ʱ�Ƿ��Ѿ�������Ϸ���
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//��Ϸ������
		{
			break;
		}
	}
	//whileѭ���˳�����ret��ֵ���ж���Ϸ���
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}