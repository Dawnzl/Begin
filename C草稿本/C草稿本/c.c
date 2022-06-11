#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<string.h>
//
//unsigned int ConvertNum(char str[])
//{
//    int i = 0;
//    unsigned int num = 0;
//    for (i = 0; i < 20; i++)
//    {
//        if (str[i] >= '1' && str[i] <= '9')
//        {
//            int w = str[i] - '0' + 0;
//            num = w + num * 10;
//        }
//    }
//    return num;
//}
//
//int main()
//{
//    char ch, numStr[20] = { 0 };
//    unsigned int num;
//    int i = 0;
//
//    gets(numStr);
//    num = ConvertNum(numStr);
//    printf("%u", num);
//
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int num = 0;
//    int ind = 0;
//    scanf("%d", &num);
//    //printf("%d", num);
//    if (num % 3 != 0)
//    {
//        printf("Error!");
//        return 0;
//    }
//    else
//    {
//        int sum = 0;
//        int t = 0;
//        do
//        {
//            //do {
//            //    t = num % 10;
//            //    sum += t * t * t;
//            //    t /= 10;
//            //} while (t);
//
//
//            while (num > 0) {
//                int w = num % 10;
//                num = num / 10;
//                int s = w;
//                int n = 1;
//                while (n < 3) {
//                    s *= w;
//                    n++;
//                }
//                sum += s;
//            }
//            num = sum;
//            sum = 0;
//            ind++;
//        } while (num != 153);
//        printf("%d", ind);
//    }
//
//    return 0;
//}


/*埃式筛法*/
//#include<stdio.h>
//#include<stdbool.h>
//#include<stdbool.h>
//
//int main()
//{
//    int T = 0;
//    int n = 0, m = 0;
//    scanf("%d", &T);
//    while (T--)
//    {
//        scanf("%d %d", &m, &n);
//        int i = 0;
//        bool prime[1000001];
//        for (i = 2; i <= n; i++)
//        {
//            prime[i] = true;
//        }
//        int s = sqrt(n) + 1;
//        for (i = 2; i <= s; i++)
//        {
//            if (prime[i])
//            {
//                for (int j = i * i; j < n; j += i)
//                {
//                    prime[j] = false;
//                }
//            }
//        }
//        for (i = m; i < n; i++)
//        {
//            if (prime[i])
//            {
//                printf("%d ", i);
//            }
//        }
//        //isp(m, n);
//        printf("\n");
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char name[3][20] = { {"yww"},{"yzl"},{"xiaohong"} };
//
//	//while (1)
//	//{
//		int i = 0;
//		int j = 0;
//		int k = 0;//k是字符的项标
//		for (i = 0; i < 3-1 ; i++)
//		{
//			for (j = 0; j < 3 - i - 1; j++)
//			{
//				if (name[j][k] > name[j+1][k])
//				{
//					char t[20];
//					strcpy(t, name[j]);
//					strcpy(name[j], name[j + 1]);
//					strcpy(name[j + 1], t);
//
//				}
//				
//			}
//		}
//		for (i = 0; i < 3; i++)
//		{
//			printf("%s\n", name[i]);
//		}
//	//}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//    char str[8][9] = { "CHINA","JAPAN","KOREA","INDIA","CANADA","CNAADA","ENGLAND","FRANCE" };
//    char temp[9];
//    int i, l;
//    for (i = 0; i < 8; i++)
//    {
//        for (l = 0; l < 9; l++)
//        {
//            printf("%c", str[i][l]);
//        }
//        printf("\n");
//    }
//    //排序
//    printf("以上8个国家按字典中排序如下所示：\n");
//    int j, k;
//    for (j = 0; j < 8; j++)
//        for (k = j + 1; k < 8; k++)
//        {
//            if (strcmp(str[j], str[k]) > 0)
//            {//交换
//                strcpy(temp, str[j]);
//                strcpy(str[j], str[k]);
//                strcpy(str[k], temp);
//            }
//        }
//    for (i = 0; i < 8; i++)//输出
//        printf("%s\n", str[i]);
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char sigh[20];
//    scanf("%s", sigh);
//    //printf("%d\n",strlen(sigh)); 
//    if (strlen(sigh) == 11 && sigh[0] == '1')
//    {
//        int i = 0;
//        int f = 1;
//        for (i = 0; i < 11; i++)
//        {
//            if (sigh[i] < '0' || sigh[i]>'9')
//            {
//                printf("no\n");
//                f = 0;
//                break;
//            }
//        }
//        if (f) printf("yes\n");
//    }
//    else printf("no\n");
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#define M 3
//#define N 4
//int main()
//{
//	int max, a[M][N], b[M], i, j;
//	for (i = 0; i < M; i++)
//		for (j = 0; j < N; j++)
//			scanf("%d", &a[i][j]);
//
//	for (i = 0; i < M; i++)
//	{
//		max = 0;
//		for (j = 0; j < N; j++)
//		{
//			if (max < a[i][j])
//			{
//				max = a[i][j];
//			}
//		}
//		b[i] = max;
//	}
//
//
//	for (i = 0; i < M; i++)
//		printf("%4d ", b[i]);
//
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//void fun(int* a, int* b)
//{
//	int* c;
//	c = a; a = b; b = c;
//}
//int main()
//{
//	int x = 3, y = 5, * p = &x, * q = &y;
//	fun(p, q); printf("%d,%d,", *p, *q);
//	fun(&x, &y); printf("%d,%d\n", *p, *q);
//	return 0;
//}

//#include <stdio.h>
//void f(int* p, int* q);
//main()
//{
//	int m = 1, n = 2, * r = &m;
//	f(r, &n);
//	printf("%d,%d", m, n);
//}
//void f(int* p, int* q)
//{
//	p = p + 1; *q = *q + 1;
//}

//#include <stdio.h>
//struct ord
//{
//	int x, y;
//} dt[2] = { 1,2,3,4 };
//int main()
//{
//	struct ord* p = dt;
//	printf("%d,", ++p->x); printf("%d\n", ++p->y);
//}
 
/*字符逆序*/
//#include<stdio.h>
//int main()
//{
//	int i, j,temp;
//	char str[80];
//	i = 0;
//	while ((str[i] = getchar()) != '\n')
//		i++;
//	str[i] = 0;
//	
//	for (j = 0; j < i / 2; j++)
//	{
//		(char)temp = str[j];
//		str[j] = str[i - j - 1];
//		str[i - j - 1] = temp;
//	}
//
//
//	for (i = 0; str[i] != 0; i++)
//		putchar(str[i]);
//}

/*判断回文*/
//#include<stdio.h>
//int mirror(char* p);
//void main()
//{
//	char s[80];
//	int repeat, ri;
//	scanf_s("%d", &repeat);
//	getchar();
//	for (ri = 1; ri <= repeat; ri++)
//	{
//		gets(s);
//		if (mirror(s) != 0)
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//}
//int mirror(char* p) {
//	int i, n = 0;
//	for (i = 0; p[i] != '\0'; i++)
//	{
//		n++;
//	}
//	for (i = 0; i < n / 2; i++)
//	{
//		if (p[i] != p[n - i - 1])
//		{
//			return 0;
//		}
//	}
//	return 1;
//}


//#include<stdio.h>
//#include<string.h>
//
//void main()
//{
//	char str[100], s[100], c;
//	int i = 0, j = 0;
//	printf("zfc:");
//	gets(str);
//	printf("sc:");
//	scanf("%c", &c);
//
//	//while(i < strlen(str))
//	//{
//	//	if (str[i] != c)
//	//	{
//	//		s[j++] = str[i++];
//	//	}
//	//	else
//	//	{
//	//		i++;
//	//	}
//	//}
//
//	for (i = 0; i < strlen(str); i++)
//	{
//		if (str[i] != c)
//		{
//			s[j++] = str[i];
//		}
//	}
//	s[j] = '\0';
//
//	printf("%s\n", s);
//
//}

/*判断最小值位置*/
//#include<stdio.h>
//int station(int s[], int n)
//{
//	int min_x = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (s[i] < s[min_x])
//		{
//			min_x = i;
//		}
//	}
//	return min_x + 1;
//}
//int main()
//{
//	int a[100], n, i, t;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%d", &a[i]);
//	}
//	t = station(a, n);
//	printf("%d\n", t);
//}


//#include<stdio.h>
//
//int main()
//{
//
//	return 0;
//}