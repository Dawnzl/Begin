#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user
{
	char name[20];//�û���
	char password[7];//����6λ������λ'\0'������ַ���
};

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

void menu();
void Loginp(struct user us[]);//��¼ҳ��
void Susslogged();//��¼�ɹ�ҳ��

void make();//����ѧ����Ϣ
void add();//����ѧ����Ϣ
void look();//���ѧ����Ϣ
void revise();//�޸�ѧ����Ϣ
void fine();//����ѧ����Ϣ
void del();//ɾ��ѧ����Ϣ	
void analyse();//����γ����Ʒ����ɼ�
void sort();//����(ѧ�š��������ɼ���)


int verifyname(char name[], struct user ux[], char psw[]);//��֤�û���






void inpsw(char psw[]);//�����������
int isnum(char st[]);//�ж��Ƿ�������
int isalph(char st[]);//�ж��Ƿ�����ĸ
int ispsw(char st[]);//�ж��Ƿ��г������֣���ĸ������ַ�