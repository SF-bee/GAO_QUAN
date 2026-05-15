#include <bits/stdc++.h>
const int T = 20;
const int MAX = 1e5 + 5;

int v, n, t;
std::vector<std::pair<int, int>> term[T];
std::array<int, MAX> dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> v >> n >> t;
    for (int w, c, p, i = 1; i <= n; i++) {
        std::cin >> w >> c >> p;
        term[p].push_back({w, c});
    }

    for (int i = 1; i <= t; i++) {
        for (int j = v; j >= 0; j--) {
            for (auto [w, v] : term[i])
                if (w <= j) {
                    dp[j] = std::max(dp[j], dp[j - w] + v);
                }
        }
    }
    std::cout << dp[v];
    return 0;
}