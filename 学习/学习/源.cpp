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

//����������n�����ɶ�̬���飬����������ݡ�
#include <stdio.h>
#include <malloc.h>
int* getarray(int n);
int main()
{
    int* a = NULL, n, i;
    scanf_s("%d", &n);
    if (n <= 0) return 0;
    a = getarray(n);
    if (a != NULL)
    {
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        free(a);
    }
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */

int* getarray(int n)
{
    int* a = new int[n];
    int i;
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    return a;
    delete[] a;
}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

/**/
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}