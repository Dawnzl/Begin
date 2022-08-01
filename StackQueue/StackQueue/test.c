#include<stdio.h>
#include"Stack.h"

void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);//从栈顶输出一个就删除一个
	}


	StackDestory(&st);
}



int main()
{
	TestStack();
	return 0;
}