#include <bits/stdc++.h>
using dbl = double;
const int MAX = 1e3 + 10;

int n;
dbl x[MAX], f[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> x[i];

    f[n] = x[n];
    for (int j = n - 1; j >= 1; j--) {
        dbl p = std::min(6, n - j), sum = 0;
        for (int k = 1; k <= p; k++)
            sum += f[j + k];
        f[j] = x[j] + sum / p;
    }
    if (fabs(f[1] - (long long)f[1]) <= 1e-9)
        std::cout << f[1];
    else
        std::cout << std::fixed << std::setprecision(10) << f[1] << "\n";
    return 0;
}
// f[i] 表示从 i 到 n 的得分期望