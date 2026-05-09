#include <bits/stdc++.h>
using ll = long long;

std::vector<std::vector<ll> > operator * (const std::vector<std::vector<ll> > &a,const std::vector<std::vector<ll> > &b){
    int n = a.size(),m = b.size(),k = b[0].size();
    std::vector<std::vector<ll> > c(n,std::vector<ll>(k));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < k;j++)
            for(int l = 0;l < m;l++)
                c[i][j] += a[i][l] * b[l][j];
    return c;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<ll> > a(n,std::vector<ll>(m));
    std::vector<std::vector<ll> > b(m,std::vector<ll>(k));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            std::cin >> a[i][j];
    for(int i = 0;i < m;i++)
        for(int j = 0;j < k;j++)
            std::cin >> b[i][j];
    std::vector<std::vector<ll> > c(n,std::vector<ll>(k));
    c = a * b;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < k;j++)
            std::cout << c[i][j] << " \n"[j == k - 1];
    return 0;
}