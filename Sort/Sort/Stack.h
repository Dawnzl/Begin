#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef int STDataType;
struct Stack
{
	STDataType* a;//����
	int top;//ջ��
	int capacity;//��������������
};

//typedef struct Stack ST;
typedef struct Stack Stack;

void StackInit(Stack* pst);//��ʼ��
void StackDestory(Stack* pst);

//���ʾ�����ջ����������
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

STDataType StackTop(Stack* pst);//����ջ������

//�շ���1���ǿշ���0
bool StackEmpty(Stack* pst);

int StackSize(Stack* pst);