#include <bits/stdc++.h>
const int MAX = 3e2 + 5;
using ll = long long;
using Row = std::array<ll, MAX>;

int n;
// v为某段区间费用，f为合并某段区间的最小花费
std::array<Row, MAX> v, f;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    std::memset(&f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
        std::cin >> v[i][i], f[i][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            v[i][j] = std::__gcd(v[i][j - 1], v[j][j]);
    for (int l = 2; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++)
                f[i][j] = std::min(f[i][j], f[i][k] + f[k + 1][j] + v[i][k] + v[k + 1][j]);
        }

    std::cout << v[1][n] << ' ' << f[1][n] << '\n';
    return 0;
}