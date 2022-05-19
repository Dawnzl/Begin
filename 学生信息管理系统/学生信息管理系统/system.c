#define _CRT_SECURE_NO_WARNINGS 1
#include"system2.h"

void menu()
{
	printf("=============================================\n");
	printf("                 学生信息管理系统            \n");
	printf("=============================================\n");
}
//登录页面
void Loginp(struct user us[])
{
	char name[20];
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
		if (strcmp(psw, verpsw) == 0) {
			break;
		}
		else printf("密码错误，请重新输入\n");
	} while (1);
	FILE* date;
	int n;
	date = fopen("LOG.txt", "a+");//日志
	WriteDate(date, us);
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
void WriteDate(FILE* date, struct user us[])
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(date, "管理员%s于", us->name);//管理员名字
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
void OutDate(FILE* date, struct user us[])
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(date, "管理员%s于", us->name);//管理员名字
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

	int inp;

	do
	{
		scanf("%d", &inp);
		printf("\n");
		if (inp == 1)
		{
			char in;
			struct  student stu[100]; //学生类型
			do
			{
				printf("你选择了从键盘输入数据\n");
				printf("请输入学生的人数：");
				int num;
				scanf("%d", &num);

				printf("请按照 学号 姓名 性别 语文 数学 英语的顺序输入每个学生的信息\n");
				int i = 0;
				for (i = 0; i < num; i++)
				{
					printf("请输入：");
					scanf("%d %s %c %d %d %d", stu->sid, stu->name, stu->sex, stu->score[0], stu->score[1], stu->score[2]);
				}

				printf("创建成功！\n");
				printf("按回车键继续输入，按任意键返回主界面\n");
				getchar();
				in = getchar();

			} while (in == '\n');
		
		}
		else if (inp == 2)
		{
			printf("你选择了从文件读取数据\n");
		}
		else printf("输入有误，请重新输入\n");


	} while (inp != 1 || inp != 2);


}

//增加学生信息
void add()
{

}
//浏览学生信息
void look()
{

}
//修改学生信息
void revise()
{

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
				int num;//学号
				printf("\n你选择了按照学号查找，请继续\n");
				printf("请输入学生的学号：");
				scanf("%d", &num);

				//搜索（未完成）


				printf("按回车键继续输入，按任意键返回主界面\n");
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
				printf("\n你选择了按照姓名查找，请继续\n");
				printf("请输入学生的学号：");
				scanf("%s", name);

				//搜索（未完成）


				printf("按回车键继续输入，按任意键返回主界面\n");
				getchar();
				in = getchar();

			} while (in == '\n');



		}
		else printf("输入有误，请重新输入\n");


	} while (inp != 1 || inp != 2);
}
//删除学生信息
void del()
{

}
//输入课程名称分析成绩
void analyse()
{

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
	printf("请输入选项（1--2）：");
}

//排序(学号、姓名、成绩等)
void sort()
{
	SortMenu();

}

//结束保存时间
void Out(struct user us[])
{
	FILE* date;
	int n;
	date = fopen("LOG.txt", "a+");//日志

	//用链表保存开始时间
	OutDate(date, us);
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
		else if (s[i] >= 0 && s[i] < 9) s[i]++;
		else if (s[i] == 9) s[i] = 0;
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