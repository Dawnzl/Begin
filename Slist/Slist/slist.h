#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;//方便后期修改数据类型
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//单项+ 不带头+ 不循环
void SListPrint(SLTNode* plist);

void SListPushBack(SLTNode** pplist, SLTDataType x);//尾插
void SListPushFront(SLTNode** plist, SLTDataType x);//头插

void SListPopBack(SLTNode** pplist);//尾删
void SListPopFront(SLTNode** pplist);//头删

SLTNode* SListFind(SLTNode* plist, SLTDataType x);//搜索

void SListInsertAfter(SLTNode* pos, SLTDataType x);//任意插入
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x);
//任意插入pos位置前

void SListEraseAfter(SLTNode* pos);//删除pos后节点
//void SListEraseCur(SLTNode* pos);//删除pos




//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//	struct ListNode* drev;
//};