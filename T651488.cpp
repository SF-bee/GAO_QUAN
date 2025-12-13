#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 998244353;
const int MAX = 2e6 + 5;

int n;
ll fact[MAX],infa[MAX];

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
    return ((fact[n] * infa[m]) % mod * infa[n - m] % mod) % mod;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    fact[0] = infa[0] = 1;
    for(int i = 1;i < MAX;i++)
        fact[i] = fact[i - 1] * i % mod,infa[i] = innum(fact[i]); 
    std::cout << (2 * c(2 * n - 1,n) - n) % mod << '\n';
    return 0;
}