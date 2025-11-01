#include <bits/stdc++.h>
const int N = 1e2;
const int MAX = 1e3;

int n,m,a[N],b[N],dp[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int i = 1;i <= m;i++)
        std::cin >> b[i];
    dp[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = a[i];j < 1000;j++){
            dp[j % 360] = std::max({dp[j % 360],dp[(j - a[i]) % 360],dp[(j + a[i]) % 360]});
        }
    }
    for(int i = 1;i <= m;i++)
        std::cout << (dp[b[i]] ? "YES\n" : "NO\n");
    return 0;
}