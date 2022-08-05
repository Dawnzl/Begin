#include<stdio.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;//���㺢�ӽڵ���±꣬Ĭ����������
	//�ж��Ƿ�ִ�Ҷ�ӽ��
	while (child < n)
	{
		//ѡ�����Һ�����������һ��
		//child+1 < n ��Ϊ���ж��Һ��Ӵ治����(���ȱ�ٿ��ܻ�Խ��)
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;//��ڵ�С��++���ƶ����ҽڵ�
		}
		if (a[child] > a[parent])
		{
			//�������ӽ���е�ֵ
			Swap(&a[parent], &a[child]);
			//��ʱ���ڵ���ԭ�ӽڵ��λ�ã������±�
			parent = child;
			//�����ҳ��µ��ӽڵ�
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//������
//�����򣬽����
void HeapSort(int* a, int n)
{
	//���� -> ʱ�临�Ӷ���O(N)
	for (int i = ((n - 1) - 1) / 2; i >= n; --i)//n-1�����һ���ڵ���±�
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;//ȷ�����һ�����ݵ��±�
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//����һ�����ݺ����һ�����ݽ�����ͬʱ���һ�����ݲ�����������Ķ���
		//ѡ���δ��
		//��ʱ���������������end
		AdjustDown(a, end, 0);
		--end;
	}
}

int main()
{
	//int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	//AdjustDown(a, n, 0);
	int a[] = { 15,18,28,34,65,19,49,25,37,27 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);
	return 0;
}