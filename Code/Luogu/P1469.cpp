#include <bits/stdc++.h>

int n,a;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n;
    for(int i = 0;i < n;i++){
        int t;
        std::cin >> t;
        a ^= t;
    }
    std::cout << a;
    return 0;
}