#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e3 + 5;

int n, m;
ll a[MAX], b[MAX], c[MAX], d[MAX];
ll dp[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> c[0] >> d[0];
    for (int i = 1; i <= m; i++)
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];

    a[0] = n;
    b[0] = 1;
    for (int i = 0; i <= m; i++)
        for (int k = 1; k <= a[i] / b[i]; k++)
            for (int j = n; j >= c[i]; j--)
                dp[j] = std::max(dp[j], dp[j - c[i]] + d[i]);

    std::cout << dp[n] << '\n';
}
/*
题意
给定 m 种
*/