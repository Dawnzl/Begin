#include<stdio.h>
#include"Stack.h"

//初始化
void StackInit(Stack* pst)
{
	assert(pst);
	//pst->a = NULL;
	//pst->top = 0;
	//pst->capacity = 0;

	pst->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	pst->top = 0;
	pst->capacity = 4;
}

void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;

}

//性质决定在栈顶出入数据
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//异常结束程序（0是正常结束）
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}

	pst->a[pst->top] = x;
	pst->top++;
}


void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->top--;
}

STDataType StackTop(Stack* pst)//导出栈顶数据
{
	assert(pst);
	assert(!StackEmpty(pst));
	
	return pst->a[pst->top - 1];
}
//空返回1，非空返回0
bool StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}

int StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}
