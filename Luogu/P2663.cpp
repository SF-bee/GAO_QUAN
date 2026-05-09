#include <bits/stdc++.h>
const int N = 1e2 + 5;
const int MAX = 1e4 + 5;

int n;
int a[N];
std::bitset<MAX> dp[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], sum += a[i];

    sum >>= 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= 1; j--)
            dp[j] = dp[j] | (dp[j - 1] << a[i]);
    for (int k = sum; k >= 0; k--)
        if (dp[n / 2][k]) {
            std::cout << k << '\n';
            return 0;
        }
    return 0;
}