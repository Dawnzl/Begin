#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

//void print(int num[],int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", num[i]);
//	}
//}
//
//int main()
//{
//	srand(time(NULL));
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;   //正常型
//	int num[100];//正常型
//	for (i = 0; i < n; i++)//正常型
//	{
//		num[i] = rand() % 11;
//	}
//	//int i = 5;     //测试例
//	//int num[5] = { 4,5,1,2,3 };//测试例
//	print(num, n);
//
//	int j = 0;
//	int max = num[0];
//	int max_x = 0;
//	int min = num[0];
//	int min_x = 0;
//	for (j = 0; j < i; j++)
//	{
//		if (max < num[j])
//		{
//			max = num[j];
//			max_x = j;
//		}
//		if (min > num[j])
//		{
//			min = num[j];
//			min_x = j;
//		}
//	}
//
//	//中值比较
//	int zz = n / 2;
//	int fine;//合适选择左右
//	if (abs(max_x - (zz)) > abs(min_x - (zz)))
//	{
//		fine = abs(max_x - (zz)) + zz;
//	}
//	else
//	{
//		fine = abs(min_x - (zz)) + zz;
//	}
//
//	printf("\n%d", fine);
//
//
//
//	//do 
//	//{
//	//	num[i] = rand() % 101;
//	//} while (num[i]!=num[i-1]);
//
//
//	return 0;
//}


/*
给出一个数列 A，求出一个数列B.

其中Bi   表示 数列A中 Ai 右边第一个比 Ai 大的数的下标(从1开始计数),没有找到这一个下标  Bi 就为0

输出数列B

输入描述:

第一行1个数字 n (n ≤ 10000)

第二行n个数字第 i 个数字为 Ai (0 ≤ Ai  ≤ 1000000000)

输出描述:

一共一行，第 i 个数和第 i+1 个数中间用空格隔开.



示例

输入

6

3 2 6 1 1 2

输出

3 3 0 6 6 0
*/

void print(int num[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}

int main()
{
	srand(time(NULL));
	int n = 0;
	scanf("%d", &n);
	int i = 0;   //正常型
	int num[100]={3,2,6,1,1,2};//正常型
	//for (i = 0; i < n; i++)//正常型
	//{
	//	num[i] = rand() % 11;
	//}
	print(num, n);

	int j = 0;
	int k = 0;
	int ii = 0;//下标
	int inf[100] = { 0 };//下标数组
	for (j = 0, ii = 0; j < n; j++, ii++)//重点!
	{
		//int max = num[j];//作比较项
		for (k = j; k < n; k++)
		{
			if (num[k] > num[j])
			{
				inf[ii] = k + 1;//下标加一
				break;
			}

		}
	}
	print(inf, n);

	return 0;
}
