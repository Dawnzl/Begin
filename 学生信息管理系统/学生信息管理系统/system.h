#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct  student  //ѧ������
{
	int sid;  //ѧ��
	char name[10]; //����
	char sex;  //�Ա�
	int  score[3]; //�γ̳ɼ�
};
struct stnode  //�������
{
	struct  student  data;  //���������
	struct stnode* next; // ���ָ����
};
struct sttable  //ѧ����Ϣ��������
{
	struct  student  s[100];  //��������
	int  len;   //������ʵ�ʵ�Ԫ������
};
struct stlist  //ѧ����Ϣ��������
{
	struct stnode* sthead;  //����ָ��
	int len;   //������ʵ�ʵ�Ԫ������
};
