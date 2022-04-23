#include<stdio.h>
#include<conio.h>

void inpsw(char psw[]);//ÃÜÂëÊäÈë·À¿ú


int main()
{
	char psw[20];
	inpsw(psw);
	return 0;
}

void inpsw(char psw[])//ÃÜÂëÊäÈë·À¿ú
{
	int i;
	for (i = 0; i < 6; i++)
	{
		psw[i] = getch();
		putchar('*');
	}
}