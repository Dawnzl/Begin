#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<time.h>
#include <stdlib.h>

//void sy(char ch,int l, int a, int b);

int main()
{
	int cx = 1;
	printf("\n��ӭ������ѧ������ϰ\n�밴���س���������ϰ\n");
	char h = getchar();
	while (h == '\n') {
		int zf = 0;
		while (cx == 1) {

			int limit;
			srand(time(NULL));

			do {
				printf("���������ķ�Χ��");
				scanf("%d", &limit);
				if (limit > 100) printf("\n����������100���ڵ����ݽ��\n");
			} while (limit > 100);

			char ch;
			printf("��������������ͣ��ӷ����롰+��,������-���������sj����");
			scanf("%s", &ch);

			int a, b, x, y, s = 0;

			if (ch == '+') {
				for (int n = 1; n <= 10; n++)//����������ʮ����
				{
					//sy//
					do {

						a = rand() % 101;//������Χ��0-100
						b = rand() % 101;
						x = a + b;
					} while (x > limit);//ʹ������Χ������100����
		//sy//
					printf("\n\n��%d�⣺%d+%d=", n, a, b);

					scanf("%d", &y);
					if (x == y) printf("��ȷ\n");
					else printf("���� �𰸣�%d\n", x);

					//���м�¼//
					if (x == y) {
						zf++;
						s++;
						if (s % 5 == 0) {
							zf = zf + 5;
							printf("��ϲ����������������֣�\n");
						}
					}
					else {
						s = 0;
						if (zf > 1) printf("���ź������Ա�����\n");
					}
					printf("-----------\n��ǰ�÷֣�%d\n-----------", zf);
				}
			}//sy//
			else if (ch == '-') {
				for (int n = 1; n <= 10; n++)//����������ʮ����
				{

					do {
						a = rand() % 101;//������Χ��0-100
						b = rand() % 101;
						x = a - b;
					} while (x > limit || x < 0);

					printf("\n\n��%d�⣺%d-%d=", n, a, b);

					scanf("%d", &y);
					if (x == y) printf("��ȷ\n");
					else printf("���� �𰸣�%d\n", x);

					//���м�¼//
					if (x == y) {
						zf++;
						s++;
						if (s % 5 == 0) {
							zf = zf + 5;
							printf("��ϲ����������������֣�\n");
						}
					}
					else {
						s = 0;
						if (zf > 1) printf("���ź������Ա�����\n");
					}
					printf("-----------\n��ǰ�÷֣�%d\n-----------", zf);
				}
			}//sy//

			else {
				for (int n = 1; n <= 10; n++)
				{
					int sj = rand() % 2;
					do {
						a = rand() % 101;
						b = rand() % 101;
						if (a + b < limit || (a - b < limit && a - b>0)) {
							if (sj == 0 && a + b < limit) {
								x = a + b;
								break;
							}
							else if (sj == 1 && (a - b < limit && a - b>0)) {
								x = a - b;
								break;
							}
						}
					} while (1);
					if (sj == 0) {
						printf("\n\n��%d�⣺%d+%d=", n, a, b);
					}
					else {
						printf("\n\n��%d�⣺%d-%d=", n, a, b);
					}
					scanf("%d", &y);
					if (x == y) printf("��ȷ\n");
					else printf("���� �𰸣�%d\n", x);

					//���м�¼//
					if (x == y) {
						zf++;
						s++;
						if (s % 5 == 0) {
							zf = zf + 5;
							printf("��ϲ����������������֣�\n");
						}
					}
					else {
						s = 0;
						if (zf > 1) printf("���ź������Ա�����\n");
					}
					printf("-----------\n��ǰ�÷֣�%d\n-----------", zf);
				}
			}

			printf("\n\n�����������������1,������������0��\n");
			scanf("%d", &cx);
			if (cx == 1) {
				zf = zf + 1;
				printf("Ϊ���Ŭ����һ�֣�\n");
			}
		}
	}
	return 0;
}

//void sy(char ch,int l, int a, int b) {
//	if (ch == '+') {
//		l < a + b;
//	}
//	else if(ch == '-') {
//		l < a - b;
//	}
//}

//int tx(char ch) {
//	srand(time(NULL));//��ʱ������s
//	int x;
//	int a = rand() % 101;//������Χ��0-100
//	int b = rand() % 101;
//	//if (ch == '+') {
//		return (x = a + b);
		//return x, a, b;
	//}
	//else if (ch == '-') {
	//	x = a - b;
	//	return x, a, b;
	//}
//}