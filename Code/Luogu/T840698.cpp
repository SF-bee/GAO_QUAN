#include <bits/stdc++.h>

int T;
int n, a1, a2, a3;

void sol() {
    std::cin >> n >> a1 >> a2 >> a3;
    if (a1 == 0 && a3 == 0) {
        std::cout << -1 << '\n';
        return;
    }
    std::vector<std::pair<int, int>> g(n + 1, {0, 0});
    auto add = [&](int u, int v) {
        
    };
    if (a1 >= 2) {
        std::cout <<
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    while (T--)
        sol();
    return 0;
}
/*
题解说是大分讨，那么从部分分开始吧
考虑无解？当a1 = a3 = 0的时候是无解的
图染色，每个点必然是黑白的，然后因为距离都是 2 颜色一定都是一样的，矛盾。所以无解
只有a1,a2?
直接把所有的a1排成链，接下来的a2接到倒数第二个点上，这样一定可以用完所有a1,a2，
也就是说，a1,a2的消耗是容易的，考虑a3
一个长度为3的链是一定可以消耗所有的a1,a2,a3的，直接考虑怎么最小的搞出这个链
原来部分分是干这个的
a1 >= 1,a2 >= 1,边12 23 14,排列1243
a1 >= 2,12 23,123
a1 = 1,a2 = 0, 12 13 15 26 34,124563
a1 = 0,a2 >= 2,
*/