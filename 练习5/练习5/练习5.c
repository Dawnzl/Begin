#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



int main()
{
	int shou, limit;
	scanf("%d %d", &shou, &limit);

	int ss[100];
	int i, k, j = 0;
	for (i = shou; i <= limit; i++)//闭区间
	{
		int f = 1;
		for (k = 2; k < i - 1; k++)
		{
			if (i % k == 0)
			{
				f = 0;
				break;
			}
		}
		if (f) ss[j++] = i;
	}

	for (int i = 0; i < j; i++)
	{
		printf("%d ", ss[i]);
		if ((i+1) % 5 == 0) printf("\n");
	}

	printf("\n");
	printf("\n");


	//int Css[100][100];

	//for (i = 0; i < j; i++)
	//{
	//	for (int ind = 1; ind < 10; ind++)//项间隔
	//	{
	//		int d = ss[i + ind] - ss[i];
	//		int set = ss[i + ind] + d;
	//		Css[i][0] = ss[i];
	//		Css[i][1] = ss[i + ind];
	//		for (k = i + 2; k < j; k++)//k是第二项的下标
	//		{
	//			if (ss[k] == set)
	//			{
	//				Css[i][k] = ss[k];
	//				set = ss[k] + d;
	//			}
	//		}
	//	}

	//}
	
	//int d = 1;
	//int ind;//Css的列标
	//for (i = 0; i < j; i++)//控制首项的下标
	//{
	//	Css[i][0] = ss[i];
	//	for (d = 1, ind = 1; d < 100; d++)//公差
	//	{
	//		int set = ss[i] + d;//下一项
	//		for (k = i; k < j; k++)//寻找下一项
	//		{
	//			if (ss[k] == set)
	//			{
	//				Css[i][ind++] = ss[k];
	//				set = ss[k] + d;
	//				//continue;
	//			}
	//		}
	//	}
	int step = 0;
	i = 0;
	int d, s;
	while (i < j - 3)
	{
		d = ss[i + 1] - ss[i];
		while (ss[i + 2] - ss[i + 1] == d)
		{
			i++;
			step++;
		}
		if (step > 0)
		{
			for (s = i - step; s < i + 2; ++s)printf("%d ", ss[s]);
			printf("\n");
			i += 2;
			step = 0;
		}
		else
		{
			i++;
			step = 0;
		}
	}
	//if (step > 0)
	//{
	//	for (int s = i - step; s < i + 2; ++s) printf("\n");
	//}




	//for (j = 0; j < 100; j++)
	//{
	//	for (i = 0; i < 3; i++)
	//	{
	//		printf("%d ", Css[j][i]);
	//	}
	//	printf("\n");
	//}

	return 0;
}