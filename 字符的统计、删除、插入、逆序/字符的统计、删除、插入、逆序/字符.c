#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>

void shuru(char* str);
int NUM(char* str); // 单词个数
void Delete(char str[]); //删除相同字符
void Delete2(char* str);//指针型
void Insert(char str[]);
void Insert2(char* str);
void reverse(char* str); // 逆序字符串指针型
void reverse2(char str[]);//逆序字符串数组型

int main()
{
	char str[100];
	shuru(str);
	int l = 0;
	int r = strlen(str)-1;

	printf("单词个数=%d\n", NUM(str));
	reverse(str);
	printf("指针型逆序：%s\n", str);
	reverse2(str,l,r);
	printf("数组型逆序：%s\n", str);
	Insert2(str);
	Delete2(str);
	printf("删除相同字符过后：%s\n", str);
	return 0;
}


void shuru(char* str) 
{

	int n = 0;
	while ((*(str + n) = getchar()) != '\n') {
		n++;
	}
	*(str + n) = '\0';
}

int NUM(char* str)//单词个数
{

	int i = 0, num = 0;
	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (i == 0 && (*(str + i) >= 'a' && *(str + i) <= 'z') || (*(str + i) >= 'A' && *(str + i) <= 'Z')) num++;
		else if (*(str + i) == ' ' && ((*(str + i + 1) >= 'a' && *(str + i + 1) <= 'z') || (*(str + i + 1) >= 'A' && *(str + i + 1) <= 'Z')))
		{
			num++;
		}
	}
	return num;
}

void Delete(char str[]) //删除相同字符  数组型
{
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		int c = i + 1, j = i + 1;
		while (str[j] != '\0') {
			if (str[j] != str[i]) {
				str[c++] = str[j++];
			}
			else {
				j++;
			}
		}
		str[c] = '\0';
	}
}

void Delete2(char* str) //删除相同字符  指针型
{
	char* ps = str;
	int i;
	for (i = 0; *(ps+i) != '\0'; i++) {
		int c = i + 1, j = i + 1;
		while (*(ps + j) != '\0') {
			if (*(ps + j) != *(ps + i)) {
				*(ps + c) = *(ps + j);
				c++;
				j++;
			}
			else {
				j++;
			}
		}
		str[c] = '\0';
	}

}

void Insert(char *str)
{
	int i=0,j=0,k;
		char t[200];
		for (i=j,k=0 ; *(str + i) != '\0'; i++)
		{
			if (*(str+i) != ' ')
			{
				*(t + (k++)) = *(str + i);
				*(t + (k++)) = ' ';
			}

		}
		*(t + k) = '\0';
		printf("%s", t);
	

}

void Insert2(char str[])
{
	int i = 0, j = 0, k;
	char t[200];
	for (i = j, k = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ') 
		{
			t[k++] = str[i];
			t [k++] = ' ';
		}

	}
	t[k] = '\0';
	printf("插入空格后=%s\n", t);

}

void reverse(char* str)//逆序字符串指针型
{
	char tmp = *str;
	int len = strlen(str);
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (strlen(str + 1) >= 2)
		reverse(str + 1);
	*(str + len - 1) = tmp;
}



void reverse2(char str[])//逆序字符串数组型
{
	int i;
	int s = strlen(str);
	for (i = 0; i <  s / 2; i++)
	{
		char tmp = str[i];
		str[i] = str[s-1-i];
		str[s-1-i] = tmp;
	}

}