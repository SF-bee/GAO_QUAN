#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;

int T;
int n;
std::vector<int> g[MAX];
ll siz[MAX], dep[MAX], mde[MAX];

struct cmp {
    bool operator()(int x, int y) const { return mde[x] > mde[y]; }
};

void solve() {
    memset(siz, 0, sizeof(siz));
    memset(dep, 0, sizeof(dep));
    memset(mde, 0, sizeof(mde));
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int f, i = 2; i <= n; i++) {
        std::cin >> f;
        g[f].push_back(i);
    }
    ll ans1 = 0, ans2 = 0;
    auto dfs1 = [&](auto &self, int u) -> void {
        siz[u] = 1;
        for (auto v : g[u]) {
            mde[v] = dep[v] = dep[u] + 1;
            self(self, v);
            siz[u] += siz[v];
            mde[u] = std::max(mde[u], mde[v]);
        }
        ans1 = std::max(ans1, mde[u]);
        ans2 += dep[u];
    };
    dfs1(dfs1, 1);
    for (int u = n; u >= 1; u--) {
        std::priority_queue<int, std::vector<int>, cmp> q1;
        std::priority_queue<ll, std::vector<ll>, std::greater<ll>> q2;
        for (auto v : g[u]) {
            q1.push(v);
            q2.push(siz[v]);
        }
        while (q1.size() > 2) {
            int a = q1.top();
            q1.pop();
            int b = q1.top();
            q1.pop();
            mde[u] = std::max({mde[u], ++mde[a], ++mde[b]});
            ans1 = std::max({ans1, mde[a], mde[b]});
            if (mde[a] > mde[b]) q1.push(a);
            else
                q1.push(b);
        }
        while (!q1.empty()) {
            int x = q1.top();
            q1.pop();
            mde[u] = std::max(mde[u], mde[x]);
        }
        ans1 = std::max(ans1, mde[u]);

        while (q2.size() > 2) {
            ll a = q2.top();
            q2.pop();
            ll b = q2.top();
            q2.pop();
            ans2 += a + b;
            q2.push(a + b);
        }
    }
    std::cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    while (T--)
        solve();
    return 0;
}
/*
考虑第一问：
那么对于每一个节点，如果它个数小于2，那么对深度没有影响
每次合并会让子树深度加1
那么就合并浅的点，因为浅的点变深不一定会让树高变大
依次合并然后丢进优先队列？？？这样是n^2logn的
第二问是一样的吧，每次合并都会让对答案贡献一个子树大小
那么我们就合并子树小的
但是直接暴力合并是每个点nlogn的，这可怎么办？
不对，每个点是 ulogu的，u之和是n所以总复杂度就是nlogn
*/
