#include <bits/stdc++.h>
using ll = long long;
const int MOD = 1e9 + 7;

int T, n, m;
ll v;

ll qpow(ll x, ll c) {
    ll res = 1;
    while (c) {
        if (c & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        c >>= 1;
    }
    return res;
}

void solve() {
    std::cin >> n >> m >> v;
    std::map<int, int> auk;
    bool conflict = false;
    
    for (int i = 0; i < m; i++) {
        int c, d;
        std::cin >> c >> d;
        if (auk.count(c) && auk[c] != d) {
            conflict = true;
        }
        auk[c] = d;
    }
    if (conflict) {
        std::cout << "0\n";
        return;
    }
    if (auk.empty()) {
        ll ans = qpow(v * v % MOD, n - 1);
        std::cout << ans << '\n';
        return;
    }
    ll ans = 1;
    int first_pos = auk.begin()->first;
    if (first_pos > 1) {
        ans = ans * qpow(v * v % MOD, first_pos - 1) % MOD;
    }
    
    auto it = auk.begin();
    auto next_it = it;
    ++next_it;
    
    while (next_it != auk.end()) {
        int l = it->first;
        int r = next_it->first;
        int gap = r - l - 1;
        
        if (gap > 0)
            ans = ans * qpow(v * v % MOD, gap) % MOD;
        if (it->second != next_it->second){
            ll ways = (v * v - (v - 1) + MOD) % MOD;
            ans = ans * ways % MOD;
        }
        else ans = ans * (v * v % MOD) % MOD;
        
        ++it;
        ++next_it;
    }
    
    int last_pos = auk.rbegin()->first;
    if (last_pos < n) {
        ans = ans * qpow(v * v % MOD, n - last_pos) % MOD;
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