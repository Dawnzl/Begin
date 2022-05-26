#pragma once
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct user
{
	char name[20];//用户名
	char password[7];//密码6位，第七位'\0'，组成字符串
};

struct  student  //学生类型
{
	int sid;  //学号
	char name[10]; //姓名
	char sex;  //性别
	int  score[3]; //课程成绩
};
struct stnode  //结点类型
{
	struct  student  data;  //结点数据域
	struct stnode* next; // 结点指针域
};
struct sttable  //学生信息表，数组存放
{
	struct  student  s[100];  //数据数组
	int  len;   //数组中实际的元素数量
};
struct stlist  //学生信息表，链表存放
{
	struct stnode* sthead;  //链表指针
	int len;   //链表中实际的元素数量
};

void WriteDate(FILE* date, char name[]);//日志时间的写入

void menu();
void Loginp(struct user us[], char name[]);//登录页面
void Susslogged();//登录成功页面
void MakeMenu();//创建页面
void FineMenu();//查找页面
void SortMenu();//排序界面

void make();//创建学生信息
void add();//增加学生信息
void look();//浏览学生信息
void revise();//修改学生信息
void fine();//查找学生信息
void del();//删除学生信息	
void analyse();//输入课程名称分析成绩
void sort();//排序(学号、姓名、成绩等)
void Out(char name[]);//结束保存日志
void Enterf(struct student stu[], int n);//录入文件
void addstd(struct student stu[], int num);//将注册的用户名和密码输入到文件中
void addread(struct student stu[], int* num);//将文件中学生信息输出到程序中//添加版

void revisestu(struct student stu[], int n);//修改学生信息函数
void finestunum(struct student stu[], int n);//按学号查找学生信息
void finestuname(struct student stu[], int n);//按姓名查找学生信息

int verifyname(char name[], struct user ux[], char psw[]);//验证用户名






void inpsw(char psw[]);//密码输入防窥
int isnum(char st[]);//判断是否有数字
int isalph(char st[]);//判断是否有字母
int ispsw(char st[]);//判断是否有除了数字，字母以外的字符
//凯撒加密
void Convert(char s[]);
//凯撒解密
void JConvert(char s[]);