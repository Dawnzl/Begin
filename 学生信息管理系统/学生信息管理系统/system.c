#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"

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


//学生信息创建页面
void MakeMenu()
{
	printf("**********学生信息的创建********** \n");
	printf("功能选项：\n");
	printf("-------------------------------------------------\n");
	printf("             1--- 从键盘输入数据信息             \n");
	printf("             2--- 从文件读取数据信息             \n");
	printf("-------------------------------------------------\n");
	printf("请输入选项（1--2）：\n");
	printf("\n");
		
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
					//scanf("%s %s %c %d %d %d", );//未完成
				}

				printf("创建成功！\n");
				printf("按回车键继续输入，按任意键返回主界面\n");

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
//查找学生信息
void fine()
{

}
//删除学生信息
void del()
{

}
//输入课程名称分析成绩
void analyse()
{

}
//排序(学号、姓名、成绩等)
void sort()
{

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