/*
考虑差分约束
dis[v] <= dis[u] + d
对于约束 1
b - a <= d  => 从a向b建一条长度为d的边
对于约束 2
b - a >= s  => 从b向a建一条长度为-d的边
考虑关于无解情况2
等价于没有
*/
#include <bits/stdc++.h>
const int MAX = 1e3 + 5;
const int INF = 0x3f3f3f3f;

int n, l1, l2;
std::array<int, MAX> dis;
std::vector<std::pair<int, int>> g[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> l1 >> l2;
    for (int i = 1; i < n; i++)
        g[i + 1].push_back({i, 0});
    for (int a, b, d, i = 1; i <= l1; i++) {
        std::cin >> a >> b >> d;
        g[a].push_back({b, d});
    }
    for (int a, b, d, i = 1; i <= l2; i++) {
        std::cin >> a >> b >> d;
        g[b].push_back({a, -d});
    }
    auto bmf = [&]() {
        dis.fill(INF);
        dis[1] = 0;
        for (int i = 1; i < n; i++) {
            bool flag = 0;
            for (int j = 1; j <= n; j++)
                for (auto [v, w] : g[j]) {
                    if (dis[v] > dis[j] + w) {
                        dis[v] = dis[j] + w;
                        flag = 1;
                    }
                }
            if (!flag)
                return 1;
            if (i == n - 1)
                return 0;
        }
        return 0;
    };
    if (!bmf())
        std::cout << -1 << '\n';
    else if (dis[n] == INF)
        std::cout << -2 << '\n';
    else
        std::cout << dis[n] << '\n';
}
/*
x2 - x1 <= 2
x3 - x2 <= 1
x3 - x1 <= 2

*/