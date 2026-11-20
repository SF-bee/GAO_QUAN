#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;
const ll mod = 998244353;

int n, D;
int a[MAX];
ll L, R;
// s 存储单人组/二人组的时间和对应的{位置,是否双人}
using Pair = std::pair<int, std::pair<int, int>>;
std::vector<Pair> p;
struct ZkwTree {
    int N = 1;
    struct Node {
        ll M[2][2];
        Node operator*(const Node &rs) const {
            Node res;
            res.M[0][0] = (M[0][0] * rs.M[0][0] % mod + M[0][1] * rs.M[1][0] % mod) % mod;
            res.M[0][1] = (M[0][0] * rs.M[0][1] % mod + M[0][1] * rs.M[1][1] % mod) % mod;
            res.M[1][0] = (M[1][0] * rs.M[0][0] % mod + M[1][1] * rs.M[1][0] % mod) % mod;
            res.M[1][1] = (M[1][0] * rs.M[0][1] % mod + M[1][1] * rs.M[1][1] % mod) % mod;
            return res;
        };
    } tre[MAX << 2];

    void Build() {
        for (; N <= n + 1; N <<= 1)
            ;
        for (int i = N; i < (N << 1); i++)
            tre[i].M[0][0] = tre[i].M[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            tre[N + i].M[0][0] = tre[N + i].M[0][1] = tre[N + i].M[1][1] = 0;
            tre[N + i].M[1][0] = 1;
        }
        for (int i = N - 1; i >= 1; i--)
            tre[i] = tre[i << 1 | 1] * tre[i << 1];
    }
    void Update(int p, int pos, int k) {
        p += N;
        tre[p].M[0][pos] = k;
        for (p >>= 1; p; p >>= 1)
            tre[p] = tre[p << 1 | 1] * tre[p << 1];
    }
} zkw;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> D;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    // 预处理所有单/双组
    for (int i = 1; i <= n; i++) {
        p.push_back({a[i], {i, 0}});                       // 单组修改第一个
        if (i > 1) p.push_back({a[i] + a[i - 1], {i, 1}}); // 双组修改第二个
    }
    std::sort(p.begin(), p.end(), [&](Pair x, Pair y) { return x.first < y.first; });
    zkw.Build();
    ll ans = 0;
    for (int l = 0, r = 0; l < p.size(); l++) {
        L = p[l].first, R = L + D;
        while (r < p.size() && p[r].first <= R) {
            zkw.Update(p[r].second.first, p[r].second.second, 1);
            r++;
        }
        ll ans1 = zkw.tre[1].M[0][0];
        // 求出 L + 1 的位置，同时跳过所有值一样的 L 防止重复
        int nxt = l;
        while (nxt < r && p[nxt].first == p[l].first) {
            zkw.Update(p[nxt].second.first, p[nxt].second.second, 0);
            nxt++;
        }
        ll ans2 = zkw.tre[1].M[0][0];
        l = nxt - 1;
        ans = (ans + ans1 - ans2 + mod) % mod;
    }
    std::cout << ans << '\n';
    return 0;
}
/*
直接统计所有方案是不容易的，因为什么信息都没有，一般的解决方案就是
固定一个最小值，然后统计不大于另一个边界的值。
因此，设 dp[L][L + D] 表示所有任务的时间落在 [L,L+D] 的方案数
那么为了不重不漏，对于每一个 L 的方案就是 [L,L+D] - [L+1,L+D]
不同的执行时间是 O(n) 的，所以 L 也是 O(n) 的
所以可以枚举每一个 L
考虑对于每一个 L 如何求出答案？
设 f[i] 表示考虑到第 i 个元素，所有组都落在 [L,R] 的方案数
那么有转移 f[i] = [L<= a[i] <= R]*f[i - 1] + [L <= a[i] + a[i - 1] <= R] * f[i - 2]
边界f[-1] = 0,f[0] = 1;
可以线段树维护矩阵
  f[i]   s[i] s[i-1]
f[i - 1]  1      0
*/