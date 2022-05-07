#define _CRT_SECURE_NO_WARNINGS 1
#include"SL.h"

void menu()
{
	printf("***********************************\n");
	printf("**********    1.play    ***********\n");
	printf("**********    0.exit    ***********\n");
	printf("***********************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化数组的内容为指定内容
	//mine 数组在没有布置雷时都是'0'
	InitBoard(mine, ROWS, COLS, '0');
	//show 数组在没有布置雷时都是'*'
	InitBoard(show, ROWS, COLS, '*');

	//设置雷
	SetMine(mine, ROW, COL);

	//DispalyBoard(mine, ROW, COL);//打印棋盘用到9*9的格子
	DispalyBoard(show, ROW, COL);//打印棋盘用到9*9的格子

	//排查雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	//设置随机数的生成起点
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择有误\n");
			break;
		}
	} while (input);

	return 0;
}