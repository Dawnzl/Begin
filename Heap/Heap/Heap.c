#include"Heap.h"

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

//单独沿着插入节点到根的那一条路径 向上调整
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)//child == 0 就终止
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}


void HeapInit(HP* php, HPDataType* a, int n)//初始化
{
	assert(php);
	php->a =(HPDataType*) malloc(sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	memcpy(php->a, a, sizeof(HPDataType) * n);
	php->size = n;
	php->capacity = n;

	//建堆
	for (int i = (php->size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->a, php->size, i);
	}
}


void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	//满了要增容
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, php->capacity * 2 * sizeof(HPDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;

	//沿着插入节点到根的路径 向上调整
	AdjustUp(php->a, php->size - 1);


}

void HeapPop(HP* php)//删除堆顶数据
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[php->size - 1], &php->a[0]);
	//将首尾两数据交换位置后，调换到尾的数据不参与接下来的向下调整
	php->size--;

	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0; 
}

void HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; ++i)
		printf("%d ", php->a[i]);
	printf("\n");

	int num = 0;
	int levelSize = 1;//每一层的个数
	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
		++num;
		if (num == levelSize)
		{
			printf("\n");
			levelSize *= 2;
			num = 0;
		}
	}
	printf("\n\n");
}