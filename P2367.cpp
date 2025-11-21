#include <bits/stdc++.h>
const int MAX = 5e6 + 5;

int n,p,a[MAX],c[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> p;
    for(int i = 1;i <= n;i++) std::cin >> a[i];
    
    int x,y,z;
    while(p--){
        std::cin >> x >> y >> z;
        c[x] += z;
        c[y + 1] -= z;
    }
    int mina = INT_MAX;
    for(int i = 1;i <= n;i++) c[i] += c[i - 1], mina = std::min(mina,c[i] + a[i]);
    std::cout << mina << '\n';
    return 0;
}