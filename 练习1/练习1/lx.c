#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

//void print(int num[],int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", num[i]);
//	}
//}
//
//int main()
//{
//	srand(time(NULL));
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;   //������
//	int num[100];//������
//	for (i = 0; i < n; i++)//������
//	{
//		num[i] = rand() % 11;
//	}
//	//int i = 5;     //������
//	//int num[5] = { 4,5,1,2,3 };//������
//	print(num, n);
//
//	int j = 0;
//	int max = num[0];
//	int max_x = 0;
//	int min = num[0];
//	int min_x = 0;
//	for (j = 0; j < i; j++)
//	{
//		if (max < num[j])
//		{
//			max = num[j];
//			max_x = j;
//		}
//		if (min > num[j])
//		{
//			min = num[j];
//			min_x = j;
//		}
//	}
//
//	//��ֵ�Ƚ�
//	int zz = n / 2;
//	int fine;//����ѡ������
//	if (abs(max_x - (zz)) > abs(min_x - (zz)))
//	{
//		fine = abs(max_x - (zz)) + zz;
//	}
//	else
//	{
//		fine = abs(min_x - (zz)) + zz;
//	}
//
//	printf("\n%d", fine);
//
//
//
//	//do 
//	//{
//	//	num[i] = rand() % 101;
//	//} while (num[i]!=num[i-1]);
//
//
//	return 0;
//}


/*
����һ������ A�����һ������B.

����Bi   ��ʾ ����A�� Ai �ұߵ�һ���� Ai ��������±�(��1��ʼ����),û���ҵ���һ���±�  Bi ��Ϊ0

�������B

��������:

��һ��1������ n (n �� 10000)

�ڶ���n�����ֵ� i ������Ϊ Ai (0 �� Ai  �� 1000000000)

�������:

һ��һ�У��� i �����͵� i+1 �����м��ÿո����.



ʾ��

����

6

3 2 6 1 1 2

���

3 3 0 6 6 0
*/

void print(int num[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}

int main()
{
	srand(time(NULL));
	int n = 0;
	scanf("%d", &n);
	int i = 0;   //������
	int num[100]={3,2,6,1,1,2};//������
	//for (i = 0; i < n; i++)//������
	//{
	//	num[i] = rand() % 11;
	//}
	print(num, n);

	int j = 0;
	int k = 0;
	int ii = 0;//�±�
	int inf[100] = { 0 };//�±�����
	for (j = 0, ii = 0; j < n; j++, ii++)//�ص�!
	{
		//int max = num[j];//���Ƚ���
		for (k = j; k < n; k++)
		{
			if (num[k] > num[j])
			{
				inf[ii] = k + 1;//�±��һ
				break;
			}

		}
	}
	print(inf, n);

	return 0;
}
