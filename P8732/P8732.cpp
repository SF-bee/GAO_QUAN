#include <bits/stdc++.h>
const int MAX = 1e3 + 5;

long long n,t,ans,s[MAX],a[MAX],e[MAX],sum[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> s[i] >> a[i] >> e[i],sum[i] = s[i] + a[i] + e[i];
    std::sort(sum + 1,sum + n + 1);
    for(int i = 1;i <= n;i++)
        t += sum[i],ans += t - e[i];
    std::cout << ans << '\n';
    return 0;
}