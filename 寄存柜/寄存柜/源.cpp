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
	printf("寄存柜总数：");
	scanf("%d", &n);
	fen();
	int xz, tb;
	int N[100] = { 0 };
	int bh = 0;
	int mm, srmm, srwn;
	int wnmm = 9999;//万能密码设置为9999//
	do {
		printf("1.投硬币   2.输密码   0.退出\n");
		printf("请选择：");
		scanf("%d", &xz);
		if (xz == 1) {
			printf("投币值：");
			do {
				scanf("%d", &tb);
				if (tb != 1) {
					printf("已退币，请投一枚一元硬币\n");
					printf("投币值：");
				}
			} while (tb != 1);
			do {
				mm = rand() % 10000;
			} while (mm < 1000);
			int f2 = 1;
			if (bh == n) {
				for (int jc = 0; jc < n; jc++) {
					if (N[jc] == 0) {
						printf("寄存柜编号：%d 密码：%d\n", jc + 1, mm);
						N[jc] = mm;
						f2 = 0;
						break;
					}
				}//处理柜子编号排满时，搜索是否有已取出的柜子//
				if (f2) printf("本柜已满\n");
				fen();
			}
			else {
				printf("寄存柜编号：%d 密码：%d\n", bh + 1, mm);
				fen();
				N[bh] = mm;//将密码存进bh相同的柜子里代表有东西在里面//
				bh++;
			}

		}
		else if (xz == 2) {
		flag:
			printf("输入密码：");
			scanf("%d", &srmm);
			int f1 = 1;
			for (int i1 = 0; i1 < n; i1++) {
				if (N[i1] == srmm) {
					printf("%d号寄存柜已打开\n", i1 + 1);
					N[i1] = 0;
					f1 = 0;
					fen();
					break;
				}
			}
			if (f1) {
				printf("密码错误\n");
				goto flag;
			}
		}
		else if (xz == 5) {
		flag1:
			printf("请输入万能密码：");
			scanf("%d", &srwn);
			if (srwn == wnmm) {
				printf("箱子已全部打开");
				int f = 1;
				printf("，请重点检查");
				for (int i2 = 0; i2 < n; i2++) {
					if (N[i2] != 0) {
						f = 0;
						printf("编号%d ", i2 + 1);
					}
				}

				if (f) printf("是否有物存留\n");
				else printf("的箱子是否有物存留\n");
				fen();
				for (int qk = 0; qk < n; qk++) {
					N[qk] = 0;
				}//输入万能密码后所有柜子里的寄存物都被取出，将柜子清空//
			}
			else {
				printf("万能密码错误\n");
				goto flag1;
			}
		}
	} while (xz != 0);
	printf("结束");
	return 0;
}