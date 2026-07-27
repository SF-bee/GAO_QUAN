#include <bits/stdc++.h>
using ll = long long;
const int N = 1e2 + 5;
const int K = 1e5 + 5;
const ll mod = 1e9 + 7;

int n, k;
int a[N];
// sum维护前一轮的前缀和，dp维护当前的答案
ll sum[K], dp[K];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        sum[0] = dp[0];
        for (int j = 1; j <= k; j++)
            sum[j] = (sum[j - 1] + dp[j]) % mod;
        for (int j = 0; j <= k; j++) {
            if (j - a[i] <= 0)
                dp[j] = sum[j];
            else
                dp[j] = (sum[j] - sum[j - a[i] - 1] + mod) % ;
        }
    }
    std::cout << dp[k] << '\n';
    return 0;
}
/*
考虑dp

dp_i_j 表示考虑到第i个人，它们可以分配 j 颗糖的方案数

对于第i个孩子，它可以拿 [0,a_i] 颗糖

考虑转移 dp[i][j] = sum_x=0 ^a_i (dp[i - 1][j - x])
考虑边界 第一个孩子可以那
*/