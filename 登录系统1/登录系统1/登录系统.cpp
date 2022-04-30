#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"

int main()
{
	struct user us[10];
	int sr;

	do {
		zym();
		printf("请选择：");
		scanf("%d", &sr);

		if (sr == 1) {
			Register(us);//注册程序
		}

		else if (sr == 2)
		{
			Loginp(us);//登录程序

		}

		else if (sr == 3)
		{
			Changepassword(us);//修改密码程序
		}

		else if (sr == 4)
		{
			ADLoginp(us);//管理员登录程序
		}
	} while (sr != 5);
	printf("\n感谢使用本系统！\n");

	return 0;
}

void Register(struct user us[])
{
	yhm();
	char name[20];
	char psw[7];
//输入用户名
	do {
		scanf("%s", name);
		if (yhmky(name, us) != 1) printf("用户名已存在，请重新输入\n");
		else {
			printf("用户名可用，请设置密码（密码必须6位，由字母和数字组成,不得出现特殊符号）\n");
			break;
		}
	} while (1);//重新输入用户名
//输入密码
	do {
		printf("输入密码：");
		inpsw(psw);//密码防窥
		if (isnum(psw) && isalph(psw) && ispsw(psw)) {
			printf("\n密码设置成功\n");
			break;
		}
		else printf("\n密码不规范\n");
	} while (1);

	add(name, psw, us);//添加新用户进文件中
	int n;
	intof(us, &n);//将文件中用户名、密码以、用户个数输出到程序中，并且用户个数加一
	Enterf(us, n);//程序数组录入文件
	zccg();//注册成功
}

void Loginp(struct user us[])
{
		char name[20];
		char psw[7];
		char verpsw[7];
		do {
			yhm();
			scanf("%s", name);
			if (verifyname(name, us,verpsw) != 1) break;//验证用户名及密码
			else {
				printf("用户名不存在，请重新输入\n");
			}
		} while (1);//重新输入用户名

		do {
			printf("输入密码：");
			inpsw(psw);//密码防窥
			printf("\n");
			if (strcmp(psw, verpsw) == 0) {
				printf("——————————————————————\n");
				break;
			}
			else printf("密码错误，请重新输入\n");
		} while (1);
		logins();//登录成功界面
		int tt;//登录子页面功能
		do {
			printf("请选择：");
			scanf("%d", &tt);
			if (tt == 1) {
				Changepassword(us);//修改密码程序
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
			printf("用户名不存在，请重新输入\n");
		}
	} while (1);//重新输入用户名

	do {
		printf("输入密码：");
		inpsw(psw);//密码防窥
		printf("\n");
		if (strcmp(psw, verpsw) == 0) {
			printf("——————————————————————\n");
			break;
		}
		else printf("密码错误，请重新输入\n");
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
		if (verifyname(name, us, verpsw) != 1) break;//同样先验证文件中是否有这个用户
		else {
			printf("用户名不存在，请重新输入\n");
		}
	} while (1);//重新输入用户名
	do {
		printf("输入原密码：");
		inpsw(psw);//密码防窥
		printf("\n");
		if (strcmp(psw, verpsw) == 0) {
			break;
		}
		else printf("原密码错误，请重新输入\n");
	} while (1);
	do {
		printf("输入新密码：");
		inpsw(newpsw);//密码防窥
		printf("\n");
		printf("再次输入新密码：");
		inpsw(newpswt);
		printf("\n");
		if (strcmp(newpsw, newpswt) == 0) {
			break;
		}
		else printf("两次输入的新密码不同，请重新输入\n");
	} while (1);
	int n;
	readfile(us, &n);//将文件中用户名、密码以、用户个数输出到程序中

	revise(name, us, newpsw, n);//修改密码
	Enterf(us, n);//将程序中用户名、密码以、用户个数输入到文件中
	printf("密码修改成功\n");
	printf("——————————————————————\n");
}






void zym()
{
	printf("——————————————————————\n");
	printf("1.注册新用户\n2.登录已有账户\n3.修改账户密码\n4.管理员登录\n5.退出\n");
	printf("——————————————————————\n");
}
void yhm() 
{
	printf("——————————————————————\n");
	printf("请输入用户名 :>");
}
void zccg()
{
	printf("注册成功!\n");
	printf("——————————————————————\n");
}
void logins()
{
	printf("**********************\n"); 
	printf("登录成功，请选择：\n"); 
	printf("1-- 修改密码\n"); 
	printf("2-- 玩井字棋\n"); 
	printf("**********************\n");
}
void ADman(char name[])
{
	printf("**********************\n");
	printf("欢迎管理员:%s\n",name);
	printf("**********************\n");
}

void Admin(struct user us[])
{
	int n;
	readfile(us, &n);//将文件中用户名和密码输出到程序中
	char name[20];
	char psw[7];

	do {
		printf("输入需要删除用户的用户名：");
		scanf("%s", name);
		if (yhmky(name, us) != 1)
		{
			printf("用户名存在，是否选择删除\n1.确定\n2.取消\n");
			break;
		}
		else {
			printf("用户名不存在，请重新输入\n");
		}
	} while (1);//重新输入用户名
	int d;
	printf("请选择：");
	scanf("%d", &d);
	if (d == 1)
	{
		dele(name, us, &n);
		//textprint(us, n);//测试输出
		Enterf(us, n);
		printf("删除成功\n");
	}
	else if (d == 2) printf("取消成功");
}


int verifyname(char name[], struct user ux[], char psw[])//验证用户名
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

int yhmky(char name[],struct user ux[])
{
	FILE* f1;
	int i, n,f=1;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f1, "%s%s", ux[i].name,ux[i].password);//将文件中用户名输出到程序中
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

int admanyz(char name[], struct user ux[], char psw[])//验证用户名
{
	FILE* f1;
	int i, n, f = 1;
	f1 = fopen("admin.txt", "r");//打开管理员文件
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

void add(char name[],char psw[],struct user ux[])//将注册的用户名和密码输入到文件中
{
	FILE* f1;
	f1 = fopen("user.txt", "a");
	fprintf(f1,"%s %s\n", name, psw);//将键盘输入的读入文件
	fclose(f1);
}

void intof(struct user ux[],int *n)//输出文件到程序的结构数组里
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
		fscanf(f, "%s%s", ux[i].name, ux[i].password);//将文件中用户名和密码输出到程序中
	}
	fclose(f);
}

void Enterf(struct user ux[], int n)//录入文件
{
	FILE* f;
	int i = 0 ;
	f = fopen("user.txt", "w+");
	fprintf(f, "%d\n", n);
	for (i = 0; i < n; i++)
	{
		fprintf(f, "%s %s\n", ux[i].name, ux[i].password);//将文件中用户名和密码输出到程序中
	}
	fclose(f);
}


void textprint(struct user us[], int n)//输入尝试
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%s %s\n", us[i].name, us[i].password);
	}

}

void readfile(struct user ux[],int *n)//将文件中用户名和密码输出到程序中
{
	FILE* f1;
	int i;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", n);
	for (i = 0; i < *n; i++) {
		fscanf(f1, "%s%s", ux[i].name, ux[i].password);//将文件中用户名和密码输出到程序中
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