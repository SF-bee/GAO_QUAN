#include <bits/stdc++.h>
using ll = long long;
const int MAX = 60;

ll tra[MAX][MAX];
std::map<ll, std::vector<std::pair<ll, ll>>> mp;

int main() {
    freopen("balloon.in", "r", stdin);
    freopen("balloon.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    tra[0][0] = 1;
    for (int n = 1; n < MAX; n++) {
        for (int k = 0; k <= n; k++) {
            tra[n][k] += tra[n - 1][k];
            if (k > 0) tra[n][k] += tra[n - 1][k - 1];
            if (n >= 2 && k >= 1 && k < n) mp[tra[n][k]].emplace_back(n, k);
        }
    }
    int T;
    std::cin >> T;
    while (T--) {
        ll m;
        std::cin >> m;
        std::set<std::pair<ll, ll>> ans;
        if (m <= 1) {
            std::cout << "0\n";
            continue;
        }
        if (mp.count(m))
            for (auto &[n, k] : mp[m])
                ans.insert({n, k});
        if (m >= 2) {
            ans.insert({m, 1});
            ans.insert({m, m - 1});
        }
        auto C = [&](ll n, ll k) -> __int128 {
            __int128 res = 1;
            for (ll i = 1; i <= k; ++i) {
                ll a = n - k + i;
                if (res * a > (__int128)m * i) return (__int128)m + 1;
                res = res * a / i;
            }
            return res;
        };
        auto find = [&](int k) {
            ll ans = 1;
            for (int l = 60, r = 5e7, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) {
                if (C(mid, k) <= m) l = (ans = mid) + 1;
                else
                    r = mid - 1;
            }
            if (C(ans, k) == m) return ans;
            else
                return -1ll;
        };
        for (int k = 2; k <= 26; k++) {
            ll res = find(k);
            if (res != -1) ans.insert({res, k}), ans.insert({res, res - k});
        }
        std::cout << ans.size() << '\n';
        for (auto &[n, k] : ans)
            std::cout << n << ' ' << k << '\n';
    }
    return 0;
}
