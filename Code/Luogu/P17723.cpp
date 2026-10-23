#include <bits/stdc++.h>
using ll = unsigned long long;
const int MAX = 2e6 + 5;

int n;
int s[MAX];

void sol1() {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll OR = 0, MEX = 0;
        std::vector<int> cnt(n + 1, 0);
        for (int j = i; j <= n; j++) {
            OR |= s[j];
            if (0 <= s[j] && s[j] <= n) {
                ++cnt[s[j]];
                if (s[j] == MEX) {
                    while (cnt[MEX])
                        ++MEX;
                }
            }
            ans += OR | MEX;
        }
    }
    std::cout << ans << '\n';
}
void sol2() {
    ll ans = 0;
    // 贡献掉 or 的部分
    std::vector<int> lv(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int L = 0, last = 0;
        if (s[i] <= n) lv[s[i]] = i;
        for (int j = 0; j < 32; j++) {
            if (s[i] >> j & 1) last = i;
            ans += last * (1ull << j);
            // 然后 last 到 j or 的 b 都是 0 了
            // 所以 l > last,然后 l <= min(lv[0, 1, ..., 2^j - 1])
        }
    }
}

int main() {
#if !ONLINE_JUDGE
    freopen("func.in", "r", stdin);
    freopen("func.out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> s[i];
    if (n <= 5e3) sol1();
    else
        sol2();
    return 0;
}
/*
子区间问题，应该是贡献法
打暴力吧，也许会发现什么
考虑答案的构成，那么如果一位已经被 OR 贡献，那么mex就不需要再贡献，所以只考虑 or = 0
先把 or 的答案贡献掉
or 有贡献，当
就是说，一个区间的 mex，某一位 b 会被 mex 贡献，当且仅当
or 的第 b 位为 0，m 的第 b 位为 1
然后如果 last[x] 表示 x 最后一次出现的位置，那么左端点 l 必然有 l <= last[x]
所以枚举不存在的位 b，然后枚举右端点
*/