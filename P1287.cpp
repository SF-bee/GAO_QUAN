#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 20;

ll qpow(ll x,int p){
    ll res = 1;
    while(p){
        if(p & 1)
            res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}
ll n,r,c[MAX][MAX]; //c_i_j 表示在 i 个里面选 j 个

int main(){
    c[0][0] = 1;
    for(int i = 1;i <= 15;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    std::cin >> n >> r;
    ll ans = 0;
    for(int i = 0;i <= r;i++){
        if(i % 2 == 0) ans += c[r][i] * qpow(r - i,n);
        else ans -= c[r][i] * qpow(r - i,n);
    }
    std::cout << ans << '\n';
    return 0;
}