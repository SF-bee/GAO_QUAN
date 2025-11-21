#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n,k,ans = -1;
int a[MAX],sum[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    std::generate_n(a + 1,n,[]() {int x;std::cin >> x;return x;});

    for(int i = 1;i <= n;i++)
        sum[i] = a[i] + sum[i - 1];
    for(int i = 1;i <= n;i++)
        ans = std::max(ans,(i - k - 1 >= 0 ? sum[i] - sum[i - k - 1] : sum[i]));
    std::cout << ans << '\n';
    return 0;
}