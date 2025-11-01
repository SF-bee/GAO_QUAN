#include <bits/stdc++.h>
const int MAX = 1e9;

std::pair<int,int> a,b;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> a.first >> a.second >> b.first >> b.second;
    if(a.first == b.first) std::cout << (a.first == 1 ? 0 : 1) << ' ' << a.second << '\n';
    else if(a.second == b.second) std::cout << a.first << ' ' << (a.second == 1 ? 0 : 1) << '\n';
    else std::cout << a.first << ' ' << b.second << '\n';
    return 0;
}