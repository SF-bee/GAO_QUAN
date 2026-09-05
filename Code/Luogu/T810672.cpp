#include <bits/stdc++.h>
const int MAX = 4e2 + 4;
const int INF = 0x3f3f3f3f;

int n, m, a[MAX][MAX], t[MAX][MAX];
int val[MAX][MAX][4][4];
int ans[MAX][MAX];

int calc(int r, int c, std::array<int, 4> x) {
    int res = 0, fa[4] = {0, 1, 2, 3};
    auto find = [&](auto &self, int x) -> int { return fa[x] == x ? x : self(self, fa[x]); };
    if (r & 1) fa[find(find, 1)] = find(find, 0);
    if (c & 1) fa[find(find, 3)] = find(find, 0);
    if (r & 2) fa[find(find, 3)] = find(find, 2);
    if (c & 2) fa[find(find, 2)] = find(find, 1);
    for (int i = 0; i < 4; i++) {
        int cnt = 0, cnt1 = 0;
        for (int j = 0; j < 4; j++) {
            if (find(find, j) == i) cnt++, cnt1 += x[j];
        }
        res += std::min(cnt1, cnt - cnt1);
    }
    return res;
}

int main() {
    freopen("dawn.in", "r", stdin);
    freopen("dawn.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    memset(ans, 0x3f, sizeof(ans));
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char ch;
            std::cin >> ch;
            t[i][j] = ch - '0';
        }
    bool flag = 0;
    if (n > m) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                a[j][i] = t[i][j];
        std::swap(n, m);
        flag = 1;
    } else {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                a[i][j] = t[i][j];
    }
    for (int i = 1; i * 2 <= n + 1; i++) {
        for (int j = 1; j * 2 <= m + 1; j++) {
            for (int r = 0; r < 4; r++)
                for (int c = 0; c < 4; c++) {
                    if (2 * i == n + 1 && 2 * j == m + 1) val[i][j][r][c] = 0;
                    else if (2 * i == n + 1 && r & 1)
                        val[i][j][r][c] = val[i][m - j + 1][r][c] = a[i][j] != a[i][m - j + 1];
                    else if (2 * j == m + 1 && c & 1)
                        val[i][j][r][c] = val[n - i + 1][m][r][c] = a[i][j] != a[n - i + 1][m];
                    else
                        val[i][j][r][c] = val[i][n - j + 1][r][c] =
                            val[n - i + 1][n - j + 1][r][c] = val[n - i + 1][j][r][c] =
                                calc(r, c,
                                     {a[i][j], a[i][m - j + 1], a[n - i + 1][m - j + 1],
                                      a[n - i + 1][j]});
                }
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        int x = __builtin_popcount(i);
        // dp_j 表示选择恰好 j 列的最小花费
        std::vector<int> dp(m + 1, INF);
        dp[0] = 0;
        std::array<int, 3> cost;
        for (int j = 1; j * 2 <= m + 1; j++) {
            std::array<int, 4> C = {0, 0, 0, 0};
            std::vector<int> ndp(m + 1, INF);
            for (int k = 1; 2 * k <= n + 1; k++) {
                int b1 = (i >> (k - 1)) & 1;
                int b2 = (i >> (n - k)) & 1;
                int r = (k == n - k + 1) ? b1 : (b1 | (b2 << 1));

                for (int c = 0; c < 4; c++)
                    C[c] += val[k][j][r][c];
            }
            cost[0] = C[0];
            cost[1] = std::min(C[1], C[2]);
            cost[2] = C[3];
            for (int k = 0; k <= m; k++) {
                if (dp[k] == INF) continue;
                ndp[k] = std::min(ndp[k], dp[k] + cost[0]);
                if (k + 1 <= m) ndp[k + 1] = std::min(ndp[k + 1], dp[k] + cost[1]);
                if (k + 2 <= m && j != m - j + 1) {
                    ndp[k + 2] = std::min(ndp[k + 2], dp[k] + cost[2]);
                }
            }
            dp = ndp;
        }
        for (int y = 0; y <= m; y++) {
            ans[x][y] = std::min(ans[x][y], dp[y]);
        }
    }
    for (int i = n; i >= 0; i--)
        for (int j = m; j >= 0; j--)
            ans[i][j] = std::min({ans[i][j], ans[i + 1][j], ans[i][j + 1]});
    for (int i = 0; i <= (flag ? m : n); i++)
        for (int j = 0; j <= (flag ? n : m); j++) {
            int res = flag ? ans[j][i] : ans[i][j];
            std::cout << res << " \n"[j == (flag ? n : m)];
        }
    return 0;
}
/*
分析复杂度，感觉是一个了n^3或者n^2log？
再注意n,m一定有一个是小于18的，那么其实可以2^18 * m？

考虑 n = 1
那么对于所有列的约束它一定是满足的，所以只需要考虑行即可。
对于行，On扫一遍就可以出答案
考虑 n = 2
其实也很容易，相比于n = 1多了个判断要让左边等于右边还是右边等于左边
这似乎启示我们：位置的匹配是固定的，我们可以预处理所有需要互相匹配的位置如果互相匹配的最小代价
然后再注意到一件事情：不同询问之间似乎是存在转移关系的，这次询问应该是从上一行或者上一列的状态转移而来的

每个字符的匹配是独立的，意思是说可以预处理很多个2*2的小块，每个小块之间的匹配是独立的

dp[i]
*/