#include <bits/stdc++.h>
using ll = long long;
const int N = 3e5 + 5;
const int M = 5e5 + 5;

// 答案记得开ll！
int T;
int n, m;
ll a[N];

void sol() {
    std::vector<std::pair<int, ll>> g[N];
    std::cin >> n >> m;
    for (int u, v, w, i = 1; i <= m; i++)
        std::cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);

    std::vector<ll> d(n + 1, -1);
    bool ok = true;
    auto dfs1 = [&](auto &self, int u, std::vector<int> &nd) -> void {
        nd.push_back(u);
        for (auto [v, w] : g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] ^ w;
                self(self, v, nd);
            } else if (d[v] != (d[u] ^ w)) {
                ok = false;
            }
            if (!ok) return;
        }
    };

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        std::vector<int> res;
        if (d[i] == -1) d[i] = 0, dfs1(dfs1, i, res);
        if (!ok) {
            std::cout << -1 << '\n';
            return;
        }
        for (int k = 0; k <= 30; k++) {
            int cnt = 0;
            for (auto v : res)
                if (d[v] & (1 << k)) cnt++;
            if (cnt <= res.size() / 2) ans += 1ll * cnt * (1 << k);
            else
                ans += 1ll * (res.size() - cnt) * (1 << k);
        }
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
给定若干条异或为 w 的限制，求所有元素和的最小值
感觉是拆位？
没有限制当然是取 0 啊
有限制呢？
无论如何，它们的和的最小值一定是不超过 w 的，因为异或就是没有进位的加法
这是限制块里只有两个元素的情况，更多的呢？
这样就变成一个图论问题了，我们每一位分开考虑
a1 ^ a2 = w1，a2 ^ a3 = w2
那么 a1 ^ a3？
a1 ^ a3 = w1 ^ w2
推广一下：a_u ^ a_v = 路径上的w异或和
我们考虑每一个元素 a_i 与根之间有什么关系？a_i ^ a_r = 路径上的w异或和
也就是 a_i = 路径上的w异或和 ^ a_r
那么无解？环上的限制一定是 0 为什么？因为 ai ^ ai = 0 = xorsum wi
等一下等一下，这里详细一点
a_i = x ^ d1, a_i = x ^ d2
那么d1 ^ d2 = 0
那 a_i 究竟是多少？你啥子吧，d1 ^ d2 = 0 那不就是 d1 = d2 吗
这个搜一下就可以了
然后就是最小化答案
一个连通块内和就是 \sum {x ^ d_i}
现在终于可以拆位了，x的每一位要么 0 要么 1，然后分别看看哪种小选哪个
对于每一个连通块，统计这一位 d_i 1 的个数就行
*/