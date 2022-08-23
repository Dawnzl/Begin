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
    int gap = n;
    while (gap > 1)
    {
        // gap > 1��ʱ��Ԥ����
        // gap == 1��ʱ��ֱ�Ӳ�������
        gap = (gap / 3 + 1);// +1�Ǳ�֤���һ��һ����1

        for (int i = 0; i < n - gap; ++i)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }

    }

}