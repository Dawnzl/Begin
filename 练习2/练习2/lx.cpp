#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*�����*/
//
//int main()
//{
//    int n, m;//n��ѧ����m��ѧ��
//    scanf("%d %d", &n, &m);
//    int stu[100][1000] = { 0 };
//    int book[1000] = { 0 };//�±���Ϊ�γ̵ı��
//    int i = 0, j = 0, a = 0;//a��ĳѧ��ϲ���Ŀ�Ŀ��Ŀ
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
//    ////ѭ���������Ƶ�ϲ����Ŀ��book���Ӧ������++
//    //int k = 0, kk = 0;
//    //for (k = 0; k < n; k++)//ѧ������
//    //{
//    //    //ѭ��a����Ŀ����������е�ֵ��ͬ��++
//    //    for (kk = 0; kk < a; kk++)
//    //    {
//    //        int shux = 1;//��Ŀ���±�
//    //        for (shux = 1; shux <= m; shux++)
//    //        {
//    //            if (stu[k][kk] == shux)//�����һ��ѧ��ϲ���ĵ�һ����
//    //            {
//    //                book[shux]++;//1-m����ϲ�������ۼ�
//    //            }
//    //        }
//    //    }
//
//    //}
//
//    int s = 1;//��������
//    int z = 0;//����
//    for (s = 1; s <= m; s++)
//    {
//        if (book[s] == n)//���ϲ���ĸ����������������
//        {
//            z++;
//        }
//       
//    }
//    printf("%d", z);
//    return 0;
//}


//����//

int GetCount(int mine[][100],int x, int y)
{
	return mine[x - 1][y] +//��
		mine[x][y - 1] +//��
		mine[x + 1][y] +//��
		mine[x][y + 1] ;//��
}

void boom(int mine[][100], int x, int y,int n)
{
	int offset_x = 0;
	int offset_y = 0;
	int count = 0;
	//����Ϸ�
	if (x >= 0 && x <= n && y >= 0 && y <= n)
	{
		//������Χ����
		for (offset_x = -1; offset_x <= 1; offset_x++)
		{
			for (offset_y = -1; offset_y <= 1; offset_y++)
			{
				//���������겻�ǲ���
				if (mine[x + offset_x][y + offset_y] == 0)
				{
					//ͳ����Χ�׵ĸ���
					count = GetCount(mine, x + offset_x, y + offset_y);
					if (count >= 2)//������������в���
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

	int min[100][100] = { 0 };//�������󿴳�һ������
	int d = 0;//����������

	int x = 0, y = 0;
	int x1 = 0, y1 = 0;
	scanf("%d %d", &x1, &y1);
	for (d = 1; d < m; d++)
	{
		do 
		{
			scanf("%d %d", &x, &y);

		} while (x == x1 && y == y1);//��ͬ����������
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