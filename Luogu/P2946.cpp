#include <bits/stdc++.h>
const int mod = 1e8;
const int N = 2e3 + 5;

int n,f;
int r[N],dp[N][N];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> f;
    for(int i = 1;i <= n;i++)
        std::cin >> r[i],r[i] %= f,dp[i][r[i]] = 1;
    for(int i = 1;i <= n;i++)
        for(int j = 0;j < f;j++)
            dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i - 1][(j - r[i] + f) % f]) % mod;    
    std::cout << dp[n][0] << '\n';
    return 0;
}