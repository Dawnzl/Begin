#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"

int main()
{
	struct user us[10];
	int sr;

	do {
		zym();
		printf("��ѡ��");
		scanf("%d", &sr);

		if (sr == 1) {
			Register(us);//ע�����
		}

		else if (sr == 2)
		{
			Loginp(us);//��¼����

		}

		else if (sr == 3)
		{
			Changepassword(us);//�޸��������
		}

		else if (sr == 4)
		{
			ADLoginp(us);//����Ա��¼����
		}
	} while (sr != 5);
	printf("\n��лʹ�ñ�ϵͳ��\n");

	return 0;
}

void Register(struct user us[])
{
	yhm();
	char name[20];
	char psw[7];
//�����û���
	do {
		scanf("%s", name);
		if (yhmky(name, us) != 1) printf("�û����Ѵ��ڣ�����������\n");
		else {
			printf("�û������ã����������루�������6λ������ĸ���������,���ó���������ţ�\n");
			break;
		}
	} while (1);//���������û���
//��������
	do {
		printf("�������룺");
		inpsw(psw);//�������
		if (isnum(psw) && isalph(psw) && ispsw(psw)) {
			printf("\n�������óɹ�\n");
			break;
		}
		else printf("\n���벻�淶\n");
	} while (1);

	add(name, psw, us);//������û����ļ���
	int n;
	intof(us, &n);//���ļ����û����������ԡ��û���������������У������û�������һ
	Enterf(us, n);//��������¼���ļ�
	zccg();//ע��ɹ�
}

void Loginp(struct user us[])
{
		char name[20];
		char psw[7];
		char verpsw[7];
		do {
			yhm();
			scanf("%s", name);
			if (verifyname(name, us,verpsw) != 1) break;//��֤�û���������
			else {
				printf("�û��������ڣ�����������\n");
			}
		} while (1);//���������û���

		do {
			printf("�������룺");
			inpsw(psw);//�������
			printf("\n");
			if (strcmp(psw, verpsw) == 0) {
				printf("��������������������������������������������\n");
				break;
			}
			else printf("�����������������\n");
		} while (1);
		logins();//��¼�ɹ�����
		int tt;//��¼��ҳ�湦��
		do {
			printf("��ѡ��");
			scanf("%d", &tt);
			if (tt == 1) {
				Changepassword(us);//�޸��������
			}
		} while (tt != 1 && tt != 2);
}

void ADLoginp(struct user us[])
{
	char name[20];
	char psw[7];
	char verpsw[7];
	do {
		yhm();
		scanf("%s", name);
		if (admanyz(name, us, verpsw) != 1) break;
		else {
			printf("�û��������ڣ�����������\n");
		}
	} while (1);//���������û���

	do {
		printf("�������룺");
		inpsw(psw);//�������
		printf("\n");
		if (strcmp(psw, verpsw) == 0) {
			printf("��������������������������������������������\n");
			break;
		}
		else printf("�����������������\n");
	} while (1);
	ADman(name);
	Admin(us);

}

void Changepassword(struct user us[])
{
	char name[20];
	char psw[7];
	char verpsw[7];
	char newpsw[7];
	char newpswt[7];
	do {
		yhm();
		scanf("%s", name);
		if (verifyname(name, us, verpsw) != 1) break;//ͬ������֤�ļ����Ƿ�������û�
		else {
			printf("�û��������ڣ�����������\n");
		}
	} while (1);//���������û���
	do {
		printf("����ԭ���룺");
		inpsw(psw);//�������
		printf("\n");
		if (strcmp(psw, verpsw) == 0) {
			break;
		}
		else printf("ԭ�����������������\n");
	} while (1);
	do {
		printf("���������룺");
		inpsw(newpsw);//�������
		printf("\n");
		printf("�ٴ����������룺");
		inpsw(newpswt);
		printf("\n");
		if (strcmp(newpsw, newpswt) == 0) {
			break;
		}
		else printf("��������������벻ͬ������������\n");
	} while (1);
	int n;
	readfile(us, &n);//���ļ����û����������ԡ��û����������������

	revise(name, us, newpsw, n);//�޸�����
	Enterf(us, n);//���������û����������ԡ��û��������뵽�ļ���
	printf("�����޸ĳɹ�\n");
	printf("��������������������������������������������\n");
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
void logins()
{
	printf("**********************\n"); 
	printf("��¼�ɹ�����ѡ��\n"); 
	printf("1-- �޸�����\n"); 
	printf("2-- �澮����\n"); 
	printf("**********************\n");
}
void ADman(char name[])
{
	printf("**********************\n");
	printf("��ӭ����Ա:%s\n",name);
	printf("**********************\n");
}

void Admin(struct user us[])
{
	int n;
	readfile(us, &n);//���ļ����û��������������������
	char name[20];
	char psw[7];

	do {
		printf("������Ҫɾ���û����û�����");
		scanf("%s", name);
		if (yhmky(name, us) != 1)
		{
			printf("�û������ڣ��Ƿ�ѡ��ɾ��\n1.ȷ��\n2.ȡ��\n");
			break;
		}
		else {
			printf("�û��������ڣ�����������\n");
		}
	} while (1);//���������û���
	int d;
	printf("��ѡ��");
	scanf("%d", &d);
	if (d == 1)
	{
		dele(name, us, &n);
		//textprint(us, n);//�������
		Enterf(us, n);
		printf("ɾ���ɹ�\n");
	}
	else if (d == 2) printf("ȡ���ɹ�");
}


int verifyname(char name[], struct user ux[], char psw[])//��֤�û���
{
	FILE* f1;
	int i, n, f = 1;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++) 
	{
		fscanf(f1, "%s%s", ux[i].name, ux[i].password);//���ļ����û��������������������
		if (strcmp(name, ux[i].name) == 0) {
			strcpy(psw, ux[i].password);
			f = 0;
			break;
		}
	}
	if (f == 1) {
		fclose(f1);
		return 1;
	}
	fclose(f1);

	return 0;
}

int yhmky(char name[],struct user ux[])
{
	FILE* f1;
	int i, n,f=1;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f1, "%s%s", ux[i].name,ux[i].password);//���ļ����û��������������
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

int admanyz(char name[], struct user ux[], char psw[])//��֤�û���
{
	FILE* f1;
	int i, n, f = 1;
	f1 = fopen("admin.txt", "r");//�򿪹���Ա�ļ�
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(f1, "%s%s", ux[i].name, ux[i].password);//���ļ����û��������������������
		if (strcmp(name, ux[i].name) == 0) {
			strcpy(psw, ux[i].password);
			f = 0;
			break;
		}
	}
	if (f == 1) {
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

void intof(struct user ux[],int *n)//����ļ�������Ľṹ������
{
	FILE* f;
	int i;
	f = fopen("user.txt", "r");
	fscanf(f, "%d", n);
	int t = *n;
	t =  t + 1;
	*n = t;
	for (i = 0; i < t; i++)
	{
		fscanf(f, "%s%s", ux[i].name, ux[i].password);//���ļ����û��������������������
	}
	fclose(f);
}

void Enterf(struct user ux[], int n)//¼���ļ�
{
	FILE* f;
	int i = 0 ;
	f = fopen("user.txt", "w+");
	fprintf(f, "%d\n", n);
	for (i = 0; i < n; i++)
	{
		fprintf(f, "%s %s\n", ux[i].name, ux[i].password);//���ļ����û��������������������
	}
	fclose(f);
}


void textprint(struct user us[], int n)//���볢��
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%s %s\n", us[i].name, us[i].password);
	}

}

void readfile(struct user ux[],int *n)//���ļ����û��������������������
{
	FILE* f1;
	int i;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", n);
	for (i = 0; i < *n; i++) {
		fscanf(f1, "%s%s", ux[i].name, ux[i].password);//���ļ����û��������������������
	}
	fclose(f1);
}

void revise(char name[], struct user us[], char newpsw[],int n )
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(name, us[i].name) == 0) {
			strcpy(us[i].password, newpsw);
			break;
		}
	}
}

void dele(char name[], struct user us[], int* N)
{
	int i;
	int n = *N;
	for (i = 0; i < n; i++)
	{
		if (strcmp(name, us[i].name) == 0) {
			int t;
			for (t = i; t < n; t++)
			{
				strcpy(us[t].name, us[t + 1].name);
				strcpy(us[t].password, us[t + 1].password);
			}
			strcpy(us[n-1].name,"\0");
			strcpy(us[n-1].password,"\0");
			n = n - 1;
			*N = n;
			break;
		}
	}
}

//����ƪ
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