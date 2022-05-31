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

void delNode(struct stnode** phead, int n) //删除*phead指向的特定数据
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
{ //读入n个数据并存入链表，返回链表的head的地址
	if (n == 0)
	{
		return NULL;
	}
	else
	{
		struct stnode* p = makeNode();//开辟空间
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
	FILE* fp = fopen("student.txt", "w+");//打开文件获得fp指针
	*n = *n - 1;
	fprintf(fp, "%d\n", *n);
	FprintData(fp, p);
	fclose(fp);
}

void del()
{
	printf("**********学生信息的删除********** \n");
	struct student stu[100];

	FILE* fp = fopen("student.txt", "r");//打开文件获得fp指针
	int n;
	fscanf(fp, "%d", &n);//将文件中的个数读取
	struct stnode* head = readData(fp, n);//设置一个头指针链接链表，链表从文件中输入数据
	printData(head);
	fclose(fp);


	int sid = 0;//学号
	int f = 1;//判断是否需要重新输入学号
	char in;

	scanf("%d", &sid);

	delNode(&head, sid); //删除*phead指向的特定数据

	dele(head, &n);

	printData(head);

	

	//do
	//{
	//	do {
	//		printf("输入需要删学生的学号：");
	//		scanf("%d", &sid);
	//		int i = 0;
	//		for (i = 0; i < n; i++)
	//		{
	//			if (stu[i].sid == sid)
	//			{
	//				printf("该学生信息：\n");
	//				printf("    学 号   姓 名   性别  语文  数学  英语\n");
	//				printf("    %d    %s     %c    %d    %d    %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	//				printf("该学生信息存在，是否选择删除\n1.确定\n2.取消\n");
	//				f = 0;
	//				break;
	//			}

	//		}
	//		if (f)
	//		{
	//			printf("该学生信息不存在，请重新输入\n");
	//		}


	//	} while (f);//f未改变重新输入学号
	//	int d;
	//	printf("请选择：");
	//	scanf("%d", &d);
	//	if (d == 1)
	//	{
	//		dele(sid, stu, &n);
	//		//textprint(us, n);//测试输出
	//		Enterf(stu, n);
	//		printf("删除成功\n");
	//	}
	//	else if (d == 2) printf("取消成功\n");

	//	printf("按回车键继续删除，按任意键返回主界面\n");

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
