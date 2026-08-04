#include <bits/stdc++.h>
using ll = long long;
const int MAX = 4e3 + 5;
const ll mod = 998244353;

int n, m, k;
bool hvis[MAX], lvis[MAX];
ll fact[MAX], infact[MAX];
// dp_i_j 表示考虑到这一行/列，敲了j块的方案数
ll dp1[MAX][MAX], dp2[MAX][MAX];

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % mod;
    auto qpow = [&](ll x, ll p) {
        ll res = 1;
        while (p) {
            if (p & 1)
                (res *= x) %= mod;
            (x *= x) %= mod;
            p >>= 1;
        }
        return res;
    };
    infact[MAX - 1] = qpow(fact[MAX - 1], mod - 2);
    for (int i = MAX - 2; i >= 1; i--)
        infact[i] = infact[i + 1] * (i + 1) % mod;
}
ll A(int x, int y) {
    if (y > x || y < 0 || x < 0)
        return 0;
    return fact[x] * infact[x - y] % mod;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    init();
    std::cin >> n >> m >> k;
    ll r = n, c = m;
    for (int a, b, c, d, i = 1; i <= k; i++) {
        std::cin >> a >> b >> c >> d;
        hvis[a] = hvis[c] = 1;
        lvis[b] = lvis[d] = 1;
    }
    dp1[0][0] = dp2[0][0] = 1;
    for (int i = 1; i <= n; i++)
        if (hvis[i])
            r--;
    for (int i = 1; i <= m; i++)
        if (lvis[i])
            c--;
    for (int i = 1; i <= n; i++) {
        dp1[i][0] = 1;
        for (int j = 1; 2 * j <= r; j++) {
            if (i > 1 && !hvis[i] && !hvis[i - 1])
                (dp1[i][j] += dp1[i - 2][j - 1]) %= mod;
            (dp1[i][j] += dp1[i - 1][j]) %= mod;
        }
    }
    for (int i = 1; i <= m; i++) {
        dp2[i][0] = 1;
        for (int j = 1; 2 * j <= c; j++) {
            if (i > 1 && !lvis[i] && !lvis[i - 1])
                (dp2[i][j] += dp2[i - 2][j - 1]) %= mod;
            (dp2[i][j] += dp2[i - 1][j]) %= mod;
        }
    }

    ll ans = 0;
    for (int i = 0; 2 * i <= n; i++)
        for (int j = 0; 2 * j <= m; j++) {
            (ans += dp1[n][i] * dp2[m][j] % mod * A(r - 2 * i, j) % mod * A(c - 2 * j, i) % mod) %=
                mod;
        }
    std::cout << ans << '\n';
    return 0;
}
/*
注意到行和列是独立的，完全可以先考虑敲哪些行再考虑桥哪些列
*/