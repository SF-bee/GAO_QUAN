#include <bits/stdc++.h>
const int MAX = 5e2 + 5;

int n, k;
int v[MAX];
std::pair<int, int> r[MAX];
double dp[MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> r[i].first >> r[i].second;
    std::sort(r + 1, r + n + 1, [](const auto &a, const auto &b) {
        if (a.second == -1 && b.second == -1) return false;
        if (a.second == -1) return false;
        if (b.second == -1) return true;
        return a.second < b.second;
    });

    for (int m = 0; m <= k; ++m) {
        std::memset(dp, 0x3f, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
        }
    }
    return 0;
}
/*
打部分分吧
#4-6 都不能提供模块，所以直接排个序就可以算了
#7-9 所有速度都相等，那么就是相当于拿模块没用，和上一档一样的
n < 70
是不是分层图啊
接入模块是不是越早越好呢？
如果我不修好这座塔，那么我也没必要为了拿模块去修这座塔？
不对吧，万一这座塔的拿模块费用很低呢？
背包吗？
设 dp[i][j][k] 表示考虑到第 i 个塔，有 j 个模块，修好了 k 座塔的最小用时
那么转移方程
第 i 座塔可以是修一半 dp[i - 1][j - 1][k] + b[i] / a[j - 1]
第 i 座塔可以是从修一半修好了 dp[i - 1][j][k - 1] + (a[i] - b[i]) / a[j]
或者是直接从 0 修好 dp[i - 1][j - 1][k - 1] + a[i] / a[j - 1]
枚举顺序呢？
不对，这样设计有后效性了，我先修后面的塔有可能让前面更优，可能需要排序

如果一个 a 要被维修，那么放到后面再修一定是不劣的
因为如果在一个 b 前修，那么一定是不如在后面修更好的
然后按照 b 进行排序（-1不参与排序？），那么答案的形式一定是把某个长度的前缀全部修 a 或者 b
然后再从最后一个 b 之后选择最小的 a 补齐
然后枚举我们要修 m 个 b，然后dp_i,j表示考虑前 i 个维修了 j 个 b 的最小用时
转移就是
dp_i,j = min(dp_{i-1,j-1} + b[i]/v[j-1],dp_{i-1,j} + a[i]/v[m])
对于每一个 m跑完之后 我们再固定 j = m，然后枚举 i，这样每一个
i都会分成两部分：一部分是前缀全部修完，剩下的部分就选小的a补齐
*/