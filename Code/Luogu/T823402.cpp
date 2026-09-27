#include <bits/stdc++.h>
const int MAX = 3e5 + 5;
const int mod = 998244353;

int T;
int n, m;
int a[MAX], b[MAX], frac[MAX];
std::vector<int> A[MAX], B[MAX];

void solve() {
    std::cin >> n >> m;
    for (int j = 1; j <= n; j++)
        A[j].clear(), B[j].clear();
    for (int i = 1; i <= m; i++) {
        for (int num, j = 1; j <= n; j++)
            std::cin >> num, A[j].push_back(num);
        for (int num, j = 1; j <= n; j++)
            std::cin >> num, B[j].push_back(num);
    }
    std::map<std::vector<int>, std::vector<int>> f;
    for (int i = 1; i <= n; i++)
        f[A[i]] = {};
    for (int i = 1; i <= n; i++) {
        if (!f.count(B[i])) {
            std::cout << 0 << '\n';
            return;
        }
        f[B[i]].push_back(i);
    }
    int ans = 1;
    for (auto vec : f)
        ans = 1ll * ans * frac[vec.second.size()] % mod;
    std::cout << ans << '\n';
}

int main() {
#if !ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    frac[0] = 1;
    for (int i = 1; i < MAX; i++)
        frac[i] = (1ll * frac[i - 1] * i) % mod;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}
/*
先解决不合法的情况：
如果b中的元素不是a的排列，那么一定不合法
观察是什么导致了不同的结果？是相同的元素，相同的元素导致我们不知道对应关系
换句话说，独一的元素可以确定一个位置
先考虑m = 1吧
可以记录a中的每一种元素对应了b中的什么位置
如果位置 1 ，那么对答案贡献*1
如果位置 > 1，那么对答案贡献*A_len^len
如果位置 = 0，那么对答案贡献*0
那m > 1呢？不同轮次的询问怎么结合呢？

*/