#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//��ӡ�˵�
void menu()
{
	printf("*********************\n");
	printf("*********************\n");
	printf("********1.paly*******\n");
	printf("********0.exit*******\n");
	printf("*********************\n");
	printf("*********************\n");
}
//������Ϸ
void game()
{
	//����mine�������ڴ洢���̵���Ϣ��show����������ʾ���׺�õ�����Ϣ
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	//�ȶ����������̽��г�ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//����
	SetMine(mine, ROW, COL);
	//չʾ��ǰ���̣����Խ������̶�չʾ��������ɺ�����mine��ֻչʾshow��
	//DisPlay(mine, ROW, COL);
	DisPlay(show, ROW, COL);
	//��ʼ����,����һ�κ󿴱仯
	FindMine(mine, show, ROW, COL);

 }
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������\n");
			break;
		}
	} while (input);
}