#include <bits/stdc++.h>
#define int long long
const int MAX = 1e5 + 5;

int n,a[20],v[20] = {0,1,3,5,7,9,10,11,14,15,17};
int f[20],dp[MAX];  //f_j表示运载重量为j的船能获得的最大收益

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= 10;i++)
        std::cin >> a[i];
    //init
    for(int i = 1;i <= 10;i++)
        for(int j = i;j <= 10;j++)
            f[j] = std::max(f[j],f[j - i] + a[i]);
    for(int i = 1;i <= 10;i++)
        f[i] = f[i] - v[i];
    //看作一个大小为n的背包用装不同的船
    for(int i = 1;i <= 10;i++)
        for(int j = i;j <= n;j++)
            dp[j] = std::max(dp[j],dp[j - i] + f[i]);
    
    std::cout << *std::max_element(dp + 1,dp + n + 1);
    return 0;
}