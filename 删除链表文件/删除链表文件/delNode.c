//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//struct  student  //学生类型
//{
//	int sid;  //学号
//	char name[10]; //姓名
//	char sex;  //性别
//	int  score[3]; //课程成绩
//};
//
//struct stnode
//{
//	struct student data;
//	struct stnode* next;
//};
//
//void delNode(struct stnode** phead, int n) //删除*phead指向的特定数据
//{
//	struct stnode* head = *phead;
//	if (head != NULL)
//	{
//		if (n != head->data.sid)
//		{
//			delNode(&head->next, n);
//			
//		}
//			
//		else
//		{
//			printf("该学生信息：\n");
//			printf("    学 号   姓 名   性别  语文  数学  英语\n");
//			printf("    %d    %s     %c    %d    %d    %d\n", head->data.sid, head->data.name, head->data.sex, head->data.score[0], head->data.score[1], head->data.score[2]);
//			printf("该学生信息存在，是否选择删除\n1.确定\n2.取消\n");
//			int d;
//			printf("请选择：");
//			scanf("%d", &d);
//			if (d == 1)
//			{
//				*phead = head->next;
//				free(head);
//				head = NULL;
//				printf("删除成功\n");
//			}
//			else if (d == 2) printf("取消成功\n");
//
//
//		}
//	}
//	else printf("该学生信息不存在，请重新输入\n");
//}
//
//struct stnode* makeNode()
//{
//	struct stnode* p = (struct stnode*)malloc(sizeof(struct stnode));
//	p->next = NULL;
//	return p;
//}
//
//struct stnode* readData(FILE* fp, int n)
//{ //读入n个数据并存入链表，返回链表的head的地址
//	if (n == 0)
//	{
//		return NULL;
//	}
//	else
//	{
//		struct stnode* p = makeNode();//开辟空间
//		fscanf(fp, "%d %s %c %d %d %d", &p->data.sid, p->data.name, &p->data.sex, &p->data.score[0], &p->data.score[1], &p->data.score[2]);
//		p->next = readData(fp, n - 1);
//		return p;
//	}
//}
//
//void printData(struct stnode* p)
//{
//	if (p != NULL)
//	{
//		printf("%d %s %c %d %d %d\n", p->data.sid, p->data.name, p->data.sex, p->data.score[0], p->data.score[1], p->data.score[2]);
//		printData(p->next);
//	}
//}
//
//void FprintData(FILE* fp, struct stnode* p)
//{
//	if (p != NULL)
//	{
//		fprintf(fp, "%d %s %c %d %d %d\n", p->data.sid, p->data.name, p->data.sex, p->data.score[0], p->data.score[1], p->data.score[2]);
//		FprintData(fp, p->next);
//	}
//}
//
//void Dele(struct stnode* p, int* n)
//{
//	FILE* fp = fopen("student.txt", "w+");//打开文件获得fp指针
//	*n = *n - 1;
//	fprintf(fp, "%d\n", *n);
//	FprintData(fp, p);
//	fclose(fp);
//}
//
//void del()
//{
//	printf("**********学生信息的删除********** \n");
//	struct student stu[100];
//
//	FILE* fp = fopen("student.txt", "r");//打开文件获得fp指针
//	int n;
//	fscanf(fp, "%d", &n);//将文件中的个数读取
//	struct stnode* head = readData(fp, n);//设置一个头指针链接链表，链表从文件中输入数据
//	printData(head);
//	fclose(fp);
//
//
//	int sid = 0;//学号
//	int f = 1;//判断是否需要重新输入学号
//	char in;
//
//	
//
//	
//
//	do
//    {
//		printf("输入需要删学生的学号：");
//		scanf("%d", &sid);
//
//		delNode(&head, sid); //删除*phead指向的特定数据
//
//		Dele(head, &n);
//
//		printData(head);
//		printf("按回车键继续删除，按任意键返回主界面\n");
//
//		getchar();
//		in = getchar();
//		if (in != '\n') break;
//
//	} while (in != '1' && in == '\n');
//}
//
//int main()
//{
//	del();
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct student //学生类型
{
	int sid;	   //学号
	char name[10]; //姓名
	char sex;	   //性别
	int score[3];  //课程成绩
};

struct stnode
{
	struct student data;
	struct stnode* next;
};

char TABLE_HEAD[] = "    学 号   姓 名   性别  语文  数学  英语\n";
char TABLE_BODY[] = "    %d    %s     %c    %d    %d    %d\n";

char myGetc() //获取一个不为换行的字符
{
	char c;
	while ((c = getchar()) == '\n')
		printf("%d", (int)c);
	return c;
}

void printStdent(struct student s)
{
	printf(TABLE_BODY, s.sid, s.name, s.sex, s.score[0], s.score[1], s.score[2]);
}

void fprintStudent(FILE* fp, struct student s)
{
	fprintf(fp, "%d %s %c %d %d %d\n", s.sid, s.name, s.sex, s.score[0], s.score[1], s.score[2]);
}

void printList(struct stnode* p)
{
	if (p != NULL)
	{
		printStdent(p->data);
		printList(p->next);
	}
}

void fprintList(FILE* fp, struct stnode* p)
{
	if (p != NULL)
	{
		fprintStudent(fp, p->data);
		fprintList(fp, p->next);
	}
}

struct stnode** selectNodeBySid(struct stnode** phead, int sid) //查找学生学号为sid的节点
{
	struct stnode* head = *phead;
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		if (sid == head->data.sid)
		{
			return phead;
		}
		else
		{
			return selectNodeBySid(&head->next, sid);
		}
	}
}

void deleteNode(struct stnode** pp) //删除*pp指向的节点
{
	struct stnode* head = *pp;
	*pp = head->next;
	free(head);
}

struct stnode* makeListByFile(FILE* fp, int n) //从文件读入n个数据并存入链表，返回链表头节点的地址
{
	if (n == 0)
	{
		return NULL;
	}
	else
	{
		struct stnode* p = (struct stnode*)malloc(sizeof(struct stnode)); //开辟空间
		fscanf(fp, "%d %s %c %d %d %d", &p->data.sid, p->data.name, &p->data.sex, &p->data.score[0], &p->data.score[1], &p->data.score[2]);
		p->next = makeListByFile(fp, n - 1);
		return p;
	}
}

void saveData(struct stnode* p, int* n)
{
	FILE* fp = fopen("student.txt", "w+"); //打开文件获得fp指针
	fprintf(fp, "%d\n", *n);
	fprintList(fp, p);
	fclose(fp);
}

void deleteMenu()
{
	printf("**********学生信息的删除********** \n");
	struct student stu[100];

	FILE* fp = fopen("student.txt", "r"); //打开文件获得fp指针
	int n;
	fscanf(fp, "%d", &n);						 //将文件中的个数读取
	struct stnode* head = makeListByFile(fp, n); //设置一个头指针链接链表，链表从文件中输入数据
	printf(TABLE_HEAD);
	printList(head);
	fclose(fp);

	do
	{
		struct stnode** pp = NULL;
		while (pp == NULL)//如果搜索不到重新输入
		{
			printf("输入需要删学生的学号：");
			int sid;
			scanf("%d", &sid);
			pp = selectNodeBySid(&head, sid);
			if (pp == NULL)
			{
				printf("该学生信息不存在，请重新输入\n");
			}
		}

		printf("该学生信息：\n");
		printf(TABLE_HEAD);
		printStdent((*pp)->data);

		printf("请选择是否选择删除\n1.确定\n2.取消\n");
		if (myGetc() == '1')
		{
			n--;
			deleteNode(pp);
			printList(head);
			saveData(head, &n);
		}
		else
		{
			printf("已取消\n");
		}

		printf("按回车键继续删除，按任意键返回主界面\n");
		getchar();
	} while (getchar() == '\n');
}

int main()
{
	deleteMenu();
	return 0;
}
