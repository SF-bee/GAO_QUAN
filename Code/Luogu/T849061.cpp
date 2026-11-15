#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;
const int INF = 2 * 0x3f3f3f3f;
const ll mod = 998244353;

int n, D;
int a[MAX];

void sol1() {
    // 搜索，记录当前到第几个，上一个在哪，然后记录切分点
    std::vector<bool> vis(n + 1);
    int ans = 0;
    auto dfs = [&](auto &self, int d, bool lst) -> void {
        if (d == n + 1) {
            if (!vis[n]) return;
            int cnt = 0, minT = INF, maxT = -INF;
            for (int i = 1; i <= n; i++) {
                cnt += a[i];
                if (vis[i]) {
                    minT = std::min(minT, cnt);
                    maxT = std::max(maxT, cnt);
                    cnt = 0;
                }
            }
            if (cnt) {
                minT = std::min(minT, cnt);
                maxT = std::max(maxT, cnt);
            }
            if (maxT - minT <= D) ans++;
            return;
        }
        if (lst) {
            vis[d] = 1;
            self(self, d + 1, 1);
            vis[d] = 0;
            self(self, d + 1, 0);
        } else {
            vis[d] = 1;
            self(self, d + 1, 1);
            vis[d] = 0;
        }
    };
    dfs(dfs, 1, 1);
    std::cout << ans << '\n';
}
void sol2() {
    // a 都一样，直接可以有答案
    // 不能分不一样的
    if (a[1] > D) {
        if (n % 2 == 0) std::cout << 2 << '\n';
        else
            std::cout << 1 << '\n';
    } else {
        // 斐波那契
        std::vector<ll> f(n + 3);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n + 2; i++)
            f[i] = (f[i - 1] + f[i - 2]) % mod;
        std::cout << f[n] << '\n';
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> D;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (i > 1 && a[i] != a[i - 1]) flag = 0;
    }

    if (n <= 20) sol1();
    else if (flag)
        sol2();
    return 0;
}