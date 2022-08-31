#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef int STDataType;
struct Stack
{
	STDataType* a;//数组
	int top;//栈顶
	int capacity;//容量，方便增容
};

//typedef struct Stack ST;
typedef struct Stack Stack;

void StackInit(Stack* pst);//初始化
void StackDestory(Stack* pst);

//性质决定在栈顶出入数据
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

STDataType StackTop(Stack* pst);//导出栈顶数据

//空返回1，非空返回0
bool StackEmpty(Stack* pst);

int StackSize(Stack* pst);