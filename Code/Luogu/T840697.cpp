#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;

int T;
int n;
std::string s;

void sol() {
    std::cin >> n >> s;
    s = '&' + s + '&';

    std::vector<std::pair<char, int>> r; // 压缩连续段
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (s[j] == s[i])
            j++;
        r.emplace_back(s[i], j - i);
        i = j - 1;
    }
    std::vector<int> len1;
    for (auto [c, len] : r) {
        if (c == '1') len1.push_back(len);
    }
    int m = len1.size();
    std::vector<int> gap(m + 1); // 0段
    int cnt1 = 0;
    for (auto [c, len] : r) {
        if (c == '1') cnt1++;
        else
            gap[cnt1] = len;
    }

    //
    auto check = [&](int x) {
        int ok[2] = {0, 0};
        // 最左边的
        int add0 = (len1[0] == 1 && gap[0] > 0) ? 1 : 0;
        if (gap[0] + add0 <= x) ok[0] = 1;
        if (len1[0] <= 1 && gap[0] <= x) ok[1] = 1;
        // 中间的
        for (int i = 1; i < m; ++i) {
            int nxt[2] = {0, 0};
            if (ok[0]) {
                int L = (len1[i] == 1 && gap[i] > 0) ? 1 : 0;

                if (gap[i] + L <= 2 * x) nxt[0] = 1;

                if (len1[i] <= 1 && gap[i] <= 2 * x) nxt[1] = 1;
            }
            if (ok[1]) {
                int R = (len1[i - 1] == 1 && gap[i] > 0) ? 1 : 0;
                int L = (len1[i] == 1 && gap[i] > 0) ? 1 : 0;

                if (gap[i] + R + L <= 2 * x) nxt[0] = 1;

                if (len1[i] <= 1 && gap[i] + R <= 2 * x) nxt[1] = 1;
            }
            ok[0] = nxt[0];
            ok[1] = nxt[1];
        }
        // 最右边的
        if (ok[0] && gap[m] <= x) return true;
        if (len1[m - 1] <= 1) {
            int add = (len1[m - 1] == 1 && gap[m] > 0) ? 1 : 0;
            if (ok[1] && gap[m] + add <= x) return true;
        }
        return false;
    };

    int ans = n;
    for (int l = 0, r = n, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) {
        if (check(mid)) r = (ans = mid) - 1;
        else
            l = mid + 1;
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
0100 2
00100 3
1000 3
单侧：
一个 1 两侧扩展当然要先扩展更长的那个，这样一定是不亏的

*/