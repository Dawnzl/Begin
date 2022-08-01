#include"DList.h"

//结构优势


ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;//让头指向指向自己
	phead->prev = phead;//让尾指向指向自己

	return phead;
}

void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//尾插节点
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	//初链表只有一个节点或者多节点都可以实现

	ListNode* tail = phead->prev;//因为循环，所以头节点的前一个是为节点，用tail记录
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;//将原尾节点tail连接新节点
	newnode->prev = tail;//新节点的前驱节点设置为tail
	newnode->next = phead;//新节点的下一节点设置为头节点
	phead->prev = newnode;//头节点的前驱指针指向新节点

	//此方法也是尾插
	/*ListInsert(phead, x);*/ 

}

//头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	//头插注意要先将newnode先连接第一有数据节点（不是头指针）
	//或者设置一个新的指针(frist)先存放第一有数据节点
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);

	//开始连接三个指针
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;

	//此方法也是头插
	/*ListInsert(phead->next, x);*/
}

//尾删
void ListPopBack(ListNode* phead)
{
	//不用遍历即可找到尾项
	assert(phead);
	assert(phead->next != phead);//如果链表只有头节点在此情况也是错误链表

	ListNode* tail = phead->prev;//设置指针指向原尾项
	ListNode* tailPrev = tail->prev;//设置指针指向倒数第二项
	free(tail);//释放最后一项

	tailPrev->next = phead;//倒数第二项晋升为最后一项，用其连接头节点
	phead->prev = tailPrev;//将头节点的前驱指针指向新尾节点

	//此方法也是尾插
	/*ListErase(phead->prev);*/
}

//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//如果链表只有头节点也是错误链表

	ListNode* frist = phead->next;
	ListNode* fristNext = frist->next;
	free(frist);

	fristNext->prev = phead;
	phead->next = fristNext;

	//此方法也是头插
	/*ListErase(phead->next);*/

}

//查找
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}
	return NULL;//没找到返回空
}

//插入前（对于双向链表在pos前后插入节点都很简单）
//就算pos是头节点 或者 是最后一个节点 都很容易实现
//不过pos是头节点用此方法相当于 尾插
//pos是phead->next则相当于 头插
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	prev->next = newnode;//双向
	newnode->prev = prev;

	newnode->next = pos;//双向
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	
	prev->next = next;
	next->prev = prev;

	free(pos);
}

//空返回1，非空返回0
int ListEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead ? 1 : 0;
}

//计算有效值多少个
int ListSize(ListNode* phead) 
{
	assert(phead);

	int size = 0;
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}
	return size;
	
}

//清空列表
void ListDestory(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;//此处没用，需要传递二级指针，但是会破坏一致性
	//最后要置空头指针，需要在.c文件最后plist = NULL;置空
}