#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QDataType;

//��������
struct QueueNode 
{
	QDataType data;
	struct QueueNode* next;
};

typedef struct QueueNode QueueNode;

//������е�ͷβ�ڵ�
typedef struct Queue
{
	QueueNode* head;//ͷ�ڵ�
	QueueNode* tail;//β�ڵ�
}Queue;

void QueueInit(Queue* pq);//��ʼ��
void QueueDestroy(Queue* pq);//���ٶ���

void QueuePush(Queue* pq, QDataType x);//��β��
void QueuePop(Queue* pq);//��ͷ��
QDataType QueueFront(Queue* pq);//�����ͷ����
QDataType QueueBack(Queue* pq);//�����β����
bool QueueEmpty(Queue* pq); //�Ƿ�Ϊ��
int QueueSize(Queue* pq);//��Ч���ݸ���



