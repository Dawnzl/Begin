/*分数*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char fun(int n) {
	char x;
	if (n <= 10 && n >= 9) return 'A';
	else if (n < 9 && n >= 8) return 'B';
	else if (n < 8 && n >= 6) return 'C';
	else if (n < 6 && n>=0) return 'D';
	
}
int main() {
	int s, n;
	char p;
	scanf("%d", &s);
	n = s / 10;
	p = fun(n);
	printf("%c", p);
	return 0;
}

/*各位数是否可被5整除*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int fun(int w)
{
	int sum = 0;
	while (w > 0) {
		int gsbw = w % 10;//从个位开始检测//
		w = w / 10;//进位//
		int t = gsbw * gsbw;
		sum += t;
	}
	if (sum % 5 == 0) return 1;
	else return 0;
}
int main() {
	int m;
	scanf("%d", &m);
	printf("%d", fun(m));
	return 0;
}

/*因子之积*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
long int fun(int n) {
	int i,j=1;
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			j = j * i;
		}
	}
	return j;

}
int main() {
	int m;
	scanf("%d", &m);
	printf("%d", fun(m));
	return 0;
}

/*是否被7或11整除*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define M 100

void fun(int m, int* a, int* n)
{
	int i,j=0,k;
	*n = 0;
	for (i = 1; i <= m; i++) {
		if (i % 7 == 0 || i % 11 == 0) {
			a[j++] = i;
		}
	}
	*n = j;

	for (k = 0; k < j; k++) {
		printf("%d ", a[k]);
	}
	printf("\n%d", *n);
}
int main() {
	int aa[M],k,n;
	fun(50, aa, &n);
	for (k = 0; k < n; k++)
		if ((k + 1) % 20 == 0)
			printf("\n");
	//printf("%d", n);
	return 0;
}

/*max-min*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "stdlib.h"
#define N 30

int max_min(int a[], int n)
{
	int i,min=a[0], max=a[0];
	for (i = 0; i < n; i++) {
		min = (a[i] < min) ? a[i] : min;
		max = (a[i] > max) ? a[i] : max;
	}
	return max - min;
}
int main() {
	int a[N],i,k;
	for (i = 0; i < N; i++)
		scanf_s("%d", a[i]);
	for (i = 0; i < N; i++) {
		printf("%5d", a[i]);
		if ((i + 1) % 5 == 0) printf("\n");
	}
	k = max_min(a, N);
	printf("%d", k);
	return 0;
}

/*y=1/2+1/4+.....*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
double fun(int m)
{
	int i;
	double y=0;
	for (i = 1; i <= m; i++) {
		y += 1.0 / (2 * i);
	}
	return y;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lf", fun(n));
	return 0;
}

/*n!*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int n;
	double factor;
	double fact(int n);
	scanf("%d", &n);
	factor = fact(n);
	printf("%d!=%f", n, factor);
	return 0;
}

double fact(int n)
{
	double N = 1.0;
	while (n>0) {
		N = N * n;
		n--;
	}
	return N;
}

/*素数*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h>
#define MAX 100
int fun(int lim, int aa[MAX]) {
	int i,j, f , k=0;
	for (i = lim; i <= 100; i++) {
		f = 1;//每一次循环都要重新定义！！！//
		for (j = 2; j < i/2; j++) {
			if (i % j == 0) {
				f = 0;
				break;
			}
		}
		if (f) aa[k++] = i;
	}
	return k;
}
void main() {
	int limit, i, sum;
	int aa[MAX];
	scanf_s("%d", &limit);
	sum = fun(limit, aa);
	for (i = 0; i < sum; i++) {
		if (i % 10 == 0 && i != 0) printf("\n");
		printf("%5d", aa[i]);
	}
}

/**/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);
    if (x++ > 5) printf("%d\n", x);
    else printf("%d\n", x--);
	return 0;
}

