#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e7 + 5;

int n,tot;
ll f[MAX],e[MAX],vis[MAX],prm[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    f[1] = 1;
    for(int i = 2;i <= n;i++){
        if(!vis[i]){
            f[i] = e[i] = 1;
            prm[++tot] = i;
        }
        for(int j = 1;j <= tot && i * prm[j] <= n;j++){
            ll p = prm[j];
            vis[i * p] = 1;
            if (i % p == 0) {
                e[i * p] = e[i] + 1;
                f[i * p] = f[i] / e[i] * e[i * p];
                break;
            }
            else {
                e[i * p] = 1;
                f[i * p] = f[i];
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++)
        ans ^= f[i];
    std::cout << ans << '\n';
    return 0;
}