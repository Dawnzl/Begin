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
	char mine[ROWS][COLS] = { 0 };//��Ų��úõ���
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
	//��ʼ�����������Ϊָ������
	//mine ������û�в�����ʱ����'0'
	InitBoard(mine, ROWS, COLS, '0');
	//show ������û�в�����ʱ����'*'
	InitBoard(show, ROWS, COLS, '*');

	//������
	SetMine(mine, ROW, COL);

	//DispalyBoard(mine, ROW, COL);//��ӡ�����õ�9*9�ĸ���
	DispalyBoard(show, ROW, COL);//��ӡ�����õ�9*9�ĸ���

	//�Ų���
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	//������������������
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ������\n");
			break;
		}
	} while (input);

	return 0;
}