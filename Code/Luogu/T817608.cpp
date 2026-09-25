#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

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
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
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