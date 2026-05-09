/*
注意到方格取数变式：
考虑dp
! 关键性质注意：
    1. 每个路径长度应该是等长的
    2. 每次转移应该是同时进行的

设dp[d][i][j][k] 表示当前对角线为d,三条路径分别到达第 i，j，k，行时的最大收益
! 考虑当走到同一个点时：
    应当只进行一次收益记录

考虑转移
    每一个点从上面或者左边转移而来，总共有2^3种组合
*/
#include <bits/stdc++.h>
const int MAX = 50;

int n, map[MAX][MAX];
int dp[MAX][MAX][MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> map[i][j];

    // 统计这种状态的分数
    auto GetMarks = [&](int d, int i, int j, int k) -> int {
        int yi = d - i;
        int yj = d - j;
        int yk = d - k;
        // 三个不同
        if (i != j && j != k && i != k)
            return map[i][yi] + map[j][yj] + map[k][yk];
        // 两个不同
        else if (i == j && i != k)
            return map[i][yi] + map[k][yk];
        else if (i == k && i != j)
            return map[i][yi] + map[j][yj];
        else if (j == k && i != j)
            return map[j][yj] + map[i][yi];
        // 全都相同
        else
            return map[i][yi];
    };
    for (int d = 2; d <= 2 * n; d++)
        for (int i = 1; i <= std::min(d, n); i++)
            for (int j = 1; j <= std::min(d, n); j++)
                for (int k = 1; k <= std::min(d, n); k++) {
                    int yi = d - i;
                    int yj = d - j;
                    int yk = d - k;
                    dp[d][i][j][k] =
                        std::max({dp[d - 1][i - 1][j - 1][k - 1], dp[d - 1][i - 1][j - 1][k],
                                  dp[d - 1][i - 1][j][k - 1], dp[d - 1][i - 1][j][k],
                                  dp[d - 1][i][j - 1][k - 1], dp[d - 1][i][j - 1][k],
                                  dp[d - 1][i][j][k - 1], dp[d - 1][i][j][k]}) +
                        GetMarks(d, i, j, k);
                }
    std::cout << dp[2 * n][n][n][n];
    return 0;
}
/*
  1 2 3 4
1 2 3 4 5
2 3 4 5 0
3 4 5 0 0
4 5 6 7 8
*/