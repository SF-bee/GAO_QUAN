#include <bits/stdc++.h>
const int MAX = 5e2;

int n;
int dp[MAX],cost[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n;
    std::memset(dp,0x3f,sizeof(dp));
    dp[1] = 0;
    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
            std::cin >> cost[i][j];
    for(int i = 2;i <= n;i++){
        for(int j = 1;j < i;j++){
            dp[i] = std::min(dp[i],dp[j] + cost[j][i]);
        }
    }
    std::cout << dp[n] << '\n';
    return 0;
}