#include <bits/stdc++.h>
const int M = 1e3 + 5;
const int MAX = 1e6 + 5;

int n,m;
int w[M],l[M],r[M],dp[M];
bool vis[M][MAX],ans[M]; //记录选不选

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::cin >> w[i] >> l[i] >> r[i];
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= r[i];j--){
            if(dp[j] < dp[j - r[i]] + w[i]) dp[j] = dp[j - r[i]] + w[i],vis[i][j] = 1;
        }
    }
    std::cout << dp[m] << '\n';
    for(int i = n;i >= 1;i--){
        if(vis[i][m]){
            ans[i] = 1;
            m -= r[i];
        }
    }
    for(int i = 1;i <= n;i++) std::cout << ans[i] << ' ';
    return 0;
}