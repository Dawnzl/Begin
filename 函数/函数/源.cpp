/*�ݹ�����*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int age(int n) {
//	if (n == 1) return 10;
//	else return age(n - 1) + 2;
//}
//int main() {
//	printf("%d", age(5));
// return 0;
//}

/*�ݹ�n��*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int nj(int n) {
//	if (n == 1 || n == 0) return 1;
//	else return n * nj(n - 1);
//}
//int main() {
//	printf("%d", nj(5));
//	return 0;
//}

/*�ݹ�������̨�׵ķ���*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int jump(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	if (n == 2) {
//		return 2;
//	}
//	return jump(n - 1) + jump(n - 2);//�������һ����Ծ�ķ����������һ������һ������������//
//}
//int main() {
//	int n = 5;
//	printf("%d", jump(n));
//	return 0;
//}

/*�������ֵ*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int reverse(int a);
//int main() {
//	int a;
//	scanf("%d", &a);
//	printf("%d", reverse(a));
//	return 0;
//}
//int reverse(int x) {
//	int l = 0;
//	while (x > 0) {
//		int t = x % 10;
//		l = l * 10 + t;
//		x = x / 10;
//	}
//	return l;
//}

/*����ϵͳ*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//void fun(int n) {
//	for (int i = 0; i < n; i++) {
//		printf("*");
//	}
//}
//int main() {
//	int x[40];
//	for (int i = 0; i < 40; i++) {
//		scanf("%d", &x[i]);
//	}
//	for (int a = 0; a < 40; a++) {
//		printf("Greade:%d Count:%d Histogram:", a + 1, x[a]);
//		fun(x[a]);
//		printf("\n");
//	}
//	return 0;
//}

/*c����ָ�����*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int divide(int a, int b, int* jg);
//int main() {
//	int a = 5;
//	int b = 2;
//	int jg;					 //��Ҫ����jg����Ȼָ������
//	if (divide(a, b, &jg)) {  //����jg�ĵ�ַ
//		printf("%d/%d=%d\n", a, b, jg);
//	}
//	return 0;
//}
//int divide(int a, int b, int* jg) { //�Ž��������ǽ����ַ�����ֵ��jg��
//	int ret = 1;
//	if (b == 0) ret = 0;
//	else {
//		*jg = a / b;				//jg��ֵ�Ž�jg�ĵ�ַ��
//	}
//	return ret;
//}

/*�߼���*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//void ptfun(int x[], int n) {
//	int i;
//	for (i = 0; i < n; i++)
//		printf("%5d", x[i]);
//}
//int main() {
//	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	ptfun(a + 3, 5); //a+3���+���߼��Ӳ��������ӣ�ָ����a���������������
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	int x;
//	int a[10];
//	int i;
//	scanf("%d", &x);
//	i = 0;
//	do{
//	a[i] = x % 2;
//	x = x / 2;
//	i++;
//	}while (x > 0);
//	for (i = i - 1; i >= 0; i--)
//		printf("%d", a[i]);
//	return 0;
//}

/*��������*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int find(int a[], int x);
//int main() {
//	
//	return 0;
//}
//int find(int a[], int x) {
//	int i;
//	for (i = 0; i < 10; i++) {
//		if (a[i] == x) return i;
//	}//����ֵ����������
//	return -1;//û����ֵ������-1
//
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	int a[5][5] = { 0 }, i, j;
//	int x = 1;
//	i = 0; j = 2;
//	a[i][j] = x;
//	int mi, mj;
//
//	for (x = 2; x <= 25; x++) {
//		mi = i; mj = j;
//		i = i - 1;
//		if (i < 0) i = 4;
//		j = j + 1;
//		if (j > 4) j = 0;
//		if(a[i][j]==0) a[i][j] = x;
//		else {
//			i = mi + 1; j = mj;
//			a[i][j] = x;
//		}
//	}
//	for (i = 0; i < 25; i++) {
//		for (j = 0; j < 5; j++)
//			printf("%3d", a[i][j]);
//		printf("\n");
//	}
//	return 0;
//}

/*����������maxmin��������*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<time.h>
//#include <stdlib.h>
//// �����������������Ԫ�ظ�ֵ��1000���ڵ������� 
//void rand_array(int a[], int n);
//
//// �������Ԫ�أ�һ��20��
//void print_array(int a[], int n);
//
//// �ҳ����� a[n] �е����ֵ������
//int find_largest(int a[], int n);
//
//// �ҳ����� a[n] �е���Сֵ������
//int find_smallest(int a[], int n);
//
//// ������ a[n] �в��� x�����ҵ��򷵻� x ���±꣬�Ҳ���ʱ���� -1
//int find(int a[], int n, int x);
//
//// ������ a[n] ����С����ѡ������
//void selection_sort(int a[], int n);
//
//// ������ a[n] ���Ӵ�Сð������
//void bubble_sort_desc(int a[], int n);
//
//int main() {
//	int x[100];
//
//	rand_array(x, 100);
//	print_array(x, 100);
//	printf("���ֵ%d\n", find_largest(x, 100));
//	printf("��Сֵ%d\n",find_smallest(x, 100));
//	int a = find(x, 100, 777);
//	if (a != -1) printf("���±�%d\n", a);
//	else printf("���޴���\n");
//	selection_sort(x, 100);
//	printf("\n");
//	bubble_sort_desc(x, 100);
//	return 0;
//}
//
//void rand_array(int a[], int n) {
//	int x;
//	srand(time(NULL));
//	for (int i = 0; i < n; i++) {
//		x = rand() % 1000;
//		a[i] = x;
//	}
//}
//
//void print_array(int a[], int n) {
//	for (int i = 0; i < n; i++) {
//		printf("%d ", a[i]);
//		if ((i+1) % 20 == 0) printf("\n");
//	}
//}
//
//int find_largest(int a[], int n) {
//	int ind = 0;
//	for (int z = 0; z < n; z++) {
//		if (a[z] > a[ind]) {
//			ind = z;
//		}
//	}
//	return a[ind];
//}
//
//int find_smallest(int a[], int n) {
//	int ind = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] < a[ind]) {
//			ind = i;
//		}
//	}
//	return a[ind];
//}
//
//int find(int a[], int n, int x){
//		/*���ַ�����*/
//	int l, h, m;
//	l = 0;
//	h = n - 1;
//	while (l <= h) {
//		m = (l + h) / 2;
//		if (x == a[m]) {
//			break;
//		}
//		else if (x < a[m]) {
//			h = m - 1;
//		}
//		else {
//			l = m + 1;
//		}
//	}
//	if (l <= h) {
//		return m;
//	}
//	else {
//		return -1;
//	}
//
//}
//
//void selection_sort(int a[], int n) {
//	int min, ind, t;
//	for (int k = 0; k < n; k++) {
//		min = a[k];
//		ind = k;
//		for (int i = k; i < n; i++) {
//			if (a[i] < min) {
//				min = a[i];
//				ind = i;
//				t = a[k];
//				a[k] = a[ind];
//				a[ind] = t;
//			}
//		}
//	}
//	for (int z = 0; z < n; z++) {
//		printf("%d ", a[z]);
//		if ((z+1) % 20 == 0) printf("\n");
//	}
//	
//}
//
//void bubble_sort_desc(int a[], int n) {
//
//	for (int k = 1; k <= n; k++) {
//		for (int i = 0;i <= n-1; i++) {
//			if (a[i] > a[i + 1]) {
//				int t = a[i];
//				a[i] = a[i + 1];
//				a[i + 1] = t;
//			}
//		}
//	}
//	for (int j = 0; j < n; j++) {
//		printf("%d ", a[j]);
//		if ((j+1) % 20 == 0) printf("\n");
//	}
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//double mysqrt(double a)
//{
//	double x1 = a;
//	double d;
//	do {
//		double x2 = 0.5 * (x1 + a / x1);
//		d = x1 - x2;
//		x1 = x2;
//	} while (d * d > 0.0000001);
//	return  x1;
//}
//
//int main()
//
//{
//	double x;
//
//	printf("input:");
//
//	scanf("%lf", &x);
//
//	if (x >= 0)
//
//		printf("%lf ��ƽ������ %lf \n",x, mysqrt(x));
//
//	else
//
//		printf("�������\n");
//
//	return 0;
//
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//    int n, x[10][10];
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            scanf("%d", &x[i][j]);
//        }
//    }
//    /*    for (int i = 0; i < n; i++) {
//            for(int j=0;j<n;j++){
//            printf("%d ", x[i][j]);
//            if ((j+1) % 5 == 0) printf("\n");
//            }
//    */
//int indi, indj, h, l, z, max, min, f = 1;
//for (h = 0; h < n; h++) {
//    indj = 0;
//    indi = 0;
//    max = 0;
//    min = 0;
//    for (l = 0; l < n; l++) {
//        if (x[h][l] > x[h][indj]) {
//            indj = l;
//        }
//    }
//    max = x[h][indj];
//    printf("%d ", max);
//    for (z = 0; z < n; z++) {
//        if (x[z][h] < x[indi][h]) {
//            indi = z;
//        }
//        printf("%d ", x[indi][h]);
//    }
//    min = x[indi][z];
//    printf("%d ", min);
//    printf("\n");
//    if (max == min) {
//        printf("%d %d %d", indi, indj, max);
//        f = 0;
//            break;
//    }
//}
//   
//
//    return 0;
//}

/*ɾ���ַ�*/
//����һ������ĸ����С��ĸ�����ԣ�����ַ��������Ȳ�����127����Ȼ������һ��n (n<=52)��������n����ĸ����ĸǰ���������0���������ĵĶ��š���������Щ��ĸ���ַ�����ɾ���������ĸû�����ַ����г��ֹ��������ĸ��ɾ���������������ã�//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<string.h>
//void ReadDelChar(char delchr[], int n) {  //����n����ĸ���浽����delchr�� 
//    int i;
//    for (i = 0; i < n; i++) {
//        //scanf("%c",&delchr[i]);
//        delchr[i] = getchar();
//        if (delchr[i] == ',') {
//            i--;
//        }
//    }
//    delchr[i] = '\0';//i����Ѽ�1������i+1//
//    //puts(delchr);
//}
//void DelChar(char str[], char delchr[], int n) {   //ɾ��str�����г�����delchr�е���ĸ 
//    int i, j, k;
//    for (i = 0; i < n; i++) {
//        for (j = 0, k = 0; str[j] != '\0'; j++) {
//            if (str[j] != delchr[i]) {
//                str[k++] = str[j];
//            }
//        }
//        str[k] = '\0';//?//
//    }
//
//}
//
//int main() {
//        int n;
//        char str[128], cr[52];
//        gets(str);
//        getchar();
//        scanf("%d", &n);
//        ReadDelChar(cr, n);
//        DelChar(str, cr, n);
//        printf("%s", str);
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d", a > b ? a : b);
//	return 0;
//}

/*ָ�뷵������ֵ*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//void maxmin(int a[],int n, int* max, int* min) 
//{
//	int i;
//	*max = a[0];
//	*min = a[0];
//	for (i = 0; i < n; i++) {
//		if (*max < a[i]) *max = a[i];
//		if (*min > a[i]) *min = a[i];
//	}
//}
//
//int main() 
//{
//	int a[5],max,min;
//	for (int i = 0; i < 5; i++) {
//		scanf_s("%d", &a[i]);
//	}
//	maxmin(a, 5, &max, &min);
//	printf("max=%d,min=%d", max, min);
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//void conj(char* s1, char* s2) {
//    int t[64], * s1p, * tp;
//    tp = t;
//    s1p = s1;
//    while (*s1 != '\0' && *s2 != '\0') {
//        *tp++ = *s1++;
//        *tp++ = *s2++;
//    }
//    while (*s1 != '\0' && *s2 == '\0') {
//        *tp++ = *s1++;
//    }
//    while (*s1 == '\0' && *s2 != '\0') {
//        *tp++ = *s2++;
//    }
//    *tp = '\0';
//    tp = t;
//    while(*tp != '\0') {
//        *s1p++ = *tp++;
//    }
//    *s1p = '\0';
    /*int i;
    for(i=0;t[i]!='\0';i++){
        s1[i]=t[i];
    }
    s1[i]='\0';
    */
//}
//int main() {
//	
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//    printf("%c\n", ('z' - 'a' + 2) % 26 + 'a');
//    printf("%d\n", ('z' - 'a'));
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//void fun(char* Pstr, const int n) {
//    if (n >= 0) {
//        if (n >= 26) {
//            n = n % 26;
//        }
//    }
//    int i;
//    for (i = 0; *(Pstr + i) != '\0'; i++) {
//        if (Pstr[i] >= 'a' && Pstr[i] <= 'z') {
//            if (n >= 0) {
//                Pstr[i] = (Pstr[i] - 'a' + n) % 26 + 'a';
//            }
//            else if (n < 0) {
//                Pstr[i] = (Pstr[i] - 'a' + n + 26) % 26 + 'a';
//            }
//
//        }
//        else if (Pstr[i] >= 'A' && Pstr[i] <= 'A') {
//            if (n >= 0) {
//                Pstr[i] = (Pstr[i] - 'A' + n) % 26 + 'A';
//            }
//            else if (n < 0) {
//                Pstr[i] = (Pstr[i] - 'A' + n + 26) % 26 + 'A';
//            }
//        }
//    }
//    Pstr[i] = '\0';
//} 
//
//int main() {
//	
//	return 0;
//}


/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//    int a[3], i;
//    for (i = 0; i < 3; i++) {
//        scanf("%d", &a[i]);
//    }
//    for(int j=0;j<3;j++)
//        for (int k = 0; k < 3 - j; k++) {
//            if (a[j] < a[j + 1]) {
//                int t = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = t;
//            }
//        }
//  
//    for (i = 0; i < 3; i++) {
//        printf("%d ", a[i]);
//    }
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//    for (int i = 1; i <= 100; i++) {
//        if (i % 3 == 0) printf("%d ", i);
//    }
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//        int m, n;
//        int t;
//        scanf("%d %d", &m, &n);
//        while (t = m % n)
//        {
//            m = n;
//            n = t;
//        }
//        printf("%d\n", n);
//
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int i;
//	for (i = 1000 ; i <= 2000 ; i++)
//	{
//		if ((i % 100 != 0 && i % 4 == 0) || i % 400 == 0)  
//		{               
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//    int i = 0;
//    for (i = 100; i <= 200; i++) {
//        int j = 0;
//        for (j = 2; j < i; j++) {
//            if (i % j == 0) {
//                break;
//            }
//        }
//        if (j == i) printf("%d ", i);
//    }
//	return 0;
//}


//����Ҫ��ʵ��һ���ַ���ѹ���ļ򵥺�����ѹ�������ǣ����ĳ���ַ�x��������n��n>1���Σ�����n���ַ�x�滻Ϊnx����ʽ�����򱣳ֲ��䡣
#include <stdio.h>
#include<string.h>
#define MAXS 20

void zip(char* p);

int main()
{
    char s[MAXS];
    gets_s(s);
    zip(s);
    printf("%s\n", s);

    return 0;
}

/* ����������д�� */
void zip(char* p) {
    int i = 0, t = 0;
    while (*(p + i) != '\0') {
        if (p[i] != p[i + 1]) {
            p[t++] = p[i];
            i++;
        }
        else if (p[i] == p[i + 1]) {
            char l = p[i];
            int ret = 1;
            while (p[i] == p[i + 1]) {
                ret++;
                i++;
            }
            if (ret >= 2 && ret <= 9) {
                p[t] = ret + 48;
                p[++t] = l;
            }
            else if (ret >= 10)
            {
                p[t] = (ret / 10) + 48;//������ʮλ
                p[++t] = (ret % 10) + 48;//�����ĸ�λ
                p[++t] = l;
            }

        }

    }
    p[t] = '\0';
}




/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	
//	return 0;
//}

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	
//	return 0;

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	
//	return 0;

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	
//	return 0;

/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	
//	return 0;
//}
// 
/**/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	
//	return 0;
//}
//}
//}
//}
