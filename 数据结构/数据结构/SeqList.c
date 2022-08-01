#include<stdio.h>
#include <assert.h>
#include <stdlib.h>

/*静态顺序表*/
//#define N 100
//struct SeqList_j
//{
//	int a[N];
//	int size;;//有效数据个数
//};

//动态顺序表
typedef int SeqDateType;//int 可修改方便修改类型
typedef struct SeqList
{
	SeqDateType* a;
	int size;    //有效数据的个数
	int capacity;//容量
}SeqList,SEQ;//命两个名字


// 初始化(不能放到头文件.h中)
void SeqListInit (SeqList* pq)
{
	assert(pq);
	pq->a = NULL;
	pq->size = pq->capacity = 0;
}

// 释放顺序表
void SeqListDestory(SeqList* pq)
{
	assert(pq);//如果传入指针为空指针则断言错误
	free(pq->a);
	pq->a = NULL;
	pq->size = pq->capacity = 0;
}


/*输出顺序表*/
void SeqListPrint(SeqList* pq)
{
	assert(pq);
	for (int i = 0; i < pq->size; ++i)
	{
		printf("%d ", pq->a[i]);
	}
	printf("\n");
}


// 内存中管理数据的结构增删改查的接口

/*检查表中数组是否已满*/
void SeqCheck(SeqList* pq)
{
	if (pq->size == pq->capacity)
	{
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2;
		//因为结构受到初始化，空间0。现添加一个判断，如果空间数字为0，则新空间数为4
		//设置一个数值是原来总容量的两倍
		SeqDateType* newA = realloc(pq->a, sizeof(SeqDateType) * newcapacity);
		//设置一个相同SDT类型的newA，给pq结构中数组进行后续开辟空间，开辟空间大小为SDT类型的字节 * 二倍的newcapacity

		//满了，要增容
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}//判断如果newA为空则输出错误并退出程序

		pq->a = newA;//结构类型相同，都是数组，可以直接赋值
		pq->capacity = newcapacity;//显示最新的内存大小
	}

}

/*尾插法*/
void SeqListPushBack(SeqList* pq, SeqDateType x)
{
	assert(pq);

	SeqCheck(pq);//检查是否已满

	pq->a[pq->size] = x;//有效数个数的就是要加入数组的最新值的数组下标
	pq->size++;//记得给有效数值加一
}

/*头插法*/
void SeqListPushFront(SeqList* pq, SeqDateType x)
{
	assert(pq);

	SeqCheck(pq);

	int end = pq->size - 1;//最后一个有效数字下标
	while (end >= 0)//从最后一个值往后挪
	{
		pq->a[end + 1] = pq->a[end];
		--end;
	}
	pq->a[0] = x;//将数值放入
	pq->size++;
}

/*尾删法*/
void SeqListPopBack(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0);//如果判断条件为否，也就是有效数值小于0时报错
	--pq->size;//记得给有效数值减1
}

/*头删法*/
void SeqListPopFront(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0);//如果判断条件为否，也就是有效数值小于0时报错
	int begin = 0;
	while (begin < pq->size - 1)
	{
		pq->a[begin] = pq->a[begin + 1];//后数据替代前数据 
		++begin;//begin++才能移动顺序表
	}
	pq->size--;
}

//查找x的下标
int SeqListFind(SeqList* pq, SeqDateType x)
{
	assert(pq);
	for (int i = 0; i < pq->size; ++i)
	{
		if (pq->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}

//设定点插入设定数值
void SeqListInsert(SeqList* pq, int pos, SeqDateType x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);//加 = 是因为可以用此方法实现尾插
	//SeqListInsert(pq, pq->size, x); 尾插

	SeqCheck(pq);

	int end = pq->size - 1;
	while (end >= pos)
	{
		pq->a[end + 1] = pq->a[end];
		--end;
	}

	pq->a[pos] = x;
	pq->size++;
}

void SeqListErase(SeqList* pq, int pos, SeqDateType x)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	//pos<不等于因为等于pq->size是最后一个数据，本身没有数据，不需要等于
	int begin = pos;
	while (begin <= pq->size - 1)
	{
		pq->a[begin] = pq->a[begin + 1];
		++begin;
	}

	pq->size--;
}

void SeqListModify(SeqList* pq, int pos, SeqDateType x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);

	pq->a[pos] = x;
}

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);//初始化

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPrint(&s);

	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListDestory(&s);

}

int main()
{

	TestSeqList1();
	return 0;
}
