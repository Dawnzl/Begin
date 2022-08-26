#include"Sort.h"

void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//插入排序
void InsertDort(int* a, int n)
{
    //多趟排序
    for (int i = 0; i < n - 1; ++i)
    {
       //把tmp插入到数组的[0,end]有序区间中
        int end = i;
        int tmp = a[end + 1];

        //用于挪动大于tmp的数据，并且找到end的数据位置
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
        //放入数据
        a[end + 1] = tmp;
    }
}

//希尔排序
void ShellSort(int* a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        // gap > 1的时候，预排序
        // gap == 1的时候，直接插入排序 O（N）
        gap = (gap / 3 + 1);// +1是保证最后一次一定是1

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
        //为了更清晰的感觉：
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

//选择排序
void SelectSort(int* a, int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        //选出最大的和最小的值（下标）
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
        // 如果最大值下标等于在left位置
        // 一旦最小值调换到left位置上去
        // 则最大值会被调换到原最小值位置
        // 为避免这种情况，用此方法
        if (left == maxIndex)
        {
            maxIndex = minIndex;
        }
        Swap(&a[right], &a[maxIndex]);
        ++left;
        --right;
    }

}

//堆排序
//排升序，建大堆
void HeapSort(int* a, int n)
{
    for (int i = ((n - 1) - 1) / 2; i >= 0; --i)
    {

    }
}
