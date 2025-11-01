#include <bits/stdc++.h>

const int M = 10005;
const int MAX = 10000005;
int t,m;
int a[M],b[M];
long long dp[MAX];


int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> t >> m;
    for(int i = 1;i <= m;i++) std::cin >> a[i] >> b[i];

    for(int i = 1;i <= m;i++){
        for(int j = a[i];j <= t;j++){
            dp[j] = std::max(dp[j], dp[j - a[i]] + b[i]);
        }
    }

    std::cout << dp[t];
    return 0;
}