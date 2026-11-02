#include <bits/stdc++.h>
const int N = 2e3;
const int MAX = 6e3 + 5;

int n, m, k;
int maze[MAX][MAX], sum[MAX][MAX];

int main() {
    // freopen("clean.in", "r", stdin);
    // freopen("clean.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> k;
    for (int i = N + 1; i <= N + n; i++) {
        for (int j = N + 1; j <= N + m; j++) {
            std::cin >> maze[i][j];
        }
    }

    auto mark = [&](int i, int j, int t) {
        if (t < 0) return;
        sum[i - t + 1][j]++;
        sum[i + 1][j - t]--;
        sum[i + 1][j + t]--;
        sum[i + t + 1][j]++;
    };
    for (int i = N + 1; i <= N + n; i++) {
        for (int j = N + 1; j <= N + m; j++) {
            if (maze[i][j] == 1) {
                mark(i, j, k);
                mark(i, j, k - 1);
            }
        }
    }
    for (int i = 1; i <= 3 * N; i++)
        for (int j = 1; j <= 3 * N; j++)
            sum[i][j] += sum[i - 1][j + 1];
    for (int i = 1; i <= 3 * N; i++)
        for (int j = 1; j <= 3 * N; j++)
            sum[i][j] += sum[i - 1][j - 1];
    int ans = -1, x, y;
    for (int i = N + 1; i <= N + n; i++)
        for (int j = N + 1; j <= N + m; j++) {
            if (sum[i][j] > ans) ans = sum[i][j], x = i, y = j;
        }

    std::cout << ans << '\n';
    std::cout << x - N << ' ' << y - N << '\n';
    return 0;
}
/*
考虑一颗雷会影响哪些点？
我们需要标记斜着的点，那可以上顶点打1，右左顶点打-1
然后做一次前缀和，这样我们就搞出两条边的标记了
然后另外一个方向做前缀和，这样我们就打出来那个菱形的标记了
然后横着做一次前缀和，我们就标记出每个点覆盖的位置了
*/