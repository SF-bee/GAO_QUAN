#include <bits/stdc++.h>
using ll = long long;
const int POS = 20;
const int N = 15;

using Row = std::array<ll, N>;
ll a, b;
std::array<Row, POS> f;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> a >> b;

    auto get = [&](int x) {
        // 初始化为 -1，因为方案数可能为 0，用 0 判断是否访问过会重复计算
        memset(&f, -1, sizeof(f));
        std::vector<int> num;
        while (x) {
            num.push_back(x % 10);
            x /= 10;
        }
        // pos:当前位, last:上一位的数字, lim:是否贴上限, lead:是否有前导零
        auto dfs = [&](auto &self, int pos, int last, bool lim, bool lead) -> ll {
            // 边界条件：各位填完。若全是一直前导零则是数字 0 (不合题意)，
            // 否则说明找到了 1 个合法正整数。
            if (pos < 0)
                return !lead;
            // 只有在不贴上限、且没有前导零的通用状态下，才能复用和写入记录
            if (!lim && !lead && f[pos][last] != -1)
                return f[pos][last];
            int up = lim ? num[pos] : 9;
            ll ans = 0;
            for (int i = 0; i <= up; i++) {
                if (lead && i == 0) {
                    // 情况 A：依然是前导零，不触发相邻差限制，last 随便传个 0
                    ans += self(self, pos - 1, 0, false, true);
                } else {
                    // 情况 B：正常填数（或是前导零后的第一个有效数字）
                    // 核心 2：如果是第一个数字(lead==true)，无限制；否则必须满足差值 >= 2
                    if (lead || std::abs(last - i) >= 2) {
                        // 核心 3：当下层也贴上限的条件：当前贴上限且当前位填到了最大值
                        ans += self(self, pos - 1, i, lim && (i == up), false);
                    }
                }
            }
            if (!lim && !lead)
                f[pos][last] = ans;
            return ans;
        };
        return dfs(dfs, num.size() - 1, 0, true, true);
    };
    std::cout << get(b) - get(a - 1) << '\n';
    return 0;
}