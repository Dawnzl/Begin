#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int read(char name[][100]);//��ȡ������󷵻ظ���
void print(int i, char name[][100]);
void paixu(int i,char name[][100]);//Ӣ������ĸ����
//void find(char CX, char name[][100], int n);
void find2(char name[][100], char CX[], int n);


int main()
{

	char name[50][100];
	int i = read(name);

	printf("�ļ����ݣ�\n");
	print(i, name);

	paixu(i, name);
	printf("\n");
	printf("����ĸ�����\n");
	print(i, name);

	char CX[30];
	printf("\n");
	printf("�������ѯ���ĵ��ʣ�");
	scanf("%s", CX);
	find2(name, CX, i);
	printf("\n");
	//find(CX, name, i);
	return 0;
}

int read(char name[][100])//��ȡ�ļ�������󷵻ظ���
{
	FILE* f;
	int i = 0;
	f = fopen("name.txt", "r+");
	while (!feof(f))
	{
		fscanf(f, "%s", name[i++]);//���ļ����û��������������������
	}
	fclose(f);
	return i;
}

void paixu(int i,char name[][100])
{
	int k = 0; char t[50]; int n = 0; int nj = 0;
	for (n = 0; n < i; n++)
	{
		for (k = 0; k < i - n - 1; k++)
		{
			//	for (nj = 0; nj < 30; nj++)
			//	{
			if (name[k][nj] > name[k + 1][nj])//��k�е�0��������ĸ
			{
				int ij = 0;
				for (ij = 0; ij < 50; ij++)
				{
					t[ij] = name[k][ij];
				}
				for (ij = 0; ij < 50; ij++)
				{
					name[k][ij] = name[k + 1][ij];
				}
				for (ij = 0; ij < 50; ij++)
				{
					name[k + 1][ij] = t[ij];
				}

			}
			//		}
		}
	}
}

void find(char CX[], char name[][100], int n)
{
	CX = (char*)malloc(30);//��Ҫ��̬�����ڴ�
	int i, f = 1;
	for (i = 0; i < n; i++) {
		if (strcmp(CX, name[i])==0) 
		{
			f = 0;
			printf("�˻����ļ���");
			break;
		}
	}
	if (f == 1) {
		printf("�˻��ļ���δ��ѯ��");
	}

	free(CX);//�ͷ��ڴ�
}

void find2(char name[][100], char CX[],int n)
{
	FILE* f1;
	int i, f = 1;
	f1 = fopen("name.txt", "r");
	for (i = 0; i <  n; i++) {
		fscanf(f1, "%s", name[i]);
		if (!strcmp(CX, name[i])) {
			f = 0;
			break;
		}
	}
	if (f == 1) {
		printf("�˻��ļ���δ��ѯ��");
		fclose(f1);
	}
	else {
		printf("�˻����ļ���");
		fclose(f1);
	}
}

void print(int i,char name[][100])
{
	int j = 0;
	for (j = 0; j < i; j++) printf("%s\n", name[j]);
}