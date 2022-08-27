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
        // gap == 1��ʱ��ֱ�Ӳ������� O��N��
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
        //Ϊ�˸������ĸо���
        printf("gap:%d->", gap);
        PrintArray(a, n);
    }

}

void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//ѡ������
void SelectSort(int* a, int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        //ѡ�����ĺ���С��ֵ���±꣩
        int minIndex = left;
        int maxIndex = left;
        for (int i = left; i <= right; ++i)
        {
            if (a[i] < a[minIndex])
                minIndex = i;

            if (a[i] > a[maxIndex])
                maxIndex = i;
        }
        Swap(&a[left], &a[minIndex]);
        // ������ֵ�±������leftλ��
        // һ����Сֵ������leftλ����ȥ
        // �����ֵ�ᱻ������ԭ��Сֵλ��
        // Ϊ��������������ô˷���
        if (left == maxIndex)
        {
            maxIndex = minIndex;
        }
        Swap(&a[right], &a[maxIndex]);
        ++left;
        --right;
    }

}

//������
void AdjustDown(int* a, int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child + 1] > a[child])
        {
            ++child;
        }

        if (a[child] > a[parent])
        {
            Swap(&a[child], a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else break;
    }
}

//�����򣬽����
void HeapSort(int* a, int n)
{
    for (int i = ((n - 1) - 1) / 2; i >= 0; --i)
    {
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        --end;
    }
}

//�������򡪡�ð������
void BubbleSort(int* a, int n)
{
    //for (int end = n; end > n; end--)
    //{
    //    for (int i = 1; i < end; ++i)
    //    {
    //    }
    //}
    for (int j = 0; j < n; ++j)
    {
        int exchange = 0;
        for (int i = 1; i < n - j; ++i)
        {
            if (a[i - 1] < a[i])
            {
                Swap(&a[i - 1], &a[i]);
                exchange = 1;
            }
        }
        //�������������������ֵ����˵���Ѿ�����
        if (exchange == 0)
        {
            break;
        }
    }

}

//���ŵĵ������� hoare�汾��������ָ�뷨
int PartSort(int* a, int left, int right)
{
    int keyi = left;
    while (left < right)
    {
        //��С
        while (left < right && a[right] >= a[keyi])
            --right;
        //�Ҵ�
        while (left < right && a[left] <= a[keyi])
            ++left;

        Swap(&a[left], &a[right]);
    }
    Swap(&a[keyi], &a[left]);

    return left;
}

//��������
void QuickSort(int* a, int begin, int end)
{
    if (begin >= end)
        return;

    int keyi = PartSort(a, begin, end);
    

    // [begin, keyi-1] keyi [keyi+1, end]
    QuickSort(a, begin, keyi - 1);
    QuickSort(a, keyi + 1, end);

}