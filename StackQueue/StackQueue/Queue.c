#include"Queue.h"

void QueueInit(Queue* pq)//��ʼ��
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)//���ٶ���
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)//��β��
{
	assert(pq);

	//��Ϊ����ֻ���������ݵ�ʱ����Ҫ�½ڵ㣬��������д����ĺ���ȥ���崴���ڵ�
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	//���β�ڵ�Ϊ����˵���ö����ǿն��У���Ҫ��ͷβָ��ָ���һ���½ڵ�
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		//��ʱ��tailָ�����һ����Ч���ݽڵ㣬���ڵ��nextָ���½ڵ�
		pq->tail->next = newnode;
		//������β�ڵ�tailָ��newnode
		pq->tail = newnode;
	}


}

void QueuePop(Queue* pq)//��ͷ��
{
	assert(pq);
	//����Ϊ���򲻷�������
	assert(!QueueEmpty(pq));

	if (pq->head->next == NULL)
	{
		//�ͷŵ���headָ�����Ч�ڵ�
		free(pq->head);
		//�ٽ�ͷβ�ڵ��ÿ�
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

}

QDataType QueueFront(Queue* pq)//�����ͷ����
{
	assert(pq);
	assert(!QueueEmpty(pq));
	
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)//�����β����
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

bool QueueEmpty(Queue* pq)//�Ƿ�Ϊ��
{
	assert(pq);

	return pq->head == NULL;
}

int QueueSize(Queue* pq)//��Ч���ݸ���
{
	int size = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}

	return size;
}

