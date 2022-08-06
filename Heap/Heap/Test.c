#include"Heap.h"



//������
//�����򣬽����
void HeapSort(int* a, int n)
{
	//���� -> ʱ�临�Ӷ���O(N)
	for (int i = ((n - 1) - 1) / 2; i >= n; --i)//n-1�����һ���ڵ���±�,i�Ǹ��ڵ�
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
	//HeapSort(a, n);

	HP hp;
	HeapInit(&hp, a, n);
	HeapPrint(&hp);

	HeapPush(&hp, 8);
	HeapPrint(&hp);

	HeapPush(&hp, 88);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);

	return 0;
}