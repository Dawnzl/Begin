#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

/*第一奖金*/
//int main()
//{
//	long double i = 0;//利润
//	long double j = 0;//奖金
//	long double ii = 0;//中间变量
//	scanf("%lf", &i);
//	if (i <= 100000)
//	{
//		j = i * 0.1;
//	}
//	else if(i > 100000 && i <= 200000)
//	{
//		ii = i - 10000;
//		j = 10000 + ii * 0.075;
//	}
//	else if (i > 200000 && i <= 400000)
//	{
//		ii = i - 200000;
//		j = 17500 + ii * 0.05;
//	}
//	else if (i > 400000 && i <= 600000)
//	{
//		ii = i - 400000;
//		j = 27500 + ii * 0.03;
//	}
//	else if (i > 600000 && i <= 1000000)
//	{
//		ii = i - 600000;
//		j = 33500 + ii * 0.015;
//	}
//	else if (i > 1000000)
//	{
//		ii = i - 1000000;
//		j = 39500 + ii * 0.01;
//	}
//	printf("奖金有%lf\n", j);
//	return 0;
//}

/*第二完数*/
//int main()
//{
//	int i = 0, j = 2, sum = 0;
//	for (i = 2; i <= 1000; i++)
//	{
//		sum = 1;//1是任何数的因数
//		for (j = 2; j <= i / 2; j++)
//		{
//			if (i % j == 0)
//			{
//				sum += j;
//			}
//		}
//		if (sum == i) printf("%d ", i);
//	}
//	
//	return 0;
//}

/*第三猴子吃桃*/
//int main()
//{
//	int tao = 1;
//	int i=10;
//	for (i = 10; i > 1; i--)//计算9次
//	{
//		tao = (tao + 1) * 2;
//	}
//	printf("第一天有%d个桃子",tao);
//	return 0;
//}

/*第四nums*/
//int main()
//{
//	int nums[4] = {1,2,3,4};
//	int nums2[5] = { 3,1,2,10,1 };
//	//int x1 = sizeof(arr1) / sizeof(arr1[0]);
//	//int x2 = sizeof(arr2) / sizeof(arr2[0]);
//	int i = 0, sum = 0;
//	for (i = 0; i < 4; i++)
//	{
//		sum += nums[i];
//		printf("%d ", sum);
//	}
//	printf("\n");
//	sum = 0;
//	for (i = 0; i < 5; i++)
//	{
//		sum += nums2[i];
//		printf("%d ", sum);
//	}
//
//	return 0;
//}

/*第五杨辉三角*/
int main()
{
	int i, j;
	int yh[100][100] = { 0 };
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		yh[i][0] = 1;
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%3d ", yh[i][j]);
		}
		printf("\n");
	}
	return 0;
}