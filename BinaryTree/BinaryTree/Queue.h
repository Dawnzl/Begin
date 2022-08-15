#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//前置声明二叉树节点
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;

//定义链表
struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
};

typedef struct QueueNode QueueNode;

//定义队列的头尾节点
typedef struct Queue
{
	QueueNode* head;//头节点
	QueueNode* tail;//尾节点
}Queue;

void QueueInit(Queue* pq);//初始化
void QueueDestroy(Queue* pq);//销毁队列

void QueuePush(Queue* pq, QDataType x);//队尾进
void QueuePop(Queue* pq);//队头出
QDataType QueueFront(Queue* pq);//输出对头数据
QDataType QueueBack(Queue* pq);//输出队尾数据
bool QueueEmpty(Queue* pq); //是否为空
int QueueSize(Queue* pq);//有效数据个数



