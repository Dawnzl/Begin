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

void delNode(struct stnode** phead, int n) //ɾ��*pheadָ����ض�����
{
	struct stnode* head = *phead;
	if (head != NULL)
		if (n != head->data.sid)
			delNode(&head->next, n);
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
		fscanf(fp, "%d %s %c %d %d %d", &p->data.sid, p->data.name, &p->data.sex, &p->data.score[0], &p->data.score[1], &p->data.score[2]);
		p->next = readData(fp, n - 1);
		return p;
	}
}

void printData(struct stnode* p)
{
	if (p != NULL)
	{
		printf("%d %s %c %d %d %d\n", p->data.sid, p->data.name, p->data.sex, p->data.score[0], p->data.score[1], p->data.score[2]);
		printData(p->next);
	}
}

void FprintData(FILE* fp, struct stnode* p)
{
	if (p != NULL)
	{
		fprintf(fp, "%d %s %c %d %d %d\n", p->data.sid, p->data.name, p->data.sex, p->data.score[0], p->data.score[1], p->data.score[2]);
		FprintData(fp, p->next);
	}
}

void dele(struct stnode* p, int* n)
{
	FILE* fp = fopen("student.txt", "w+");//���ļ����fpָ��
	*n = *n - 1;
	fprintf(fp, "%d\n", *n);
	FprintData(fp, p);
	fclose(fp);
}

void del()
{
	printf("**********ѧ����Ϣ��ɾ��********** \n");
	struct student stu[100];

	FILE* fp = fopen("student.txt", "r");//���ļ����fpָ��
	int n;
	fscanf(fp, "%d", &n);//���ļ��еĸ�����ȡ
	struct stnode* head = readData(fp, n);//����һ��ͷָ����������������ļ�����������
	printData(head);
	fclose(fp);


	int sid = 0;//ѧ��
	int f = 1;//�ж��Ƿ���Ҫ��������ѧ��
	char in;

	scanf("%d", &sid);

	delNode(&head, sid); //ɾ��*pheadָ����ض�����

	dele(head, &n);

	printData(head);

	

	//do
	//{
	//	do {
	//		printf("������Ҫɾѧ����ѧ�ţ�");
	//		scanf("%d", &sid);
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			if (stu[i].sid == sid)
	//			{
	//				printf("��ѧ����Ϣ��\n");
	//				printf("    ѧ ��   �� ��   �Ա�  ����  ��ѧ  Ӣ��\n");
	//				printf("    %d    %s     %c    %d    %d    %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	//				printf("��ѧ����Ϣ���ڣ��Ƿ�ѡ��ɾ��\n1.ȷ��\n2.ȡ��\n");
	//				f = 0;
	//				break;
	//			}

	//		}
	//		if (f)
	//		{
	//			printf("��ѧ����Ϣ�����ڣ�����������\n");
	//		}


	//	} while (f);//fδ�ı���������ѧ��
	//	int d;
	//	printf("��ѡ��");
	//	scanf("%d", &d);
	//	if (d == 1)
	//	{
	//		dele(sid, stu, &n);
	//		//textprint(us, n);//�������
	//		Enterf(stu, n);
	//		printf("ɾ���ɹ�\n");
	//	}
	//	else if (d == 2) printf("ȡ���ɹ�\n");

	//	printf("���س�������ɾ���������������������\n");

	//	getchar();
	//	in = getchar();
	//	if (in != '\n') break;

	//} while (in != '1' && in == '\n');
}

int main()
{
	del();
	return 0;
}
