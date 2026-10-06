#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, k;
ll a[MAX];
std::vector<std::array<ll, MAX>> dp;

void solve1() {
    for (int j = 2; j <= k; j++) {
        for (int i = j + 1; i <= n; i++) {
            ll max = a[i], min = a[i];
            for (int p = i - 1; p >= j - 1; p--) {
                dp[j][i] = std::min(dp[j][i], dp[j - 1][p] + (max - min));
                max = std::max(max, a[p]);
                min = std::min(min, a[p]);
            }
        }
    }
    std::cout << dp[k][n] << '\n';
}
void solve2() {
    for (int j = 2; j <= k; j++) {
        ll min = dp[j - 1][j - 1] - a[j];
        for (int i = j + 1; i <= n; i++) {
            dp[j][i] = std::min(dp[j][i], min + a[i]);
            min = std::min(min, dp[j - 1][i] - a[i + 1]);
        }
    }
    std::cout << dp[k][n] << '\n';
}

int main() {
#if !ONLINE_JUDGE
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    dp.resize(k + 1);
    for (auto &i : dp)
        i.fill(INF);
    {
        ll max = INF, min = -INF;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            max = std::max(max, a[i]), min = std::min(min, a[i]);
            dp[1][i] = max - min;
            if (i <= k) dp[i][i] = 0;
        }
        if (k == 1) {
            std::cout << max - min << '\n';
            return 0;
        } else if (k == n) {
            std::cout << 0 << '\n';
            return 0;
        }
    }

    if (std::is_sorted(a + 1, a + n + 1)) solve2();
    else if (std::is_sorted(a + 1, a + n + 1, std::greater<ll>())) {
        std::reverse(a + 1, a + n + 1);
        solve2();
    } else
        solve1();
    return 0;
}
/*
题目大意：给定一个序列将其分成恰好 k 段使得每一段的极差之和最小
dp
设 dp[i][j] 表示前 i 个元素划分成正好 j 段的最小极差之和
那么 dp[i][j] = min_p in [j,i - 1](dp[p][j - 1] + [p + 1,i 的极差])
考虑一下边界
*/