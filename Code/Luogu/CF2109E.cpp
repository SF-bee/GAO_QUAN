#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e2 + 5;
const int mod = 1e9 + 7;

int T, n, k;
std::string s;
ll frac[MAX], infa[MAX];
ll dp[MAX][MAX];

void init() {
    frac[0] = 1;
    for (int i = 1; i < MAX; i++)
        frac[i] = frac[i - 1] * i % mod;
    auto qpow = [&](ll x, int p) {
        ll res = 1;
        for (; p; x = x * x % mod, p >>= 1)
            if (p & 1) res = res * x * mod;
        return res;
    };
    infa[MAX - 1] = qpow(frac[MAX - 1], mod - 2);
    for (int i = MAX - 2; i >= 0; i--)
        infa[i] = infa[i + 1] * (i + 1) % mod;
}
ll C(int n, int m) {
    if (n < 0 || m > n) return 0;
    return frac[n] * infa[n - m] % mod * infa[m] % mod;
}
void solve() {
    std::memset(dp, 0, sizeof(dp));
    std::cin >> n >> k >> s;
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            for (int m = 0; m <= j; m++) {
            }
        }
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    init();
    std::cin >> T;
    while (T--)
        return 0;
}
/*
题目大意：给定一个 0/1 串，每次可以选择一个 0 的位置将这个位置及其前缀取反
    求恰好操作 k 次的方案数
设 dp[i][j] 表示考虑到前 i 个元素一共操作了 j 次的方案数
这样设计是不正确的，因为我后面操作了会使得我可以继续在前面操作，这会不满足无后效性
我们希望我们一次操作，只会影响未来的操作
这启示我们倒观
设 dp[i][j] 表示考虑到后 i 个元素一共操作了 j 次的方案数
考虑转移,可以枚举当前这一位操作了 m 次，那么我们需要把这 m 次操作分配到前 j - m 次当中
s[i] = 0 第一次操作要隔偶数次才可以操作，接着的操作必须隔奇数次
s[i] = 1 第一次操作要隔奇数次才可以操作，接着的操作必须隔奇数次
这是一个不相邻的组合计数（但是我不会）
*/