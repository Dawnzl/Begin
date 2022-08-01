#include<stdio.h>
#include <assert.h>
#include <stdlib.h>

/*��̬˳���*/
//#define N 100
//struct SeqList_j
//{
//	int a[N];
//	int size;;//��Ч���ݸ���
//};

//��̬˳���
typedef int SeqDateType;//int ���޸ķ����޸�����
typedef struct SeqList
{
	SeqDateType* a;
	int size;    //��Ч���ݵĸ���
	int capacity;//����
}SeqList,SEQ;//����������


// ��ʼ��(���ܷŵ�ͷ�ļ�.h��)
void SeqListInit (SeqList* pq)
{
	assert(pq);
	pq->a = NULL;
	pq->size = pq->capacity = 0;
}

// �ͷ�˳���
void SeqListDestory(SeqList* pq)
{
	assert(pq);//�������ָ��Ϊ��ָ������Դ���
	free(pq->a);
	pq->a = NULL;
	pq->size = pq->capacity = 0;
}


/*���˳���*/
void SeqListPrint(SeqList* pq)
{
	assert(pq);
	for (int i = 0; i < pq->size; ++i)
	{
		printf("%d ", pq->a[i]);
	}
	printf("\n");
}


// �ڴ��й������ݵĽṹ��ɾ�Ĳ�Ľӿ�

/*�����������Ƿ�����*/
void SeqCheck(SeqList* pq)
{
	if (pq->size == pq->capacity)
	{
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2;
		//��Ϊ�ṹ�ܵ���ʼ�����ռ�0�������һ���жϣ�����ռ�����Ϊ0�����¿ռ���Ϊ4
		//����һ����ֵ��ԭ��������������
		SeqDateType* newA = realloc(pq->a, sizeof(SeqDateType) * newcapacity);
		//����һ����ͬSDT���͵�newA����pq�ṹ��������к������ٿռ䣬���ٿռ��СΪSDT���͵��ֽ� * ������newcapacity

		//���ˣ�Ҫ����
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}//�ж����newAΪ������������˳�����

		pq->a = newA;//�ṹ������ͬ���������飬����ֱ�Ӹ�ֵ
		pq->capacity = newcapacity;//��ʾ���µ��ڴ��С
	}

}

/*β�巨*/
void SeqListPushBack(SeqList* pq, SeqDateType x)
{
	assert(pq);

	SeqCheck(pq);//����Ƿ�����

	pq->a[pq->size] = x;//��Ч�������ľ���Ҫ�������������ֵ�������±�
	pq->size++;//�ǵø���Ч��ֵ��һ
}

/*ͷ�巨*/
void SeqListPushFront(SeqList* pq, SeqDateType x)
{
	assert(pq);

	SeqCheck(pq);

	int end = pq->size - 1;//���һ����Ч�����±�
	while (end >= 0)//�����һ��ֵ����Ų
	{
		pq->a[end + 1] = pq->a[end];
		--end;
	}
	pq->a[0] = x;//����ֵ����
	pq->size++;
}

/*βɾ��*/
void SeqListPopBack(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0);//����ж�����Ϊ��Ҳ������Ч��ֵС��0ʱ����
	--pq->size;//�ǵø���Ч��ֵ��1
}

/*ͷɾ��*/
void SeqListPopFront(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0);//����ж�����Ϊ��Ҳ������Ч��ֵС��0ʱ����
	int begin = 0;
	while (begin < pq->size - 1)
	{
		pq->a[begin] = pq->a[begin + 1];//���������ǰ���� 
		++begin;//begin++�����ƶ�˳���
	}
	pq->size--;
}

//����x���±�
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

//�趨������趨��ֵ
void SeqListInsert(SeqList* pq, int pos, SeqDateType x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);//�� = ����Ϊ�����ô˷���ʵ��β��
	//SeqListInsert(pq, pq->size, x); β��

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
	//pos<��������Ϊ����pq->size�����һ�����ݣ�����û�����ݣ�����Ҫ����
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
	SeqListInit(&s);//��ʼ��

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
