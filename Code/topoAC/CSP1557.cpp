#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e6 + 5;

int n;
ll a[MAX];

int main() {
    freopen("mancala.in", "r", stdin);
    freopen("mancala.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    ll ans = 0;
    int flag = 0;
    for (int i = n; i >= 1; i--) {
        ll res = a[i] + ans;
        if (a[i] + ans >= i) {
            if (a[i] <= i) {
                ans += res / i;
                res %= i;
            }
        }
        if (res > 0) flag = 1;
    }
    ans += flag;
    std::cout << ans << '\n';
    return 0;
}
/*
一个显然的做法：因为我们肯定先去拿前面的，因为前面对后面没有影响
暴力模拟这个过程可以得到n^2的做法
复杂度瓶颈在于每次往前暴力修改
考虑能不能一次性算出每一个点对答案的贡献？
其实是可以的，因为每个点只会被后面的点影响，那么如果在遍历这个点的时候后面已经全部算完就好
这启示我们倒序处理
*/