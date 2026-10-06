#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n;
char c[MAX];
std::vector<int> g[MAX];
std::unordered_set<std::string>

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];
    for (int u, v, i = 1; i < n; i++) {
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto dfs = [&](auto &self, int u, int fa) -> void {
        int id = trie.push(pre, u, (u != 1 && g[u].size() == 1));
        for (auto v : g[u])
            if (v != fa) {
                self(self, v, u, id);
            }
    };
    return 0;
}