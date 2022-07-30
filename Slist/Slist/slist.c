#pragma once
#include"slist.h"

void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}

//将所需数据放入节点里，return 创建的地址，需要一个指针接收
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;

	return node;
}

void SListPushBack(SLTNode** pplist, SLTDataType x)//尾插
{
	//创建节点存储
	SLTNode* newnode = BuySLTNode(x);

	//1、空的情况
	//2、非空情况
	if (*pplist == NULL)
	{
		*pplist = newnode;//修改的是地址，且函数无return，所以用二级指针
	}
	else
	{
		//找尾
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;//用节点尾巴去接上新节点
	}
	
}

//空和非空都可以
void SListPushFront(SLTNode** pplist, SLTDataType x)//头插
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist; //先将new的next指向pplist原本指向的节点
	*pplist = newnode;       //再将new节点的地址设置为pplist
}

//尾删
void SListPopBack(SLTNode** pplist)
{
	//1、没有节点
	//2、一个节点
	//3、多个节点
	if (*pplist == NULL)
	{
		return;
	}
	else if((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SLTNode* prev = NULL;//前驱指针
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;       //前驱后移
			tail = tail->next; //tail也后移
		}
		free(tail);//将tail置空,此时plist的最后一个节点也被置空
		tail = NULL;//防止野指针

		prev->next = NULL;//将尾指针置空
	}
	
}

//头删
void SListPopFront(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = (*pplist)->next;//制定一个next存放首节点后的节点
		free(*pplist);

		*pplist = next;
	}
}

//查找,返回节点x的指针
SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}


void SListInsertAfter(SLTNode* pos, SLTDataType x)//任意插入
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;//先将新封装的节点连接到d3
	pos->next = newnode;//再讲d2的next连接到新节点
}


//任意插入pos位置前
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
	//只要涉及到改变第一个节点，也就是要修改传入的指针变量
	//那么就要用二级指针
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);

	if (pos == *pplist)//就是头插
	{
		newnode->next = pos;
		*pplist = newnode;//将新节点指定为第一个节点，用二级指针传值
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}

}


void SListEraseAfter(SLTNode* pos)//删除节点
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = pos->next;//用next存放d3
		pos->next = next->next;//再将pos连接到d3的后一节点
		free(next);//释放d3
	}
}

