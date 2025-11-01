#include <bits/stdc++.h>

const int MAX = 20010;
int n,m;
int a[MAX],b[MAX],dp[MAX];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0;i < m;i++) std::cin >> a[i];
    for(int i = 0;i < n;i++) std::cin >> b[i];
    for(int i = 0;i < n + n;i++) dp[i] = -1e9;

    dp[0] = 0;
    for(int i = 0;i < n + n;i++){
        for(int j = 0;j < m;j++){
            if(i >= a[j]){
                dp[i] = std::max(dp[i],dp[i - a[j]] + b[i - a[j]]);
            }
        }
    }
    // int ans = -INT_MAX;
    // for(int i = n;i < n + n;i++){
    //     ans = std::max(ans,dp[i]);
    // }
    // std::cout << ans;
    std::cout << *std::max_element(dp + n,dp + n + n);
    return 0;
}