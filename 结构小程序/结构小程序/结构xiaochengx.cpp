#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdbool.h>
//
//struct date {
//	int month;
//	int day;
//	int year;
//}; //声明一个结构//
//
//bool isLeap(struct date d);//声明一个bool函数//
//int numberOfdays(struct date d);
//int main(int argc, char const* argv[])
//{
//	struct date today, tommorrw;//定义两个结构//
//
//	printf("输入当前月日年");
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
//	printf("明天是%i-%i-%i\n", tommorrw.year, tommorrw.month, tommorrw.day);
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
/*本题目要求先输入正整数N，然后输入N个类型为结构体stud的数组元素，
计算每个学生的总分，输出每个学生的学号、姓名、三门课的成绩及总分；
计算全部成绩的平均分并输出；输出总分最高同学的各项信息。

输入样例:
在这里给出一组输入。例如：

4
1  张三  81  85  82
2  李四  82  78  74
3  王五  85  74  90
4  赵六  77  85  79



输出样例:
在这里给出相应的输出。例如：

1 张三 81 85 82 248
2 李四 82 78 74 234
3 王五 85 74 90 249
4 赵六 77 85 79 241
总平均分=81.000000
3 王五 85 74 90 249
*/
struct stud {
    int num; //学号
    char name[10]; //姓名
    int score[3]; //3门课成绩
    int sum; //总分
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
    printf("总平均分=%lf\n", zsum / (3 * nt));
    printf("%d %s %d %d %d %d\n", tj[xb].num, tj[xb].name, tj[xb].score[0], tj[xb].score[1], tj[xb].score[2], tj[xb].sum);
    return 0;
}