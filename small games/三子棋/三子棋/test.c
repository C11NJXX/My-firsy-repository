#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
int main()
{
	srand((unsigned int)time(NULL)); 
	int input = 0;
	do
	{
		menu();
		printf("请选择1 or 0\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("请重新输入正确的值\n");
			break;
		}
	} while (input);
	return 0;
}