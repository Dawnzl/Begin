#include"Queue.h"

void QueueInit(Queue* pq)//初始化
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)//销毁队列
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
void QueuePush(Queue* pq, QDataType x)//队尾进
{
	assert(pq);

	//因为队列只有在入数据的时候需要新节点，所以无需写额外的函数去定义创建节点
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	//如果尾节点为空则说明该队列是空队列，需要将头尾指针指向第一个新节点
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		//此时的tail指代最后一个有效数据节点，最后节点的next指向新节点
		pq->tail->next = newnode;
		//将队列尾节点tail指向newnode
		pq->tail = newnode;
	}


}

void QueuePop(Queue* pq)//队头出
{
	assert(pq);
	//队列为空则不符合条件
	assert(!QueueEmpty(pq));

	if (pq->head->next == NULL)
	{
		//释放的是head指向的有效节点
		free(pq->head);
		//再将头尾节点置空
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

}

QDataType QueueFront(Queue* pq)//输出队头数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)//输出队尾数据
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

bool QueueEmpty(Queue* pq)//是否为空
{
	assert(pq);

	return pq->head == NULL;
}

int QueueSize(Queue* pq)//有效数据个数
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

