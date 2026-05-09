#include <bits/stdc++.h>
const int MAX = 2e6 + 5;

int n,m,ans;
std::pair<int,int> a[MAX];

int main(){ 
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= m;i++)
        std::cin >> a[i].first >> a[i].second;
    std::sort(a + 1,a + m + 1);
    for(int i = 1;i <= m;i++){
        if(a[i].second < n) ans += a[i].first * a[i].second,n -= a[i].second;
        else{
            ans += a[i].first * n;
            break;
        }
    }
    std::cout << ans << '\n';
    return 0;
}