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

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++)
    { // 遍历物品
        for (int j = bagWeight; j >= weight[i]; j--)
        { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
	return 0;
}


//struct WP {
//    int v;
//    int w;
//    double arg;//均价
//};
//
//bool cmp(WP a, WP b)
//{
//    return a.arg > b.arg;
//}
//int main()
//{
//
//    WP* W; // 设置物品
//    int n = 0, V = 0;
//    cin >> V >> n; // 物品个数，背包体积
//    W = new WP[n];//开n个物品空间
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
