#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n, k;
std::pair<int, int> p[MAX];
std::vector<int> sp[9];

void in(int x) {
    int id = 0;
    if (p[x].first >= k + 1 && p[x].first <= 2 * k) id += 1;
    else if (p[x].first >= 2 * k + 1)
        id += 2;
    if (p[x].second >= k + 1 && p[x].second <= 2 * k) id += 3;
    else if (p[x].second >= 2 * k + 1)
        id += 6;
    sp[id].push_back(x);
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    k = n / 3;
    for (int i = 1; i <= n; i++)
        std::cin >> p[i].first >> p[i].second, in(i);

    std::cout << 4ll * k * k << '\n';
    std::array<std::array<int, 3>, 6> ch = {
        {{0, 4, 8}, {0, 5, 7}, {1, 3, 8}, {1, 5, 6}, {2, 3, 7}, {2, 4, 6}}};
    for (int i = 1; i <= n; i++)
        for (auto [a, b, c] : ch)
            if (sp[a].size() && sp[b].size() && sp[c].size()) {
                std::cout << sp[a].back() << ' ' << sp[b].back() << ' ' << sp[c].back() << '\n';
                sp[a].pop_back(), sp[b].pop_back(), sp[c].pop_back();
            }

    return 0;
}
/*
考虑答案上界，注意到a,b是独立贡献的。
最大的取 2k + 1 ～ 3k，就是 (5k + 1)k/2
最小的取 1 ～ k,就是 (k + 1)k/2
相减就是最大值。b同理
那么，考虑我们是如何取到这个最大值的？
考虑分成三个部分：
0 1 2
3 4 5
6 7 8
*/