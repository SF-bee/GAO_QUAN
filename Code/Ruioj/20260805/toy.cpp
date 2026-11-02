#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int n, m, k;
ll a[20][MAX];
void solve1() {
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ll mx = 0;
        for (int j = 1; j <= n; j++)
            mx = std::max(mx, a[j][i]);
        ans += mx;
    }
    std::cout << ans << '\n';
}
bool vis[10][10];
void solve2() {
    ll ans = 0;
    auto dfs = [&](auto &self, int d, ll sum) -> void {
        if (d > m) {
            ans = std::max(ans, sum);
            return;
        }
        for (int i = d - k + 1; i <= d; i++) {
            for (int j = 1; j <= n; j++) {
                if (!vis[j][i]) {
                    vis[j][i] = 1;
                    self(self, d + 1, sum + a[j][i]);
                    vis[j][i] = 0;
                }
            }
        }
    };
    dfs(dfs, k, 0);
    std::cout << ans << '\n';
}

int main() {
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
            a[i][j] = std::max(0ll, a[i][j]);
        }
    if (k == 1)
        solve1();
    else if (m <= 5)
        solve2();
    return 0;
}
/*
负数的直接改成 0，这样保证即使选了也相当于没选


先考虑单行的，反悔贪心应该是
维护一个选择队列和一个放弃栈，
从第1个开始滑动窗口，队列长度保证为当前可以进行选择的次数
先考虑栈
如果新入队元素小于栈顶，那么就

我们可以把每一行压成一行全部一起考虑


*/