#define _CRT_SECURE_NO_WARNINGS 1
#include"system2.h"

void menu()
{
	printf("=============================================\n");
	printf("                 ѧ����Ϣ����ϵͳ            \n");
	printf("=============================================\n");
}
//��¼ҳ��
void Loginp(struct user us[],char name[])
{
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

		//���м���
		Convert(psw);
		//printf("%s", psw);
		if (strcmp(psw, verpsw) == 0) {
			break;
		}
		else printf("�����������������\n");
	} while (1);
	FILE* date;
	date = fopen("LOG.txt", "a+");//��־
	WriteDate(date, name);
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
			//�ӽ���

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
}

void Menu()
{
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
void WriteDate(FILE* date, char name[])
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(date, "����Ա%s��", name);//����Ա����
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
void OutDate(FILE* date, char name[])
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(date, "����Ա%s��", name);//����Ա����
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
	char in;
	int inp;
	do
	{
		do
		{
			scanf("%d", &inp);
			printf("\n");
			if (inp == 1)
			{
				struct student stu[100]; //ѧ������

					printf("��ѡ���˴Ӽ�����������\n");
					printf("������ѧ����������");
					int num;
					scanf("%d", &num);

					printf("�밴�� ѧ�� ���� �Ա� ���� ��ѧ Ӣ��   ��˳������ÿ��ѧ������Ϣ\n");
					int i = 0;
					for (i = 0; i < num; i++)
					{
						printf("�����룺");
						scanf("%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
					}

					Enterf(stu, num);

					printf("�����ɹ���\n");
					

			}
			else if (inp == 2)
			{
				struct student stu[100]; //ѧ������
				printf("��ѡ���˴��ļ���ȡ����\n");
				printf("�ֽ��򿪡�Fstudent���ļ������и������\n");
				printf("�Ƿ�ȷ��������ļ�ѧ����Ϣ��\n1.ȷ��\n2.ȡ��\n");
				int o = 0;
				printf("��ѡ��");
				do
				{
					scanf("%d", &o);

					if (o == 1)
					{

						int n = inFstudent(stu);//stu�ȴ�������ļ�ѧ������Ϣ
						Enterf(stu, n);

						printf("�����ɹ���\n");
					}
					else if (o == 2) printf("ȡ���ɹ�\n");

					else printf("�����������������\n");


				} while (o < 1 || o > 2);



			}
			else printf("������������������\n");


		} while (inp != 1 && inp != 2);

		printf("���س����������룬�����������������\n");
		getchar();
		in = getchar();
		if (in != '\n') break;

	} while (in == '\n');
}

//��Fѧ���ļ�
int inFstudent(struct student stu[])
{
	FILE* f1;
	int i, n;
	f1 = fopen("Fstudent.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f1, "%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//���ļ������������
	}
	fclose(f1);
	return n;
}

//¼���ļ�
void Enterf(struct student stu[], int n)//n���Զ����
{
	FILE* f;
	int i = 0;
	f = fopen("student.txt", "w+");//����ԭ��
	fprintf(f, "%d\n", n);//����n
	for (i = 0; i < n; i++)
	{
		fprintf(f, "%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
	fclose(f);
}

//���볢��
void textprint(struct student stu[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}

}

//����ѧ����Ϣ
void add()
{
	printf("**********ѧ����Ϣ�����********** \n");
	printf("����ѡ�\n");
	printf("-------------------------------------------------\n");
	printf("             1--- �Ӽ�������������Ϣ             \n");
	printf("             2--- ���ļ���ȡ������Ϣ             \n");
	printf("-------------------------------------------------\n");
	printf("������ѡ�1--2����");
	int inp;
	char in;

	do
	{ 
		do
		{
			scanf("%d", &inp);
			printf("\n");
			if (inp == 1)
			{
				struct student stu[100]; //ѧ������

				printf("��ѡ���˴Ӽ�����������\n");
				printf("������ѧ����������");
				int num;
				scanf("%d", &num);
				


				printf("�밴��  ѧ��   ����   �Ա�  ����  ��ѧ  Ӣ���˳������ÿ��ѧ������Ϣ\n");
				int i = 0;
				int n = 0;
				for (i = 0; i < num; i++)
				{
					printf("��������Ϣ��");
					scanf("%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
					if (sidfine(stu[i].sid))//���ѧ���Ƿ����
					{
						printf("���������\n");
					}
					else
					{
						i--;
						printf("����������\n");
					}
				}

				addstd(stu, num);//��ӽ��ļ�   stu���ȴ����
				//textprint(stu, num);

				addread(stu, &num);//ѧ������                              


				Enterf(stu, num);//
				//textprint(stu, num);


				printf("�����ɹ���\n");

			}

			else if (inp == 2)
			{
				struct student stu[100]; //ѧ������
				printf("��ѡ���˴��ļ���ȡ����\n");
				printf("�ֽ��򿪡�Astudent���ļ������д������\n");
				printf("�Ƿ�ȷ��������ļ�ѧ����Ϣ��\n1.ȷ��\n2.ȡ��\n");
				int o;
				printf("��ѡ��");
				do
				{
					scanf("%d", &o);

					if (o == 1)
					{
						//Ҫ�Ȱ�ԭ�ļ���ѧ����Ϣ���뵽������
						//�ٰ���һ�ļ���ѧ�����뵽������
						//���ѳ����еĴ���Դ�ļ���
						int n = instudent(stu);//stu�ȴ�������ļ�ѧ������Ϣ
						addstd(stu, n);//��ѧ������Ϣ���뵽�ļ���
						addread(stu, &n);//���ļ������е�ѧ����Ϣ����������У�����stu���飩

						int i = 0, j = 0;

						for (j = 0; j < n; j++)
						{
							for (i = 0; i < n; i++)
							{
								if (stu[i].sid == stu[j].sid && i != j)
								{
									printf("    ѧ ��   �� ��   �Ա�  ����  ��ѧ  Ӣ��\n");
									printf("1��  %d    %s     %c    %d    %d    %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
									printf("2��  %d    %s     %c    %d    %d    %d\n", stu[j].sid, stu[j].name, stu[j].sex, stu[j].score[0], stu[j].score[1], stu[j].score[2]);
									printf("��ѧ��ѧ���ظ���ѡ��ɾ1��Ϣ��2��Ϣ��\nɾ��1��Ϣ\nɾ��2��Ϣ\n");
									//f = 1;
									int d;
									printf("��ѡ��");
									scanf("%d", &d);
									if (d == 1)
									{
										dele(stu[i].sid, stu, &n);
										//textprint(us, n);//�������
										//Enterf(stu, n);
										printf("ɾ���ɹ�\n");
									}
									else if (d == 2)
									{
										dele(stu[j].sid, stu, &n);
										//textprint(us, n);//�������
										//Enterf(stu, n);
										printf("ɾ���ɹ�\n");
									}
								}

							}
						}

						Enterf(stu, n);//����ɾ��������ٽ�stu¼���ļ���
					}
					else if (o == 2) printf("ȡ���ɹ�\n");

					else printf("�����������������");


				} while (o < 1 || o>2);





			}
			else printf("������������������\n");


		} while (inp != 1 && inp != 2);

	printf("���س����������룬�����������������\n");

	getchar();
	in = getchar();
	if (in != '\n') break;

	} while (in == '\n');
} 

int instudent(struct student stu[])//����ת��
{
	FILE* f1;
	int i, n;
	f1 = fopen("Astudent.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f1, "%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//���ļ������������
	}
	fclose(f1);
	return n;
}
//int outstudent(struct student stu[], int n)
//{
//	FILE* f1;
//	int i = 0, n = 0;
//	f1 = fopen("student.txt", "a");
//	for (i = 0; i < n; i++)
//	{
//		fprintf(f1, "%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
//	}
//	fclose(f1);
//}

int sidfine(int num)
{
	struct student stu[100]; 
	int n = readfile(stu);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (num == stu[i].sid)
		{
			printf("%d��ѧ������ѧ��ռ�ã���������²���\n", num);
			return 0;
		}
	}
	return 1;
}

void addstd(struct student stu[],int num)//��ѧ������Ϣ���뵽�ļ���
{
	FILE* f1;
	f1 = fopen("student.txt", "a");//����������Ķ����ļ�
	int i = 0;
	for (i = 0; i < num; i++)
	{
		fprintf(f1, "%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
	fclose(f1);
}

//���ļ���ѧ����Ϣ�����������//��Ӱ�
void addread(struct student stu[], int* num)//ѧ������ĩβ�±�
{
	FILE* f1;
	int i, n;
	f1 = fopen("student.txt", "r");
	fscanf(f1, "%d", &n);
	*num = n + *num;                  //������ѧ���ĸ���   +   �ļ���ѧ���ĸ���
	for (i = 0; i < *num; i++)
	{
		fscanf(f1, "%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//���ļ���ѧ����Ϣ�����������
	}
	fclose(f1);
}

////�����Ϣ
//void Enterfadd(struct student stu[], int* n, int num)//n���Զ����
//{
//	FILE* f;
//	int i = 0;
//	f = fopen("student.txt", "w+");//����ԭ��
//	fscanf(f, "%d", n);
//	int t = *n;
//	t = t + num;
//	*n = t;
//	for (i = 0; i < n; i++)
//	{
//		fprintf(f, "%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
//	}
//	fclose(f);
//}



//���ѧ����Ϣ
void look()
{
	printf("-------------------------------------------------\n");
	printf("                  ѧ����Ϣ����                   \n");
	printf("-------------------------------------------------\n");
	printf("    ѧ ��   �� ��   �Ա�  ����  ��ѧ  Ӣ��\n");
	struct  student stu[100]; //ѧ������
	int n = readfile(stu);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("    %d    %s     %c    %d    %d    %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}

}

//���ļ���ѧ����Ϣ�����������//�����
int readfile(struct student stu[])
{
	FILE* f1;
	int i, n;
	f1 = fopen("student.txt", "r");
	fscanf(f1, "%d", &n); 
	for (i = 0; i < n; i++) {
		fscanf(f1, "%d %s %c %d %d %d\n", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//���ļ����û��������������������
	}
	fclose(f1);
	return n;
}


//���ļ����û��������������������
//void readfile(struct student stu[])
//{
//	FILE* f1;
//	int i, n;
//	f1 = fopen("student.txt", "r");
//	fscanf(f1, "%d", &n);
//	for (i = 0; i < n; i++) {
//		fscanf(f1, "%d %s %c %d %d %d\n", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//���ļ����û��������������������
//	}
//	fclose(f1);
//}

void ReviseMenu()
{
	printf("**********ѧ����Ϣ���޸�**********\n");

}

//�޸�ѧ����Ϣ
void revise()
{
	ReviseMenu();
	struct student stu[100];
	char in;

	printf("\n");
	do
	{


		printf("\n�밴��ѧ�Ų���\n");

		int n = readfile(stu);//��ѧ����Ϣ���뵽������

		revisestu(stu, n);//�޸ĳɹ�

		Enterf(stu, n);//¼���޸���Ϣ

		printf("���س����������룬�����������������\n");

		getchar();
		in = getchar();
		if (in != '\n') break;                                                       

	} while ( in == '\n');

		

}

void revisestu(struct student stu[], int n)
{
	int i = 0;
	int f = 1;
	int num;//ѧ��
	char in;

	do
	{
		do
		{
			printf("������ѧ����ѧ�ţ�");
			scanf("%d", &num);

			for (i = 0; i < n; i++)
			{

				if (num == stu[i].sid)
				{
					printf("ѧ����Ϣ��%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
					//textprint(stu, n);
					printf("��ѡ���޸���Ŀ��������1�����Ա�2�������ĳɼ���3������ѧ�ɼ���4����Ӣ��ɼ���5��");
					int input = 0;

					do
					{
						printf("��ѡ��");
						scanf("%d", &input);
						if (input == 1)
						{
							printf("��������%s���޸ĳɣ�", stu[i].name);
							char name[20];
							scanf("%s", name);
							strcpy(stu[i].name, name);
						}

						else if (input == 2)//δ�ж�ֻ������M ����W
						{
							getchar();//�����س�
							printf("���Ա�%c���޸ĳɣ�", stu[i].sex);
							char sex;
							scanf("%c", &sex);
							stu[i].sex = sex;
						}

						else if (input == 3)
						{
							printf("�����ĳɼ���%d���޸ĳɣ�", stu[i].score[0]);
							int sco;
							scanf("%d", &sco);
							stu[i].score[0] = sco;
						}

						else if (input == 4)
						{
							printf("����ѧ�ɼ���%d���޸ĳɣ�", stu[i].score[1]);
							int sco;
							scanf("%d", &sco);
							stu[i].score[1] = sco;
						}

						else if (input == 5)
						{
							printf("��Ӣ��ɼ���%d���޸ĳɣ�", stu[i].score[2]);
							int sco;
							scanf("%d", &sco);
							stu[i].score[2] = sco;
						}
						else printf("�����������������\n");

					} while (input < 1 || input > 5);

					f = 0;
					printf("�޸ĳɹ���\n");
					printf("�޸ĺ����Ϣ��%d %s %c %d %d %d\n\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);

					break;
				}
			}
			if (f) printf("δ�ҵ���ѧ����Ϣ������������\n");

			getchar();

		} while (f);
		printf("���س��������޸ģ������������������\n");
		in = getchar();
		if (in != '\n') break;

	} while (in != '1' && in == '\n');
	



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
	struct student stu[100];
	int inp;
	char in;

	do
	{
		do
		{
			scanf("%d", &inp);
			printf("\n");
			if (inp == 1)
			{

				printf("\n��ѡ���˰���ѧ�Ų��ң������\n");
				printf("������ѧ����ѧ�ţ�");

				int n = readfile(stu);//��ѧ����Ϣ���뵽������

				finestunum(stu, n);

			}
			else if (inp == 2)
			{

				char name[20];
				printf("\n��ѡ���˰����������ң������\n");
				printf("������ѧ����������");

				int n = readfile(stu);//��ѧ����Ϣ���뵽������

				finestuname(stu, n);

			}
			else printf("������������������\n");


		} while (inp < 1 || inp > 2);

		printf("���س�������ɾ���������������������\n");

		getchar();
		in = getchar();
		if (in != '\n') break;

	} while ( in == '\n');

}

void finestunum(struct student stu[],int n)
{
	int i = 0;
	int f = 1;
	int num;//ѧ��

	do
	{
		scanf("%d", &num);
		for (i = 0; i < n; i++)
		{

			if (num == stu[i].sid)
			{
				printf("ѧ����Ϣ��%d %s %c %d %d %d\n\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				f = 0;
				break;
			}
		}
		if(f) printf("δ�ҵ���ѧ����Ϣ������������\n");

	} while (f);



}
void finestuname(struct student stu[], int n)
{
	int i = 0;
	int f = 1;
	char name[20] = { 0 };

	do
	{
		scanf("%s", name);

		for (i = 0; i < n; i++)
		{

			if (!strcmp(name, stu[i].name))
			{
				printf("\nѧ����Ϣ��%d %s %c %d %d %d\n\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				f = 0;
				break;
			}
		}
		if (f) printf("δ�ҵ���ѧ����Ϣ������������:");

	} while (f);



}


//ɾ��ѧ����Ϣ
void del()
{
	printf("**********ѧ����Ϣ��ɾ��********** \n");
	struct student stu[100];
	int n = readfile(stu);
	int sid = 0;//ѧ��
	int f = 1;//�ж��Ƿ���Ҫ��������ѧ��
	char in;
	do
	{
		do {
			printf("������Ҫɾѧ����ѧ�ţ�");
			scanf("%d", &sid);
			int i = 0;
			for (i = 0; i < n; i++)
			{
				if (stu[i].sid == sid)
				{
					printf("��ѧ����Ϣ��\n");
					printf("    ѧ ��   �� ��   �Ա�  ����  ��ѧ  Ӣ��\n");
					printf("    %d    %s     %c    %d    %d    %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
					printf("��ѧ����Ϣ���ڣ��Ƿ�ѡ��ɾ��\n1.ȷ��\n2.ȡ��\n");
					f = 0;
					break;
				}

			}
			if (f)
			{
				printf("��ѧ����Ϣ�����ڣ�����������\n");
			}


		} while (f);//fδ�ı���������ѧ��
		int d;
		printf("��ѡ��");
		scanf("%d", &d);
		if (d == 1)
		{
			dele(sid, stu, &n);
			//textprint(us, n);//�������
			Enterf(stu, n);
			printf("ɾ���ɹ�\n");
		}
		else if (d == 2) printf("ȡ���ɹ�\n");

		printf("���س�������ɾ���������������������\n");

		getchar();
		in = getchar();
		if (in != '\n') break;

	} while (in != '1' && in == '\n');
}


void dele(int sid, struct student stu[], int* N)
{
	int i;
	int n = *N;
	struct student T;
	//={ 0, "\0", '\0', 0,0,0  }
	for (i = 0; i < n; i++)
	{
		if (sid==stu[i].sid) 
		{
			T = stu[i];
			int t;
			for (t = i; t < n; t++)
			{
				stu[t] = stu[t + 1];
				
			}
			//stu[n - 1] = t;
			strcpy(stu[n - 1].name, "\0");
			stu[n - 1].sex = '\0';
			stu[n - 1].score[0] = 0;
			stu[n - 1].score[1] = 0;
			stu[n - 1].score[2] = 0;

			n = n - 1;
			*N = n;
			break;
		}
	}
	FILE* f;
	f = fopen("delstudent.txt", "a");//���
	fprintf(f, "%d %s %c %d %d %d\n", T.sid, T.name, T.sex, T.score[0], T.score[1], T.score[2]);
	fclose(f);
}
//����γ����Ʒ����ɼ�
//����γ����ƣ���ʾ�ÿγ̵���߷֡���ͷ֡�ƽ���֡�����������
void analyse()
{
	printf("***********�γ� ����*********** \n");
	struct student stu[100];
	int n = readfile(stu);
	int score = 0;//�γ̴���
	int cj[4];
	char in;
	do
	{
		do {
			printf("������Ҫ�����Ŀγ�  ���ģ�1����ѧ��2��Ӣ�3����");
			scanf("%d", &score);
			if (score == 1)
			{
				printf("���ĳɼ�������\n");
				analcj(stu, n, cj, 0);
				printf("�ð�������߷֣�%d�֣���%sͬѧ��ȡ\n", stu[cj[0]].score[0], stu[cj[0]].name);
				printf("�ð�������ͷ֣�%d��\n", stu[cj[1]].score[0]);
				printf("�ð�����ƽ���֣�%d��\n", cj[2]);
				printf("�ð����ĵ���60�ֵĲ�����������%d��\n", cj[3]);

			}
			else if (score == 2)
			{
				printf("��ѧ�ɼ�������\n");
				analcj(stu, n, cj, 1);
				printf("�ð���ѧ��߷֣�%d�֣���%sͬѧ��ȡ\n", stu[cj[0]].score[1], stu[cj[0]].name);
				printf("�ð���ѧ��ͷ֣�%d��\n", stu[cj[1]].score[1]);
				printf("�ð���ѧƽ���֣�%d��\n", cj[2]);
				printf("�ð���ѧ����60�ֵĲ�����������%d��\n", cj[3]);

			}
			else if (score == 3)
			{
				printf("Ӣ��ɼ�������\n");
				analcj(stu, n, cj, 2);
				printf("�ð�Ӣ����߷֣�%d�֣���%sͬѧ��ȡ\n", stu[cj[0]].score[2], stu[cj[0]].name);
				printf("�ð�Ӣ����ͷ֣�%d��\n", stu[cj[1]].score[2]);
				printf("�ð�Ӣ��ƽ���֣�%d��\n", cj[2]);
				printf("�ð�Ӣ�����60�ֵĲ�����������%d��\n", cj[3]);
			}
			else printf("�����������������\n");

		} while (score<1||score>3);

		printf("���س������������������������������\n");

		getchar();
		in = getchar();
		if (in != '\n') break;

	} while (in == '\n');
}

void analcj(struct student stu[], int n, int cj[4], int x)
{

	int i = 0;
	int num = 0;
	int sum = 0;
	int max = 0;
	int min = 101;
	for (i = 0; i < n; i++)
	{
		if (max < stu[i].score[x])
		{
			max = stu[i].score[x];
			cj[0] = i;
		}

		if (min > stu[i].score[x])
		{
			min = stu[i].score[x];
			cj[1] = i;//min��Сֵ���±�
		}

		if (stu[i].score[x] < 60)
		{
			num++;
		}

		sum += stu[i].score[x];
	}
	cj[2] = sum / n;
	cj[3] = num;
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
}

//����(ѧ�š��������ɼ���)
void sort()
{
	SortMenu();
	int ind = 0;
	char in;
	struct student stu[100];
	int n = readfile(stu);//��ѧ����Ϣ���뵽������

	do
	{
		do
		{
			printf("������ѡ�1--5����");
			scanf("%d", &ind);
			if (ind == 1)
			{
				printf("\n");
				printf("-------------------------------------------------\n");
				printf("                  ѧ��ѧ������                   \n");
				printf("-------------------------------------------------\n");
				printf("    ѧ ��   �� ��   �Ա�  ����  ��ѧ  Ӣ��\n");
				int i = 0;
				int j = 0;
				for (i = 0; i < n - 1; i++)
				{
					for (j = 0; j < n - i - 1; j++)
					{
						if (stu[j].sid > stu[j + 1].sid)
						{
							struct student t = stu[j];
							stu[j] = stu[j + 1];
							stu[j + 1] = t;
						}
					}
				}
				for (i = 0; i < n; i++)
				{
					printf("%5d%10s    %c%5d%5d%5d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}
			}

			else if (ind == 2)
			{
				printf("\n");
				printf("-------------------------------------------------\n");
				printf("                  ѧ����������                   \n");
				printf("-------------------------------------------------\n");
				printf("    �� ��   ѧ ��   �Ա�  ����  ��ѧ  Ӣ��\n");
				int i = 0;
				int j = 0;
				for (i = 0; i < n - 1; i++)
				{
					for (j = 0; j < n - i - 1; j++)
					{
						if (strcmp(stu[j].name , stu[j + 1].name) > 0)
						{
							struct student t = stu[j];
							stu[j] = stu[j + 1];
							stu[j + 1] = t;
						}
					}
				}
				for (i = 0; i < n; i++)
				{
					printf("    %s    %d     %c    %d    %d    %d\n",  stu[i].name, stu[i].sid, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}

			}
			else if (ind == 3)
			{
				printf("\n");
				printf("-------------------------------------------------\n");
				printf("                  ���ĳɼ�����                   \n");
				printf("-------------------------------------------------\n");
				printf("    ����  ѧ ��   �� ��   �Ա�  ��ѧ  Ӣ��\n");
				int i = 0;
				int j = 0;
				for (i = 0; i < n - 1; i++)
				{
					for (j = 0; j < n - i - 1; j++)
					{
						if (stu[j].score[0] > stu[j + 1].score[0])
						{
							struct student t = stu[j];
							stu[j] = stu[j + 1];
							stu[j + 1] = t;
						}
					}
				}
				for (i = 0; i < n; i++)
				{
					printf("    %d    %d    %s     %c    %d    %d\n", stu[i].score[0], stu[i].sid, stu[i].name, stu[i].sex,  stu[i].score[1], stu[i].score[2]);
				}

			}
			else if (ind == 4)
			{
				printf("\n");
				printf("-------------------------------------------------\n");
				printf("                  ��ѧ�ɼ�����                   \n");
				printf("-------------------------------------------------\n");
				printf("    ��ѧ  ѧ ��   �� ��   �Ա�  ����  Ӣ��\n");
				int i = 0;
				int j = 0;
				for (i = 0; i < n - 1; i++)
				{
					for (j = 0; j < n - i - 1; j++)
					{
						if (stu[j].score[1] > stu[j + 1].score[1])
						{
							struct student t = stu[j];
							stu[j] = stu[j + 1];
							stu[j + 1] = t;
						}
					}
				}
				for (i = 0; i < n; i++)
				{
					printf("    %d    %d    %s     %c    %d    %d\n", stu[i].score[1], stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[2]);
				}

			}
			else if (ind == 5)
			{
			printf("\n");
			printf("-------------------------------------------------\n");
			printf("                  Ӣ��ɼ�����                   \n");
			printf("-------------------------------------------------\n");
			printf("    Ӣ��  ѧ ��   �� ��   �Ա�  ����  ��ѧ\n");
			int i = 0;
			int j = 0;
			for (i = 0; i < n - 1; i++)
			{
				for (j = 0; j < n - i - 1; j++)
				{
					if (stu[j].score[2] > stu[j + 1].score[2])
					{
						struct student t = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = t;
					}
				}
			}
			for (i = 0; i < n; i++)
			{
				printf("    %d    %d    %s     %c    %d    %d\n", stu[i].score[2], stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1]);
			}

			}
		} while (ind > 5 || ind < 1);

		getchar();
		printf("���س����������ң������������������\n");
		in = getchar();
		if (in != '\n') break;

	} while (in != '1' && in == '\n');

	
}

//��������ʱ��
void Out(char name[])
{
	FILE* date;
	int n;
	date = fopen("LOG.txt", "a+");//��־

	//�������濪ʼʱ��
	OutDate(date, name);
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
		else if (s[i] >= '0' && s[i] < '9') s[i]++;
		else if (s[i] == '9') s[i] = '0';
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