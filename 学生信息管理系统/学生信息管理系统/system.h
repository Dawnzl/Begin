#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
