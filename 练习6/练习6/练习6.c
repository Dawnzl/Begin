#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

/*
输入2:

MSRTZCJKPFLQYVAWBINXUEDGHOOILSMIJFRCOPPQCEUNYDUMPP    //

YIZSDWAHLNOVFUCERKJXQMGTBPPKOIYKANZWPLLVWMQJFGQYLL    //字符间隔数字用

FLSO

输出2：

NOIP
*/


int del(char str[]) {
    int c = 0, j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        c = i + 1, j = i + 1;
        while (str[j] != '\0') {
            if (str[j] != str[i]) {
                str[c++] = str[j++];
                // j++;
                // c++;
            }
            else {
                j++;
            }
        }
        str[c] = '\0';
    }
    return c;
}

int main()
{
    char pss1[100] = { 0 };
    char pss2[100] = { 0 };

    char pss3[100] = { 0 };
    char pssNUM[27] = { 0 };
    int i = 0, j = 0;

    gets(pss1);
    gets(pss2);
    gets(pss3);

    int num = del(pss1);
    //printf("%d ", num);
    del(pss2);
    if (num < 26)
    {
        printf("Failed\n");
    }
    else
    {
        //printf("%s\n", pss1);
   //printf("%s\n", pss2);

        for (i = 0; pss1[i] != '\0'; i++)
        {
            char NUM = pss1[i] - 'A';
            //printf("%d ", NUM);
            pssNUM[NUM] = pss2[i];

            //printf("%c ", pssNUM[NUM]);
            //printf("\n");
        }
        pssNUM[i] = '\0';


        //for (i = 0; pssNUM[i] != '\0'; i++)
        //{
        //    printf("%c ", pssNUM[i]);
        //}
        int ii = 0;
        char gai[100];
        j = 0;

        for (ii = 0; pss3[ii] != '\0'; ii++)
        {
            int num = pss3[ii] - 'A';
            gai[ii] = pssNUM[num];
        }
        gai[ii] = '\0';
        printf("%s\n", gai);


    }

   
    return 0;
}