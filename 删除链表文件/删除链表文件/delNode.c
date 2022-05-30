//#include<stdio.h>
//#include<malloc.h>
//
//struct  student  //学生类型
//{
//	int sid;  //学号
//	char name[10]; //姓名
//	char sex;  //性别
//	int  score[3]; //课程成绩
//};
//struct stnode  //结点类型
//{
//	struct  student  data;  //结点数据域
//	struct stnode* next; // 结点指针域
//};
//
//struct stlist  //学生信息表，链表存放
//{
//	struct stnode* sthead;  //链表指针
//	int len;   //链表中实际的元素数量
//};
//
////打开F学生文件
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
//		fscanf(f1, "%d %s %c %d %d %d", &pnew->data.sid, pnew->data.name, &pnew->data.sex, &pnew->data.score[0], &pnew->data.score[1], &pnew->data.score[2]);//将文件输出到程序中
//	}
//	fclose(f1);
//	return n;
//}
//
////录入文件
//void Enterf(struct student stu[], int n)//n是自定义的
//{
//	FILE* f;
//	int i = 0;
//	f = fopen("student.txt", "w+");//覆盖原有
//	fprintf(f, "%d\n", n);//传入n
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
//	printf("输入学号：");
//	scanf("%d", &num);
//	deNode = findNode(phead, num);
//	if (deNode == NULL)
//	{
//		printf("此学号为空");
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
//		printf("删除成功！");
//	}
//}
//
//struct stnode* findNode(struct stnode* phead, int num)
//{
//	struct stnode* pfind = phead;
//	while (pfind != NULL)
//	{
//		if (pfind->data.sid == num)//学号如果与输入相同
//		{
//			return pfind;
//		}
//		pfind = pfind->next;
//	}
//	return NULL;//或者pfind
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

struct  student  //学生类型
{
	int sid;  //学号
	char name[10]; //姓名
	char sex;  //性别
	int  score[3]; //课程成绩
};

struct stnode
{
	struct student data;
	struct stnode* next;
};

void delNode(struct stnode** phead, int n) //删除*phead指向的结点后面第n个节点
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
{ //读入n个数据并存入链表，返回链表的head的地址
	if (n == 0)
	{
		return NULL;
	}
	else
	{
		struct stnode* p = makeNode();//开辟空间
		fscanf(fp, "%s %d", p->data.name, &p->data.score);
		p->next = readData(fp, n - 1);
		return p;
	}
}

void printData(struct stnode* p)
{
	if (p != NULL)
	{
		printf("数据: %s %d\n", p->data.name, p->data.score);
		printData(p->next);
	}
}

void del()
{
	printf("**********学生信息的删除********** \n");
	struct student stu[100];

	FILE* fp = fopen("student.txt", "r");
	int n;
	fscanf(fp, "%d", &n);
	struct stnode* head = readData(fp, n);
	printData(head);
	fclose(fp);


	int n = readfile(stu);
	int sid = 0;//学号
	int f = 1;//判断是否需要重新输入学号
	char in;
	do
	{
		do {
			printf("输入需要删学生的学号：");
			scanf("%d", &sid);
			int i = 0;
			for (i = 0; i < n; i++)
			{
				if (stu[i].sid == sid)
				{
					printf("该学生信息：\n");
					printf("    学 号   姓 名   性别  语文  数学  英语\n");
					printf("    %d    %s     %c    %d    %d    %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
					printf("该学生信息存在，是否选择删除\n1.确定\n2.取消\n");
					f = 0;
					break;
				}

			}
			if (f)
			{
				printf("该学生信息不存在，请重新输入\n");
			}


		} while (f);//f未改变重新输入学号
		int d;
		printf("请选择：");
		scanf("%d", &d);
		if (d == 1)
		{
			dele(sid, stu, &n);
			//textprint(us, n);//测试输出
			Enterf(stu, n);
			printf("删除成功\n");
		}
		else if (d == 2) printf("取消成功\n");

		printf("按回车键继续删除，按任意键返回主界面\n");

		getchar();
		in = getchar();
		if (in != '\n') break;

	} while (in != '1' && in == '\n');
}

int main()
{

	return 0;
}
