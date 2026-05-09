/*
定义dp_i_j表示以i行j列为顶点的三角形边长
分类讨论
对于好格子
若j为奇数（三角形向下）
若正上方是好的，那么在左上和和右上选最小的
若j为偶数（三角形向上）
若正下方是好的，那么在左下和右下选最小的
*/
#include <bits/stdc++.h>
const int MAX = 1e4 + 5;

int n;
int cake[MAX][MAX];
int dp[MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= (n - i) * 2 + 1; j++) {
            char ch;
            std::cin >> ch;
            cake[i][j] = (ch == '-' ? 0 : 1);
        }
    // 只看向下的，从上往下
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= (n - i) * 2 + 1; j += 2) {
            if (cake[i][j] == 0) {
                dp[i][j] = 1;
                if (i == 1 || cake[i - 1][j + 1] == 0)
                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j + 2]) + 1;
            }
        }
    // 只看向上的，从下往上
    for (int i = n; i >= 1; i--)
        for (int j = 2; j <= (n - i) * 2 + 1; j += 2) {
            if (cake[i][j] == 0) {
                dp[i][j] = 1;
                if (cake[i + 1][j - 1] == 0) {
                    int l = 0, r = dp[i + 1][j];
                    if (j - 2 >= 1)
                        l = dp[i + 1][j - 2];
                    dp[i][j] = std::min(l, r) + 1;
                }
            }
        }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (n - i) * 2 + 1; j++) {
            ans = std::max(ans, dp[i][j]);
        }
    }
    std::cout << ans * ans << '\n';
    return 0;
}
/*
1 -> 2
3 -> 4
5 -> 6
  1 2 3 4 5 6 7 8 9
1 # - # # - - - - #
2 - - - - - # -
3 - - - # -
4 - # -
5 -
*/