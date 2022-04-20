#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

struct date {
	int month;
	int day;
	int year;
}; //声明一个结构//

bool isLeap(struct date d);//声明一个bool函数//
int numberOfdays(struct date d);
int main(int argc, char const* argv[])
{
	struct date today, tommorrw;//定义两个结构//

	printf("输入当前月日年");
	scanf("%i %i %i", &today.month, &today.day, &today.year);

	if (today.day != numberOfdays(today)) {
		tommorrw.day = today.day + 1;
		tommorrw.month = today.month;
		tommorrw.year = today.year;
	}
	else if (today.month == 12) {
		tommorrw.day = 1;
		tommorrw.month = 1;
		tommorrw.year = today.year + 1;
	}
	else {
		tommorrw.day = 1;
		tommorrw.month = today.month + 1;
		tommorrw.year = today.year;
	}

	printf("明天是%i-%i-%i\n", tommorrw.year, tommorrw.month, tommorrw.day);

	return 0;
}

int numberOfdays(struct date d) {
	int days;
	const int daysMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (d.month == 2 && isLeap(d))
		days = 29;
	else days = daysMonth[d.month - 1];
	return days;
}

bool isLeap(struct date d) {
	bool leap = false;

	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		leap = true;

	return leap;
}