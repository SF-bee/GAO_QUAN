/*
dp
设计状态 dp[i][j] 表示以i,j为最大正方形
考虑到达了点 (i,j) 若它可以组成一个新的正方形，当且仅当：
    a[i][j] = 1
若它可以扩大原有的正方形，那么新正方形的边长为
    std::min(dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1]) + 1
    (短板效应)
*/
#include <bits/stdc++.h>
const int MAX = 1e2 + 5;

int n, m;
int a[MAX][MAX], dp[MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j]) {
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = std::max(ans, dp[i][j]);
    std::cout << ans * ans << '\n';
    return 0;
}