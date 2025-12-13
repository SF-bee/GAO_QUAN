#include <bits/stdc++.h>

int T;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        std::cout << (3 - (n % 3)) % 3 << '\n';
    }
    return 0;
}