#pragma once

#include<stdio.h>
#include<conio.h>
#include <string.h>

void Register(struct user us[]);
void Loginp(struct user us[]);
void Changepassword(struct user us[]);
void ADLoginp(struct user us[]);

void zym();//��ҳ��
void yhm();//�û���ҳ��
void zccg();//ע��ɹ�����
void logins();//��¼����

void inpsw(char psw[]);//�����������
int isnum(char st[]);//�ж��Ƿ�������
int isalph(char st[]);//�ж��Ƿ�����ĸ
int ispsw(char st[]);//�ж��Ƿ��г������֣���ĸ������ַ�

void readfile(struct user ux[], int* n);//���ļ����û����������ԡ��û����������������
int yhmky(char name[], struct user ux[]);//��֤�û����Ƿ����
int admanyz(char name[], struct user ux[], char psw[]);//����Ա��֤
void add(char name[], char psw[], struct user ux[]);//������û����ļ���

void intof(struct user ux[], int* n);//���ļ����û����������ԡ��û���������������У������û�������һ
void Enterf(struct user ux[], int n);//���������û����������ԡ��û��������뵽�ļ���
int verifyname(char name[], struct user ux[], char psw[]);//��֤�û��������ļ����û��������������������
void revise(char name[], struct user us[], char newpsw[], int n);//�޸�����

void Admin(struct user us[]);
void ADman(char name[]);//����Ա��ҳ��
void dele(char name[], struct user us[], int* N);//ɾ���û�

void textprint(struct user us[], int n);//�������

struct user
{
	char name[20];//�û���
	char password[7];//����6λ������λ'\0'������ַ���
};

void game();