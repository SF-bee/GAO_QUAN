#include <bits/stdc++.h>
const int MAX = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int n, k;
int en[MAX];
std::vector<int> g[MAX];

bool check(int mid) {
    // OnSiz[u] 表示与 u 相连，已经通上电的节点数
    // OffSiz[u] 表示与 u 相连，没有同上电的节点数
    std::vector<int> OnSiz(n + 1, 0), OffSiz(n + 1, 0);
    auto dfs = [&](auto &self, int u, int fa) -> bool {
        int tot = 1; // 统计子树内需要并网的点数（自己也算一个）
        for (auto v : g[u])
            if (v != fa) {
                if (!self(self, v, u)) return false;
                // 发电机一定不会有残留的并网点
                if (!en[v]) tot += OffSiz[v];
            }
        // 如果需要的比限量还大，那么不可能
        if (tot > mid) return false;
        // 这个是发电机，那么把所有都点了，不然不可能由其他来点
        if (en[u]) {
            OnSiz[u] = tot;
            return true;
        }
        // 这个不是发电机，看看儿子里有没有可以帮的，不然就只能等父亲了
        else {
            // 这里必须要找容量最大的点去帮
            int mina = INF;
            for (auto v : g[u])
                if (v != fa) mina = std::min(mina, OnSiz[v]);
            if (mina + tot <= mid) {
                OnSiz[u] = mina + tot;
                return 1;
            }
            OffSiz[u] = tot;
            OnSiz[u] = INF;
            return true;
        }
    };
    bool flag1 = dfs(dfs, 1, 1);
    return flag1 && !OffSiz[1];
}

int main() {
#if !ONLINE_JUDGE
    freopen("typhoon.in", "r", stdin);
    freopen("typhoon.out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    for (int u, i = 1; i <= k; i++)
        std::cin >> u, en[u] = 1;
    for (int u, v, i = 1; i < n; i++)
        std::cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    int ans = n;
    for (int l = 1, r = n, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) {
        if (check(mid)) ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    std::cout << ans;
    return 0;
}
/*
给定一棵树，树上有若干个电站
求出一种删边方式，使得所有的连通块内都存在电站并且最大的连通块最小

可以先预处理出每一颗子树的大小和子树是否通电
二分，二分连通块大小 mid
每次 check 连通块是否可以不超过 mid
check怎么做？
dfs，
记录子树 i 内与根相连，并且没有通电的节点个数
记录子树 i 内与根相连，并且已经通电的节点个数
每一个节点，要么是发电机，要么不是
发电机要么只点自己子树内的，要么把自己子树内和父亲子树内的全都点了
不然必然是不合法的

5 2
1 2
2 3
3 4
4 5
1 5

*/