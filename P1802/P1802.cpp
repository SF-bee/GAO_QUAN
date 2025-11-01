#include <bits/stdc++.h>

const int MAX = 1e6 + 5;
int n,x;
int l[MAX],w[MAX],u[MAX];
int dp[MAX];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> x;
    for(int i = 1;i <= n;i++) std::cin >> l[i] >> w[i] >> u[i];

    for(int i = 1;i <= n;i++){
        for(int j = x;j >= u[i];j--){ //可以打败的时候
            dp[j] = std::max(dp[j] + l[i],dp[j - u[i]] + w[i]);
        }
        for(int j = u[i] - 1;j >= 0;j--){
            dp[j] += l[i];
        }
    }

    std::cout << dp[x] * 5;
    return 0;
}