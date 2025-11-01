#include <bits/stdc++.h>

const int N = 200;
const int MAX = 100005;
int n,m;
int arr[N];
int dp[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::cin >> arr[i];
    
    dp[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= arr[i];j--){
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }
    std::cout << dp[m];
    return 0;
}