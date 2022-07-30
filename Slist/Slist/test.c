#include<stdio.h>
#include"slist.h"

void TesSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);


}

void TesSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SLTNode* pos = SListFind(plist, 3);

	if (pos)
	{
		//����޸�����
		//pos->data = 30;
		printf("�ҵ���");
	}
	else
	{
		printf("δ�ҵ�");
	}
	SListPrint(plist);
}

void TesSList3()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	SListInsertAfter(pos, 30);
	SListInsertBefore(&plist, pos, 300);
	SListPrint(plist);
}


int main()
{
	TesSList3();

}