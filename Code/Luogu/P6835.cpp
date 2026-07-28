#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;
const ll mod = 998244353;

int id, n, m;
std::vector<int> e[MAX];
ll f[MAX], sum[MAX];

void add(ll &x, ll d) { x = (x + d) % mod; }

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> id >> n >> m;
    for (int u, v, i = 1; i <= m; i++) {
        std::cin >> u >> v;
        e[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        add(f[i], e[i].size() + 1);
        for (int v : e[i]) {
            add(f[i], sum[i - 1] - sum[v - 1] + mod);
        }
        add(sum[i], sum[i - 1] + f[i]);
    }
    std::cout << sum[n] << '\n';
    return 0;
}