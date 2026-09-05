#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int T;
int n, a[MAX];

void solve1() {
    ll ans = 0;
    auto Get = [&](const std::array<int, 4> &cnt) {
        int Max = 0, Min = 0x3f3f3f3f;
        for (int i = 1; i <= 3; i++)
            if (cnt[i] != 0) Max = std::max(Max, cnt[i]), Min = std::min(Min, cnt[i]);
        return Max - Min;
    };
    for (int i = 1; i <= n; i++) {
        std::array<int, 4> cnt = {0, 0, 0, 0};
        for (int j = i; j <= n; j++) {
            cnt[a[j]]++;
            ans += Get(cnt);
        }
    }
    std::cout << ans << '\n';
}
namespace solve2 {
int l1[MAX], l3[MAX];
ll sum1[MAX];
struct BIT {
    int sum[MAX];
#define lowbit(x) (x & (-x))
    void add(int pos, int x) {
        for (; pos <= n; pos += lowbit(pos))
            sum[pos] += x;
    }
    int query(int r) {
        int res = 0;
        while (r) {
            res += sum[r];
            r -= lowbit(r);
        }
        return res;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
#undef lowbit
} bit;
void solve2() {
    for (int i = 1; i <= n; i++) {
        sum1[i] += (a[i] == 1 ? 1 : -1);
        sum1[i] = sum1[i] + sum1[i - 1];
        bit.add(i, sum1[i]);
        if (a[i] == 1) l1[i] = i, l3[i] = l3[i - 1];
        if (a[i] == 3) l3[i] = i, l1[i] = l1[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
                }
    }
}
} // namespace solve2

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    while (T--) {
        std::cin >> n;
        bool flag2 = 1;
        for (int i = 1; i <= n; i++)
            std::cin >> a[i], flag2 &= (a[i] != 2);
        if (n <= 5000) solve1();
        else if (flag2)
            solve2::solve2();
    }
    return 0;
}
/*
注意到由于值域是1～3，而且仅计算出现过的元素。
考虑部分分a = {1,3}
对于只有1/3的区间，贡献为0
对于有1又有3的区间，贡献为abs(#1 - #3)
那么可以考虑前缀和，然后枚举 r，做两次前缀和就可以了
*/