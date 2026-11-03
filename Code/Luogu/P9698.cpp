#include <bits/stdc++.h>

int T;
int n, m;

void sol() {
    std::cin >> n >> m;
    std::vector<std::vector<int>> maz(n + 1, std::vector<int>(m + 1));
    std::vector<std::pair<int, int>> pos(n * m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            std::cin >> maz[i][j];
            pos[maz[i][j]] = {i, j};
        }

    auto check = [&](int mid) -> bool {
        std::vector<std::vector<int>> sum(n + 1, std::vector<int>(m + 1));
        for (int i = 0; i < mid; i++) {
            auto [x, y] = pos[i];
            sum[x][y] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        for (int i = 0; i < mid; i++) {
            auto [x, y] = pos[i];
            int ld = sum[n][y - 1] - sum[x][y - 1];
            int ru = sum[x - 1][m] - sum[x - 1][y];
            if (ld || ru) return false;
        }
        return true;
    };
    int ans = 0;
    for (int l = 0, r = n + m - 1, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) {
        if (check(mid)) ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    while (T--)
        sol();
    return 0;
}
/*
题目要求路径上的 mex 最大
考虑 mex 的性质？
如果某个集合的 mex = x，那么 [0,x-1] 一定都出现了，x 一定没出现
检验答案是容易的吗？
检验答案确实是容易的，我们把必须选择的标记上，必须不选的标记上
那么对于每一个被标记了的元素，它的左下角一定不能存在被标记了的，右上角也不能存在被标记了的
这个东西是单调的吗？？？
是的，因为被标记的元素只会变多，变多就会使得不合法路径变得可能性更大
并且只要一个不合法，更多的也一定不合法
然后还要考虑头和尾必须选的情况
这个其实不影响？因为如果头尾对答案有影响，那么二分的时候就已经会枚举到了
*/