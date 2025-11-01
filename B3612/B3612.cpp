#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n;
std::array<int,MAX> a;

inline int rd(){int x; std::cin >> x; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    std::generate_n(a.begin() + 1,n,rd);
    for(int i = 1;i <= n;i++){
        a[i] += a[i - 1];
    }

    int m,l,r;
    std::cin >> m;
    while(m--){
        std::cin >> l >> r;
        std::cout << a[r] - a[l - 1] << '\n';
    }
    return 0;
}