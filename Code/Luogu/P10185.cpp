#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 2e5 + 5;
const int mod = 1e9 + 7;

ll qpow(ll x,ll p){
    ll res = 1;
    while(p){
        if(p & 1) res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}

int n;
ll sum,ans,a[MAX],v[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],sum += a[i];
    for(int i = 1;i <= n;i++)
        std::cin >> v[i];
    for(int i = 1;i <= n;i++)
        ans = (ans + qpow(2,sum - a[i]) * (qpow(v[i] + 1,a[i]) - 1) % mod) % mod;
    std::cout << ans << '\n';
    return 0;
}