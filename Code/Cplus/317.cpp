#include <bits/stdc++.h>
const int MAX = 1e2 + 5;

int n, m;
int maze[MAX][MAX], dp[MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> maze[i][j];

    dp[1][1] = maze[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1)
                continue;
            else if (i == 1)
                dp[i][j] = dp[i][j - 1] + maze[i][j];
            else if (j == 1)
                dp[i][j] = dp[i - 1][j] + maze[i][j];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + maze[i][j];
        }
    }
    std::cout << dp[n][m];
    return 0;
}