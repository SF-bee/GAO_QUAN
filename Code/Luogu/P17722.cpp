#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;
const int MNUM = 2e6 + 5;

int n, m;
int a[MAX], sum[MNUM];
ll cost[MAX];

int GetSuf(int x) { return sum[MNUM - 1] - sum[x]; }

int main() {
#if !ONLINE_JUDGE
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], sum[a[i]]++;
    for (int i = 1; i < MNUM; i++)
        sum[i] += sum[i - 1];
    for (int l, i = 1; i <= m; i++) {
        std::cin >> l;
        for (int b, j = 1; j <= l; j++)
            std::cin >> b, cost[i] += GetSuf(b);
    }

    std::sort(cost + 1, cost + m + 1);
    ll ans = 0, sum = 1ll * n * (n + 1) / 2;
    for (int i = 1; i <= m; i++) {
        sum += cost[i];
        // std::cout << sum << '\n';
        ans += sum;
    }

    std::cout << ans << '\n';
    return 0;
}
/*
题目大意：给定一个初始序列 a,和 m 个操作序列
每次操作需要把操作序列扔进上一次操作完的序列并排序
代价为操作之后初始序列在新序列中的下标之和
求操作方案最小化 m 次操作

考虑怎么求出每一次操作的代价？
开个桶，存初始序列，然后求前缀和，这样对于每一个新加入的元素，我们可以直接算出它对下标的增量
然后每个操作的代价是单增的
也就是越早进行的操作会使得累计得越多
好像就是合并果子
*/