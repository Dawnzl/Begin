//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>


////��ŵ��
//int Hanio(int num)
//{
//	if (num == 1)
//		return 1;
//	else
//		return 2 * Hanio(num - 1) + 1;
//}
//
//int main() 
//{
//	int n = 0;
//	scanf("%d", &n);
//	int inp = Hanio(n);
//	printf("%d", inp);
//}

////���׺�ŵ��
////������ n ��Բ�̴������£���С������ڵ�һ�������ϣ�Ҫ����ЩԲ��ȫ���ƶ������������ӣ����Ƕ�֪�������ٵ��ƶ���ĿΪ 2 ^ n - 1 �Ρ�������������Ҫ��Ĳ����������
////
////������ 1��2��...��n ��ʾ n�����ӵı�ţ����Խ�����Ӿ�Խ�����ƶ������У��е�Բ���ƶ������࣬�е��١���֪�����������̺ţ���������ӵ��ƶ�����
//#include<stdio.h>
//
////��ŵ��
//long long int Hanio(int num, int end)
//{
//	if (num == end)
//		return 1;
//	else
//		return 2 * Hanio(num, end + 1);
//}
//
//int main()
//{
//	int T = 0;
//	scanf("%d", &T);
//	while (T--)
//	{
//		int n = 0;
//		int e = 0;
//		scanf("%d %d", &n, &e);
//		long long int inp = Hanio(n, e);
//		printf("%lld\n", inp);
//	}
//
//}

//��λ����������ƽ����
//#include<stdio.h>
//#include<stdlib.h>
//
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int a[100] = { 0 };
//    for (int i = 0; i < n; ++i)
//    {
//        scanf("%d", &a[i]);
//    }
//
//    int max = a[0], min = a[0];
//    int sum = a[0];
//    for (int i = 1; i < n; ++i)
//    {
//        if (a[i] > max)
//            max = a[i];
//
//        if (a[i] < min)
//            min = a[i];
//
//        sum += a[i];
//    }
//    int p = sum / n;
//    int z = 0;
//    if (n % 2 == 0)
//    {
//        z = (a[n / 2] + a[n / 2 - 1]) / 2;
//    }
//    else
//        z = a[n / 2];
//    // �����ݷ�Χ
//    int range = max - min + 1;
//    int count[100] = { 0 };
//
//    for (int i = 0; i < n; ++i)
//    {
//        //���ӳ������±�
//        count[a[i] - min]++;
//    }
//
//    int maxsum = 0;
//    for (int i = 1; i < range; ++i)
//    {
//        if (count[i] > count[maxsum])
//            maxsum = i;
//    }
//
//    printf("%d %d %d", z, p, maxsum + min);
//    return 0;
//}