#include <bits/stdc++.h>
const int MAX = 1e2 + 5;

int n;
std::bitset<MAX> f[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int u; std::cin >> u;
            if(u) f[i][j] = 1;
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            if(f[i][k])
                f[i] |= f[k];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            std::cout << f[i][j] << " \n"[j == n];
        }
    }
    return 0;
}