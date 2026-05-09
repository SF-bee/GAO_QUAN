#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,s,ans = 1e9,a[MAX],sum[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> s;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],sum[i] = sum[i - 1] + a[i];
    
    for(int l = 1,r = l;r <= n;r++){
        int cnt = sum[r] - sum[l - 1];
        while(cnt >= s && l <= r){
            ans = std::min(ans,r - l + 1);
            cnt = sum[r] - sum[l++];
        }
    }
    std::cout << ans << '\n';
    return 0;
}