#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e5 + 5;

int n;
ll ans,sum,c[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> c[i];
    std::sort(c + 1,c + n + 1);
    for(int i = 1;i <= n;i++){
        if(c[i] * (n - i + 1) > sum) sum = c[i] * (n - i + 1),ans = c[i];
    }
    std::cout << sum << ' ' << ans << '\n';
    return 0;
}