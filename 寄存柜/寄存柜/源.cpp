#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void fen() {
	printf("-----------------------------------\n");
}
int main() {
	int n;
	srand(time(NULL));
	printf("�Ĵ��������");
	scanf("%d", &n);
	fen();
	int xz, tb;
	int N[100] = { 0 };
	int bh = 0;
	int mm, srmm, srwn;
	int wnmm = 9999;//������������Ϊ9999//
	do {
		printf("1.ͶӲ��   2.������   0.�˳�\n");
		printf("��ѡ��");
		scanf("%d", &xz);
		if (xz == 1) {
			printf("Ͷ��ֵ��");
			do {
				scanf("%d", &tb);
				if (tb != 1) {
					printf("���˱ң���ͶһöһԪӲ��\n");
					printf("Ͷ��ֵ��");
				}
			} while (tb != 1);
			do {
				mm = rand() % 10000;
			} while (mm < 1000);
			int f2 = 1;
			if (bh == n) {
				for (int jc = 0; jc < n; jc++) {
					if (N[jc] == 0) {
						printf("�Ĵ���ţ�%d ���룺%d\n", jc + 1, mm);
						N[jc] = mm;
						f2 = 0;
						break;
					}
				}//������ӱ������ʱ�������Ƿ�����ȡ���Ĺ���//
				if (f2) printf("��������\n");
				fen();
			}
			else {
				printf("�Ĵ���ţ�%d ���룺%d\n", bh + 1, mm);
				fen();
				N[bh] = mm;//��������bh��ͬ�Ĺ���������ж���������//
				bh++;
			}

		}
		else if (xz == 2) {
		flag:
			printf("�������룺");
			scanf("%d", &srmm);
			int f1 = 1;
			for (int i1 = 0; i1 < n; i1++) {
				if (N[i1] == srmm) {
					printf("%d�żĴ���Ѵ�\n", i1 + 1);
					N[i1] = 0;
					f1 = 0;
					fen();
					break;
				}
			}
			if (f1) {
				printf("�������\n");
				goto flag;
			}
		}
		else if (xz == 5) {
		flag1:
			printf("�������������룺");
			scanf("%d", &srwn);
			if (srwn == wnmm) {
				printf("������ȫ����");
				int f = 1;
				printf("�����ص���");
				for (int i2 = 0; i2 < n; i2++) {
					if (N[i2] != 0) {
						f = 0;
						printf("���%d ", i2 + 1);
					}
				}

				if (f) printf("�Ƿ��������\n");
				else printf("�������Ƿ��������\n");
				fen();
				for (int qk = 0; qk < n; qk++) {
					N[qk] = 0;
				}//����������������й�����ļĴ��ﶼ��ȡ�������������//
			}
			else {
				printf("�����������\n");
				goto flag1;
			}
		}
	} while (xz != 0);
	printf("����");
	return 0;
}