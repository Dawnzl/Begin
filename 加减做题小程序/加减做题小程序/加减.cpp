#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<time.h>
#include <stdlib.h>

//void sy(char ch,int l, int a, int b);

int main()
{
	int cx = 1;
	printf("\n欢迎来到数学计算练习\n请按‘回车’进入练习\n");
	char h = getchar();
	while (h == '\n') {
		int zf = 0;
		while (cx == 1) {

			int limit;
			srand(time(NULL));

			do {
				printf("请输入结果的范围：");
				scanf("%d", &limit);
				if (limit > 100) printf("\n请重新输入100以内的数据结果\n");
			} while (limit > 100);

			char ch;
			printf("请输入计算题类型（加法输入“+”,减法“-”，随机“sj”）");
			scanf("%s", &ch);

			int a, b, x, y, s = 0;

			if (ch == '+') {
				for (int n = 1; n <= 10; n++)//控制题数是十道题
				{
					//sy//
					do {

						a = rand() % 101;//余数范围在0-100
						b = rand() % 101;
						x = a + b;
					} while (x > limit);//使得数范围控制在100以内
		//sy//
					printf("\n\n第%d题：%d+%d=", n, a, b);

					scanf("%d", &y);
					if (x == y) printf("正确\n");
					else printf("错误 答案：%d\n", x);

					//裁判记录//
					if (x == y) {
						zf++;
						s++;
						if (s % 5 == 0) {
							zf = zf + 5;
							printf("恭喜连对五个，额外加五分！\n");
						}
					}
					else {
						s = 0;
						if (zf > 1) printf("很遗憾，连对被打破\n");
					}
					printf("-----------\n当前得分：%d\n-----------", zf);
				}
			}//sy//
			else if (ch == '-') {
				for (int n = 1; n <= 10; n++)//控制题数是十道题
				{

					do {
						a = rand() % 101;//余数范围在0-100
						b = rand() % 101;
						x = a - b;
					} while (x > limit || x < 0);

					printf("\n\n第%d题：%d-%d=", n, a, b);

					scanf("%d", &y);
					if (x == y) printf("正确\n");
					else printf("错误 答案：%d\n", x);

					//裁判记录//
					if (x == y) {
						zf++;
						s++;
						if (s % 5 == 0) {
							zf = zf + 5;
							printf("恭喜连对五个，额外加五分！\n");
						}
					}
					else {
						s = 0;
						if (zf > 1) printf("很遗憾，连对被打破\n");
					}
					printf("-----------\n当前得分：%d\n-----------", zf);
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
						printf("\n\n第%d题：%d+%d=", n, a, b);
					}
					else {
						printf("\n\n第%d题：%d-%d=", n, a, b);
					}
					scanf("%d", &y);
					if (x == y) printf("正确\n");
					else printf("错误 答案：%d\n", x);

					//裁判记录//
					if (x == y) {
						zf++;
						s++;
						if (s % 5 == 0) {
							zf = zf + 5;
							printf("恭喜连对五个，额外加五分！\n");
						}
					}
					else {
						s = 0;
						if (zf > 1) printf("很遗憾，连对被打破\n");
					}
					printf("-----------\n当前得分：%d\n-----------", zf);
				}
			}

			printf("\n\n如果继续答题请输入1,结束答题输入0：\n");
			scanf("%d", &cx);
			if (cx == 1) {
				zf = zf + 1;
				printf("为你的努力加一分！\n");
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
//	srand(time(NULL));//种时间种子s
//	int x;
//	int a = rand() % 101;//余数范围在0-100
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