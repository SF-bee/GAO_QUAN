#include <bits/stdc++.h>
const int MAX = 3e4 + 5;

int w,n,ans,a[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> w >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    std::sort(a + 1,a + n + 1);
    for(int l = 1,r = n;l <= r;l++){
        while(l != r && a[l] + a[r] > w) ans++,r--;
        ans++,r--;
    }
    std::cout << ans << '\n';
    return 0;
}