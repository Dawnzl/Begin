#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"

void menu()
{
	printf("=============================================\n");
	printf("                 ѧ����Ϣ����ϵͳ            \n");
	printf("=============================================\n");
}
//��¼ҳ��
void Loginp(struct user us[])
{
	char name[20];
	char psw[7];
	char verpsw[7];
	do {
		menu();
		printf("�û�����");
		scanf("%s", name);
		if (verifyname(name, us, verpsw) != 1) break;//��֤�û���������
		else {
			printf("�û��������ڣ�����������\n");
		}
	} while (1);//���������û���

	do {
		printf("���룺");
		inpsw(psw);//�������
		printf("\n");
		if (strcmp(psw, verpsw) == 0) {
			break;
		}
		else printf("�����������������\n");
	} while (1);

	Susslogged();

}
//��֤�û���
int verifyname(char name[], struct user ux[], char psw[])
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
//��¼�ɹ�ҳ��
void Susslogged()
{
	printf("��¼�ɹ�!\n");
	printf("=============================================\n");
	printf("����ѡ�\n");
	printf("	0---������Ϣ���˳�\n");
	printf("	1--- ����ѧ����Ϣ 2--- ����ѧ����Ϣ\n");
	printf("	3--- ���ѧ����Ϣ 4--- �޸�ѧ����Ϣ\n");
	printf("	5--- ����ѧ����Ϣ 6--- ɾ��ѧ����Ϣ\n");
	printf("	7--- ����γ����Ʒ����ɼ�\n");
	printf("	8--- ����(ѧ�š��������ɼ���)\n");	
	printf("=============================================\n");
	printf("������ѡ�0--7��:");

}


//ѧ����Ϣ����ҳ��
void MakeMenu()
{
	printf("**********ѧ����Ϣ�Ĵ���********** \n");
	printf("����ѡ�\n");
	printf("-------------------------------------------------\n");
	printf("             1--- �Ӽ�������������Ϣ             \n");
	printf("             2--- ���ļ���ȡ������Ϣ             \n");
	printf("-------------------------------------------------\n");
	printf("������ѡ�1--2����\n");
	printf("\n");
		
}


//����ѧ����Ϣ
void make()
{
	MakeMenu();

	int inp;

	do
	{
		scanf("%d", &inp);
		printf("\n");
		if (inp == 1)
		{
			char in;
			do
			{
				printf("��ѡ���˴Ӽ�����������\n");
				printf("������ѧ����������");
				int num;
				scanf("%d", &num);

				printf("�밴�� ѧ�� ���� �Ա� ���� ��ѧ Ӣ���˳������ÿ��ѧ������Ϣ\n");
				int i = 0;
				for (i = 0; i < num; i++)
				{
					printf("�����룺");
					//scanf("%s %s %c %d %d %d", );//δ���
				}

				printf("�����ɹ���\n");
				printf("���س����������룬�����������������\n");

				in = getchar();

			} while (in == '\n');
		
		}
		else if (inp == 2)
		{
			printf("��ѡ���˴��ļ���ȡ����\n");
		}
		else printf("������������������\n");


	} while (inp != 1 || inp != 2);


}
//����ѧ����Ϣ
void add()
{

}
//���ѧ����Ϣ
void look()
{

}
//�޸�ѧ����Ϣ
void revise()
{

}
//����ѧ����Ϣ
void fine()
{

}
//ɾ��ѧ����Ϣ
void del()
{

}
//����γ����Ʒ����ɼ�
void analyse()
{

}
//����(ѧ�š��������ɼ���)
void sort()
{

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