#include <bits/stdc++.h>
using ll = long long;
const ll N = 15;

ll a, b;
std::array<ll, 10> ans1, ans2;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> a >> b;
    auto get = [&](ll x) {
        std::vector<int> num;
        using Row = std::array<ll, N>;
        std::array<Row, N> f;
        std::array<ll, 10> res;
        while (x) {
            num.push_back(x % 10);
            x /= 10;
        }
        // 需要记录数码 d 已经出现了 cnt次
        auto dfs = [&](auto &self, int pos, int cnt, bool lim, bool lead, int d) -> ll {
            if (pos < 0)
                return cnt;
            if (!lim && !lead && f[pos][cnt] != -1)
                return f[pos][cnt];
            ll res = 0;
            int up = lim ? num[pos] : 9;
            for (int i = 0; i <= up; i++) {
                int flag = 0;
                if (!(lead && i == 0) && i == d)
                    flag++;
                res += self(self, pos - 1, cnt + flag, lim && i == up, lead && i == 0, d);
            }
            if (!lim && !lead)
                f[pos][cnt] = res;
            return res;
        };
        for (int i = 0; i <= 9; i++) {
            std::memset(&f, -1, sizeof(f));
            res[i] = dfs(dfs, num.size() - 1, 0, true, true, i);
        }
        return res;
    };
    ans1 = get(a - 1);
    ans2 = get(b);
    for (int i = 0; i <= 9; i++)
        std::cout << ans2[i] - ans1[i] << " \n"[i == 9];
    return 0;
}
/*
考虑一个不理会前导零的 2 位数字
对于某个数位 i :十位上它出现了10次，个位上出现了10次
所以每个数字都出现了20次。
考虑一个不理会前导零的 3 位数字
一个数位i：百位上出现了100次，十位上出现了100次，个位上出现了100次
所以每个数字都出现了300次
*/