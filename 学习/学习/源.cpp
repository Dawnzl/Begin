//#include<stdio.h>
//int main()
//{
//	int a = 0;//Ҫ���ڱ��ϳ�ʼ�������ĺ�ϰ��
//	a++;
//	printf("%d", a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	float b = 0.0f;//0.0Ĭ��Ϊdouble�ͣ��ں�Ӹ�fתΪfloat��
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;//-4,-1.2.
//	}
//	printf("%d\n", a);
//	return 0;
//}

/*1-100��9�ĸ���*/
//#include<stdio.h>
//int main()
//{
//	int a,ret=0,t;
//	for (a = 1; a <= 100; a++) {
//		int i = a;//ʹ��forѭ��ʱ����ѭ������a����ֱ�Ӳ���������������¶���a=1�������������Ҫһ�������н�aֵ
//		while (i > 0) {
//			t = i % 10;
//			i = i / 10;
//			if (t == 9) {
//				ret++;
//			}
//		}
//	}
//	printf("1-100�к�9�ĸ���%d", ret);
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//	int a = 0, i = 1, v = -1;
//	float sum = 1.0;
//	for (i = 2; i <= 100; i++) {
//		float t = v * 1.0 / i;
//		sum += t;
//		v *= -1;
//	}
//	printf("%f", sum);
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//	int a[10],i;
//	for (i = 0; i < 10; i++) {
//		scanf_s("%d", &a[i]);
//	}
//	int max = a[0],j;
//	for (j = 0; j < 10; j++)
//		max = (max < a[j]) ? a[j] : max;
//	printf("%d", max);
//	return 0;
//}

/*windowsͷ�ļ�*/
//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "welcome to bit!!!!";
//	char arr2[] = "##################";
//
//	int left = 0;
//	int right = strlen(arr2) - 1;
//
//	while (left <= right) {
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		//�����Ļ
//		system("cls");//ststem��һ���⺯��������ִ��ϵͳ����
//		left++;
//		right--;
//	}
//	printf("%s", arr2);
//	return 0;
//}

/**/
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char password[20]={0};
//	scanf("%s", password);
//	if (strcmp(password, "abcdef") == 0) {
//		//����Աȣ����Ϊ0
//	}
//	return 0;
//}

//#include <stdio.h>
//int  fun(int* p, int  n, int  x);
//int main()
//{
//	int  a[10] = { 1,2,3,4,5,6,7,8,9,10 }, x, k;
//	scanf_s("%d", &x);
//	k = fun(a, 10, x);
//	if (k >= 0)  printf("%d\n", k);
//	else  printf("no\n");
//	return 0;
//}
//int  fun(int* p, int  n, int  x) {
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		if (*(p + i) == x) return i;
//		
//	}
//	return -1;
//}

////����������n�����ɶ�̬���飬����������ݡ�
//#include <stdio.h>
//#include <malloc.h>
//int* getarray(int n);
//int main()
//{
//    int* a = NULL, n, i;
//    scanf_s("%d", &n);
//    if (n <= 0) return 0;
//    a = getarray(n);
//    if (a != NULL)
//    {
//        for (i = 0; i < n; i++)
//            printf("%d ", a[i]);
//        free(a);
//    }
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//
//int* getarray(int n)
//{
//    int* a = new int[n];
//    int i;
//    for (i = 0; i < n; i++) {
//        a[i] = i + 1;
//    }
//    return a;
//    delete[] a;
//}

/**/
//#include<stdio.h>
//
//void jh(int *x, int *y) 
//{
//	int t = *x;
//	*x = *y;
//	*y = t;
//}
//
//int main()
//{
//	int x = 5, y = 6;
//	jh(&x, &y);
//	printf("x=%d,y=%d", x, y);
//	return 0;
//}

/**/
//#include<stdio.h>
//
//void cfb(int n)
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//			printf("%d*%d=%-2d ", i, j, i * j);
//		printf("\n");
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	cfb(n);
//	return 0;
//}

/*�ļ��Ķ�д*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	FILE* f1;
//	char name[10], str[20] = "789";
//	int i;
//
//	f1 = fopen("file.txt", "w");
//	//fprintf(f1, "%s", str);
//	fseek(f1, 13, 0);//
//	i = ftell(f1);
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int f = void* malloc(unsigned int 100);
//	void* calloc(unsigned int);
//	free(f);
//	return 0;
//}

/*����*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

	//�ŵ㣺����Ԫ�ؿ���ֻ������
	//ȱ�㣺��ȡЧ�ʲ��ߣ�ֻ��ͨ��˳���ȡ

	//������ 
	struct LNode
	{
		int date;//������
		struct LNode* next;//ָ����
	};

void printflist(struct LNode* h)
	{
		//struct 

	}

void appendlist(struct LNode* h)
{
	struct LNode* pn, * end;
	int x;

	end = h->next;//ĩβΪ��ʱ

	do
	{
		scanf("%d", &x);
		if (x != 0)
		{
			pn = (struct LNode*)malloc(sizeof(struct LNode));
			pn->date = x;
			pn->next = NULL;
		
			if (end == NULL)
			{
				h->next = pn;
				end = pn;
		    }//endΪ��ʱ�����ж�
			else
			{
				end->next = pn;
				end = pn;
			}
		}

	} while (x != 0);

}

void appendlistone(struct LNode* h)
{
	struct LNode* pn, * end;
	int x;

	end = h;
	while (end->next != NULL)
	{
		end = end->next;
	}
	do
	{
		scanf("%d", &x);
		if (x != 0)
		{
			pn = (struct LNode*)malloc(sizeof(struct LNode));
			pn->date = x;
			pn->next = NULL;

			if (end == NULL)
			{
				h->next = pn;
				end = pn;
			}//endΪ��ʱ�����ж�
			else
			{
				end->next = pn;
				end = pn;
			}
		}

	} while (x != 0);

}

int main()
{
	//struct LNode a, b, c;
	//a.date = 1;          a.next = &b;
	//b.date = 5;          b.next = &c;
	//c.date = 2;          c.next = NULL;

	//printf("%d", a.next->next->date);//ָ��next����ʹ�������. ֻ����->
	struct LNode a, * pn;
	int n;
	a.date = 1;          a.next = NULL;

	n = sizeof(struct LNode);
	pn = (struct LNode*)malloc(n);
	pn->date = 12;
	pn->next = NULL;
	a.next = pn;
	printf("%d", a.next->date);

	return 0;
}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}
