#include <bits/stdc++.h>
const int MAX = 200;

int n,a[MAX][MAX],sum[MAX][MAX];
int dp[MAX];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) {
            std::cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    
    int ans = INT_MIN;
    for(int u = 1;u <= n;u++) //枚举上边界
        for(int d = u;d <= n;d++) { //枚举下边界
            //最大子段和
            for(int i = 1;i <= n;i++){
                int tsum = sum[d][i] - sum[d][i - 1] - sum[u - 1][i] + sum[u - 1][i - 1];
                dp[i] = std::max(tsum,dp[i - 1] + tsum);
                ans = std::max(ans,dp[i]);
            }
        }
    std::cout << ans << '\n';
    return 0;
}