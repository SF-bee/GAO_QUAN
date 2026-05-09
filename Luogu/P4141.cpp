#include <bits/stdc++.h>
const int MAX = 2e3 + 5;

int n,m,w[MAX],dp[MAX],ans[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> w[i];
    dp[0] = 1;
    for(int i = 1;i <= n;i++)
        for(int j = m;j >= w[i];j--)
            dp[j] = (dp[j] + dp[j - w[i]]) % 10;
    for(int i = 1;i <= n;i++){
        memcpy(ans,dp,sizeof(dp));
        for(int j = w[i];j <= m;j++)
            ans[j] = (ans[j] - ans[j - w[i]] + 10) % 10;
        for(int j = 1;j <= m;j++)
            std::cout << ans[j];
        std::cout << "\n";
    }
    return 0;
}