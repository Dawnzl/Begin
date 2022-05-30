//#include<stdio.h>
//#include<malloc.h>
//
//struct  student  //ѧ������
//{
//	int sid;  //ѧ��
//	char name[10]; //����
//	char sex;  //�Ա�
//	int  score[3]; //�γ̳ɼ�
//};
//struct stnode  //�������
//{
//	struct  student  data;  //���������
//	struct stnode* next; // ���ָ����
//};
//
//struct stlist  //ѧ����Ϣ��������
//{
//	struct stnode* sthead;  //����ָ��
//	int len;   //������ʵ�ʵ�Ԫ������
//};
//
////��Fѧ���ļ�
//int inFstudent(struct stnode* phead)
//{
//	FILE* f1;
//	int i, n;
//	struct stnode* pnew = NULL;
//	struct stnode* pfind = phead;
//	while (pfind->next != NULL)
//	{
//		pfind = pfind->next;
//	}
//
//
//
//	f1 = fopen("Fstudent.txt", "r");
//	fscanf(f1, "%d", &n);
//	for (i = 0; i < n; i++) {
//		pnew = (struct stnode*)malloc(sizeof(struct stnode));
//		fscanf(f1, "%d %s %c %d %d %d", &pnew->data.sid, pnew->data.name, &pnew->data.sex, &pnew->data.score[0], &pnew->data.score[1], &pnew->data.score[2]);//���ļ������������
//	}
//	fclose(f1);
//	return n;
//}
//
////¼���ļ�
//void Enterf(struct student stu[], int n)//n���Զ����
//{
//	FILE* f;
//	int i = 0;
//	f = fopen("student.txt", "w+");//����ԭ��
//	fprintf(f, "%d\n", n);//����n
//	for (i = 0; i < n; i++)
//	{
//		fprintf(f, "%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
//	}
//	fclose(f);
//}
//

//

//
//void deleNode(struct stnode* phead)
//{
//	int num = 0;
//	struct stnode* deNode = NULL;
//	struct stnode* pfind = phead;
//	struct stnode* ptemp = NULL;
//	printf("����ѧ�ţ�");
//	scanf("%d", &num);
//	deNode = findNode(phead, num);
//	if (deNode == NULL)
//	{
//		printf("��ѧ��Ϊ��");
//		return 0;
//	}
//	else
//	{
//		ptemp = deNode->next;
//		while(pfind->next != delNode)
//		{
//			pfind = pfind->next;
//		}
//		free(deleNode);
//		deleNode = NULL;
//		pfind->next = ptemp;
//		printf("ɾ���ɹ���");
//	}
//}
//
//struct stnode* findNode(struct stnode* phead, int num)
//{
//	struct stnode* pfind = phead;
//	while (pfind != NULL)
//	{
//		if (pfind->data.sid == num)//ѧ�������������ͬ
//		{
//			return pfind;
//		}
//		pfind = pfind->next;
//	}
//	return NULL;//����pfind
//}
//
//
//int main()
//{
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct  student  //ѧ������
{
	int sid;  //ѧ��
	char name[10]; //����
	char sex;  //�Ա�
	int  score[3]; //�γ̳ɼ�
};

struct stnode
{
	struct student data;
	struct stnode* next;
};

void delNode(struct stnode** phead, int n) //ɾ��*pheadָ��Ľ������n���ڵ�
{
	struct stnode* head = *phead;
	if (head != NULL)
		if (n != head->data.sid)
			delNode(&head->next, n - 1);
		else
		{
			*phead = head->next;
			free(head);
			head = NULL;
		}
}

struct stnode* makeNode()
{
	struct stnode* p = (struct stnode*)malloc(sizeof(struct stnode));
	p->next = NULL;
	return p;
}

struct stnode* readData(FILE* fp, int n)
{ //����n�����ݲ������������������head�ĵ�ַ
	if (n == 0)
	{
		return NULL;
	}
	else
	{
		struct stnode* p = makeNode();//���ٿռ�
		fscanf(fp, "%s %d", p->data.name, &p->data.score);
		p->next = readData(fp, n - 1);
		return p;
	}
}

void printData(struct stnode* p)
{
	if (p != NULL)
	{
		printf("����: %s %d\n", p->data.name, p->data.score);
		printData(p->next);
	}
}

void del()
{
	printf("**********ѧ����Ϣ��ɾ��********** \n");
	struct student stu[100];

	FILE* fp = fopen("student.txt", "r");
	int n;
	fscanf(fp, "%d", &n);
	struct stnode* head = readData(fp, n);
	printData(head);
	fclose(fp);


	int n = readfile(stu);
	int sid = 0;//ѧ��
	int f = 1;//�ж��Ƿ���Ҫ��������ѧ��
	char in;
	do
	{
		do {
			printf("������Ҫɾѧ����ѧ�ţ�");
			scanf("%d", &sid);
			int i = 0;
			for (i = 0; i < n; i++)
			{
				if (stu[i].sid == sid)
				{
					printf("��ѧ����Ϣ��\n");
					printf("    ѧ ��   �� ��   �Ա�  ����  ��ѧ  Ӣ��\n");
					printf("    %d    %s     %c    %d    %d    %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
					printf("��ѧ����Ϣ���ڣ��Ƿ�ѡ��ɾ��\n1.ȷ��\n2.ȡ��\n");
					f = 0;
					break;
				}

			}
			if (f)
			{
				printf("��ѧ����Ϣ�����ڣ�����������\n");
			}


		} while (f);//fδ�ı���������ѧ��
		int d;
		printf("��ѡ��");
		scanf("%d", &d);
		if (d == 1)
		{
			dele(sid, stu, &n);
			//textprint(us, n);//�������
			Enterf(stu, n);
			printf("ɾ���ɹ�\n");
		}
		else if (d == 2) printf("ȡ���ɹ�\n");

		printf("���س�������ɾ���������������������\n");

		getchar();
		in = getchar();
		if (in != '\n') break;

	} while (in != '1' && in == '\n');
}

int main()
{

	return 0;
}
