#pragma once
#include<stdio.h>
#include <stdlib.h> 
#include<assert.h>


typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* BuyListNode(LTDataType x);//�����ڵ�

ListNode* ListInit();//��ʼ���ڵ�
void ListPrint(ListNode* phead);//��ӡ����

void ListPushBack(ListNode* phead, LTDataType x);//β��
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);

//�շ���1���ǿշ���0
int ListEmpty(ListNode* phead);
int ListSize(ListNode* phead);
void ListDestory(ListNode* phead);