#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include <string.h>

void zym();
void inpsw(char psw[]);//�����������
int isnum(char st[]);//�ж��Ƿ�������
int isalph(char st[]);//�ж��Ƿ�����ĸ
int ispsw(char st[]);//�ж��Ƿ��г������֣���ĸ������ַ�
void readfile(struct user ux[]);//���ļ����û��������������������
void textprint(struct user us[]);//�������
int yhmky(char name[], struct user ux[]);//��֤�û����Ƿ����
void yhm();//�û���ҳ��
void add(char name[], char psw[], struct user ux[]);//
void zccg();

struct user
{
	char name[20];//�û���
	char password[7];//����6λ������λ'\0'������ַ���
};

/*
1.�û���������ע��ɹ��������ʾ������������
2.�û����������¼�ɹ�����ʾ�ӽ��棺
**********************
��¼�ɹ�����ѡ��
1---
2---
**********************

3.�����޸ĳɹ��������ʾ������������
4.���ļ�����û���������
5.����ṹ���ͱ�ʾ�û���Ϣ
6.���������ú���ʵ��
7.����ѡ�����ܣ�
�û�����ɾ���û���ֻ��admin�и�Ȩ�ޣ�
������ܺͽ���
*/
int main()
{
	struct user us[10];
	int sr;

	do {
		zym();
		scanf("%d", &sr);

		if (sr == 1) {
		    yhm();
		    char name[20];
			char psw[7];
			do {
				scanf("%s", name);
				if (yhmky(name, us) != 1) printf("�û����Ѵ��ڣ�����������\n");
				else {
					printf("�û������ã����������루�������6λ������ĸ���������,���ó���������ţ�\n");
					break;
				}
			} while (1);//���������û���

			do {
				printf("�������룺");
				inpsw(psw);//�������
				if (isnum(psw) && isalph(psw) && ispsw(psw)) {
					printf("\n�������óɹ�\n");
					break;
				}
				else printf("\n���벻�淶\n");
			} while (1);
			add(name, psw, us);//��δ�ɹ����ļ��е�n���ģ�Ҫ��λ
			zccg();
		}
	} while (sr != 5);






	

	readfile(us);
	textprint(us);



	return 0;
}






void zym()
{
	printf("��������������������������������������������\n");
	printf("1.ע�����û�\n2.��¼�����˻�\n3.�޸��˻�����\n4.����Ա��¼\n5.�˳�\n");
	printf("��������������������������������������������\n");
}

void yhm() 
{
	printf("��������������������������������������������\n");
	printf("�������û��� :>");
}

void zccg()
{
	printf("ע��ɹ�!\n");
	printf("��������������������������������������������\n");
}

int yhmky(char name[],struct user ux[])
{
	FILE* f1;
	int i, n,f=1;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < 2*n; i++) {
		fscanf(f1, "%s", ux[i].name);//���ļ����û��������������������
		if (!strcmp(name, ux[i].name)) {
			f = 0;
			break;
		}
	}
	if(f==1){
		fclose(f1);
		return 1;
	}
	fclose(f1);
	return 0;
}

void add(char name[],char psw[],struct user ux[])//��ע����û������������뵽�ļ���
{
	FILE* f1;
	f1 = fopen("user.txt", "a");
	fprintf(f1,"%s %s\n", name, psw);//����������Ķ����ļ�
	fclose(f1);
}


void textprint(struct user us[])
{
	int i;
	for (i = 0; i < 4; i++) {
		printf("%s %s\n", us[i].name, us[i].password);
	}

}

void readfile(struct user ux[])//���ļ����û��������������������
{
	FILE* f1;
	int i, n;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f1, "%s%s", ux[i].name, ux[i].password);//���ļ����û��������������������
	}
	fclose(f1);
}


void inpsw(char psw[])//�����������
{
	int i;
	for (i = 0; i < 6; i++)
	{
		psw[i] = _getch();
		psw[6] = '\0';
		putchar('*');

	}
}

int isnum(char st[])//�ж��Ƿ�������
{
	int i;
	for (i = 0; i < 6; i++) 
		if (st[i] >= '0' && st[i] <= '9') return 1;
	return 0;
}

int isalph(char st[])//�ж��Ƿ�����ĸ
{
	int i;
	for (i = 0; i < 6; i++)
		if (st[i] >= 'a' && st[i] <= 'z') return 1;
		else if (st[i] >= 'A' && st[i] <= 'Z') return 1;
	return 0;
}

int ispsw(char st[])//�ж��Ƿ��г������֣���ĸ������ַ�
{
	int i;
	for (i = 0; i < 6; i++)
		if (st[i] >= '0' && st[i] <= '9') continue;
		else if (st[i] >= 'a' && st[i] <= 'z') continue;
		else if (st[i] >= 'A' && st[i] <= 'Z') continue;
	    else return 0;
	return 1;
}