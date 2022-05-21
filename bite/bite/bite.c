#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*按位^操作符,不用创建临时变量交换数值*/
//int main()
//{
//	int a = 3;
//	int b = 5;
//
//	printf("交换前：a=%d,b=%d", a, b);
//
//	//^异或操作符，相同的值异或=0；0异或任何值都等于该值
//	a = a ^ b;//a=3^5
//	b = a ^ b;//b=3^5^5=3
//	a = a ^ b;//a=3^5^3=5
//
//	printf("交换后：a=%d,b=%d", a, b);
//
//	return 0;
//}

/*变种水仙花*/
//#include<stdio.h>
//int main()
//{
//    int num ;
//    for (num = 10000; num < 100000; num++)
//    {
//        num = 655;
//        int b = 10;
//        int wei = num % b;
//        int shou = num / b;
//        int sum = wei * shou;
//        while (shou > 0)
//        {
//            b *= 10;
//            wei = num % b;
//            shou = num / b;
//            sum += (wei * shou);
//        }
//        if (sum == num) printf("%d ", num);
//    }
//
//    return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//		int arr1[10] = { 0 };
//		int arr2[10] = { 0 };
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			scanf("%d", &arr1[i]);
//		}
//		for (i = 0; i < 10; i++)
//		{
//			scanf("%d", &arr2[i]);
//		}
//		for (i = 0; i < 10; i++)
//		{
//			int t = arr1[i];
//			arr1[i] = arr2[i];
//			arr2[i] = t;
//		}
//		printf("arr1:");
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", arr1[i]);
//		}
//		printf("\n");
//		printf("arr2:");
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", arr2[i]);
//		}
//		
//	return 0;
//}

/*自研函数*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//void init(int arr[], int c)
//{
//	int i = 0;
//	for (i = 0; i < c; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void print(int arr[], int c)
//{
//	int i = 0;
//	for (i = 0; i < c; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[], int c)
//{
//	int l = 0;
//	int r = c - 1;
//
//	while (l < r)
//	{
//		int t = arr[l];
//		arr[l] = arr[r];
//		arr[r] = t;
//		l++;
//		r--;
//	}
//}
//int main()
//{
//	int arr[10];
//	init(arr, 10);
//	print(arr, 10);
//	int arr2[10] = {1,2,3,4,5,6,7,8,9,0};
//	reverse(arr2, 10);
//	print(arr2, 10);
//	return 0;
//}

/*MY长度函数*/

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<assert.h>
//
//int my_strlen(const char* arr)
//{
//	int count = 0;
//	assert(arr != NULL);
//	while (*arr)
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//
//
//int main()
//{
//	const char* str = "aaaaaaa";
//	int c;
//	c = my_strlen(str);
//	printf("%d\n", c);
//	return 0;
//}

/*short *只收录两个字节*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };//int arr[0] ===> 01 00 00 00 | 02.....
//							  //short =低->高=> 01 00 | 00 00 | 02...
//	short* p = (short*)arr;//将int四字节强制成两字节short
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		*(p + i) = 0;
//	}
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//    int a = 0x11223344;//内存中存放是 |44|33|22|11| 
//    char* pc = (char*)&a;
//    *pc = 0;
//    printf("%x\n", a);
//	return 0;
//}

/**/
/*
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void print(int* p, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	print(arr, len);
	return 0;
}*/

/*水仙花数*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<math.h>
//
//int main()
//{
//	int i;
//	for (i = 0; i <= 100000; i++)
//	{
//		int n = 1;//至少一位数
//		int t = i;
//		int sum = 0;
//
//		while (t / 10)
//		{
//			n++;
//			t /= 10;
//		}
//		t = i;
//		while(t)
//		{
//			sum += pow(t % 10, n);
//			t /= 10;
//		}
//		if (sum == i)
//		printf("%d ", i);
//	}
//	return 0;
//}

/*喝汽水问题*/

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	int money;//钱数
//	scanf("%d", &money);
//	//int total = money;//瓶
//	//int empty = money;//空瓶
//
//	////置换
//	//while (empty >= 2)
//	//{
//	//	total += empty / 2;
//	//	empty = empty / 2 + empty % 2;
//	//}
//	//printf("%d\n", total);
//	if (money > 0) printf("%d\n", 2 * money - 1);
//	else printf("0\n");
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//		int a = 0;
//		int n = 0;
//		int i = 0;
//		int sum = 0;
//		int k = 0;
//		scanf("%d %d", &a, &n);
//
//		for (i = 0; i < n; i++)
//		{
//			k = k * 10 + a;
//			sum += k;
//		}
//	
//		printf("%d\n", sum);
//	
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//		int l = 0;
//		scanf("%d", &l);
//		int line = l / 2;
//		int i = 0;
//		for (i = 0; i < line; i++)
//		{
//			int j = 0;
//			for (j = 0; j < line-1-i; j++)
//			{
//				printf(" ");
//			}
//			for (j = 0; j < 2 * i + 1; j++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//
//		for (i = 0; i < line-1; i++)
//		{
//			int j = 0;
//			for (j = 0; j <= i; j++)
//			{
//				printf(" ");
//			}
//			for (j = 0; j <2*(line-1-i)-1; j++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<assert.h>
//void my_strcpy(char* dest,const char* src)
//{
//	assert(src!=NULL);
//	assert(dest != NULL);
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//
//int main()
//{
//	char arr1[20] = "XXXXXXXXXXXXXXXXXXX";
//	char arr2[] = "hello bite";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	int num[] = { 1,1,1,2,4,5,6,8,9,7,4,5,11,2 };
//	int len = sizeof(num) / sizeof(num[0]);
//	int i = 0, j = 0;
//	for (i = 0; i < len; i++)
//	{
//		for (j = 0; j < len - i - 1; j++)
//		{
//			if (num[i] > num[j])
//			{
//				int t = num[i];
//				num[i] = num[j];
//				num[j] = t;
//			}
//		}
//	}
//
//	for (int k = 0; k < len; k++)
//	{
//		for (i = 0, j = len - k - 1; i < j; i++)
//		{
//			if (num[i] % 2 == 0)
//			{
//				int t = num[i];
//				num[i] = num[j];
//				num[j--] = t;
//			}
//
//		}
//	}
//
//
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", num[i]);
//	}
//	return 0;
//}

/*指针数组*/
//指针变量构成的数组
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	int arr1[4] = { 1,2,3,4 };
//	int arr2[4] = { 2,3,4,5 };
//	int arr3[4] = { 3,4,5,6 };
//
//	int* parr[3] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			parr[i][j];
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*返回一个数值的二进制中的1的个数*/

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>

//int CountNumof1(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if ((n % 2) == 1)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	return count;
//}//-1无法使用

//int CountNumof1(int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//n = -1
//100000000000000000000000000000000001  原码
//111111111111111111111111111111111110 反码
//111111111111111111111111111111111111 补码
//111111111111111111111111111111111110 


//int CountNumof1(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//n = n & (n-1)
//n=15
// 每一次&都会消除补码的一个1
//1111 n 
//1110 n-1
//1110 &后n
//1101 n-1
//1100 &后n
//1011 n-1
//1000 &后n
//0111 n-1
//0000 &后n


//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int n = CountNumof1(num);
//	printf("%d\n", n);
//	return 0;
//}

/*
两个int（32位）整数m和n的二进制表达中，有多少个位bit不同？*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int count_diff_bit1(int m, int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((((m >> i) & 1)) != ((m >> i) & 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
////异或
//int count_diff_bit(int m, int n)
//{
//	int count = 0;
//	//^异或操作符
//	//相同为0，相异为1
//	int ret = m ^ n;
//	//获得一串已经相异或者相同的二进制数
//	//统计ret有多少个1则可以得出结果
//	while (ret)
//	{
//		ret = ret & (ret - 1);
//		count++;
//	}
//
//	return count;
//}
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &m, &n);
//	int ret = count_diff_bit(m, n);
//	printf("%d\n", ret);
//	return 0;
//}

/**/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int num = 0;
	scanf("%d", &num);

	//获得奇数位的数字
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);//num>>30是第一个奇数位
	}

	//获得偶数位的数字
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);//num>>31是第一个偶数位
	}
	return 0;
}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}