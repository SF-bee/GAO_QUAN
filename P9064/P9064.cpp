#include <bits/stdc++.h>

const int MAX = 1e5+5;
int n,m;
int a[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::cin >> a[i];

    std::sort(a + 1,a + n + 1);

    int ans = INT_MAX;
    for(int l = 1,r = m;r < n;l++,r++)
        ans = std::min(ans,a[r] - a[l]);
    std::cout << ans;
    return 0;
}