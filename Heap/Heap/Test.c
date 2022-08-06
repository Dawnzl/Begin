#include"Heap.h"



//堆排序
//排升序，建大堆
void HeapSort(int* a, int n)
{
	//建堆 -> 时间复杂度是O(N)
	for (int i = ((n - 1) - 1) / 2; i >= n; --i)//n-1是最后一个节点的下标,i是父节点
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;//确定最后一个数据的下标
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//将第一个数据和最后一个数据交换，同时最后一个数据不参与接下来的堆排
		//选出次大的
		//此时的数组个数正好是end
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