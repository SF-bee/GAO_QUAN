#include <bits/stdc++.h>
using ll = long long;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int n, k;
    std::cin >> n >> k;
    ll sum = 0;
    for (int a, i = 1; i <= n; i++)
        std::cin >> a, sum += a;

    std::string str = std::to_string(sum);
    ll ans = sum;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j <= k && (j == 0 || i + j - 1 < str.size()); j++) {
            std::string s = str;
            std::reverse(s.begin() + i, s.begin() + i + j);
            ans = std::max(ans, std::stoll(s));
        }
    }
    std::cout << ans << '\n';
    return 0;
}