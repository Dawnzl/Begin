#pragma once
#include<stdio.h>
#include<stdbool.h>;
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int HPDataType;
struct Heap
{
	HPDataType* a;
	int size;
	int capacity;//��������
};

typedef struct Heap HP;

void Swap(int* p1, int* p2);
void AdjustDown(int* a, int n, int parent);
//���Ų���ڵ㵽����·�� ���ϵ���
void AdjustUp(int* a, int child);


// HP* HeapInit(HPDataType* a, int n);//��ʼ��
void HeapInit(HP* php, HPDataType* a, int n);//��ʼ��
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);//ɾ���Ѷ�����
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);
void HeapPrint(HP* php);