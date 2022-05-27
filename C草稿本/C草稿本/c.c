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

#include<stdio.h>
#include<string.h>

int main()
{
    char str[8][9] = { "CHINA","JAPAN","KOREA","INDIA","CANADA","CNAADA","ENGLAND","FRANCE" };
    char temp[9];
    int i, l;
    for (i = 0; i < 8; i++)
    {
        for (l = 0; l < 9; l++)
        {
            printf("%c", str[i][l]);
        }
        printf("\n");
    }
    //排序
    printf("以上8个国家按字典中排序如下所示：\n");
    int j, k;
    for (j = 0; j < 8; j++)
        for (k = j + 1; k < 8; k++)
        {
            if (strcmp(str[j], str[k]) > 0)
            {//交换
                strcpy(temp, str[j]);
                strcpy(str[j], str[k]);
                strcpy(str[k], temp);
            }
        }
    for (i = 0; i < 8; i++)//输出
        printf("%s\n", str[i]);
    return 0;
}