#include <bits/stdc++.h>
using ll = long long;
const int N = 3e3 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N], c[N];
ll K, b[N], d[N], e[N], x[N], sum[N];
ll minC = 0, minV = 0, A[N], B[N]; // minC 表示都不出门的满意度，minV表示花费
ll dp[N][10 * N];
ll pre[10 * N], head[10 * N], tail[10 * N];
uint16_t que[10 * N][N];

ll front(int i) { return dp[que[i][head[i]]][i]; }
ll back(int i) { return dp[que[i][tail[i] - 1]][i]; }

void sol() {
    memset(dp, 0x3f, sizeof(dp));
    memset(pre, 0x3f, sizeof(pre));
    dp[0][0] = minV;
    pre[0] = dp[0][0];
    que[0][tail[0]++] = 0;
    for (int t = 0, i = 1; i <= n; i++) {
        // 更新分界
        while (t < i - 1 && sum[i - 1] - sum[t] > K)
            t++;
        // 弹出过期元素
        for (int j = 0; j <= 10 * n; j++)
            while (head[j] < tail[j] && que[j][head[j]] < t)
                head[j]++;
        for (int j = A[i]; j <= 10 * n; j++) {
            // 需要路费
            dp[i][j] = std::min(dp[i][j], pre[j - A[i]] + e[i] + B[i]);
            // 不需要路费
            if (head[j - A[i]] < tail[j - A[i]])
                dp[i][j] = std::min(dp[i][j], front(j - A[i]) + B[i]);
        }
        for (int j = A[i]; j <= 10 * n; j++) {
            if (dp[i][j] >= INF) continue;
            // 更新决策集合
            pre[j] = std::min(pre[j], dp[i][j]);
            while (head[j] < tail[j] && back(j) >= dp[i][j])
                tail[j]--;
            que[j][tail[j]++] = i;
        }
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> q >> K;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> x[i];
        A[i] = c[i] - a[i];
        B[i] = d[i] - b[i];
        minC += a[i], minV += b[i];
    }
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1] + x[i];
    sol();
    for (int j = 10 * n - 1; j >= 0; j--)
        pre[j] = std::min(pre[j], pre[j + 1]);
    while (q--) {
        ll m;
        std::cin >> m;
        if (minV > m) std::cout << "-1 ";
        else
            std::cout << minC + std::upper_bound(pre, pre + 10 * n + 1, m) - pre - 1 << ' ';
    }

    return 0;
}
/*
题目大意
这道题看着就很背包啊，所以应该是 dp
dp[i][j][m][l] 表示前i天，选择了j个1，花费不超过m，上一次选m是i=l的最大幸福值
喂喂喂，k的范围是 1e18，m的范围是 1e18，n的范围是 3e3，这个 dp 是不可能过的
但是满意度很小啊
dp[i][a][t] 表示前i天，幸福值为a,最后一次出门的天数是t的最小花费
复杂度 O(10n^3) 我去，好像有说法？

注意到每一天都必须吃饭，所以为了方便讨论可以设
A_i = c_i - a_i
B_i = d_i - b_i
然后就可以提前算出最小的预算和最小满意度
设 dp[i][j] 表示考虑到第 i 天，并且第 i 天出门，额外满意度达到 j 的最小花费
dp[i][j] = min_k<=i-1{dp[k][j - A[i]] + [sum[i-1] - sum[k] > K]*e[i]} + B[i]
设 t 是最小满足 sum[i - 1] - sum[t] <= K 的整数，这个是单调的，可以维护
那么决策集合分为两段
min_k<t{dp[k][j - A[i]] + e[i]}
这个直接看成min_k<i{dp[k][j - A[i]] + e[i]}对答案没有影响，
直接维护前缀 dp[][j - A[i]] 的前缀最小值
min_t<=k<i{dp[k][j - A[i]]}
这个可以单调队列
*/