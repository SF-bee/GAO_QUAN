#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n, k;
int cnt[10];

int main() {
#if !ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    for (auto ch : s)
        cnt[ch - '0']++;
    return 0;
}
/*
C 1e5 100 非常巨大，肯定不能枚举（废话
不过100相对于1e5来说非常小，似乎是一个切入点？
观察到题面居然说0可以被任何数整除，这似乎启发我们按照积进行分组？
100个0～9和的结果数是非常小的！只有900！
而且非常像背包啊，甚至是非常友好的多重背包
题目大意：
给定 n 个 [0,9]，每个数字有若干个。一个大小为 k 的背包。
求出装满背包，并且和可以整除积的方案数
设 dp[i][j] 表示
*/