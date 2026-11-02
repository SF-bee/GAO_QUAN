#include <bits/stdc++.h>
using ll = long long;

ll safe_ceil(ll a, ll b) { return a <= 0 ? 0 : (a - 1) / b + 1; }

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    ll k, p, e;
    if (!(std::cin >> k >> p >> e))
        return 0;

    if (e == 1)
        return std::cout << 0 << '\n', 0;
    if (p <= 1)
        return std::cout << safe_ceil(e - 1, k) << '\n', 0;

    ll ans = safe_ceil(e - 1, k);
    ll current_spent = 0;
    ll pos = e;

    while (pos >= p) {
        ll d = pos % p;

        current_spent += safe_ceil(d, k) + 1;
        pos /= p;
        ans = std::min(ans, current_spent + safe_ceil(pos - 1, k));
    }

    std::cout << ans << '\n';
    return 0;
}