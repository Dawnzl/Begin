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

//���������ݷ���ڵ��return �����ĵ�ַ����Ҫһ��ָ�����
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;

	return node;
}

void SListPushBack(SLTNode** pplist, SLTDataType x)//β��
{
	//�����ڵ�洢
	SLTNode* newnode = BuySLTNode(x);

	//1���յ����
	//2���ǿ����
	if (*pplist == NULL)
	{
		*pplist = newnode;//�޸ĵ��ǵ�ַ���Һ�����return�������ö���ָ��
	}
	else
	{
		//��β
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;//�ýڵ�β��ȥ�����½ڵ�
	}
	
}

//�պͷǿն�����
void SListPushFront(SLTNode** pplist, SLTDataType x)//ͷ��
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist; //�Ƚ�new��nextָ��pplistԭ��ָ��Ľڵ�
	*pplist = newnode;       //�ٽ�new�ڵ�ĵ�ַ����Ϊpplist
}

//βɾ
void SListPopBack(SLTNode** pplist)
{
	//1��û�нڵ�
	//2��һ���ڵ�
	//3������ڵ�
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
		SLTNode* prev = NULL;//ǰ��ָ��
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;       //ǰ������
			tail = tail->next; //tailҲ����
		}
		free(tail);//��tail�ÿ�,��ʱplist�����һ���ڵ�Ҳ���ÿ�
		tail = NULL;//��ֹҰָ��

		prev->next = NULL;//��βָ���ÿ�
	}
	
}

//ͷɾ
void SListPopFront(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = (*pplist)->next;//�ƶ�һ��next����׽ڵ��Ľڵ�
		free(*pplist);

		*pplist = next;
	}
}

//����,���ؽڵ�x��ָ��
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


void SListInsertAfter(SLTNode* pos, SLTDataType x)//�������
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;//�Ƚ��·�װ�Ľڵ����ӵ�d3
	pos->next = newnode;//�ٽ�d2��next���ӵ��½ڵ�
}


//�������posλ��ǰ
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
	//ֻҪ�漰���ı��һ���ڵ㣬Ҳ����Ҫ�޸Ĵ����ָ�����
	//��ô��Ҫ�ö���ָ��
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);

	if (pos == *pplist)//����ͷ��
	{
		newnode->next = pos;
		*pplist = newnode;//���½ڵ�ָ��Ϊ��һ���ڵ㣬�ö���ָ�봫ֵ
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


void SListEraseAfter(SLTNode* pos)//ɾ���ڵ�
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = pos->next;//��next���d3
		pos->next = next->next;//�ٽ�pos���ӵ�d3�ĺ�һ�ڵ�
		free(next);//�ͷ�d3
	}
}

