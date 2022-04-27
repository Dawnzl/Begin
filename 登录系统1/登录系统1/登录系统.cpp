#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include <string.h>

void zym();
void inpsw(char psw[]);//密码输入防窥
int isnum(char st[]);//判断是否有数字
int isalph(char st[]);//判断是否有字母
int ispsw(char st[]);//判断是否有除了数字，字母以外的字符
void readfile(struct user ux[]);//将文件中用户名和密码输出到程序中
void textprint(struct user us[]);//测试输出
int yhmky(char name[], struct user ux[]);//验证用户名是否可用
void yhm();//用户名页面
void add(char name[], char psw[], struct user ux[]);//
void zccg();

struct user
{
	char name[20];//用户名
	char password[7];//密码6位，第七位'\0'，组成字符串
};

/*
1.用户名和密码注册成功后给出提示并返回主界面
2.用户名和密码登录成功后显示子界面：
**********************
登录成功，请选择：
1---
2---
**********************

3.密码修改成功后给出提示并返回主界面
4.用文件存放用户名和密码
5.定义结构类型表示用户信息
6.各个功能用函数实现
7.自由选做功能：
用户管理（删除用户，只有admin有该权限）
密码加密和解密
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
				if (yhmky(name, us) != 1) printf("用户名已存在，请重新输入\n");
				else {
					printf("用户名可用，请设置密码（密码必须6位，由字母和数字组成,不得出现特殊符号）\n");
					break;
				}
			} while (1);//重新输入用户名

			do {
				printf("输入密码：");
				inpsw(psw);//密码防窥
				if (isnum(psw) && isalph(psw) && ispsw(psw)) {
					printf("\n密码设置成功\n");
					break;
				}
				else printf("\n密码不规范\n");
			} while (1);
			add(name, psw, us);//还未成功将文件中的n更改，要定位
			zccg();
		}
	} while (sr != 5);






	

	readfile(us);
	textprint(us);



	return 0;
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

int yhmky(char name[],struct user ux[])
{
	FILE* f1;
	int i, n,f=1;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < 2*n; i++) {
		fscanf(f1, "%s", ux[i].name);//将文件中用户名和密码输出到程序中
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

void add(char name[],char psw[],struct user ux[])//将注册的用户名和密码输入到文件中
{
	FILE* f1;
	f1 = fopen("user.txt", "a");
	fprintf(f1,"%s %s\n", name, psw);//将键盘输入的读入文件
	fclose(f1);
}


void textprint(struct user us[])
{
	int i;
	for (i = 0; i < 4; i++) {
		printf("%s %s\n", us[i].name, us[i].password);
	}

}

void readfile(struct user ux[])//将文件中用户名和密码输出到程序中
{
	FILE* f1;
	int i, n;
	f1 = fopen("user.txt", "r");
	fscanf(f1, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f1, "%s%s", ux[i].name, ux[i].password);//将文件中用户名和密码输出到程序中
	}
	fclose(f1);
}


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