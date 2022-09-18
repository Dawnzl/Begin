#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{

    int bagWeight, num;
    cin >> bagWeight >> num;
    vector<int> weight(num);
    vector<int> value(num);
    for (int i = 0; i < num; ++i)
    {
        cin >> weight[i] >> value[i];
    }

    // ��ʼ��
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++)
    { // ������Ʒ
        for (int j = bagWeight; j >= weight[i]; j--)
        { // ������������
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
	return 0;
}


//struct WP {
//    int v;
//    int w;
//    double arg;//����
//};
//
//bool cmp(WP a, WP b)
//{
//    return a.arg > b.arg;
//}
//int main()
//{
//
//    WP* W; // ������Ʒ
//    int n = 0, V = 0;
//    cin >> V >> n; // ��Ʒ�������������
//    W = new WP[n];//��n����Ʒ�ռ�
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> W[i].v;
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> W[i].w;
//        W[i].arg = W[i].w / (W[i].v * 1.0);
//    }
//    sort(W, W + n, cmp);
//    int maxV = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        if (W[i].v <= V)
//        {
//            V -= W[i].v;
//            maxV += W[i].w;
//        }
//        else
//            break;
//    }
//    cout << maxV << endl;
//    return 0;
//}
