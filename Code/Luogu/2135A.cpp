#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int T;
int n, a[MAX];
int pre[MAX], dp[MAX];

void sol() {
    std::memset(pre, 0, sizeof(pre));
    std::memset(dp, 0, sizeof(dp));
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::vector<std::queue<int>> q(n + 1);
    for (int i = 1; i <= n; i++) {
        q[a[i]].push(i);
        while (q[a[i]].size() > a[i])
            q[a[i]].pop();
        if (q[a[i]].size() == a[i]) dp[i] = pre[q[a[i]].front() - 1] + a[i];
        pre[i] = std::max(pre[i - 1], dp[i]);
    }
    std::cout << pre[n] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    while (T--)
        sol();
    return 0;
}
/*
定义块是其中元素与长度都相等的子串，求最长的子序列满足其由若干个块组成

一看就是某种 dp，考虑需要什么状态？
考虑到 i，以 j 结尾，结尾长度为 k 的最长子序列！
然后成功得到一个 n^4 的 dp

这些状态真的是必要的吗？
我们只关系完整的块，所以生成中的块应该是不处理的
考虑到 i，以 i 结尾的最长子序列
那么肯定选择从这个开始的最接近 i 的 a[i] 个 a[i]
接到哪里？最前一个 a[i] 前的最长的一个 dp，这个前缀最大值即可
可以先预处理出每一个元素最长到哪里？这个看起来不容易，也许需要在转移过程中从处理
a[i]<=n，这是一个性质吗？
开 n 个队列不就好了？存每一种元素出现的位置
*/