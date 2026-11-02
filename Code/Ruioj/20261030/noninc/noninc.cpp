#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e2 + 5;
const int mod = 998244353;

int n;
int l[MAX], r[MAX];

void sol1() {
    std::unordered_map<int, ll> pre;
    l[0] = l[1], r[0] = r[1];
    for (int i = l[1]; i <= r[1]; i++)
        pre[i] = 1;
    for (int i = 1; i <= n; i++) {
        std::unordered_map<int, ll> now;
        for (int j = r[i]; j >= l[i]; j--) {
            if (j < l[i - 1]) now[j] = (now[j + 1] + pre[l[i - 1]]) % mod;
            else
                now[j] = (now[j + 1] + pre[j]) % mod;
        }
        pre = now;
    }
    std::cout << pre[l[n]] << '\n';
}

int main() {
    // #if !ONLINE_JUDGE
    // freopen("noninc.in", "r", stdin);
    // freopen("noninc.out", "w", stdout);
    // #endif
    std::cin.tie(0)->sync_with_stdio(0);

    bool flag1 = 1;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> l[i] >> r[i];
        if (r[i] - l[i] >= 1e6) flag1 = 0;
        if (i > 1 && r[i] > r[i - 1]) r[i] = r[i - 1];
        if (l[i] > r[i]) {
            std::cout << 0;
            return 0;
        }
    }

    sol1();
    return 0;
}
/*
给定序列每个元素的取值范围
求出所有的满足单调不增序列的个数

设dp[i][j] 表示考虑到 i，第 i 个元素为 j 的方案数
转移: dp[i][j] = /sum_{k = l_i - 1}^{j} dp[i - 1][k]
***，第一个点都过不了，空间爆炸了
考虑优化？
转移的话可以前缀和O1转移，然后dp数组用哈希表存，然后可以滚动数组
这样可以过前 6 个点

3
1 2
1 2
1 2

10
24 73
57 82
10 99
27 777
11 289
22 73
57 81
10 900
27 1000
11 1145
*/