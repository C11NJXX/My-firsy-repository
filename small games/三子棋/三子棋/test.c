#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
int main()
{
	srand((unsigned int)time(NULL)); 
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��1 or 0\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("������������ȷ��ֵ\n");
			break;
		}
	} while (input);
	return 0;
}