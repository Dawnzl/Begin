#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化数据
void Initboard(char board[ROW][COL], int row, int col) 
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割信息
		//printf("---|---|---\n");

		if (i < row - 1)//最后一行不打印分割符号
		{
			int j = 0;
			for (j = 0; j < col; j++)//j是列
			{
				printf("---");
				if (j < col - 1 )    //  |符号总是比---符少一个
				{
					printf("|");
				}
			}
			printf("\n");
		}

		//printf("---|---|---\n");
	}
}

