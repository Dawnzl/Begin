#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>

typedef struct _list
{
	Node* head;//�洢headͷָ��
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
	list.head = NULL;//��ʼ��ͷָ���ָ��
	do
	{
		scanf("%d", &num);
		if (num != -1)
		{
			add(&list, num); //�洢headͷָ��ĵ�ַ
		}

	} while (num != -1);
	print(&list);
	return 0;
}

//���ӵ�����������
void add(List* pList, int num)//headͷָ��ĵ�ַ
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->date = num;
	p->next = NULL;
	Node* last = pList->head;
	if (last != NULL)
	{
		while (last->next != NULL)
		{
			last = last->next;//���ϵĻ���last��ָ��last next���Ǹ��ṹ��
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