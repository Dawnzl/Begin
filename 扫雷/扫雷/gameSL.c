#define _CRT_SECURE_NO_WARNINGS 1
#include"SL.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DispalyBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------------扫雷游戏---------------------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------------扫雷游戏---------------------\n");

}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	//1-9
	//1-9
	while(count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)//统计周围雷的个数
{
	return (board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0');
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	int win = 0;//找到非雷的个数

	while (win < row * col - EASY_COUNT)//所有的格子减去雷的个数
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')//因为输入非雷的坐标后win会++，相同非雷坐标也会。为了防止游戏提前结束，要先要判断该坐标是否被排查过
			{
				printf("该坐标已被排查过，不能重复排查\n");
			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					DispalyBoard(mine, ROW, COL);
					break;
				}
				else //如果不是雷
				{
					win++;
					//统计mine数组中x，y坐标周围有几个雷
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//转换成数字字符放进所选的show数组里的坐标
					DispalyBoard(show, ROW, COL);
				}
			}

		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！");
		DispalyBoard(mine, ROW, COL);
	}
}

//1.标记功能
//2.当排查x，y坐标的时候：
// 2.1该坐标不是雷
// 2.2该坐标周围也不是雷
// 2.3该坐标没有被排查过
void boom(char mine[ROWS][COLS], int x, int y)
{
	if (mine[x][y] == '0')
	{
		mine[x][y] = ' ';
		if()
		{

		}
	}
}
//