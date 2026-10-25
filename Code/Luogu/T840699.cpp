#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

int n, m;
std::vector<int> g[MAX];

void sol1() {
    auto bfs = [&](int s, int t) {
        std::vector<int> frm(n + 1);
        std::vector<bool> vis(n + 1);
        std::queue<std::pair<int, int>> q;
        for (q.push({s, 0}), vis[s] = 1; !q.empty();) {
            auto [u, d] = q.front();
            q.pop();
            if (u == t) {
                for (int x = u; x != s; x = frm[x])
                    g[x].push_back(frm[x]);
                return d;
            }
            for (auto v : g[u])
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, d + 1});
                    frm[v] = u;
                }
        }
    };
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        int dis = bfs(i - 1, i);
        std::cout << ans + dis << '\n';
        ans += dis;
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int u, v, i = 1; i <= m; i++)
        std::cin >> u >> v, g[u].push_back(v);

    if (n <= 5e3) sol1();
    return 0;
}
/*
边不大于点，又保证连通，这特么什么鬼啊
哦，基环树
就是最多只会有一个简单环
那就可以考虑树的情况怎么搞，环的情况怎么搞
必须要一步一步完成，那么 2 就一定是要第一个完成的，那么我们就有了一个 n^2 的做法
从 1 搜到 2，然后记录经过的点，修改为无向边，以 2 为起点，再跑一次
每次的复杂度n + m，跑 n 次，就是n(n + m)
*/