#include <bits/stdc++.h>
const int MAX = 5e2 + 5;
const int INF = 0x3f3f3f3f;
using Row = std::array<int, MAX>;

int n;
std::string s;
std::array<Row, MAX> f; // f_{i,j} 表示使得区间 [i,j] 是回文串的最小花费

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> s;
    s = "$" + s;
    std::memset(&f, 0x3f, sizeof(f));
    for (int l = 1; l <= n; l++) {
        if (l == 1) {
            for (int i = 1; i <= n; i++)
                f[i][i] = 0;
            continue;
        }
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            f[i][j] = std::min(f[i][j - 1], f[i + 1][j]) + 1;
            if (s[i] == s[j]) {
                if (i + 1 <= j - 1)
                    f[i][j] = std::min(f[i][j], f[i + 1][j - 1]);
                else
                    f[i][j] = 0;
            }
        }
    }
    std::cout << f[1][n];
    return 0;
}