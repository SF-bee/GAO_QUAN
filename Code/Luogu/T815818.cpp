#include <bits/stdc++.h>
using ll = long long;
const int MAX = 4e5 + 5;
const int mod = 998244353;

int n, K, L;
std::vector<std::pair<int, int>> a;
int mst[MAX], cnt[MAX];
int fact[MAX], infact[MAX], C0[MAX], C1[MAX], C2[MAX];

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = 1ll * fact[i - 1] * i % mod;
    auto qpow = [&](int x, int p) {
        int res = 1;
        while (p) {
            if (p & 1) res = 1ll * res * x % mod;
            x = 1ll * x * x % mod;
            p >>= 1;
        }
        return res;
    };
    infact[MAX - 1] = qpow(fact[MAX - 1], mod - 2);
    for (int i = MAX - 2; i >= 0; i--)
        infact[i] = 1ll * infact[i + 1] * (i + 1) % mod;
}
int C(int n, int m) {
    if (m > n || m < 0) return 0;
    return 1ll * fact[n] * infact[m] % mod * infact[n - m] % mod;
}

int main() {
#if !ONLINE_JUDGE
    freopen("case.in", "r", stdin);
    freopen("case.out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    init();
    std::cin >> n >> K >> L;
    for (int x, s, i = 1; i <= n; i++) {
        std::cin >> x >> s;
        if (s == 2) continue;
        a.push_back({x, s});
    }
    std::sort(a.begin(), a.end());
    n = a.size();
    if (n == 0) {
        std::cout << (K == 0) << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++)
        a.push_back({a[i].first + L, a[i].second});
    for (int i = 0; i < 2 * n; i++) {
        if (a[i].second == 0) cnt[i] = 1;
        else if (a[i].second == 1)
            mst[i] = 1;
        if (i > 0) cnt[i] += cnt[i - 1], mst[i] += mst[i - 1];
    }
    mst[2 * n] = mst[2 * n - 1];
    cnt[2 * n] = cnt[2 * n - 1];
    if (mst[n - 1] > K) {
        std::cout << 0 << '\n';
        return 0;
    }
    if (K < 3 && K - mst[n - 1] >= 0) {
        std::cout << C(cnt[n - 1], K - mst[n - 1]) << '\n';
        return 0;
    }

    int ans = 0;
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        // 枚举大于L/2的，内部不包含必选点的空弧，排除掉
        while (j < i + n && a[j].first - a[i].first <= L / 2)
            j++;
        if (mst[j - 1] - mst[i] > 0) continue;
        k = std::max(k, j);
        // 从j开始往后找第一个必选点
        while (k < i + n && mst[k] - mst[i] == 0)
            k++;
        if (k > j) {
            // k更新过，所以 j 到 k - 1 之间一定全是0
            int cc = K - mst[n - 1] - (a[i].second == 0) - 1;
            ans = (ans + C(cnt[i + n - 1] - cnt[j] + 1, cc + 1) -
                   C(cnt[i + n - 1] - cnt[k - 1], cc + 1)) %
                  mod;
        }
        // k==j或者是最后的k，那这个一定是1
        int cc = K - mst[n - 1] - (a[i].second == 0);
        ans = (ans + C(cnt[i + n - 1] - cnt[k], cc)) % mod;
    }
    std::cout << ans << '\n';
    return 0;
}
/*
我们注意到，题目的限制实际上是说
环上取三段弧，每段弧不能都小于周长的一半 <-> 最长弧长小于1/L
可以注意到，超过弧长一半的只会有一段
直接正着去考虑所有的合法方案数
我们考虑一个事件它是最大弧长的一个端点
因为它是最大弧长，所以我们就在另外一侧去数点，这样就可以保证一定没有非法的
直接枚举不选的弧[i,j]，然后在对侧选点
*/