#include<stdio.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;//计算孩子节点的下标，默认是左孩子先
	//判断是否抵达叶子结点
	while (child < n)
	{
		//选出左右孩子中最大的那一个
		//child+1 < n 是为了判断右孩子存不存在(如果缺少可能会越界)
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;//左节点小，++后移动到右节点
		}
		if (a[child] > a[parent])
		{
			//交换父子结点中的值
			Swap(&a[parent], &a[child]);
			//此时父节点在原子节点的位置，换置下标
			parent = child;
			//定义找出新的子节点
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//堆排序
//排升序，建大堆
void HeapSort(int* a, int n)
{
	//建堆 -> 时间复杂度是O(N)
	for (int i = ((n - 1) - 1) / 2; i >= n; --i)//n-1是最后一个节点的下标
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
	HeapSort(a, n);
	return 0;
}