#include <bits/stdc++.h>
const int INF = 1e9;
using ll = long long;

int a,b;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> a >> b;
    std::unordered_set<int> bit;
    for(int i = 0;(1 << i) <= INF;i++) bit.insert(1 << i);
    if(b == 0 || a == b) {
        std::cout << 1 << '\n';
    }
    int ans1;
    if(bit.count(b)) {
        
    }
    return 0;
}