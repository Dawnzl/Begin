#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*满意度*/
//
//int main()
//{
//    int n, m;//n个学生，m个学科
//    scanf("%d %d", &n, &m);
//    int stu[100][1000] = { 0 };
//    int book[1000] = { 0 };//下标作为课程的编号
//    int i = 0, j = 0, a = 0;//a是某学生喜欢的科目数目
//    
//    int stud = 0;
//    for (stud = 0; stud < n; stud++)
//    {
//        scanf("%d", &a);
//        for (i = 0; i < a; i++)
//        {
//            //scanf("%d", stu[stud][i]);
//            scanf("%d", &j);
//            book[j]++;
//        }
//
//    }
//
//    ////循环搜索各科的喜欢项目，book相对应的数字++
//    //int k = 0, kk = 0;
//    //for (k = 0; k < n; k++)//学生个数
//    //{
//    //    //循环a个科目，如果数组中的值相同则++
//    //    for (kk = 0; kk < a; kk++)
//    //    {
//    //        int shux = 1;//科目的下标
//    //        for (shux = 1; shux <= m; shux++)
//    //        {
//    //            if (stu[k][kk] == shux)//如果第一个学生喜欢的第一本书
//    //            {
//    //                book[shux]++;//1-m号书喜欢的人累加
//    //            }
//    //        }
//    //    }
//
//    //}
//
//    int s = 1;//搜索变量
//    int z = 0;//总数
//    for (s = 1; s <= m; s++)
//    {
//        if (book[s] == n)//如果喜欢的个数等于人数则输出
//        {
//            z++;
//        }
//       
//    }
//    printf("%d", z);
//    return 0;
//}


//病毒//

int GetCount(int mine[][100],int x, int y)
{
	return mine[x - 1][y] +//左
		mine[x][y - 1] +//下
		mine[x + 1][y] +//右
		mine[x][y + 1] ;//上
}

void boom(int mine[][100], int x, int y,int n)
{
	int offset_x = 0;
	int offset_y = 0;
	int count = 0;
	//坐标合法
	if (x >= 0 && x <= n && y >= 0 && y <= n)
	{
		//遍历周围坐标
		for (offset_x = -1; offset_x <= 1; offset_x++)
		{
			for (offset_y = -1; offset_y <= 1; offset_y++)
			{
				//如果这个坐标不是病毒
				if (mine[x + offset_x][y + offset_y] == 0)
				{
					//统计周围雷的个数
					count = GetCount(mine, x + offset_x, y + offset_y);
					if (count >= 2)//如果超过两边有病毒
					{
							mine[x + offset_x][y + offset_y] = 1 ;
							boom(mine, x + offset_x, y + offset_y, n);
					}
					else
					{
						mine[x + offset_x][y + offset_y] = 0;
					}
				}
			}
		}
	}
	
}

int main()
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);

	int min[100][100] = { 0 };//把培养皿看成一个棋盘
	int d = 0;//病菌的数量

	int x = 0, y = 0;
	int x1 = 0, y1 = 0;
	scanf("%d %d", &x1, &y1);
	for (d = 1; d < m; d++)
	{
		do 
		{
			scanf("%d %d", &x, &y);

		} while (x == x1 && y == y1);//相同就重新输入
		min[x][y] = 1;
		boom(min, x, y, n);
		x1 = x; y1 = y;
	}
	int i = 0, j = 0, count = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			count += min[i][j];
		}
	}

	if (min[i][j] == n * n) printf("YES");
	else printf("NO");

	return 0;
}