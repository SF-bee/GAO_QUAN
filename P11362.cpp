#include <bits/stdc++.h>
using ll = long long;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int T,n,m;
ll v;

ll qpow(ll x,ll c){
    ll res = 1;
    while (c){
        if(c & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        c >>= 1;
    }
    return res;
}

void solve(){
    std::cin >> n >> m >> v;
    std::map<int,int> auk;
    for(int c,d,i = 1;i <= m;i++){
        std::cin >> c >> d;
        if(auk.count(c) == 0) auk[c] = d;
        else if(auk[c] == d){
            std::cout << 0;
            return;
        }
    }
    ll ans = qpow(v,2*((*auk.begin()).first - 1));
    for(auto i = auk.begin();i != auk.end();i++){
        auto p = i;
        int l = (*p).first,r = (*(++p)).first;
        if(p == --auk.end()) break;
        ll cnt = qpow(v,(r - l - 1)) * (v - 1) % MOD;
        cnt = (qpow(v,2*(r - l)) - cnt + MOD) % MOD;
        ans = ans * cnt % MOD;
    }
    ans = ans * qpow(v,2*(n - (*auk.rbegin()).first)) % MOD;
    std::cout << ans << '\n';
}

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> T;
    while(T--)
        solve();
    return 0;
}