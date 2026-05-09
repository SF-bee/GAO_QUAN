/*
考虑悬线法
对于每一个点，分别求出：
  1. 它向上延申最长的高度 l_i_j
  2. 它向左延申最长的位置 left_i_j
  3. 它向右延伸最长的位置 right_i_j
不对不对，这题好像可以单调栈：注意到一条悬线可以延伸需要满足
  1. 两侧的悬线大于等于它
  2. 两侧的悬线与他黑白相间
*/
#include <bits/stdc++.h>
const int MAX = 2e3 + 5;

int n, m, a[MAX][MAX];
int len[MAX][MAX], L[MAX][MAX], R[MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> a[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            L[i][j] = j;
            if (j > 1 && a[i][j - 1] != a[i][j])
                L[i][j] = L[i][j - 1];
        }
        for (int j = m; j >= 1; j--) {
            R[i][j] = j;
            if (j < m && a[i][j + 1] != a[i][j])
                R[i][j] = R[i][j + 1];
        }
        for (int j = 1; j <= m; j++) {
            len[i][j] = 1;
            if (i > 1 && a[i][j] != a[i - 1][j]) {
                len[i][j] = len[i - 1][j] + 1;
                R[i][j] = std::min(R[i][j], R[i - 1][j]);
                L[i][j] = std::max(L[i][j], L[i - 1][j]);
            }
        }
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            ans1 = std::max(ans1, std::min(R[i][j] - L[i][j] + 1, len[i][j]));
            ans2 = std::max(ans2, len[i][j] * (R[i][j] - L[i][j] + 1));
        }
    std::cout << ans1 * ans1 << '\n' << ans2 << '\n';
    return 0;
}