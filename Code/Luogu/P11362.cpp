#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;
const int mod = 1e9 + 7;

int T;
int m;
ll n, v;
std::pair<int, int> l[MAX];

void solve() {
    std::cin >> n >> m >> v;
    std::vector<std::pair<int, int>> lim;
    for (int i = 1; i <= m; i++)
        std::cin >> l[i].first >> l[i].second;
    std::sort(l + 1, l + m + 1);
    lim.emplace_back(0, 0);
    for (int i = 1; i <= m; i++) {
        if (l[i].first == l[i - 1].first) {
            if (l[i].second != l[i - 1].second) {
                std::cout << 0 << '\n';
                return;
            }
        } else {
            lim.push_back(l[i]);
        }
    }
    auto qpow = [&](ll x, ll p) -> ll {
        ll res = 1;
        for (; p; x = x * x % mod, p >>= 1)
            if (p & 1) res = res * x % mod;
        return res;
    };
    if (m == 0) {
        std::cout << qpow(v, 2 * n) << '\n';
        return;
    }
    int pre = lim[1].first;
    ll ans = qpow(v, 2 * (lim[1].first - 1)) * qpow(v, 2 * (n - lim.back().first)) % mod;
    for (int i = 2; i < lim.size(); i++) {
        int x = lim[i].first - pre;
        ans = ans * ((qpow(v, 2 * x) - qpow(v, x) + qpow(v, x - 1)) + mod) % mod;
        pre = lim[i].first;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    while (T--)
        solve();
    return 0;
}
/*
注意到一元限制把数列分成了非常鲜明的每一段，那么我们只需要考虑每一段内的方案然后乘法原理就可以了
每一段包括：一个一元限制到下一个一元限制前
所以考虑如果没有单元限制的答案是多少，假设区间长度是 x，然后设 f(x) 表示这个区间的合法方案
有点复杂，不如去考虑不合法的方案，即一种限制，使得区间内一定无解
每一个区间总共有 v^2x 种方案
不合法的应该是第一条的 a 与 d 相同，然后下一条的 a 与这一条的 b 相同
最后一条的 b 与下一段的 d 不同
总共是 v^x - v^{x-1}
所以整个区间的方案数就是
f(x) = v^2x - v^x + v^{x-1}
然后特判第一段和最后一段
*/