#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	/*
	一个文本文件里存有多种花草树木的英文名称，一个一行，编写程序完成：
	读取该文件内容
	编写函数按英文字典顺序排序
	编写查找函数，输入一种花木的英文名称，查找是否存在该表中。
	*/
	FILE* f;
	int i=0;
	f = fopen("name.txt", "r+");
	char name[100][100];
	while (!feof(f))
	{
		fscanf(f, "%s", name[i++]);//将文件中用户名和密码输出到程序中
		
	}
	while (i--) printf("%s", name[i]);
	return 0;
}