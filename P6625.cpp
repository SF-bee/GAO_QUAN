#include <bits/stdc++.h>

int n,a,ans,sum;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        std::cin >> a;
        sum += a;
        if(sum > 0 && i > 0) ans += sum;
    }
    std::cout << ans << '\n';
    return 0;
}