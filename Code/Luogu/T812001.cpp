#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;

int n, p[MAX], bt[MAX], mp;
std::pair<int, int> cp[MAX];
struct FWT {
    int sum[MAX];
#define lowbit(x) (x & (-x))
    void add(int pos, int x) {
        for (; pos <= mp; pos += lowbit(pos))
            sum[pos] += x;
    }
    void qadd(int l, int r, int x) {
        add(r + 1, -x);
        add(l, x);
    }
    int query(int x) {
        int res = 0;
        while (x) {
            res += sum[x];
            x -= lowbit(x);
        }
        return res;
    }
} fwt;
int cost(int pa, int pb, int S) {
    if (pa > pb) std::swap(pa, pb);
    if (S <= pa - 1) return 2;
    if (S <= std::max(pa + 2, pb - 1)) return 1;
    return 0;
}

int main() {
    freopen("football.in", "r", stdin);
    freopen("football.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= 2 * n; i++)
        std::cin >> p[i], p[i]++, mp = std::max(mp, p[i] + 3);

    for (int a, b, i = 0; i < n; i++) {
        std::cin >> a >> b;
        a++, b++;
        bt[a] = b;
        bt[b] = a;
        if (p[a] > p[b]) std::swap(a, b);
        fwt.qadd(1, p[a] - 1, 1);
        fwt.qadd(1, std::min(std::max(p[a] + 3, p[b]), p[b] + 1) - 1, 1);
    }
    for (int i = 1; i <= 2 * n; i++) {
        int rank = fwt.query(p[i] + 3) - cost(p[i], p[bt[i]], p[i] + 3);
        rank += (p[bt[i]] > p[i] + 3 ? 1 : 0);
        std::cout << rank + 1 << " \n"[i == 2 * n];
    }
    return 0;
}
/*
每个队伍恰好进行一次比赛，那么最优肯定是获得3分
那么接下来就要考虑其他比赛的胜负分配
如果一场比赛的两支队伍同时低于这个队伍3分及以上，那么无需处理，因为它们一定不会影响到排名
低于1分以下，可以平局
有点像偏序
不如把每场比赛参赛的队伍分数看成一个区间？
px > S 那么无论怎么样 S 都不会超过x
如果px + 3 < S 那么无论怎么样，x 都不会超过 x
那么其实只需要考虑如何分配那些分数在区间 [S - 3,S] 的队伍
它们肯定不能赢，不过还有一种两个队伍都在[S - 2,S]这时候必有一支队伍超过 S
可以考虑树状数组维护这个信息
*/