#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;
const int INF = 0x3f3f3f3f;

int t, T;
int n, a[MAX];

void sol() {
    int ans = INF;
    // 枚举断点
    for (int mask = 0; mask < (1 << n - 1); ++mask) {
        int cnt = 0, flag = 1;
        // 判断断点是否合法
        for (int pre = 0, i = 0; i < n - 1; ++i) {
            bool yes = 0;
            // 判断这一段是否合法
            if (mask >> i & 1) {
                cnt++;
                for (int k = 20; k >= 0; k--) {
                    bool ok = true;
                    for (int l = pre + 1; l <= i; l++) {
                        if (a[l - 1] >> k & 1 == a[l] >> k & 1) {
                            if (a[l - 1] > a[l]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) {
                        yes = 1;
                        break;
                    }
                }
            }
            if (!yes) {
                flag = 0;
                break;
            }
            pre = i + 1;
        }
        if (flag) ans = std::min(ans, cnt);
    }
    std::cout << ans << '\n';
}

int main() {
#if !ONLINE_JUDGE
    freopen("rain.in", "r", stdin);
    freopen("rain.out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> t >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        sol();
    }
    return 0;
}
/*
我们肯定不会重复操作同一个前缀，完全可以直接操作一次就可以了
问题转化为：每个树求出一个d_i使得它单调
然后操作数就是d_i != d_(i + 1) 的个数
然后观察相邻数字a_i,a_i+1
因为要单调增，所以一定是异或从高到低第一个不同位h
字集枚举，判断合不合法就行了，如果相邻
*/