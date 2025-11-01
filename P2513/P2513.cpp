#include <bits/stdc++.h>
const int MAX = 1e3 + 5;
const int MOD = 1e4;

int n,k;
int dp[MAX][MAX],sum[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    dp[0][0] = 1;
    for(int i = 0;i <= k;i++) sum[0][i] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= k;j++){
            dp[i][j] = sum[i - 1][j];
            if(j - i >= 0) dp[i][j] -= sum[i - 1][j - i];
            sum[i][j] = dp[i][j];
            if(j > 0) sum[i][j] += sum[i][j - 1];
            dp[i][j] %= MOD;
            sum[i][j] %= MOD;
        }
    }
    std::cout << (dp[n][k] >= 0 ? dp[n][k] : dp[n][k] + MOD) << '\n';
    return 0;
}