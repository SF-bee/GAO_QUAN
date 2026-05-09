#include <bits/stdc++.h>
using ll = long long;
const int MAX = 16;
const int mod = 1e8;

ll n,m,a[MAX],f[MAX][1 << MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    int upc = 1 << m;
    for(int i = 1;i <= n;i++){
        for(int in,j = m - 1;j >= 0;j--){
            std::cin >> in;
            if(in == 1) a[i] |= (1 << j);
        }
    }

    for(int fs = 1,s0 = a[1];fs;fs = (s0 == 0 ? 0 : 1),s0 = (s0 - 1) & a[1]) if(!(s0 & (s0 << 1)))
        f[1][s0] = 1;
    for(int i = 1;i < n;i++)
        for(int fj = 1,j = a[i];fj;fj = (j == 0 ? 0 : 1),j = (j - 1) & a[i]) if(!(j & (j << 1)))
            for(int fk = 1,k = a[i + 1];fk;fk = (k == 0 ? 0 : 1),k = (k - 1) & a[i + 1]) if(!(k & (k << 1))){
                if(!(j & k)){
                    f[i + 1][k] = (f[i + 1][k] + f[i][j]) % mod;
                }
            }
                
    ll res = 0;
    for(int fs = 1,s0 = a[n];fs;fs = (s0 == 0 ? 0 : 1),s0 = (s0 - 1) & a[n])
        res = (res + f[n][s0]) % mod;
    std::cout << res << '\n';
    return 0;
}