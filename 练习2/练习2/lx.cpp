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

int boom(int n)
{

	
}

int main()
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);

	int min[1000][1000] = { 0 };//�������󿴳�һ������
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
		x1 = x; y1 = y;
	}



	return 0;
}