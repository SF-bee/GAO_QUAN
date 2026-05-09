#include <bits/stdc++.h>
const int MAX = 3e5 + 5;

int n,ans,maxa = -1,b[MAX],cnt[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> b[i];
    
    std::sort(b + 1,b + n + 1,std::greater<int>());
    for(int i = 1;i <= n;i++)
        maxa = std::max(maxa,(cnt[i] = b[i] + i));
    for(int i = i;i <= n;i++)
        if(b[i] + n >= maxa) ans++;
    std::cout << ans << '\n';
    return 0;
}