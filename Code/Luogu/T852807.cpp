#include <bits/stdc++.h>
using ll = long long;
const int MAX = 20;
const int LEN = 250;
const ll mod = 998244353;

int n, k;
ll A, a[MAX], b[MAX];
int m;
struct Mat {
    ll M[LEN][LEN] = {};
    Mat operator*(const Mat &x) const {
        Mat res;
        for (int i = 0; i <= m; i++)
            for (int k = 0; k <= m; k++)
                for (int j = 0; j <= m; j++)
                    res.M[i][j] = (res.M[i][j] + M[i][k] * x.M[k][j]) % mod;
        return res;
    }
} dp;
ll gInv(ll x, int p = mod - 2) {
    ll res = 1;
    for (; p; x = x * x % mod, p >>= 1)
        if (p & 1) res = res * x % mod;
    return res;
}
Mat qpow(Mat x, int p) {
    Mat res;
    for (int i = 0; i <= m; i++)
        res.M[i][i] = 1;
    for (; p; x = x * x, p >>= 1)
        if (p & 1) res = res * x;
    return res;
}

// 判断一个状态是否合法
bool check(int x) {
    std::vector<bool> col(n + 1), num(n + 1);
    for (int k = 0; k < n * n; k++) {
        if (x & (1 << k)) {
            if (a[k + 1] == 0) return 0;
            if (col[k / n + 1] || num[k % n]) return 0;
            col[k / n + 1] = num[k % n] = 1;
        }
    }
    return 1;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    for (int i = 1; i <= n * n; i++)
        std::cin >> a[i], A += a[i];
    for (int i = 1; i <= n * n; i++)
        std::cin >> b[i];

    // 枚举所有的状态并编号
    std::vector<int> z;
    std::unordered_map<int, int> book;
    for (int i = 0; i <= (1 << (n * n)) - 1; i++) {
        if (check(i)) z.push_back(i);
    }
    // 冲突
    std::vector<int> conf(n * n + 1);
    for (int i = 0; i < n * n; i++)
        for (int j = 0; j < n * n; j++)
            if (i / n == j / n || i % n == j % n) conf[i] |= 1 << j;
    m = z.size();
    for (int i = 0; i < z.size(); i++)
        book[z[i]] = i + 1;

    // 预处理转移矩阵
    // 预处理概率部分
    for (int i = 0; i < z.size(); i++) {
        int h = z[i];
        int pc = __builtin_popcount(h);
        ll inv = gInv(A - pc);

        for (int k = 0; k < n * n; k++) {
            ll cnt = a[k + 1] - ((h >> k) & 1);
            if (!cnt) continue;

            int clash = h & conf[k];
            int tar = clash ? h ^ clash : h | (1 << k);
            int id = book[tar];

            dp.M[id][i + 1] = (dp.M[id][i + 1] + cnt * inv) % mod;
        }
    }
    // 总积分转移
    dp.M[0][0] = 1;
    for (int i = 0; i < z.size(); i++) {
        for (int k = 0; k < n * n; k++) {
            if (z[i] & (1 << k)) dp.M[0][i + 1] = (dp.M[0][i + 1] + b[k + 1]) % mod;
        }
    }
    dp = qpow(dp, k + 1);
    std::cout << dp.M[0][1] << '\n';
    return 0;
}
/*
好复杂的题目！期望题本质就是计数题
也就是说，最多只有 16 种牌。n 的含义其实是花色和数字的种类数
直接状压手牌！这样是可行的，因为我们是不可能同时拿两张一样的牌的
dp[t][h] 表示第 t 轮获得手牌 h 的概率
那么看看怎么转移？
每一轮，可以预处理出当前手牌的状态集合，假如已经知道一个手牌，接下来有可能是什么状态？
依次去翻每一位，用个 set 去存决策集合
然后就可以愉快转移了，每一个决策，概率会贡献 ((那张牌有多少张)/(牌堆大小))*dp[t][h]
但是要算 k 轮，这不算爆你？
但是我们注意到合法手牌状态非常小啊，而且同一个手牌同一个牌堆，每一轮都是一样的
这不直接转移矩阵！？
直接预处理转移矩阵然后矩阵快速幂秒了
*/