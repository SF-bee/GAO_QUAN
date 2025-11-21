#include <bits/stdc++.h>

int n;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = n / 14;i >= 0;i--){
        for(int j = i;j <= n / 4;j++){
            for(int k = i;k <= n / 3;k++){
                if(i * 7 + j * 4 + k * 3 == n){
                    std::cout << i << ' ' << j << ' ' << k << '\n';
                    return 0;
                }
            }
        }
    }
    std::cout << -1 << '\n';
    return 0;
}