#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 100003;

ll m,n;

ll qpow(ll x,ll p){
    ll res = 1;
    while(p){
        if(p & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> m >> n;
    ll ans = qpow(m,n);
    ans = (ans - m * qpow(m - 1,n - 1) % mod + mod) % mod;
    std::cout << ans << '\n';
    return 0;
}