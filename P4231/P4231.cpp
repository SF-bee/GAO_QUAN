#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e7 + 5;

int n,m;
ll c1[MAX],c2[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    int l,r,s,e,p;
    for(int i = 1;i <= m;i++){
        std::cin >> l >> r >> s >> e;
        p = (e - s) / (r - l);
        c1[l] += s - p;
        c1[r + 1] -= e;
        c2[l] += p;
        c2[r + 1] -= p;
    }
    // for(int i = 1;i <= n;i++) std::cout << c1[i] << " \n"[i == n];
    ll sum = 0,maxa = 0;
    for(int i = 1;i <= n;i++) c1[i] += c1[i - 1],c2[i] += c2[i - 1];
    for(int i = 1;i <= n;i++) c2[i] += c2[i - 1],c1[i] += c2[i],sum ^= c1[i],maxa = std::max(maxa,c1[i]);
    // for(int i = 1;i <= n;i++) std::cout << c1[i] << " \n"[i == n];
    std::cout << sum << ' ' << maxa << '\n';
    return 0;
}