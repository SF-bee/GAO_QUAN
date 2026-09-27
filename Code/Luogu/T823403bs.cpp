#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n, k, ans;
int num[MAX];
bool vis[MAX];

void dfs(int d, int sum, int pro, int pre) {
    if (d == k + 1) {
        if (sum > 0 && pro % sum == 0) ans++;
        return;
    }
    for (int i = pre + 1; i <= n; i++)
        if (!vis[i]) {
            vis[i] = 1;
            dfs(d + 1, sum + num[i], pro * num[i], i);
            vis[i] = 0;
        }
    return;
}

int main() {
#if !ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".ans", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.size(); i++)
        num[i + 1] = s[i] - '0';
    dfs(1, 0, 1, 0);
    std::cout << ans << '\n';
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
应该还要维护一些积的信息？和可以提前分解吧？
先分割一下问题，选/不选 0
选的单独算。
不选：
设 dp[j][s][c2][c3][c5][c7] 表示选了 j 个,和为 s 的,质因子2,3,5,7个数为……的方案数

*/