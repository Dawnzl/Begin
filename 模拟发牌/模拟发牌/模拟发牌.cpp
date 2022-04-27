#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>

struct card
{
	char suit[10];//��ɫ
	char face[10];//����
};

void fillcard(struct card x[]);//��ʼ��
void changecard(struct card x[]); //ϴ��
void printcard(struct card x[]);//����


int main()
{
	srand(time(NULL));
	//struct card a={"heart","3"};//������
	struct card x[52];//52����
	fillcard(x);//��ʼ��
	changecard(x);//ϴ��
	printcard(x);//����
	return 0;

}

void fillcard(struct card a[]) 
{
	char suit[4][10] = { "heart","spade","clud","diamd" };
	char face[13][10] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	int i, k, j;
	for (i = 0; i < 52; i++)
	{
		k = i / 13;//0-12,13-25,26-38,39-51 ===  i/13�����0��1,2,3�ֱ��Ӧ��ͬ�Ļ�ɫ
		j = i % 13;//ʹ������̶�
		strcpy(a[i].suit, suit[k]);
		strcpy(a[i].face, face[j]);
	}
}
void changecard(struct card a[]) 
{
	int i, k;
	struct card t;
	for (i = 0; i < 52; i++)
	{
		k = rand() % 52;
		t = a[i];
		a[i] = a[k];
		a[k] = t;
	}
} //ϴ��
void printcard(struct card a[])//����
{
	int i;
	for (i = 0; i < 52; i++)
	{
		printf("%s %s\n", a[i].suit, a[i].face);
	}
}