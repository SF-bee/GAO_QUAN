#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int T, D;
int n, a[MAX];

struct BIT {
    int sum[MAX];
#define lowbit(x) (x & (-x))
    void add(int p, int x) {
        for (; p <= n; p += lowbit(p))
            sum[p] += x;
    }
    ll query(int r) {
        ll res = 0;
        for (; r; r -= lowbit(r))
            res += sum[r];
        return res;
    }
    ll query(int l, int r) { return query(r) - query(l - 1); }
} bit;
void sol1() {
    std::vector<ll> pre(n + 1, 0), suf(n + 2, 0);
    memset(bit.sum, 0, sizeof(bit.sum));
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + bit.query(a[i] + 1, n);
        bit.add(a[i], 1);
    }
    memset(bit.sum, 0, sizeof(bit.sum));
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + bit.query(1, a[i] - 1);
        bit.add(a[i], 1);
    }
    ll ans = INF, cnt = 0;
    for (int i = 1; i < n; i++) {
        memset(bit.sum, 0, sizeof(bit.sum));
        ll ndp = 0;
        for (int j = i + 1; j < n; j++) {
            ndp = ndp + bit.query(a[j] + 1, n);
            bit.add(a[j], 1);
            if (pre[i] + ndp + suf[j + 1] < ans) {
                ans = pre[i] + ndp + suf[j + 1];
                cnt = 1;
            } else if (pre[i] + ndp + suf[j + 1] == ans)
                cnt++;
        }
    }
    std::cout << ans << ' ' << D * cnt << '\n';
}
void sol2() {
    std::array<std::vector<ll>, 4> dp;
    dp.fill(std::vector<ll>(n + 1));
    int cl = 1, cr = n;
    ll w = 0;
    for (int i = 1; i <= n; i++) {
        dp[1][i] = (w += bit.query(a[i] + 1, n));
        bit.add(a[i], 1);
    }
    auto move = [&](int nl, int nr) {
        while (cl > nl) {
            --cl;
            w += bit.query(1, a[cl] - 1);
            bit.add(a[cl], 1);
        }
        while (cr < nr) {
            ++cr;
            w += bit.query(a[cr] + 1, n);
            bit.add(a[cr], 1);
        }
        while (cl < nl) {
            w -= bit.query(1, a[cl] - 1);
            bit.add(a[cl], -1);
            ++cl;
        }
        while (cr > nr) {
            w -= bit.query(a[cr] + 1, n);
            bit.add(a[cr], -1);
            --cr;
        }
    };
    auto sol = [&](auto &self, int t, int l, int r, int optL, int optR) -> void {
        if (l > r) return;
        int mid = (l + r) >> 1, bO = -1;
        ll bV = INF;
        for (int j = std::max({l, t - 1, optL}); j <= std::min({mid - 1, r, optR}); ++j) {
            move(j + 1, mid);
            ll val = dp[t - 1][j] + w;
            if (val < bV) {
                bV = val;
                bO = j;
            }
        }
        dp[t][mid] = bV;
        self(self, t, l, mid - 1, optL, bO);
        self(self, t, mid + 1, r, bO, optR);
    };
    std::memset(bit.sum, 0, sizeof(bit.sum));
    sol(sol, 2, 2, n, 1, n);
    std::memset(bit.sum, 0, sizeof(bit.sum));
    sol(sol, 3, 3, n, 2, n);
    cl = 1, cr = n;
    w = 0;
    for (int i = 1; i <= n; i++) {
        dp[1][i] = (w += bit.query(a[i] + 1, n));
        bit.add(a[i], 1);
    }
    std::cout << dp[3][n] << ' ' << 0 << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T >> D;
    while (T--) {
        std::cin >> n;
        std::vector<int> book;
        for (int i = 1; i <= n; i++)
            std::cin >> a[i], book.push_back(a[i]);
        std::sort(book.begin(), book.end());
        book.erase(std::unique(book.begin(), book.end()), book.end());
        for (int i = 1; i <= n; i++)
            a[i] = std::lower_bound(book.begin(), book.end(), a[i]) - book.begin() + 1;
        if (n <= 5e3 + 5) sol1();
        else
            sol2();
    }
    return 0;
}
/*
枚举分界前
分别预处理前缀和后缀的逆序对，中间再单独搞

也许可以 dp?
dp[t][i] 表示把前 i 个分成 t 段的最小
那么设 w(l,r) 表示从区间 [l,r] 的逆序对个数
dp[t][i] = min{dp[t-1][j] + w(j + 1,i)} t-1 <= j <= i
这个可以分治优化 dp
*/