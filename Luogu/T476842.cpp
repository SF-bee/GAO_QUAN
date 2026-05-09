#include <bits/stdc++.h>

const int MAX = 20;
int k;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> k;
    int d = 1;
    while(d < k) d <<= 1;
    std::cout << d << ' ';
    int t = k & -k;
    int cuts = 0;
    while(t != d) t <<= 1,cuts++;
    std::cout << cuts;
    return 0;
}