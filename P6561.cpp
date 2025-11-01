#include <bits/stdc++.h>
typedef unsigned long long ll;
const ll MAX = 1e6 + 5;
const ll mod = 998244353;

int T;
ll fact[MAX],infact[MAX];
ll m,a,b;

ll innum(ll a){
    ll res = 1,p = mod - 2;
    while(p){
        if(p & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }
    return res % mod;
}
ll c(ll n,ll m){
    return ((fact[n] * infact[m]) % mod * infact[n - m] % mod) % mod;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    fact[0] = infact[0] = 1;
    for(int i = 1;i < MAX;i++)
        fact[i] = fact[i - 1] * i % mod,infact[i] = innum(fact[i]);    
    std::cin >> T;
    while(T--){
        std::cin >> m >> a >> b;
        std::cout << c(m - a,b) * c(m - b,a) % mod << '\n';
    }
    return 0;
}