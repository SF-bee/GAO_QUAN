#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e2 + 5;

int T;
std::string s;
// dp_{i,j} 考虑到第 i 个字符，已经使用了总和为 j 的字典序的方案数
std::array<ll, MAX> dp;

void solve() {
    int n, sum = 0;
    dp.fill(0);
    std::cin >> s;
    n = s.size();
    for (auto ch : s)
        sum += ch - 'a';
    s = '$' + s;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
        }
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    while (T--)
        solve();
    return 0;
}