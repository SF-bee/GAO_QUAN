#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n,ans,a[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    ans = n;
    std::cin >> a[1];
    for(int i = 2;i <= n;i++){
        std::cin >> a[i];
        if(!(a[i] & a[i - 1])) a[i] += a[i - 1], ans--;
    }
    std::cout << ans << '\n';
    return 0;
}