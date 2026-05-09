/*
考虑两次路径：
可以证明，题目等价于寻找两条路径，使得价值总和最大

考虑状态的定义：
* dp[x1][y1][x2][y2]
* 表示路径1到x1,y1，路径2到x2,y2的最大价值总和

考虑转移：
两条路径同时转移,两条路径不能同时转移同一个点
*/
#include <bits/stdc++.h>
const int MAX = 55;

int n, m;
int maze[MAX][MAX];
int dp[MAX][MAX][MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> maze[i][j];

    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = x1 + 1; x2 <= n; x2++) {
                for (int y2 = 1; y2 <= y1 - 1; y2++) {
                    dp[x1][y1][x2][y2] =
                        std::max({dp[x1 - 1][y1][x2 - 1][y2], dp[x1 - 1][y1][x2][y2 - 1],
                                  dp[x1][y1 - 1][x2 - 1][y2], dp[x1][y1 - 1][x2][y2 - 1]}) +
                        maze[x1][y1] + maze[x2][y2];
                }
            }
        }
    }
    std::cout << dp[n - 1][m][n][m - 1] << '\n';
    return 0;
}