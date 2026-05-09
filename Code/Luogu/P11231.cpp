#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n;
std::map<int,int> cnt;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n;
    for(int a,i = 1;i <= n;i++)
        std::cin >> a,cnt[a]++;
    int ans = 0;    
    for(auto [a,b] : cnt)
        ans = std::max(ans,b);
    std::cout << ans << '\n';
    return 0;
}