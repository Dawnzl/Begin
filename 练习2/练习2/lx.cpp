#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int find(int i, int stud[])
{
    int s = 0;

    return s;
}

int main()
{
    int n, m;//n��ѧ����m��ѧ��
    scanf("%d %d", &n, &m);
    int stu[100][1000];
    int book[1000] = { 0 };
    int i = 0, j = 0, a = 0;//a��ĳѧ��ϲ���Ŀ�Ŀ��Ŀ
    
    int stud = 0;
    for (stud = 0; stud < n; stud++)
    {
        scanf("%d", &a);
        for (i = 0; i < a; i++)
        {
            scanf("%d", stu[stud][i]);
        }

        //ѭ���������Ƶ�ϲ����Ŀ��book���Ӧ������++
        int k = 0;
        for (k = 0; k < n; k++)
        {
            

        }
    }
    return 0;
}