#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;//��������޸���������
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//����+ ����ͷ+ ��ѭ��
void SListPrint(SLTNode* plist);

void SListPushBack(SLTNode** pplist, SLTDataType x);//β��
void SListPushFront(SLTNode** plist, SLTDataType x);//ͷ��

void SListPopBack(SLTNode** pplist);//βɾ
void SListPopFront(SLTNode** pplist);//ͷɾ

SLTNode* SListFind(SLTNode* plist, SLTDataType x);//����

void SListInsertAfter(SLTNode* pos, SLTDataType x);//�������
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x);
//�������posλ��ǰ

void SListEraseAfter(SLTNode* pos);//ɾ��pos��ڵ�
//void SListEraseCur(SLTNode* pos);//ɾ��pos




//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//	struct ListNode* drev;
//};