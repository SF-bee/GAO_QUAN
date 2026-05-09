#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1e9 + 7;
const int MAX = 1e6 + 5;

ll fact[MAX],infa[MAX],d[MAX];
ll qpow(ll a,ll p){
    ll res = 1;
    while(p){
        if(p & 1) res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}
void init(){
    fact[0] = infa[0] = 1;
    d[1] = 0,d[0] = d[2] = 1;
    for(int i = 1;i < MAX;i++)
        fact[i] = (fact[i - 1] * i) % mod,
        infa[i] = qpow(fact[i],mod - 2);
    for(int i = 3;i < MAX;i++)
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % mod;
}
ll c(ll n,ll m) {return (fact[n] * infa[m] % mod) * infa[n - m] % mod;}
int T;
ll n,m;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    init();
    std::cin >> T;
    while(T--){
        std::cin >> n >> m;
        std::cout << c(n,m) * d[n - m] % mod << '\n';
    }
    return 0;
}