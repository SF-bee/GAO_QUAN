#include <bits/stdc++.h>
const int MAX = 5e5 + 5;
const int mod = 1e9 + 7;

int n, a[MAX], b[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::set<int> s;
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
        if (a[i] == b[i]) s.insert(a[i]);
    }
    int mex = 0;
    for (auto i = s.begin(); i != s.end(); i++) {
        if (*i == mex) mex++;
        if (*i > mex) break;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == mex || b[i] == mex) cnt++;
    }
    auto qpow = [&](int x, int p) {
        int res = 1;
        for (; p; x = (1ll * x * x % mod), p >>= 1)
            if (p & 1) res = (1ll * res * x % mod);
        return res;
    };
    std::cout << mex << ' ' << qpow(2, n - cnt) << '\n';
    return 0;
}
/*
贪心吧，直接找可以令mex最小的那次交换，其他的怎么换都不会影响的。
只有  b > a 才有可能，在此基础上a越小越好，因为答案只会和最小的 a 有关
也就是说，我们统计能贡献最小的mex所在的位置个数，那么这里就不能变了
哪些位置可以贡献？我们可以对每个对按照a排序，我们需要找到第一个令a不连续的位置
好像不太对。
考虑那些a = b的位置，那么这个数字很明显是一定会存在的，不可能是mex

*/
