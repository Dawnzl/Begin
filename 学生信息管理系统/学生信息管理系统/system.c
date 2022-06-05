#define _CRT_SECURE_NO_WARNINGS 1
#include"system2.h"

void menu()
{
	printf("=============================================\n");
	printf("                 学生信息管理系统            \n");
	printf("=============================================\n");
}
//登录页面
void Loginp(struct user us[],char name[])
{
	char psw[7];
	char verpsw[7];
	do {
		menu();
		printf("用户名：");
		scanf("%s", name);
		if (verifyname(name, us, verpsw) != 1) break;//验证用户名及密码
		else {
			printf("用户名不存在，请重新输入\n");
		}
	} while (1);//重新输入用户名

	do {
		printf("密码：");
		inpsw(psw);//密码防窥
		printf("\n");

		//进行加密
		Convert(psw);
		//printf("%s", psw);
		if (strcmp(psw, verpsw) == 0) {
			break;
		}
		else printf("密码错误，请重新输入\n");
	} while (1);
	FILE* date;
	date = fopen("LOG.txt", "a+");//日志
	WriteDate(date, name);
	fclose(date);
	Susslogged();
}
//验证用户名
int verifyname(char name[], struct user ux[], char psw[])
{
	FILE* f1;
	int i, n, f = 1;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(f1, "%s%s", ux[i].name, ux[i].password);//将文件中用户名及密码输出到程序中
		if (strcmp(name, ux[i].name) == 0) {
			//加解密

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
//登录成功页面
void Susslogged()
{
	printf("登录成功!\n");
}

void Menu()
{
	printf("=============================================\n");
	printf("功能选项：\n");
	printf("	0---保存信息并退出\n");
	printf("	1--- 创建学生信息 2--- 增加学生信息\n");
	printf("	3--- 浏览学生信息 4--- 修改学生信息\n");
	printf("	5--- 查找学生信息 6--- 删除学生信息\n");
	printf("	7--- 输入课程名称分析成绩\n");
	printf("	8--- 排序(学号、姓名、成绩等)\n");
	printf("=============================================\n");
	printf("请输入选项（0--7）:");
}

//开始日期
void WriteDate(FILE* date, char name[])
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(date, "管理员%s于", name);//管理员名字
	fprintf(date, "%d", p->tm_year + 1900); //获取年
	fputs("\\", date);
	fprintf(date, "%d", p->tm_mon + 1); //获取月
	fputs("\\", date);
	fprintf(date, "%d", p->tm_mday); //获取日
	fputs("\\", date);
	fputs(" ", date);
	fprintf(date, "%0.2d", p->tm_hour + 8); //获取时
	fputs(":", date);
	fprintf(date, "%0.2d", p->tm_min); //获取分
	fputs(":", date);
	fprintf(date, "%0.2d", p->tm_sec); //获取秒
	fputs(" ", date);
	fputs("登录", date);
	fputs("\n", date);
}

//结束日期
void OutDate(FILE* date, char name[])
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(date, "管理员%s于", name);//管理员名字
	fprintf(date, "%d", p->tm_year + 1900); //获取年
	fputs("\\", date);
	fprintf(date, "%d", p->tm_mon + 1); //获取月
	fputs("\\", date);
	fprintf(date, "%d", p->tm_mday); //获取日
	fputs("\\", date);
	fputs(" ", date);
	fprintf(date, "%0.2d", p->tm_hour + 8); //获取时
	fputs(":", date);
	fprintf(date, "%0.2d", p->tm_min); //获取分
	fputs(":", date);
	fprintf(date, "%0.2d", p->tm_sec); //获取秒
	fputs(" ", date);
	fputs("注销", date);
	fputs("\n", date);

}

//学生信息创建页面
void MakeMenu()
{
	printf("**********学生信息的创建********** \n");
	printf("功能选项：\n");
	printf("-------------------------------------------------\n");
	printf("             1--- 从键盘输入数据信息             \n");
	printf("             2--- 从文件读取数据信息             \n");
	printf("-------------------------------------------------\n");
	printf("请输入选项（1--2）：");

}


//创建学生信息
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
				struct student stu[100]; //学生类型

					printf("你选择了从键盘输入数据\n");
					printf("请输入学生的人数：");
					int num;
					scanf("%d", &num);

					printf("请按照 学号 姓名 性别 语文 数学 英语   的顺序输入每个学生的信息\n");
					int i = 0;
					for (i = 0; i < num; i++)
					{
						printf("请输入：");
						scanf("%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
					}

					Enterf(stu, num);

					printf("创建成功！\n");
					

			}
			else if (inp == 2)
			{
				struct student stu[100]; //学生类型
				printf("你选择了从文件读取数据\n");
				printf("现将打开“Fstudent”文件并进行覆盖添加\n");
				printf("是否确定传入该文件学生信息，\n1.确定\n2.取消\n");
				int o = 0;
				printf("请选择：");
				do
				{
					scanf("%d", &o);

					if (o == 1)
					{

						int n = inFstudent(stu);//stu先存放另外文件学生的信息
						Enterf(stu, n);

						printf("创建成功！\n");
					}
					else if (o == 2) printf("取消成功\n");

					else printf("输入错误，请重新输入\n");


				} while (o < 1 || o > 2);



			}
			else printf("输入有误，请重新输入\n");


		} while (inp != 1 && inp != 2);

		printf("按回车键继续输入，按 任意键+回车 返回主界面\n");
		getchar();
		in = getchar();
		if (in != '\n') break;

	} while (in == '\n');
}

//打开F学生文件
int inFstudent(struct student stu[])
{
	FILE* f1;
	int i, n;
	f1 = fopen("Fstudent.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f1, "%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//将文件输出到程序中
	}
	fclose(f1);
	return n;
}

//录入文件
void Enterf(struct student stu[], int n)//n是自定义的
{
	FILE* f;
	int i = 0;
	f = fopen("student.txt", "w+");//覆盖原有
	fprintf(f, "%d\n", n);//传入n
	for (i = 0; i < n; i++)
	{
		fprintf(f, "%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
	fclose(f);
}

//输入尝试
void textprint(struct student stu[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}

}

//增加学生信息
void add()
{
	printf("**********学生信息的添加********** \n");
	printf("功能选项：\n");
	printf("-------------------------------------------------\n");
	printf("             1--- 从键盘输入数据信息             \n");
	printf("             2--- 从文件读取数据信息             \n");
	printf("-------------------------------------------------\n");
	printf("请输入选项（1--2）：");
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
				struct student stu[100]; //学生类型
				printf("你选择了从键盘输入数据\n");
				printf("请输入学生的人数：");
				int num;
				scanf("%d", &num);
				


				printf("请按照  学号   姓名   性别  语文  数学  英语的顺序输入每个学生的信息\n");
				int i = 0;
				int n = 0;
				for (i = 0; i < num; i++)
				{
					printf("请输入信息：");
					scanf("%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
					if (sidfine(stu[i].sid))//检查学号是否可用
					{
						printf("请继续操作\n");
					}
					else
					{
						i--;
						printf("请重新输入\n");
					}
				}

				addstd(stu, num);//添加进文件   stu里先存放了
				//textprint(stu, num);

				addread(stu, &num);//学生总数                              


				Enterf(stu, num);//
				//textprint(stu, num);


				printf("创建成功！\n");

			}

			else if (inp == 2)
			{
				struct student stu[100]; //学生类型
				printf("你选择了从文件读取数据\n");
				printf("现将打开“Astudent”文件并进行传输添加\n");
				printf("是否确定传入该文件学生信息，\n1.确定\n2.取消\n");
				int o;
				printf("请选择：");
				do
				{
					scanf("%d", &o);

					if (o == 1)
					{
						//要先把原文件中学生信息输入到程序中
						//再把另一文件的学生输入到程序中
						//最后把程序中的传入源文件中
						int n = instudent(stu);//stu先存放另外文件学生的信息
						addstd(stu, n);//将学生的信息输入到文件中
						addread(stu, &n);//将文件中所有的学生信息输出到程序中（覆盖stu数组）

						int i = 0, j = 0;

						for (j = 0; j < n; j++)
						{
							for (i = 0; i < n; i++)
							{
								if (stu[i].sid == stu[j].sid && i != j)
								{
									printf("|%-8s|%-10s|%-8s|%-8s|%-8s|%-8s|\n", "学号", "姓名", "性别", "语文", "数学", "英语");
									printf("1|%-8d|%-10s|%-8c|%-8d|%-8d|%-8d|\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
									printf("2|%-8d|%-10s|%-8c|%-8d|%-8d|%-8d|\n", stu[j].sid, stu[j].name, stu[j].sex, stu[j].score[0], stu[j].score[1], stu[j].score[2]);
									printf("该学生学号重复，选择删1信息或2信息：\n删除1信息\n删除2信息\n");
									//f = 1;
									int d;
									printf("请选择：");
									scanf("%d", &d);
									if (d == 1)
									{
										dele(stu[i].sid, stu, &n);
										//textprint(us, n);//测试输出
										//Enterf(stu, n);
										printf("删除成功\n");
									}
									else if (d == 2)
									{
										dele(stu[j].sid, stu, &n);
										//textprint(us, n);//测试输出
										//Enterf(stu, n);
										printf("删除成功\n");
									}
								}

							}
						}

						Enterf(stu, n);//经过删除处理后再将stu录入文件中
					}
					else if (o == 2) printf("取消成功\n");

					else printf("输入错误，请重新输入");


				} while (o < 1 || o>2);

			}
			else printf("输入有误，请重新输入\n");


		} while (inp != 1 && inp != 2);

	printf("按回车键继续输入，按 任意键+回车 返回主界面\n");

	getchar();
	in = getchar();
	if (in != '\n') break;

	} while (in == '\n');
} 

int instudent(struct student stu[])//数据转移
{
	FILE* f1;
	int i, n;
	f1 = fopen("Astudent.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f1, "%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//将文件输出到程序中
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
			printf("%d该学号已有学生占用，请检查后重新操作\n", num);
			return 0;
		}
	}
	return 1;
}

void addstd(struct student stu[],int num)//将学生的信息输入到文件中
{
	FILE* f1;
	f1 = fopen("student.txt", "a");//将键盘输入的读入文件
	int i = 0;
	for (i = 0; i < num; i++)
	{
		fprintf(f1, "%d %s %c %d %d %d\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
	fclose(f1);
}

//将文件中学生信息输出到程序中//添加版
void addread(struct student stu[], int* num)//学生数据末尾下标
{
	FILE* f1;
	int i, n;
	f1 = fopen("student.txt", "r");
	fscanf(f1, "%d", &n);
	*num = n + *num;                  //程序中学生的个数   +   文件中学生的个数
	for (i = 0; i < *num; i++)
	{
		fscanf(f1, "%d %s %c %d %d %d", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//将文件中学生信息输出到程序中
	}
	fclose(f1);
}

////添加信息
//void Enterfadd(struct student stu[], int* n, int num)//n是自定义的
//{
//	FILE* f;
//	int i = 0;
//	f = fopen("student.txt", "w+");//覆盖原有
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



//浏览学生信息
void look()
{
	printf("---------------------------------------------------------\n");
	printf("                        学生信息总览                     \n");
	printf("---------------------------------------------------------\n");
	printf("|%-8s|%-10s|%-8s|%-8s|%-8s|%-8s|\n", "学号", "姓名", "性别", "语文", "数学", "英语");
	printf("|--------+----------+--------+--------+--------+--------|\n");

	struct  student stu[100]; //学生类型
	int n = readfile(stu);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("|%-8d|%-10s|%-8c|%-8d|%-8d|%-8d|\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);

		if (i < n - 1) printf("|--------+----------+--------+--------+--------+--------|\n");
	}
	printf("---------------------------------------------------------\n");

}

//将文件中学生信息输出到程序中//输出版
int readfile(struct student stu[])
{
	FILE* f1;
	int i, n;
	f1 = fopen("student.txt", "r");
	fscanf(f1, "%d", &n); 
	for (i = 0; i < n; i++) {
		fscanf(f1, "%d %s %c %d %d %d\n", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//将文件中用户名和密码输出到程序中
	}
	fclose(f1);
	return n;
}


//将文件中用户名和密码输出到程序中
//void readfile(struct student stu[])
//{
//	FILE* f1;
//	int i, n;
//	f1 = fopen("student.txt", "r");
//	fscanf(f1, "%d", &n);
//	for (i = 0; i < n; i++) {
//		fscanf(f1, "%d %s %c %d %d %d\n", &stu[i].sid, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);//将文件中用户名和密码输出到程序中
//	}
//	fclose(f1);
//}

void ReviseMenu()
{
	printf("**********学生信息的修改**********\n");

}

//修改学生信息
void revise()
{
	ReviseMenu();
	struct student stu[100];
	char in;

	printf("\n");
	printf("\n请按照学号查找\n");

	int n = readfile(stu);//把学生信息输入到程序中

	do
	{
		revisestu(stu, n);//修改成功
		printf("按回车键继续修改，按 任意键+回车 返回主界面\n");
		getchar();
		in = getchar();
	} while (in == '\n');



	Enterf(stu, n);//录入修改信息	

}

void revisestu(struct student stu[], int n)
{
	int i = 0;
	int f = 1;
	int num;//学号

	do
	{
		printf("请输入学生的学号：");
		scanf("%d", &num);

		for (i = 0; i < n; i++)
		{

			if (num == stu[i].sid)
			{
				printf("学生信息：|学号:%-8d|姓名:%-10s|性别:%-8c|语文:%-8d|英语:%-8d|数学:%-8d|\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				//textprint(stu, n);
				printf("请选择修改项目：姓名（1），性别（2），语文成绩（3），数学成绩（4），英语成绩（5）");
				int input = 0;

				do
				{
					printf("请选择：");
					scanf("%d", &input);
					if (input == 1)
					{
						printf("将姓名“%s”修改成：", stu[i].name);
						char name[20];
						scanf("%s", name);
						strcpy(stu[i].name, name);
					}

					else if (input == 2)
					{
						getchar();//消除回车
						printf("将性别“%c”修改成：", stu[i].sex);
						char sex;
						scanf("%c", &sex);
						stu[i].sex = sex;
					}

					else if (input == 3)
					{
						printf("将语文成绩“%d”修改成：", stu[i].score[0]);
						int sco;
						scanf("%d", &sco);
						stu[i].score[0] = sco;
					}

					else if (input == 4)
					{
						printf("将数学成绩“%d”修改成：", stu[i].score[1]);
						int sco;
						scanf("%d", &sco);
						stu[i].score[1] = sco;
					}

					else if (input == 5)
					{
						printf("将英语成绩“%d”修改成：", stu[i].score[2]);
						int sco;
						scanf("%d", &sco);
						stu[i].score[2] = sco;
					}
					else printf("输入错误，请重新输入\n");

				} while (input < 1 || input > 5);

				f = 0;
				printf("修改成功！\n");
				printf("修改后的信息：|%-8d|%-10s|%-8c|%-8d|%-8d|%-8d|\n\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);

				break;
			}
		}
		if (f) printf("未找到此学生信息，请重新输入\n");

	} while (f);

}



void FineMenu()
{
	printf("**********学生信息的查找**********\n");
	printf("功能选项：\n");
	printf("-------------------------------------------------\n");
	printf("                1--- 按照学号查找                \n");
	printf("                2--- 按照姓名查找                \n");
	printf("-------------------------------------------------\n");
	printf("请输入选项（1--2）：");

}

//查找学生信息
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

				printf("\n你选择了按照学号查找，请继续\n");
				printf("请输入学生的学号：");

				int n = readfile(stu);//把学生信息输入到程序中

				finestunum(stu, n);

			}
			else if (inp == 2)
			{

				char name[20];
				printf("\n你选择了按照姓名查找，请继续\n");
				printf("请输入学生的姓名：");

				int n = readfile(stu);//把学生信息输入到程序中

				finestuname(stu, n);

			}
			else printf("输入有误，请重新输入\n");


		} while (inp < 1 || inp > 2);

		printf("按回车键继续查找，按 任意键+回车 返回主界面\n");

		getchar();
		in = getchar();
		if (in != '\n') break;

	} while ( in == '\n');

}

void finestunum(struct student stu[],int n)
{
	int i = 0;
	int f = 1;
	int num;//学号

	do
	{
		scanf("%d", &num);
		for (i = 0; i < n; i++)
		{

			if (num == stu[i].sid)
			{
				printf("学生信息：|%-8d|%-10s|%-8c|%-8d|%-8d|%-8d|\n\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				f = 0;
				break;
			}
		}
		if(f) printf("未找到此学生信息，请重新输入\n");

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
				printf("\n学生信息：|%-8d|%-10s|%-8c|%-8d|%-8d|%-8d|\n\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				f = 0;
				break;
			}
		}
		if (f) printf("未找到此学生信息，请重新输入:");

	} while (f);



}


//删除学生信息
void del()
{
	printf("**********学生信息的删除********** \n");
	struct student stu[100];
	int n = readfile(stu);
	int sid = 0;//学号
	int f = 1;//判断是否需要重新输入学号
	char in;
	do
	{
		do {
			printf("输入需要删学生的学号：");
			scanf("%d", &sid);
			int i = 0;
			for (i = 0; i < n; i++)
			{
				if (stu[i].sid == sid)
				{
					printf("该学生信息：\n");
					printf("|%-8s|%-10s|%-8s|%-8s|%-8s|%-8s|\n", "学号", "姓名", "性别", "语文", "数学", "英语");
					printf("|%-8d|%-10s|%-8c|%-8d|%-8d|%-8d|\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
					printf("该学生信息存在，是否选择删除\n1.确定\n2.取消\n");
					f = 0;
					break;
				}

			}
			if (f)
			{
				printf("该学生信息不存在，请重新输入\n");
			}


		} while (f);//f未改变重新输入学号
		int d;
		printf("请选择：");
		scanf("%d", &d);
		if (d == 1)
		{
			dele(sid, stu, &n);
			//textprint(us, n);//测试输出
			Enterf(stu, n);
			printf("删除成功\n");
		}
		else if (d == 2) printf("取消成功\n");

		printf("按回车键继续删除，按 任意键+回车 返回主界面\n");

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
	f = fopen("delstudent.txt", "a");//添加
	fprintf(f, "%d %s %c %d %d %d\n", T.sid, T.name, T.sex, T.score[0], T.score[1], T.score[2]);
	fclose(f);
}
//输入课程名称分析成绩
//输入课程名称，显示该课程的最高分、最低分、平均分、不及格人数
void analyse()
{
	printf("***********课程 分析*********** \n");
	struct student stu[100];
	int n = readfile(stu);
	int score = 0;//课程代号
	int cj[4];
	char in;
	do
	{
		do {
			printf("输入需要分析的课程  语文（1）数学（2）英语（3）：");
			scanf("%d", &score);
			if (score == 1)
			{
				printf("语文成绩分析：\n");
				analcj(stu, n, cj, 0);
				printf("该班语文最高分：%d分，由%s同学考取\n", stu[cj[0]].score[0], stu[cj[0]].name);
				printf("该班语文最低分：%d分\n", stu[cj[1]].score[0]);
				printf("该班语文平均分：%d分\n", cj[2]);
				printf("该班语文低于60分的不及格人数有%d人\n", cj[3]);

			}
			else if (score == 2)
			{
				printf("数学成绩分析：\n");
				analcj(stu, n, cj, 1);
				printf("该班数学最高分：%d分，由%s同学考取\n", stu[cj[0]].score[1], stu[cj[0]].name);
				printf("该班数学最低分：%d分\n", stu[cj[1]].score[1]);
				printf("该班数学平均分：%d分\n", cj[2]);
				printf("该班数学低于60分的不及格人数有%d人\n", cj[3]);

			}
			else if (score == 3)
			{
				printf("英语成绩分析：\n");
				analcj(stu, n, cj, 2);
				printf("该班英语最高分：%d分，由%s同学考取\n", stu[cj[0]].score[2], stu[cj[0]].name);
				printf("该班英语最低分：%d分\n", stu[cj[1]].score[2]);
				printf("该班英语平均分：%d分\n", cj[2]);
				printf("该班英语低于60分的不及格人数有%d人\n", cj[3]);
			}
			else printf("输入错误，请重新输入\n");

		} while (score<1||score>3);

		printf("按回车键继续分析，按 任意键+回车 返回主界面\n");

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
			cj[1] = i;//min最小值的下标
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
	printf("**********学生信息的排序**********\n");
	printf("功能选项：\n");
	printf("-------------------------------------------------\n");
	printf("                1--- 按照学号排序                \n");
	printf("                2--- 按照姓名排序                \n");
	printf("              3--- 按照语文成绩排序              \n");
	printf("              4--- 按照数学成绩排序              \n");
	printf("              5--- 按照英语成绩排序              \n");
	printf("-------------------------------------------------\n");
}

//排序(学号、姓名、成绩等)
void sort()
{
	SortMenu();
	int ind = 0;
	char in;
	struct student stu[100];
	int n = readfile(stu);//把学生信息输入到程序中

	do
	{
		do
		{
			printf("请输入选项（1--5）：");
			scanf("%d", &ind);
			if (ind == 1)
			{
				printf("\n");
				printf("-------------------------------------------------\n");
				printf("                  学生学号排序                   \n");
				printf("-------------------------------------------------\n");
				printf("|%-8s|%-10s|%-8s|%-8s|%-8s|%-8s|\n", "学号", "姓名", "性别", "语文", "数学", "英语");
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
					printf("|%-8d|%-10s|%-8c|%-8d|%-8d|%-8d|\n", stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}
			}

			else if (ind == 2)
			{
				printf("\n");
				printf("-------------------------------------------------\n");
				printf("                  学生姓名排序                   \n");
				printf("-------------------------------------------------\n");
				printf("|%-10s|%-8s|%-8s|%-8s|%-8s|%-8s|\n", "姓名" ,"学号", "性别", "语文", "数学", "英语");
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
					printf("|%-10s|%-8d|%-8c|%-8d|%-8d|%-8d|\n",  stu[i].name, stu[i].sid, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}

			}
			else if (ind == 3)
			{
				printf("\n");
				printf("-------------------------------------------------\n");
				printf("                  语文成绩排序                   \n");
				printf("-------------------------------------------------\n");
				printf("|%-8s|%-8s|%-10s|%-8s|%-8s|%-8s|\n","语文", "学号", "姓名", "性别",  "数学", "英语");
				int i = 0;
				int j = 0;
				for (i = 0; i < n - 1; i++)
				{
					for (j = 0; j < n - i - 1; j++)
					{
						if (stu[j].score[0] < stu[j + 1].score[0])
						{
							struct student t = stu[j];
							stu[j] = stu[j + 1];
							stu[j + 1] = t;
						}
					}
				}
				for (i = 0; i < n; i++)
				{
					printf("|%-8d|%-8d|%-10s|%-8c|%-8d|%-8d|\n", stu[i].score[0], stu[i].sid, stu[i].name, stu[i].sex,  stu[i].score[1], stu[i].score[2]);
				}

			}
			else if (ind == 4)
			{
				printf("\n");
				printf("-------------------------------------------------\n");
				printf("                  数学成绩排序                   \n");
				printf("-------------------------------------------------\n");
				printf("|%-8s|%-8s|%-10s|%-8s|%-8s|%-8s|\n","数学",  "学号", "姓名", "性别","语文" , "英语");
				int i = 0;
				int j = 0;
				for (i = 0; i < n - 1; i++)
				{
					for (j = 0; j < n - i - 1; j++)
					{
						if (stu[j].score[1] < stu[j + 1].score[1])
						{
							struct student t = stu[j];
							stu[j] = stu[j + 1];
							stu[j + 1] = t;
						}
					}
				}
				for (i = 0; i < n; i++)
				{
					printf("|%-8d|%-8d|%-10s|%-8c|%-8d|%-8d|\n", stu[i].score[1], stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[2]);
				}

			}
			else if (ind == 5)
			{
			printf("\n");
			printf("-------------------------------------------------\n");
			printf("                  英语成绩排序                   \n");
			printf("-------------------------------------------------\n");
			printf("|%-8s|%-8s|%-10s|%-8s|%-8s|%-8s|\n","英语" , "学号", "姓名", "性别", "语文","数学" );
			int i = 0;
			int j = 0;
			for (i = 0; i < n - 1; i++)
			{
				for (j = 0; j < n - i - 1; j++)
				{
					if (stu[j].score[2] < stu[j + 1].score[2])
					{
						struct student t = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = t;
					}
				}
			}
			for (i = 0; i < n; i++)
			{
				printf("|%-8d|%-8d|%-10s|%-8c|%-8d|%-8d|\n", stu[i].score[2], stu[i].sid, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1]);
			}

			}
		} while (ind > 5 || ind < 1);

		getchar();
		printf("按回车键继续查找，按 任意键+回车 返回主界面\n");
		in = getchar();
		if (in != '\n') break;

	} while (in != '1' && in == '\n');

	
}

//结束保存时间
void Out(char name[])
{
	FILE* date;
	int n;
	date = fopen("LOG.txt", "a+");//日志

	//用链表保存开始时间
	OutDate(date, name);
	fclose(date);

}

//密码篇
void inpsw(char psw[])//密码输入防窥
{
	int i;
	for (i = 0; i < 6; i++)
	{
		psw[i] = _getch();
		psw[6] = '\0';
		putchar('*');

	}
}

int isnum(char st[])//判断是否有数字
{
	int i;
	for (i = 0; i < 6; i++)
		if (st[i] >= '0' && st[i] <= '9') return 1;
	return 0;
}

int isalph(char st[])//判断是否有字母
{
	int i;
	for (i = 0; i < 6; i++)
		if (st[i] >= 'a' && st[i] <= 'z') return 1;
		else if (st[i] >= 'A' && st[i] <= 'Z') return 1;
	return 0;
}

int ispsw(char st[])//判断是否有除了数字，字母以外的字符
{
	int i;
	for (i = 0; i < 6; i++)
		if (st[i] >= '0' && st[i] <= '9') continue;
		else if (st[i] >= 'a' && st[i] <= 'z') continue;
		else if (st[i] >= 'A' && st[i] <= 'Z') continue;
		else return 0;
	return 1;
}

//凯撒加密
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
//解密
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



void printStdent(struct student s)
{
	printf("|%-8d|%-10s|%-8c|%-8d|%-8d|%-8d|\n", s.sid, s.name, s.sex, s.score[0], s.score[1], s.score[2]);
}

void fprintStudent(FILE* fp, struct student s)
{
	fprintf(fp, "%d %s %c %d %d %d\n", s.sid, s.name, s.sex, s.score[0], s.score[1], s.score[2]);
}

void printList(struct stnode* p)
{
	if (p != NULL)
	{
		printStdent(p->data);//输出学生信息
		printList(p->next);
	}
}

void fprintList(FILE* fp, struct stnode* p)
{
	if (p != NULL)
	{
		fprintStudent(fp, p->data);
		fprintList(fp, p->next);
	}
}

struct stnode** selectNodeBySid(struct stnode** phead, int sid) //查找学生学号为sid的节点
{
	struct stnode* head = *phead;
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		if (sid == head->data.sid)
		{
			return phead;
		}
		else
		{
			return selectNodeBySid(&head->next, sid);
		}
	}
}

void deleteNode(struct stnode** pp) //删除*pp指向的节点
{
	struct stnode* head = *pp;
	*pp = head->next;
	free(head);
}

struct stnode* makeListByFile(FILE* fp, int n) //从文件读入n个数据并存入链表，返回链表头节点的地址
{
	if (n == 0)
	{
		return NULL;
	}
	else
	{
		struct stnode* p = (struct stnode*)malloc(sizeof(struct stnode)); //开辟空间
		fscanf(fp, "%d %s %c %d %d %d", &p->data.sid, p->data.name, &p->data.sex, &p->data.score[0], &p->data.score[1], &p->data.score[2]);
		p->next = makeListByFile(fp, n - 1);
		return p;
	}
}

void saveData(struct stnode* p, int* n)
{
	FILE* fp = fopen("student.txt", "w+"); //打开文件获得fp指针
	fprintf(fp, "%d\n", *n);//把n输入进文件里
	fprintList(fp, p);//把链表里的学生数据填入文件中
	fclose(fp);
}

void deleteMenu()
{
	printf("**********学生信息的删除（链表）********** \n");

	FILE* fp = fopen("student.txt", "r"); //打开文件获得fp指针
	int n;
	fscanf(fp, "%d", &n);						 //将文件中的个数读取
	struct stnode* head = makeListByFile(fp, n); //设置一个头指针链接链表，链表从文件中输入数据
	printf("|%-8s|%-10s|%-8s|%-8s|%-8s|%-8s|\n", "学号", "姓名", "性别", "语文", "数学", "英语");
	printList(head);
	fclose(fp);

	do
	{
		struct stnode** pp = NULL;//移动头指针的指针
		while (pp == NULL)//如果搜索不到重新输入
		{
			printf("输入需要删学生的学号：");
			int sid;
			scanf("%d", &sid);
			pp = selectNodeBySid(&head, sid);//将头指针的地址传入用pp接受这个地址
			if (pp == NULL)//如果返回NULL说明不存在
			{
				printf("该学生信息不存在，请重新输入\n");
			}
		}

		printf("该学生信息：\n");
		printf("|%-8s|%-10s|%-8s|%-8s|%-8s|%-8s|\n", "学号", "姓名", "性别", "语文", "数学", "英语");
		printStdent((*pp)->data);//将pp指的地址解引用得到的结构就是说查找学生信息

		printf("请选择是否选择删除\n1.确定\n2.取消\n");
		getchar();
		char in = getchar();
		if (in == '1')
		{
			n--;//删除成功 
			deleteNode(pp);
			printList(head);
			saveData(head, &n);
		}
		else
		{
			printf("已取消\n");
		}

		printf("按回车键继续删除，按 任意键+回车 返回主界面\n");
		getchar();
	} while (getchar() == '\n');
}



