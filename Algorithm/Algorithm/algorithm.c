//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>


////汉诺塔
//int Hanio(int num)
//{
//	if (num == 1)
//		return 1;
//	else
//		return 2 * Hanio(num - 1) + 1;
//}
//
//int main() 
//{
//	int n = 0;
//	scanf("%d", &n);
//	int inp = Hanio(n);
//	printf("%d", inp);
//}

////进阶汉诺塔
////现在有 n 个圆盘从上往下，从小到大叠在第一根柱子上，要把这些圆盘全部移动到第三根柱子，我们都知道，最少的移动数目为 2 ^ n - 1 次。但是现在我们要求的并不是这个。
////
////我们用 1，2，...，n 表示 n个盘子的编号，编号越大盘子就越大。在移动过程中，有的圆盘移动次数多，有的少。告知盘子总数和盘号，计算该盘子的移动次数
//#include<stdio.h>
//
////汉诺塔
//long long int Hanio(int num, int end)
//{
//	if (num == end)
//		return 1;
//	else
//		return 2 * Hanio(num, end + 1);
//}
//
//int main()
//{
//	int T = 0;
//	scanf("%d", &T);
//	while (T--)
//	{
//		int n = 0;
//		int e = 0;
//		scanf("%d %d", &n, &e);
//		long long int inp = Hanio(n, e);
//		printf("%lld\n", inp);
//	}
//
//}

//中位数、众数、平均数
//#include<stdio.h>
//#include<stdlib.h>
//
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int a[100] = { 0 };
//    for (int i = 0; i < n; ++i)
//    {
//        scanf("%d", &a[i]);
//    }
//
//    int max = a[0], min = a[0];
//    int sum = a[0];
//    for (int i = 1; i < n; ++i)
//    {
//        if (a[i] > max)
//            max = a[i];
//
//        if (a[i] < min)
//            min = a[i];
//
//        sum += a[i];
//    }
//    int p = sum / n;
//    int z = 0;
//    if (n % 2 == 0)
//    {
//        z = (a[n / 2] + a[n / 2 - 1]) / 2;
//    }
//    else
//        z = a[n / 2];
//    // 求数据范围
//    int range = max - min + 1;
//    int count[100] = { 0 };
//
//    for (int i = 0; i < n; ++i)
//    {
//        //相对映射出的下标
//        count[a[i] - min]++;
//    }
//
//    int maxsum = 0;
//    for (int i = 1; i < range; ++i)
//    {
//        if (count[i] > count[maxsum])
//            maxsum = i;
//    }
//
//    printf("%d %d %d", z, p, maxsum + min);
//    return 0;
//}