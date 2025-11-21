#include <bits/stdc++.h>
typedef unsigned long long ull;
const int MAX = 1e6 + 5;

int n;
std::array<ull,MAX> a;
std::vector<ull> sta;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    std::generate_n(a.begin() + 1,n,[](){ull x;std::cin >> x;return x;});

    for(int ans = 0,i = 1;i <= n;i++){
        while(!sta.empty() && a[sta.back()] <= a[i])
            ans ^= sta.back(),sta.pop_back();
        sta.push_back(i);
        ans ^= sta.back();
        // for(auto i : sta) std::cout << i << ' ';
        std::cout << ans << '\n';
    }
    return 0;
}