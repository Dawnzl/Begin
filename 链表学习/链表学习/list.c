#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>

typedef struct _list
{
	Node* head;//存储head头指针
}List;

typedef struct _node
{
	int date;
	struct _node *next;
} Node;

void add(List* pList, int num);
void print(List* pList);

int main()
{
	List list;
	int num;
	list.head = NULL;//初始化头指针的指向
	do
	{
		scanf("%d", &num);
		if (num != -1)
		{
			add(&list, num); //存储head头指针的地址
		}

	} while (num != -1);
	print(&list);
	return 0;
}

//增加单个链表数据
void add(List* pList, int num)//head头指针的地址
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->date = num;
	p->next = NULL;
	Node* last = pList->head;
	if (last != NULL)
	{
		while (last->next != NULL)
		{
			last = last->next;//符合的话，last就指向last next的那个结构体
		}
		last->next = p;
	}
	else
	{
		pList->head = p;
	}
	
}

void print(List* pList)
{
	Node* p;
	for (p = pList->head; p; p = p->next)
	{
		printf("%d\t", p->date);
	}
	printf("\n");
}