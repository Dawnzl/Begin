#define _CRT_SECURE_NO_WARNINGS 1
#include"system2.h"

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
	FILE* date;
	int n;
	date = fopen("LOG.txt", "a+");//��־
	WriteDate(date, us);
	fclose(date);
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

//��ʼ����
void WriteDate(FILE* date, struct user us[])
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(date, "����Ա%s��", us->name);//����Ա����
	fprintf(date, "%d", p->tm_year + 1900); //��ȡ��
	fputs("\\", date);
	fprintf(date, "%d", p->tm_mon + 1); //��ȡ��
	fputs("\\", date);
	fprintf(date, "%d", p->tm_mday); //��ȡ��
	fputs("\\", date);
	fputs(" ", date);
	fprintf(date, "%0.2d", p->tm_hour + 8); //��ȡʱ
	fputs(":", date);
	fprintf(date, "%0.2d", p->tm_min); //��ȡ��
	fputs(":", date);
	fprintf(date, "%0.2d", p->tm_sec); //��ȡ��
	fputs(" ", date);
	fputs("��¼", date);
	fputs("\n", date);
}

//��������
void OutDate(FILE* date, struct user us[])
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(date, "����Ա%s��", us->name);//����Ա����
	fprintf(date, "%d", p->tm_year + 1900); //��ȡ��
	fputs("\\", date);
	fprintf(date, "%d", p->tm_mon + 1); //��ȡ��
	fputs("\\", date);
	fprintf(date, "%d", p->tm_mday); //��ȡ��
	fputs("\\", date);
	fputs(" ", date);
	fprintf(date, "%0.2d", p->tm_hour + 8); //��ȡʱ
	fputs(":", date);
	fprintf(date, "%0.2d", p->tm_min); //��ȡ��
	fputs(":", date);
	fprintf(date, "%0.2d", p->tm_sec); //��ȡ��
	fputs(" ", date);
	fputs("ע��", date);
	fputs("\n", date);

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
	printf("������ѡ�1--2����");

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
			struct  student stu[100]; //ѧ������
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
					scanf("%d %s %c %d %d %d", stu->sid, stu->name, stu->sex, stu->score[0], stu->score[1], stu->score[2]);
				}

				printf("�����ɹ���\n");
				printf("���س����������룬�����������������\n");
				getchar();
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


void FineMenu()
{
	printf("**********ѧ����Ϣ�Ĳ���**********\n");
	printf("����ѡ�\n");
	printf("-------------------------------------------------\n");
	printf("                1--- ����ѧ�Ų���                \n");
	printf("                2--- ������������                \n");
	printf("-------------------------------------------------\n");
	printf("������ѡ�1--2����");

}

//����ѧ����Ϣ
void fine()
{
	FineMenu();

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
				int num;//ѧ��
				printf("\n��ѡ���˰���ѧ�Ų��ң������\n");
				printf("������ѧ����ѧ�ţ�");
				scanf("%d", &num);

				//������δ��ɣ�


				printf("���س����������룬�����������������\n");
				getchar();
				in = getchar();

			} while (in == '\n');

		}
		else if (inp == 2)
		{
			char in;
			do
			{
				char name[20];
				printf("\n��ѡ���˰����������ң������\n");
				printf("������ѧ����ѧ�ţ�");
				scanf("%s", name);

				//������δ��ɣ�


				printf("���س����������룬�����������������\n");
				getchar();
				in = getchar();

			} while (in == '\n');



		}
		else printf("������������������\n");


	} while (inp != 1 || inp != 2);
}
//ɾ��ѧ����Ϣ
void del()
{

}
//����γ����Ʒ����ɼ�
void analyse()
{

}

void SortMenu()
{
	printf("**********ѧ����Ϣ������**********\n");
	printf("����ѡ�\n");
	printf("-------------------------------------------------\n");
	printf("                1--- ����ѧ������                \n");
	printf("                2--- ������������                \n");
	printf("              3--- �������ĳɼ�����              \n");
	printf("              4--- ������ѧ�ɼ�����              \n");
	printf("              5--- ����Ӣ��ɼ�����              \n");
	printf("-------------------------------------------------\n");
	printf("������ѡ�1--2����");
}

//����(ѧ�š��������ɼ���)
void sort()
{
	SortMenu();

}

//��������ʱ��
void Out(struct user us[])
{
	FILE* date;
	int n;
	date = fopen("LOG.txt", "a+");//��־

	//�������濪ʼʱ��
	OutDate(date, us);
	fclose(date);

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

//��������
void Convert(char s[]) 
{
	for (int i = 0; i < 6; i++) {
		if (s[i] >= 'a' && s[i] < 'z') {
			s[i]++;
		}
		else if (s[i] >= 'A' && s[i] < 'Z') {
			s[i]++;
		}
		else if (s[i] == 'z') s[i] = 'a';
		else if (s[i] == 'Z') s[i] = 'A';
		else if (s[i] >= 0 && s[i] < 9) s[i]++;
		else if (s[i] == 9) s[i] = 0;
	}
}
//����
void JConvert(char s[])
{
	for (int i = 0; i < 6; i++) {
		if (s[i] > 'a' && s[i] <= 'z') {
			s[i]--;
		}
		else if (s[i] > 'A' && s[i] <= 'Z') {
			s[i]--;
		}
		else if (s[i] == 'a') s[i] = 'z';
		else if (s[i] == 'A') s[i] = 'Z';
		else if (s[i] > 0 && s[i] <= 9) s[i]++;
		else if (s[i] == 0) s[i] = 9;
	}
}