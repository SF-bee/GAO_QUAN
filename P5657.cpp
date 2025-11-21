#include <bits/stdc++.h>
typedef unsigned long long ull;

ull n,k;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    k ^= k >> 1;
    while(~--n) std::cout << ((k >> n) & 1);
    return 0;
}