#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e3 + 5;
const ll IINF = 0xf3f3f3f3f3f3f3f3;
const ll MOD = 1e9 + 7;

int n, m;
int maz[MAX][MAX], ind[MAX][MAX];
ll scr[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool oc[MAX][MAX];
ll dp[2][MAX][MAX]; // 0左脚/1右脚 进入i,j的最大得分

int main()
{
    freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    std::cin.tie(0);

    memset(dp, 0xf3, sizeof(dp));
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char ch;
            std::cin >> ch;
            switch (ch) {
                case 'U':
                    maz[i][j] = 0;
                    ind[i - 1][j] += 1;
                    break;
                case 'D':
                    maz[i][j] = 1;
                    ind[i + 1][j] += 1;
                    break;
                case 'L':
                    maz[i][j] = 2;
                    ind[i][j - 1] += 1;
                    break;
                case 'R':
                    maz[i][j] = 3;
                    ind[i][j + 1] += 1;
                    break;
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> scr[i][j];

    std::queue<std::pair<int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!ind[i][j])
                q.push({i, j});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        oc[x][y] = 1;
        int tx = x + dx[maz[x][y]];
        int ty = y + dy[maz[x][y]];
        if (!(--ind[tx][ty]))
            q.push({tx, ty});
    }
    auto find = [&](auto &self, int x, int y, std::vector<std::pair<int, int>> &t) {
        if (oc[x][y])
            return;
        oc[x][y] = 1;
        t.push_back({x, y});
        int tx = x + dx[maz[x][y]];
        int ty = y + dy[maz[x][y]];
        self(self, tx, ty, t);
    };
    std::vector<std::vector<std::pair<int, int>>> rd;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!oc[i][j]) {
                std::vector<std::pair<int, int>> t;
                find(find, i, j, t);
                t.insert(t.end(),t.begin(),t.end());
                rd.push_back(t);
            }
    for(auto t : rd) {
        std::queue<int> q;
        std::vector<ll> sum(t.size());
        sum[0] = scr[t[0].first][t[0].second];
        for(int base = -1,i = 1; i < t.size(); i++,base *= -1)
            sum[i] = sum[i - 1] + base * scr[t[i].first][t[i].second];
    }


    auto in = [&](int x, int y) {
        return 1 <= x && x <= n && 1 <= y && y <= m;
    };
    auto dfs = [&](auto &self, int foot, int x, int y) -> ll {
        if (dp[foot][x][y] != IINF)
            return dp[foot][x][y];
        ll res = (foot ? -scr[x][y] : scr[x][y]);
        int tx = x + dx[maz[x][y]];
        int ty = y + dy[maz[x][y]];
        if (!in(tx, ty))
            return dp[foot][x][y] = res;
        ll abc = self(self, foot ^ 1, tx, ty);
        res = std::max(res, res + abc);
        return dp[foot][x][y] = res;
    };

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dfs(dfs, 0, i, j);
    ll ans = 0, base = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = (ans + dp[0][i][j] * base % MOD) % MOD;
            base = base * 131 % MOD;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
/*
感觉跟滑雪很像，但是又不一样
滑雪由于只能从高处往低处滑，满足无后效性可以记忆化
但是这道题不可以，它有可能走回去。

不如从部分分开始：指示符只会是D,R
每个点只会走一次，也不用理会点会变相反。可以记忆化。
然后注意到一个性质，一个点左脚进入的最大得分刚好是右脚进入的相反数
这个可以直接跑一次dfs出答案

唉唉？记忆化只能有向无环，但是这道题是有环的，那可以考虑缩点啊
考虑环内：只会有偶数的环，那么也就是说绕很多圈是不优的
    并且每个点只会有一个出边，所以环内与环外是隔离的
即使环内也是相当于有向无环的，那么这道题就是一个记忆化搜索
也不需要缩点，因为都是有向无环的
*/
