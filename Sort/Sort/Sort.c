#include"Sort.h"

void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//��������
void InsertDort(int* a, int n)
{
    //��������
    for (int i = 0; i < n - 1; ++i)
    {
       //��tmp���뵽�����[0,end]����������
        int end = i;
        int tmp = a[end + 1];

        //����Ų������tmp�����ݣ������ҵ�end������λ��
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        //��������
        a[end + 1] = tmp;
    }
}

//ϣ������
void ShellSort(int* a, int n)
{
    int gap;
    int end;
    int tmp = a[end + gap];


}