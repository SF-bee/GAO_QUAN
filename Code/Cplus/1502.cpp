/*
给定若干个数据的大小关系，求出其中能确定排名的数据的个数。

考虑第一名：一定能从该节点到达其他所有节点
考虑最后一名：所有其他节点一定能到达该节点

? 首先确定的一定是最后一名或者第一名吗？
不是，它可以被若干个节点指向再指向若干个节点
*/
#include <bits/stdc++.h>
const int MAX = 1e2 + 5;

int n, m;
std::vector<int> g1[MAX], g2[MAX];
std::array<int, MAX> id1, id2;
std::bitset<MAX> in[MAX], out[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int u, v, i = 1; i <= m; i++) {
        std::cin >> u >> v;
        g1[u].push_back(v);
        g2[v].push_back(u);
        id1[v]++, id2[u]++;
    }
    for (int i = 1; i <= n; i++)
        in[i].set(i), out[i].set(i);

    {
        std::queue<int> id0;
        for (int i = 1; i <= n; i++) {
            if (id1[i] == 0)
                id0.push(i);
        }
        while (!id0.empty()) {
            int u = id0.front();
            id0.pop();
            for (auto v : g1[u]) {
                id1[v]--;
                in[v] |= in[u];
                if (id1[v] == 0)
                    id0.push(v);
            }
        }
    }
    {
        std::queue<int> id0;
        for (int i = 1; i <= n; i++) {
            if (id2[i] == 0)
                id0.push(i);
        }
        while (!id0.empty()) {
            int u = id0.front();
            id0.pop();
            for (auto v : g2[u]) {
                id2[v]--;
                out[v] |= out[u];
                if (id2[v] == 0)
                    id0.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i].count() + out[i].count() - 1 == n)
            ans++;
    }
    std::cout << ans << '\n';
    return 0;
}