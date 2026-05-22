/*
规定dp_i表示购买到第 i 种珍珠所要花费的最小价格
*/
#include <bits/stdc++.h>
const int MAX = 1e2 + 5;
using ll = long long;
using Row = std::array<int, MAX>;

int c;
std::array<int, MAX> a, p;
std::array<int, MAX> sum, dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> c;
    for (int i = 1; i <= c; i++)
        std::cin >> a[i] >> p[i], sum[i] = sum[i - 1] + a[i];

    for (int i = 1; i <= c; i++) {
        dp[i] = dp[i - 1] + a[i] * p[i];
        for (int j = i; j >= 1; j--)
            dp[i] = std::max(dp[i], (sum[i] - sum[j - 1]));
    }

    return 0;
}