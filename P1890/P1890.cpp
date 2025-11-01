#include <bits/stdc++.h>
const int MAX = 1005;

int n,m,a[MAX],dp[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],dp[i][i] = a[i];
    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
            dp[i][j] = std::__gcd(dp[i][j - 1],dp[j][j]);
    
    while(m--){
        int l,r;
        std::cin >> l >> r;
        std::cout << dp[l][r] << '\n';
    }
    return 0;
}
/*
4 12 3 6 7

*/