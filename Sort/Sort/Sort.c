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
void InsertSort(int* a, int n)
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

//排升序，建大堆
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

//交换排序——冒泡排序
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
        //如果单趟下来不交换数值，这说明已经有序
        if (exchange == 0)
        {
            break;
        }
    }

}

//三数取中
int GetMidIndex(int* a, int left, int right)
{
    int mid = (left + right) >> 1;//相当于除以2，效率更高
    // left  mid  right情况
    if (a[left] < a[mid])
    {
        if (a[mid] < a[right])
            return mid;
        else if (a[left] > a[right])// 同时是a[mid] > a[right]
            return left;
        else //a[mid] > a[right] && a[right] >[left]
            return right;
    }
    else // a[left] > a[mid]
    {
        if (a[mid] > a[right])
            return mid;
        else if (a[right] > a[left])
            return left;
        else
            return right;
    }
}


//快排的单趟排序 hoare版本——左右指针法
int PartSort1(int* a, int left, int right)
{
    //排除最坏情况
    int midIndex = GetMidIndex(a, left, right);
    Swap(&a[left], &a[midIndex]);

    int keyi = left;
    while (left < right)
    {
        //找小
        while (left < right && a[right] >= a[keyi])
            --right;
        //找大
        while (left < right && a[left] <= a[keyi])
            ++left;

        Swap(&a[left], &a[right]);
    }
    Swap(&a[keyi], &a[left]);

    return left;
}

//快排的单趟排序 挖坑法
int PartSort2(int* a, int left, int right)
{

    //排除最坏情况
    int midIndex = GetMidIndex(a, left, right);
    Swap(&a[left], &a[midIndex]);

    int key = a[left];
    //直到相遇
    while (left < right)
    {
        //找小
        while (left < right && a[right] >= key)
            --right;
        // 放到左边的坑位中，右边形成新的坑
        a[left] = a[right];

        //找大
        while (left < right && a[left] <= key)
            ++left;
        // 放到右边的坑位中，左边形成新的坑
        a[right] = a[left];
    }
    
    //相遇后一定是key的位置
    a[left] = key;
    return left;
}

//快排的单趟排序 前后指针法
int PartSort3(int* a, int left, int right)
{
    //排除最坏情况
    int midIndex = GetMidIndex(a, left, right);
    Swap(&a[left], &a[midIndex]);

    int keyi = left;
    int prev = left, cur = left + 1;
    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            Swap(&a[cur], &a[prev]);
        }
        ++cur;
    }

    Swap(&a[keyi], &a[prev]);
    return prev;

}


//快速排序
void QuickSort(int* a, int begin, int end)
{
    if (begin >= end)
        return;

    // 1、如果这个子区间是数据较多，继续选key单趟，分割子区间分治递归
    // 2、如果这个子区间是数据较小，再去分治递归不划算
    if (end - begin > 20)// 20可更改
    {
        int keyi = PartSort3(a, begin, end);

        // [begin, keyi-1] keyi [keyi+1, end]
        QuickSort(a, begin, keyi - 1);
        QuickSort(a, keyi + 1, end);
    }
    else //数据小于10就进行插入排序
    {
        InsertSort(a + begin, end - begin + 1);
    }
}

#include"Stack.h"
//非递归快排
void QuickSortNonR(int* a, int begin, int end)
{
    Stack st;
    StackInit(&st);
    StackPush(&st, begin);
    StackPush(&st, end);

    while (!StackEmpty(&st))
    {
        int left, right;
        right = StackTop(&st);
        StackPop(&st);

        left = StackTop(&st);
        StackPop(&st);

        int keyi = PartSort1(a, left, right);
        if (left < keyi - 1)
        {
            StackPush(&st, left);
            StackPush(&st, keyi - 1);
        }

        if (keyi + 1 < right)
        {
            StackPush(&st, keyi + 1);
            StackPush(&st, right);
        }
    }

    StackDestory(&st);
}

// 递归子区间 时间复杂度O（N*logN）
void _MergeSort(int* a, int left, int right, int* tmp)
{
    if (left >= right)
        return;

    int mid = (left + right) >> 1;
    // [left,mid] [mid+1,right]
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    // 两段有序子区间归并tmp，并且拷贝回a数组中
    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int i = left;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
            tmp[i++] = a[begin1++];
        else
            tmp[i++] = a[begin2++];
    }

    // 剩余情况
    while (begin1 <= end1)
        tmp[i++] = a[begin1++];

    while (begin2 <= end2)
        tmp[i++] = a[begin2++];

    // 归并完成以后，拷回去a数组中的原位置
    for (int j = left; j <= right; ++j)
    {
        a[j] = tmp[j];
    }
}

//归并排序  时间复杂度O（N）
void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int*) * n);
    if (tmp == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    _MergeSort(a, 0, n - 1, tmp);

    free(tmp);
}

void _Merge(int* a, int* tmp, int begin1, int end1, int begin2, int end2)
{

    int i = begin1;//left
    int j = begin1;//如果不提前定义，就会被++改变
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
            tmp[i++] = a[begin1++];
        else
            tmp[i++] = a[begin2++];
    }

    // 剩余情况
    while (begin1 <= end1)
        tmp[i++] = a[begin1++];

    while (begin2 <= end2)
        tmp[i++] = a[begin2++];

    // 归并完成以后，拷回去a数组中的原位置
    for (; j <= end2; ++j)
    {
        a[j] = tmp[j];
    }
}

// 非递归归并排序
void MergeSortNonR(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int*) * n);
    if (tmp == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    
    int gap = 1;
    while (gap < n)
    {
        for (int i = 0; i < n; i += 2 * gap)
        {
            // [i, i+gap-1][i+gap, i+2*gap-1]
            int begin1 = i, end1 = i + gap - 1, begin2 = i + gap, end2 = i + 2 * gap - 1;

            // 如果第二个小区间不存在就不需要归并了，结束本次循环
            if (begin2 >= n)
                break;
            // 如果第二个小区间存在，但是第二个小区间不够gap个，结束位置越界了，需要修正一下
            if (end2 >= n)
                end2 = n - 1;

            _Merge(a, tmp, begin1, end1, begin2, end2);
        }

        gap *= 2;
    }

    free(tmp);
}

void CountSort(int* a, int n)
{
    int max = a[0], min = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > max)
            max = a[i];

        if (a[i] < min)
            min = a[i];
    }

    // 求数据范围
    int range = max - min + 1;
    int* count = malloc(sizeof(int) * range);
    memset(count, 0, sizeof(int) * range);//初始化
    for (int i = 0; i < n; ++i)
    {
        //相对映射出的下标
        count[a[i] - min]++;
    }

    int i = 0;
    for (int j = 0; j < range; ++j)
    {
        while (count[j]--)
        {
            a[i++] = j + min;
        }
    }
}