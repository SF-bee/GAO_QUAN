#include <bits/stdc++.h>

int n,a,b;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> a >> b;
    int x = n / b;
    if(n % b == 0){
        std::cout << 0 << ' ' << b << '\n';
        return 0;
    }
    for(int i = x;i > 0;i--){
        if((n - i * b) % a == 0){
            std::cout << (n - i * b) / a << ' ' << i << '\n';
            return 0;
        }
    }
    if(n % a == 0) std::cout << n / a << ' ' << 0 << '\n';
    else std::cout << "NO\n";
    return 0;
}