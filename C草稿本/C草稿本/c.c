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


/*°£Ê½É¸·¨*/
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