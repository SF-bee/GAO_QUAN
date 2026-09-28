#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

<<<<<<< HEAD
int n, k;
std::pair<int, int> p[MAX];
std::vector<int> sp[9];

void in(int x) {
    int id = 0;
    if (p[x].first >= k + 1 && p[x].first <= 2 * k) id += 1;
    else if (p[x].first >= 2 * k + 1)
        id += 2;
    if (p[x].second >= k + 1 && p[x].second <= 2 * k) id += 3;
    else if (p[x].second >= 2 * k + 1)
        id += 6;
    sp[id].push_back(x);
=======
int n, K;
std::pair<int, int> a[MAX];
int ans = 0;
bool vis[MAX];
std::vector<std::tuple<int, int, int>> anslist;

int getval(std::tuple<int, int, int> x) {
    auto [u, v, w] = x;
    return std::max({a[u].first, a[v].first, a[w].first}) -
           std::min({a[u].first, a[v].first, a[w].first}) +
           std::max({a[u].second, a[v].second, a[w].second}) -
           std::min({a[u].second, a[v].second, a[w].second});
}
void dfs(int d, int res, std::vector<std::tuple<int, int, int>> &list) {
    if (d == K + 1) {
        if (res > ans) ans = res, anslist = list;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        for (int j = i + 1; j <= n; j++) {
            if (vis[j]) continue;
            for (int k = j + 1; k <= n; k++) {
                if (vis[k]) continue;
                vis[i] = vis[j] = vis[k] = 1;
                list.push_back({i, j, k});
                dfs(d + 1, res + getval({i, j, k}), list);
                list.pop_back();
                vis[i] = vis[j] = vis[k] = 0;
            }
        }
        break;
    }
>>>>>>> 8f29663709386cdcf92c355f91ef6a05e9b1df2a
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
<<<<<<< HEAD
    k = n / 3;
    for (int i = 1; i <= n; i++)
        std::cin >> p[i].first >> p[i].second, in(i);

    std::cout << 4ll * k * k << '\n';
    std::array<std::array<int, 3>, 6> ch = {
        {{0, 4, 8}, {0, 5, 7}, {1, 3, 8}, {1, 5, 6}, {2, 3, 7}, {2, 4, 6}}};
    for (int i = 1; i <= n; i++)
        for (auto [a, b, c] : ch)
            if (sp[a].size() && sp[b].size() && sp[c].size()) {
                std::cout << sp[a].back() << ' ' << sp[b].back() << ' ' << sp[c].back() << '\n';
                sp[a].pop_back(), sp[b].pop_back(), sp[c].pop_back();
            }

    return 0;
}
/*
考虑答案上界，注意到a,b是独立贡献的。
最大的取 2k + 1 ～ 3k，就是 (5k + 1)k/2
最小的取 1 ～ k,就是 (k + 1)k/2
相减就是最大值。b同理
那么，考虑我们是如何取到这个最大值的？
考虑分成三个部分：
0 1 2
3 4 5
6 7 8
*/
=======
    K = n / 3;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].first >> a[i].second;

    std::vector<std::tuple<int, int, int>> ls;
    dfs(1, 0, ls);
    std::cout << ans << '\n';
    for (auto &[i, j, k] : anslist)
        std::cout << i << ' ' << j << ' ' << k << '\n';
    return 0;
}
>>>>>>> 8f29663709386cdcf92c355f91ef6a05e9b1df2a
