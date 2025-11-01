#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

long long n,ans,b[MAX],c[MAX],cnt[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= 2 * n;i++)
        std::cin >> b[i];
    for(int i = 1;i <= 2 * n;i++)
        std::cin >> c[i],ans += c[i],cnt[i] = c[i] - b[i];
    std::sort(cnt + 1,cnt + 2 * n + 1);
    for(int i = 1;i <= n;i++)
        ans -= cnt[i];
    std::cout << ans << '\n';
    return 0;
}