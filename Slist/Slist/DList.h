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

ListNode* BuyListNode(LTDataType x);//创建节点

ListNode* ListInit();//初始化节点
void ListPrint(ListNode* phead);//打印链表

void ListPushBack(ListNode* phead, LTDataType x);//尾插
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);

//空返回1，非空返回0
int ListEmpty(ListNode* phead);
int ListSize(ListNode* phead);
void ListDestory(ListNode* phead);