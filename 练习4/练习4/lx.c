#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>

typedef struct timee
{
	int h;
	int m;
	int s;
}t;

int main()
{
	int n;
	scanf("%d", &n);
	t time[3];
	
	int i = 0;
	for (i = 0; i < n; i++)
	{
		do 
		{
			scanf("%d %d %d", &time[i].h, &time[i].m, &time[i].s);
		} while (time[i].h > 24 || time[i].h < 0 || time[i].m>60 || time[i].m < 0 || time[i].s>60 || time[i].s < 0);//判断时间合法性
		
	}
	int j = 0;
	for (j = 0; j < n - 1; j++)
	{
		for(i=0;i<n-j-1;i++)
		{
			if (time[i].h > time[i+1].h)
			{
				t tim = time[i];
				time[i] = time[i + 1];
				time[i + 1] = tim;
			}
		}

	}
	////处理分钟
	for (j = 0; j < n - 1; j++)
	{
		for (i = 0; i < n - j - 1; i++)
		{
			if ((time[i].h == time[i + 1].h) && (time[i].m > time[i + 1].m))
			{
				t tim = time[i];
				time[i] = time[i + 1];
				time[i + 1] = tim;
			}
		}
	}
	//处理秒钟
	for (j = 0; j < n - 1; j++)
	{
		for (i = 0; i < n - j - 1; i++)
		{
			if ((time[i].h == time[i + 1].h) && (time[i].m == time[i + 1].m) && (time[i].s > time[i + 1].s))
			{
				t tim = time[i];
				time[i] = time[i + 1];
				time[i + 1] = tim;
			}
		}
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%0.2d:%0.2d:%0.2d\n", time[i].h, time[i].m, time[i].s);
	}
	return 0;
}