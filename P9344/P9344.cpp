#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 2e6 + 5;

int T;
ll n,a[MAX],c[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        std::cin >> n;
        for(int i = 1;i <= n;i++)
            std::cin >> a[i];
        for(int i = 1;i <= n;i++)
            std::cin >> c[i];
        if(c[1] == c[n]){
            std::cout << a[1] + a[n] << '\n';
            continue;
        }
        ll mina = 1e18;
        for(int i = 1;i <= n - 1;i++) if(c[1] == c[i] && c[i + 1] == c[n]){
            mina = std::min(mina,a[1] + a[i] + a[i + 1] + a[n]);
        }
        std::cout << mina << '\n';
    }
    return 0;
}