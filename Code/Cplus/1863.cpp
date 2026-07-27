/*
题目翻译：
给定若干个限制形如：x_u - x_v >= w
求出以下 a
x_n - x_1 <= a

dis_v - dis_u >= w;
*/

#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n, m;
std::vector<std::pair<int, int>> g[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio;

    std::cin >> n >> m;
    for (int u, v, w, i = 1; i <= m; i++) {
        std::cin >> u >> v >> w;
        g[v].emplace_back(w, u);
    }

    for ()
        return 0;
}