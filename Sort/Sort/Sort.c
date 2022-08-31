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
void InsertSort(int* a, int n)
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

//����ȡ��
int GetMidIndex(int* a, int left, int right)
{
    int mid = (left + right) >> 1;//�൱�ڳ���2��Ч�ʸ���
    // left  mid  right���
    if (a[left] < a[mid])
    {
        if (a[mid] < a[right])
            return mid;
        else if (a[left] > a[right])// ͬʱ��a[mid] > a[right]
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


//���ŵĵ������� hoare�汾��������ָ�뷨
int PartSort1(int* a, int left, int right)
{
    //�ų�����
    int midIndex = GetMidIndex(a, left, right);
    Swap(&a[left], &a[midIndex]);

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

//���ŵĵ������� �ڿӷ�
int PartSort2(int* a, int left, int right)
{

    //�ų�����
    int midIndex = GetMidIndex(a, left, right);
    Swap(&a[left], &a[midIndex]);

    int key = a[left];
    //ֱ������
    while (left < right)
    {
        //��С
        while (left < right && a[right] >= key)
            --right;
        // �ŵ���ߵĿ�λ�У��ұ��γ��µĿ�
        a[left] = a[right];

        //�Ҵ�
        while (left < right && a[left] <= key)
            ++left;
        // �ŵ��ұߵĿ�λ�У�����γ��µĿ�
        a[right] = a[left];
    }
    
    //������һ����key��λ��
    a[left] = key;
    return left;
}

//���ŵĵ������� ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
    //�ų�����
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


//��������
void QuickSort(int* a, int begin, int end)
{
    if (begin >= end)
        return;

    // 1�������������������ݽ϶࣬����ѡkey���ˣ��ָ���������εݹ�
    // 2�������������������ݽ�С����ȥ���εݹ鲻����
    if (end - begin > 20)// 20�ɸ���
    {
        int keyi = PartSort3(a, begin, end);

        // [begin, keyi-1] keyi [keyi+1, end]
        QuickSort(a, begin, keyi - 1);
        QuickSort(a, keyi + 1, end);
    }
    else //����С��10�ͽ��в�������
    {
        InsertSort(a + begin, end - begin + 1);
    }
}

#include"Stack.h"
//�ǵݹ����
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

// �ݹ������� ʱ�临�Ӷ�O��N*logN��
void _MergeSort(int* a, int left, int right, int* tmp)
{
    if (left >= right)
        return;

    int mid = (left + right) >> 1;
    // [left,mid] [mid+1,right]
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    // ��������������鲢tmp�����ҿ�����a������
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

    // ʣ�����
    while (begin1 <= end1)
        tmp[i++] = a[begin1++];

    while (begin2 <= end2)
        tmp[i++] = a[begin2++];

    // �鲢����Ժ󣬿���ȥa�����е�ԭλ��
    for (int j = left; j <= right; ++j)
    {
        a[j] = tmp[j];
    }
}

//�鲢����  ʱ�临�Ӷ�O��N��
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
    int j = begin1;//�������ǰ���壬�ͻᱻ++�ı�
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
            tmp[i++] = a[begin1++];
        else
            tmp[i++] = a[begin2++];
    }

    // ʣ�����
    while (begin1 <= end1)
        tmp[i++] = a[begin1++];

    while (begin2 <= end2)
        tmp[i++] = a[begin2++];

    // �鲢����Ժ󣬿���ȥa�����е�ԭλ��
    for (; j <= end2; ++j)
    {
        a[j] = tmp[j];
    }
}

// �ǵݹ�鲢����
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

            // ����ڶ���С���䲻���ھͲ���Ҫ�鲢�ˣ���������ѭ��
            if (begin2 >= n)
                break;
            // ����ڶ���С������ڣ����ǵڶ���С���䲻��gap��������λ��Խ���ˣ���Ҫ����һ��
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

    // �����ݷ�Χ
    int range = max - min + 1;
    int* count = malloc(sizeof(int) * range);
    memset(count, 0, sizeof(int) * range);//��ʼ��
    for (int i = 0; i < n; ++i)
    {
        //���ӳ������±�
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