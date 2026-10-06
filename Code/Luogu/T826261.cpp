#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;
const int K = 40;
const int INF = 0x3f3f3f3f;

int n, q;
ll a[MAX];
int f[40][MAX], suf[40][MAX];

int main() {
#if !ONLINE_JUDGE
    freopen("alchemy.in", "r", stdin);
    freopen("alchemy.out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::memset(f, 0x3f, sizeof(f));
    std::memset(suf, 0x3f, sizeof(suf));
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i] == 0) f[0][i] = i;
    }

    for (int k = 1; k < K; k++) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) f[k][i] = i;
            else if (a[i] < k && f[k - 1][i] != INF)
                f[k][i] = f[k - 1][f[k - 1][i] + 1];
        }
    }
    for (int k = 0; k < K; k++)
        for (int i = n; i >= 1; i--)
            suf[k][i] = std::min(suf[k][i + 1], f[k][i]);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        for (int k = K - 1; k >= 0; k--)
            if (suf[k][l] <= r) {
                std::cout << k << '\n';
                break;
            }
    }
    return 0;
}
/*
我们需要一个每次询问logn甚至1的算法
最终的宝石一定是由某个连续区间得到的
注意到 a 的值域很小，正解也许和这个有关
有没有可能是二分答案？如果一个答案不可能，那么更高的也不可能，反之
那么考虑怎么验证一个答案是否合法，不对不对
考虑部分分，如果a相等：
那么答案就是 a + x , x 满足 2^x <= l
那么 n^2 的做法就是把区间内的点全都取出，然后依次记录连续相等区间的长度，
然后按照等级依次合并每一个等级的宝石，可以算出下一级的宝石有多少
可以提前标记出所有宝石属于的区间，然后询问的时候截断边界的区间
这个东西其实是在干什么呢？它似乎是在做二进制的加法？
如果把每个数字映射成一个 2^a,那么合并就是在做加法
但是不能前缀和，这样会导致一些不合法的合并，比如不相邻
有没有可能是倍增呢？
我们设 f[i][k] 表示以 i 为右端点，合成出 k 的最短终点
那么转移就是
f[i][k] = i,a[i] = k
f[i][k] = f[f[i][k - 1]][k - 1],a[i] < k
那么查询l,r的时候：
我们可以枚举 k,然后看是否存在 f[i][k] < R
因为 f[i][k] < R 那么这个区间一定是满足 i < R的也就是说其实不需要限制上界

*/