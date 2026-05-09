#include <bits/stdc++.h>

const int MAX = 1e3 + 5;
int n;
std::array<int,MAX> a,b;

inline int rd(){int x;std::cin >> x;return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n;
    std::generate_n(a.begin() + 1,n,rd);

    std::sort(a.begin() + 1,a.begin() + n + 1);
    for(int i = 1;i <= n;i++)
        b[i] = b[i - 1] + a[i];
    int ans = INT_MAX;
    for(int i = 1;i <= n;i++)
        ans = std::min(ans,b[i] + std::max(0,(b[n] - b[i] - i)));
        
    std::cout << ans;
    return 0;
}