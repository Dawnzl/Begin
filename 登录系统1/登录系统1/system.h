#pragma once

#include<stdio.h>
#include<conio.h>
#include <string.h>

void Register(struct user us[]);
void Loginp(struct user us[]);
void Changepassword(struct user us[]);
void ADLoginp(struct user us[]);

void zym();//主页面
void yhm();//用户名页面
void zccg();//注册成功界面
void logins();//登录界面

void inpsw(char psw[]);//密码输入防窥
int isnum(char st[]);//判断是否有数字
int isalph(char st[]);//判断是否有字母
int ispsw(char st[]);//判断是否有除了数字，字母以外的字符

void readfile(struct user ux[], int* n);//将文件中用户名、密码以、用户个数输出到程序中
int yhmky(char name[], struct user ux[]);//验证用户名是否可用
int admanyz(char name[], struct user ux[], char psw[]);//管理员验证
void add(char name[], char psw[], struct user ux[]);//添加新用户进文件中

void intof(struct user ux[], int* n);//将文件中用户名、密码以、用户个数输出到程序中，并且用户个数加一
void Enterf(struct user ux[], int n);//将程序中用户名、密码以、用户个数输入到文件中
int verifyname(char name[], struct user ux[], char psw[]);//验证用户名，将文件中用户名及密码输出到程序中
void revise(char name[], struct user us[], char newpsw[], int n);//修改密码

void Admin(struct user us[]);
void ADman(char name[]);//管理员子页面
void dele(char name[], struct user us[], int* N);//删除用户

void textprint(struct user us[], int n);//测试输出

struct user
{
	char name[20];//用户名
	char password[7];//密码6位，第七位'\0'，组成字符串
};

void game();