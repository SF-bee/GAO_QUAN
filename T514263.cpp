#include <bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(0);
    long long n;
    std::cin >> n;
    for(long long sum = 1,i = 1;i <= n;sum += (i = i + 1)) std::cout << sum << '\n';
    return 0;
}