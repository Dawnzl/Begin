#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*********************************");
	printf("********     1 .paly    *********");
	printf("********     0 .exit    *********");
	printf("*********************************");
}

void game()
{
	char board[ROW][COL]={0};
	Initboard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
}

int main()
{
	game();
}