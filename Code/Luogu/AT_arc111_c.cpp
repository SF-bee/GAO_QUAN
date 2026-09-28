#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n;
int a[MAX], b[MAX], p[MAX];
int cnt, ans;
bool vis[MAX];
std::vector<int> cet[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];
    for (int i = 1; i <= n; i++)
        std::cin >> p[i];

    for (int i = 1; i <= n; i++) {
        if (p[i] != i && b[p[i]] >= a[i]) {
            std::cout << -1 << '\n';
            return 0;
        }
        if (vis[i]) continue;
        cnt++;
        for (int ps = i; !vis[ps]; ps = p[ps]) {
            vis[ps] = 1;
            cet[cnt].push_back(ps);
        }
        ans += cet[cnt].size() - 1;
    }
    std::cout << ans << '\n';
    for (int i = 1; i <= cnt; i++) {
        if (!cet[i].size()) continue;
        int id = 0;
        for (int j = 1; j < cet[i].size(); j++)
            if (a[cet[i][j]] > a[cet[i][id]]) id = j;
        for (int j = id + 1; j < cet[i].size(); j++)
            std::cout << cet[i][id] << ' ' << cet[i][j] << '\n';
        for (int j = 0; j < id; j++)
            std::cout << cet[i][id] << ' ' << cet[i][j] << '\n';
    }
    return 0;
}
/*
考虑变成环上问题
相当于安排某种操作顺序
求出每一个环
每一个环上：以最重的人为中心按照环上的顺序开始交换，同时判断这次交换是否成功，
        如果不成功，那么一定不合法，切出
可以保证：
一定是最优的：环上交换的最少次数就是这么实现的
不合法则不存在方案：有人不能换出去，那么其他方案也不可能

*/