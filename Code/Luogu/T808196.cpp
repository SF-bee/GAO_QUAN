#include <bits/stdc++.h>

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int n;
    std::cin >> n;
    double v, w;
    for (int x, i = 1; i <= n; i++)
        std::cin >> x, v += x;
    for (int x, i = 1; i <= n; i++)
        std::cin >> x, w += x;
    std::cout << std::fixed << std::setprecision(6) << w / v << '\n';
    return 0;
}