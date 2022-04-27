#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>

struct card
{
	char suit[10];//花色
	char face[10];//牌面
};

void fillcard(struct card x[]);//初始化
void changecard(struct card x[]); //洗牌
void printcard(struct card x[]);//发牌


int main()
{
	srand(time(NULL));
	//struct card a={"heart","3"};//红桃三
	struct card x[52];//52张牌
	fillcard(x);//初始化
	changecard(x);//洗牌
	printcard(x);//发牌
	return 0;

}

void fillcard(struct card a[]) 
{
	char suit[4][10] = { "heart","spade","clud","diamd" };
	char face[13][10] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	int i, k, j;
	for (i = 0; i < 52; i++)
	{
		k = i / 13;//0-12,13-25,26-38,39-51 ===  i/13后等于0，1,2,3分别对应不同的花色
		j = i % 13;//使得牌面固定
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
} //洗牌
void printcard(struct card a[])//发牌
{
	int i;
	for (i = 0; i < 52; i++)
	{
		printf("%s %s\n", a[i].suit, a[i].face);
	}
}