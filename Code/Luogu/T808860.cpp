#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e3 + 5;

int n;
int a[MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int x;
            std::cin >> x;
            if (x != 0) a[i][j] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

    ll ak = 1, sum = 0x3f3f3f3f3f3f3f3f;
    for (int k = 1; k <= n; k++) {
        if (k * k + 1 > sum) break;
        int cnt = 0;
        int tn = k * std::ceil(1.0 * n / k);
        for (int i = k; i <= tn; i += k) {
            for (int j = k; j <= tn; j += k) {
                int r2 = std::min(i, n);
                int c2 = std::min(j, n);
                int r1 = std::min(i - k, n);
                int c1 = std::min(j - k, n);
                if (a[r2][c2] - a[r1][c2] - a[r2][c1] + a[r1][c1] != 0) {
                    cnt++;
                }
            }
        }
        if (1ll * cnt * (k * k + 1) < sum) sum = 1ll * cnt * (k * k + 1), ak = k;
    }
    std::cout << ak << ' ' << sum << '\n';
    return 0;
}