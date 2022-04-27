#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

struct food
{
	char alph;
	int x;
	int y;
};

void gotoxy(int x, int y)
{
	typedef
		struct _COORD {
		SHORT X;
		SHORT Y;
	}COORD;//位置坐标新名字
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(ST))
}

struct snack
{
	char head;
	char body;
	int len;
	int x[100];//蛇的x坐标
	int y[100];//y坐标

};

struct user
{
	char name[20];//
	char password[7];//
};


int main()
{
	srand(time(NULL));
	struct food fd = { '*',10,10 };
	struct snack st = { '@','+',3 };
	fillfood(&fd);
	int i;
	st.x[0] = 25; st.x[1] = 26; st.x[2] = 25;
	st.y[0] = 10; st.y[1] = 10; st.y[2] = 10;
	gotoxy(st.x[0], st.y[0]);


	printf("%c", st.head);
	for (i = 1; i <= st.len; i++)
	{
		gotoxy(st.x[0], st.y[0]);
		printf("%c", st.body);
	}
	sleep(1000);

	st.x[0]--;
	for (i = st.len; i > 0; i--)
	{
		st.x[i] = st.x[i - 1];
		st.y[i] = st.y[i - 1];
	}
	st.y[i]--;

	return 0;
}

void fillfood(struct food *f)
{
	(*f).alph = '*';
	f->x = rand() % 50;
	f->y = rand() % 20;
	gotoxy((*f).x, (*f).y);
	printf("%c", (*f).alph);
}