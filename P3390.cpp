#include <bits/stdc++.h>
using ll = long long;
const ll mod = 1e9 + 7;

std::vector<std::vector<ll> > operator * (const std::vector<std::vector<ll> > &a,const std::vector<std::vector<ll> > &b){
    int n = a.size(),m = b.size(),k = b[0].size();
    std::vector<std::vector<ll> > c(n,std::vector<ll>(k));
    for(int i = 0;i < n;i++)
        for(int l = 0;l < m;l++)
            for(int j = 0;j < k;j++)
                c[i][j] = (c[i][j] + a[i][l] * b[l][j] % mod) % mod;
    return c;
}

std::vector<std::vector<ll> > qpow(std::vector<std::vector<ll> > x,ll k){
    std::vector<std::vector<ll> > res(x.size(),std::vector<ll>(x.size()));
    for(int i = 0;i < res.size();i++)
        res[i][i] = 1;
    while (k){
        if(k & 1) res = res * x;
        x = x * x;
        k >>= 1;
    }
    return res;
    
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    ll n,k;
    std::cin >> n >> k;
    std::vector<std::vector<ll> > a(n,std::vector<ll>(n));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            std::cin >> a[i][j];
    a = qpow(a,k);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            std::cout << a[i][j] << " \n"[j == n - 1];
    return 0;
}