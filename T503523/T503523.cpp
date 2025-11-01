#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n,end,f[MAX];
std::array<std::pair<int,int>,MAX> a;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i].first >> a[i].second;
    std::sort(a.begin() + 1,a.begin() + n + 1);
    for(int i = 1;i <= n;i++){
        if(a[i].second > f[end]) f[++end] = a[i].second;
        else f[std::lower_bound(f + 1,f + end + 1,a[i].second) - f] = a[i].second;
    }
    std::cout << end;
    return 0;
}