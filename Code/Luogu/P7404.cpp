#include <bits/stdc++.h>
typedef long long lint;
const int MAX = 2e5 + 5;

lint n,a[MAX],b[MAX],pre[MAX],nxt[MAX];  //pre_i存储到i严格递增所需的步数，nxt反之

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        std::cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    for(int i = 1;i <= n;i++)
        pre[i] = (b[i] <= 0 ? pre[i - 1] - b[i] + 1 : pre[i - 1]);
    for(int i = n;i >= 1;i--)
        nxt[i] = (b[i] >= 0 ? nxt[i + 1] + b[i] + 1 : nxt[i + 1]);
    lint ans = LONG_LONG_MAX;
    for(int i = 1;i <= n;i++)
        ans = std::min(ans,std::max(pre[i],nxt[i + 1]));
    std::cout << ans << '\n';
    return 0;
}
/*
1  3  2  5  4
1  2 -1  3 -1
1  3  2  5 
*/