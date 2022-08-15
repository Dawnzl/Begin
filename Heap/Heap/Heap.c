#include"Heap.h"

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

//�������Ų���ڵ㵽������һ��·�� ���ϵ���
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)//child == 0 ����ֹ
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


void HeapInit(HP* php, HPDataType* a, int n)//��ʼ��
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

	//����
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
	//����Ҫ����
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

	//���Ų���ڵ㵽����·�� ���ϵ���
	AdjustUp(php->a, php->size - 1);


}

void HeapPop(HP* php)//ɾ���Ѷ�����
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[php->size - 1], &php->a[0]);
	//����β�����ݽ���λ�ú󣬵�����β�����ݲ���������������µ���
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
	int levelSize = 1;//ÿһ��ĸ���
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