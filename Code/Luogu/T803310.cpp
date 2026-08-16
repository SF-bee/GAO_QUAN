#include <bits/stdc++.h>
using ll = long long;
const ll MAX = 3e6 + 5;
const ll mod = 1e9 + 7;

ll fact[MAX], infact[MAX];
ll qpow(ll x, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            (res *= x) %= mod;
        (x *= x) %= mod;
        p >>= 1;
    }
    return res;
}
void init() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % mod;
    infact[MAX - 1] = qpow(fact[MAX - 1], mod - 2);
    for (int i = MAX - 2; i >= 0; i--)
        infact[i] = infact[i + 1] * (i + 1) % mod;
}
ll C(int n, int m) {
    if (m < 0 || m > n)
        return 0;
    return fact[n] * infact[m] % mod * infact[n - m] % mod;
}
int T;

int main() {
    freopen("ant2.in", "r", stdin);
    freopen("ant2.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    init();
    std::cin >> T;
    while (T--) {
        ll a, b, c;
        std::cin >> a >> b >> c;
        if (2 * a > c) {
            std::cout << 0 << '\n';
            continue;
        }
        c -= 2 * a;
        ll n = a + b + c;
        std::cout << C(n, a) * C(n - a, b) % mod << '\n';
    }
    return 0;
}
/*
考虑如何处理 a 操作

*/