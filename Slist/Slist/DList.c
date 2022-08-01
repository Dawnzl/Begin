#include"DList.h"

//�ṹ����


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
	phead->next = phead;//��ͷָ��ָ���Լ�
	phead->prev = phead;//��βָ��ָ���Լ�

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

//β��ڵ�
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	//������ֻ��һ���ڵ���߶�ڵ㶼����ʵ��

	ListNode* tail = phead->prev;//��Ϊѭ��������ͷ�ڵ��ǰһ����Ϊ�ڵ㣬��tail��¼
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;//��ԭβ�ڵ�tail�����½ڵ�
	newnode->prev = tail;//�½ڵ��ǰ���ڵ�����Ϊtail
	newnode->next = phead;//�½ڵ����һ�ڵ�����Ϊͷ�ڵ�
	phead->prev = newnode;//ͷ�ڵ��ǰ��ָ��ָ���½ڵ�

	//�˷���Ҳ��β��
	/*ListInsert(phead, x);*/ 

}

//ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	//ͷ��ע��Ҫ�Ƚ�newnode�����ӵ�һ�����ݽڵ㣨����ͷָ�룩
	//��������һ���µ�ָ��(frist)�ȴ�ŵ�һ�����ݽڵ�
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);

	//��ʼ��������ָ��
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;

	//�˷���Ҳ��ͷ��
	/*ListInsert(phead->next, x);*/
}

//βɾ
void ListPopBack(ListNode* phead)
{
	//���ñ��������ҵ�β��
	assert(phead);
	assert(phead->next != phead);//�������ֻ��ͷ�ڵ��ڴ����Ҳ�Ǵ�������

	ListNode* tail = phead->prev;//����ָ��ָ��ԭβ��
	ListNode* tailPrev = tail->prev;//����ָ��ָ�����ڶ���
	free(tail);//�ͷ����һ��

	tailPrev->next = phead;//�����ڶ������Ϊ���һ���������ͷ�ڵ�
	phead->prev = tailPrev;//��ͷ�ڵ��ǰ��ָ��ָ����β�ڵ�

	//�˷���Ҳ��β��
	/*ListErase(phead->prev);*/
}

//ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//�������ֻ��ͷ�ڵ�Ҳ�Ǵ�������

	ListNode* frist = phead->next;
	ListNode* fristNext = frist->next;
	free(frist);

	fristNext->prev = phead;
	phead->next = fristNext;

	//�˷���Ҳ��ͷ��
	/*ListErase(phead->next);*/

}

//����
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
	return NULL;//û�ҵ����ؿ�
}

//����ǰ������˫��������posǰ�����ڵ㶼�ܼ򵥣�
//����pos��ͷ�ڵ� ���� �����һ���ڵ� ��������ʵ��
//����pos��ͷ�ڵ��ô˷����൱�� β��
//pos��phead->next���൱�� ͷ��
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	prev->next = newnode;//˫��
	newnode->prev = prev;

	newnode->next = pos;//˫��
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

//�շ���1���ǿշ���0
int ListEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead ? 1 : 0;
}

//������Чֵ���ٸ�
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

//����б�
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
	phead = NULL;//�˴�û�ã���Ҫ���ݶ���ָ�룬���ǻ��ƻ�һ����
	//���Ҫ�ÿ�ͷָ�룬��Ҫ��.c�ļ����plist = NULL;�ÿ�
}