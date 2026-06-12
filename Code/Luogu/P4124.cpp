#include <bits/stdc++.h>
using ll = long long;
const int N = 13;

ll a, b;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> a >> b;

    // f_{pos,last,cnt,0/1,0/1} 表示考虑到第 pos 个位置，上一个数字是 last，连续出现 cnt
    // 个相同的数字，是/否已经是连续3个，是/否出现 4，是/否出现 8 的合法答案
    using Has8 = std::array<ll, 2>;
    using Has4 = std::array<Has8, 2>;
    using Cnt = std::array<Has4, N>;
    using Same = std::array<Cnt, 2>;
    using Last = std::array<Same, 10>;
    using DPTable = std::array<Last, N>;
    DPTable f;
    auto get = [&](ll x) {
        std::memset(&f, -1, sizeof(f));
        std::vector<int> num;
        while (x) {
            num.push_back(x % 10);
            x /= 10;
        }
        auto dfs = [&](auto &self, int pos, int last, int cnt, bool same, bool has4, bool has8,
                       bool lim, bool lead) -> ll {
            if (pos < 0)
                return !lead && !(has4 && has8) && same;
            if (has4 && has8)
                return 0;
            if (!lim && !lead && f[pos][last][same][cnt][has4][has8] != -1)
                return f[pos][last][same][cnt][has4][has8];
            int up = lim ? num[pos] : 9;
            ll res = 0;
            for (int i = 0; i <= up; i++) {
                if (lead && i == 0) {
                    // 还在前导零状态，继续往后搜，last 和 cnt 保持 0 即可（因为还没遇到有效数字）
                    res += self(self, pos - 1, 0, 0, false, false, false, false, true);
                } else {
                    // 填入有效数字了！
                    int _cnt;
                    // 说明当前 i 是整个手机号的第一个有效数字（最高位）
                    if (lead)
                        _cnt = 1;
                    // 说明前面已经有有效数字了，可以和上一位正常比对
                    else
                        _cnt = (i == last ? cnt + 1 : 1);

                    res += self(self, pos - 1, i, _cnt, (same || _cnt >= 3), (has4 || i == 4),
                                (has8 || i == 8), (lim && i == up), false);
                }
            }
            if (!lim && !lead)
                f[pos][last][same][cnt][has4][has8] = res;
            return res;
        };
        return dfs(dfs, num.size() - 1, 0, 0, false, false, false, true, true);
    };

    std::cout << get(b) - get(a - 1) << '\n';
    return 0;
}