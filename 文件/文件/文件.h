#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	/*
	һ���ı��ļ�����ж��ֻ�����ľ��Ӣ�����ƣ�һ��һ�У���д������ɣ�
	��ȡ���ļ�����
	��д������Ӣ���ֵ�˳������
	��д���Һ���������һ�ֻ�ľ��Ӣ�����ƣ������Ƿ���ڸñ��С�
	*/
	FILE* f;
	int i=0;
	f = fopen("name.txt", "r+");
	char name[100][100];
	while (!feof(f))
	{
		fscanf(f, "%s", name[i++]);//���ļ����û��������������������
		
	}
	while (i--) printf("%s", name[i]);
	return 0;
}