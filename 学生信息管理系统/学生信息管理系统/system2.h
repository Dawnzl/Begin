#pragma once
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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

void WriteDate(FILE* date, char name[]);//��־ʱ���д��

void menu();
void Loginp(struct user us[], char name[]);//��¼ҳ��
void Susslogged();//��¼�ɹ�ҳ��
void MakeMenu();//����ҳ��
void FineMenu();//����ҳ��
void SortMenu();//�������

void make();//����ѧ����Ϣ
void add();//����ѧ����Ϣ
void look();//���ѧ����Ϣ
void revise();//�޸�ѧ����Ϣ
void fine();//����ѧ����Ϣ
void del();//ɾ��ѧ����Ϣ	
void analyse();//����γ����Ʒ����ɼ�
void sort();//����(ѧ�š��������ɼ���)
void Out(char name[]);//����������־
void Enterf(struct student stu[], int n);//¼���ļ�
void addstd(struct student stu[], int num);//��ע����û������������뵽�ļ���
void addread(struct student stu[], int* num);//���ļ���ѧ����Ϣ�����������//��Ӱ�

void revisestu(struct student stu[], int n);//�޸�ѧ����Ϣ����
void finestunum(struct student stu[], int n);//��ѧ�Ų���ѧ����Ϣ
void finestuname(struct student stu[], int n);//����������ѧ����Ϣ

int verifyname(char name[], struct user ux[], char psw[]);//��֤�û���






void inpsw(char psw[]);//�����������
int isnum(char st[]);//�ж��Ƿ�������
int isalph(char st[]);//�ж��Ƿ�����ĸ
int ispsw(char st[]);//�ж��Ƿ��г������֣���ĸ������ַ�
//��������
void Convert(char s[]);
//��������
void JConvert(char s[]);