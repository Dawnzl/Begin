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
	int capacity;//用于扩容
};

typedef struct Heap HP;

void Swap(int* p1, int* p2);
void AdjustDown(int* a, int n, int parent);
//沿着插入节点到根的路径 向上调整
void AdjustUp(int* a, int child);


// HP* HeapInit(HPDataType* a, int n);//初始化
void HeapInit(HP* php, HPDataType* a, int n);//初始化
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);//删除堆顶数据
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);
void HeapPrint(HP* php);