#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;

int c, t;
int n;
ll x[MAX];

void sol() {
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> x[i];
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> c >> t;
    while (t--)
        sol();
    return 0;
}
/*
设 d_{i,j} 为 i 到 j 的最短路
d 可以 n^2 预处理
对于每一个左端点 l，我们求出 f_i 表示 l 到 i 最短路径的条数
那么转移就是 /sum_{L(i) <= j < i && d[j][i] = d[l][i] + 1} f_j
*/
