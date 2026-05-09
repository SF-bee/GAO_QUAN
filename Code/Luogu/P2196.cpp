#include <bits/stdc++.h>

const int MAX = 100;
int n,ans;
int arr[MAX],dp[MAX];
bool str[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    ans = n;
    for(int i = 1;i <= n;i++) std::cin >> arr[i];
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            std::cin >> str[i][j];
        }
    }

    for(int i = n;i >= 1;i--){
        dp[i] = arr[i];
        for(int j = i + 1;j <= n;j++){
            if(str[i][j]){
                dp[i] = std::max(dp[i],dp[j] + arr[i]);
            }
        }
        if(dp[ans] < dp[i]) ans = i;
    }
    std::cout << ans << ' ';
    for(int i = ans,j = ans + 1;j <= n;j++){
        if(str[i][j] && dp[i] == dp[j] + arr[i]){
            std::cout << j << ' ';
            i = j;
        }
    }
    std::cout << '\n' << dp[ans];
    return 0;
}