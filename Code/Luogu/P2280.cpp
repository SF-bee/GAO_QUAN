#include <bits/stdc++.h>
const int MAX = 1e4 + 5;

int n, m, h, w;
int a[MAX][MAX], sum[MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int x, y, v, i = 1; i <= n; i++) {
        std::cin >> x >> y >> v;
        a[x + 1][y + 1] += v;
        h = std::max(h, x + 1);
        w = std::max(w, y + 1);
    }

    for (int i = 1; i < h + m; i++)
        for (int j = 1; j < w + m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    int ans = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            int di = i + m - 1;
            int dj = j + m - 1;
            ans = std::max(ans, sum[di][dj] - sum[i - 1][dj] - sum[di][j - 1] + sum[i - 1][j - 1]);
        }
    std::cout << ans << '\n';
    return 0;
}