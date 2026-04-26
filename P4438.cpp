/*
对于每一个节点，它有四种决策：
1. 不翻修
2. 翻修公路
3. 翻修铁路
4. 都翻修

dp_i_j_k表从根示到达 i 点时，j 条公路未修复，k条铁路未修复的最小费用
dp_u_j_k = (u为父节点，v为子节点)
    若 op = 0 翻修公路 dp_u_j_k = dp_v_{j + 1}_{k}
    若 op = 1 翻修铁路 dp_u_j_k = dp_v_{j}_{k + 1}
*/
#include <bits/stdc++.h>
using ll = long long;
const int MAX = 4e4 + 5;
const int K = 50;

int n;
struct edge { // 反向边
    int v;    // 该边来自的点
    bool op;  // 边的类型，0/1 = 公路/铁路
};
std::array<int, MAX> a, b, c;
std::vector<edge> g[MAX]; // 城市的编号为1 ~ n-1，乡村的编号为 n ~ 2n-1
ll dp[MAX][K][K];         // dp_i_j_k表从根示到达 i 点时，j 条公路未修复，k条铁路未修复的最小费用

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int s, t, i = 1; i < n; i++) {
        std::cin >> s >> t;
        if (s > 0)
            g[i].emplace_back(s, 0);
        else
            g[i].emplace_back(n - 1 - s, 0);
        if (t > 0)
            g[i].emplace_back(t, 1);
        else
            g[i].emplace_back(n - 1 - t, 1);
    }
    for (int i = 1; i <= n; i++)
        std::cin >> a[i] >> b[i] >> c[i];

    std::memset(dp, 0x3f, sizeof(dp));
    auto dfs = [&](auto &self, int u, int i, int j) -> ll {
        if(g[u].size() == 0)
            return 
    };
    std::cout << dfs(dfs, 1, 0, 0);
    return 0;
}