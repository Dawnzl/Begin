#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdbool.h>
//
//struct date {
//	int month;
//	int day;
//	int year;
//}; //����һ���ṹ//
//
//bool isLeap(struct date d);//����һ��bool����//
//int numberOfdays(struct date d);
//int main(int argc, char const* argv[])
//{
//	struct date today, tommorrw;//���������ṹ//
//
//	printf("���뵱ǰ������");
//	scanf("%i %i %i", &today.month, &today.day, &today.year);
//
//	if (today.day != numberOfdays(today)) {
//		tommorrw.day = today.day + 1;
//		tommorrw.month = today.month;
//		tommorrw.year = today.year;
//	}
//	else if (today.month == 12) {
//		tommorrw.day = 1;
//		tommorrw.month = 1;
//		tommorrw.year = today.year + 1;
//	}
//	else {
//		tommorrw.day = 1;
//		tommorrw.month = today.month + 1;
//		tommorrw.year = today.year;
//	}
//
//	printf("������%i-%i-%i\n", tommorrw.year, tommorrw.month, tommorrw.day);
//
//	return 0;
//}
//
//int numberOfdays(struct date d) {
//	int days;
//	const int daysMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (d.month == 2 && isLeap(d))
//		days = 29;
//	else days = daysMonth[d.month - 1];
//	return days;
//}
//
//bool isLeap(struct date d) {
//	bool leap = false;
//
//	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
//		leap = true;
//
//	return leap;
//}

#include<stdio.h>
/*����ĿҪ��������������N��Ȼ������N������Ϊ�ṹ��stud������Ԫ�أ�
����ÿ��ѧ�����ܷ֣����ÿ��ѧ����ѧ�š����������ſεĳɼ����ܷ֣�
����ȫ���ɼ���ƽ���ֲ����������ܷ����ͬѧ�ĸ�����Ϣ��

��������:
���������һ�����롣���磺

4
1  ����  81  85  82
2  ����  82  78  74
3  ����  85  74  90
4  ����  77  85  79



�������:
�����������Ӧ����������磺

1 ���� 81 85 82 248
2 ���� 82 78 74 234
3 ���� 85 74 90 249
4 ���� 77 85 79 241
��ƽ����=81.000000
3 ���� 85 74 90 249
*/
struct stud {
    int num; //ѧ��
    char name[10]; //����
    int score[3]; //3�ſγɼ�
    int sum; //�ܷ�
};

int main()
{
    int n;
    scanf("%d", &n);
    int nt = n;
    struct stud tj[10];
    int i = 0;
    int max = 0;
    int xb = 0;
    double zsum = 0;
    while (n--) {
        scanf("%d %s %d %d %d", &tj[i].num, &tj[i].name, &tj[i].score[0], &tj[i].score[1], &tj[i].score[2]);
        tj[i].sum = tj[i].score[0] + tj[i].score[1] + tj[i].score[2];
        if (max < tj[i].sum) {
            max = tj[i].sum;
            xb = i;
        }
        zsum += tj[i].sum * 1.0;
        i++;
    }
    int j = 0;
    for (j; j < nt; j++) {
        printf("%d %s %d %d %d %d\n", tj[j].num, tj[j].name, tj[j].score[0], tj[j].score[1], tj[j].score[2], tj[j].sum);
    }
    printf("��ƽ����=%lf\n", zsum / (3 * nt));
    printf("%d %s %d %d %d %d\n", tj[xb].num, tj[xb].name, tj[xb].score[0], tj[xb].score[1], tj[xb].score[2], tj[xb].sum);
    return 0;
}