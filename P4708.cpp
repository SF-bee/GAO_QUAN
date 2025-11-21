#include <bits/stdc++.h>
typedef long long lint;
const int MAX = 1e5 + 5;

lint n,k,ans;
lint sum[MAX],cm[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    for(int i = 1;i <= n;i++){
        int x;
        std::cin >> x;
        sum[i] = x + sum[i - 1];
    }
    for(int i = 0;i <= n;i++){
        ans += cm[sum[i] % k]++;
    }
    std::cout << ans << '\n';
    return 0;
}
/*
(a1 + a2) % k = (a3 + a4) % k
(a1 + a2 + a3 + a4) % k
*/