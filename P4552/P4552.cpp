#include <bits/stdc++.h>
typedef long long lint;
const int MAX = 1e5 + 5;

int n;
std::array<lint,MAX> a;

inline int rd(){int x; std::cin >> x; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    std::generate_n(a.begin() + 1,n,rd);
    lint z = 0,f = 0;
    for(auto i = 2;i <= n;i++){
        lint c = a[i] - a[i - 1];
        c > 0 ? z += c : f -= c;
    }
    std::cout << std::max(z,f) << '\n' << abs(z - f) + 1;
    return 0;
}