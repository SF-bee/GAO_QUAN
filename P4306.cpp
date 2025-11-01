#include <bits/stdc++.h>
const int MAX = 2e3 + 5;

int n;
std::bitset<MAX> f[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            char ch;std::cin >> ch;
            if(ch == '1') f[i][j] = 1;
        }
    }
    for(int k = 1;k <= n;k++){
        f[k][k] = 1;
        for(int i = 1;i <= n;i++){
            if(f[i][k]) f[i] |= f[k];
        }
    }
    int ans = 0;
    for(int k = 1;k <= n;k++)
        ans += f[k].count();
    std::cout << ans << '\n';
    return 0;
}