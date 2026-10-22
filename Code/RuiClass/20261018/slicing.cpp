#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int T;
int n, cnt[MAX];
ll m, x[MAX], y[MAX];

void sol(int id) {
    std::memset(cnt, 0, sizeof(cnt));
    std::cin >> n >> m;
    std::vector<ll> book;
    for (int i = 1; i <= n; i++) {
        std::cin >> x[i] >> y[i];
        x[i]++, y[i]--;
        if (x[i] <= y[i]) {
            book.push_back(x[i]);
            book.push_back(y[i] + 1);
        }
    }

    std::sort(book.begin(), book.end());
    book.erase(std::unique(book.begin(), book.end()), book.end());
    std::map<ll, ll> mp;
    for (int i = 1; i <= n; i++) {
        if (x[i] <= y[i]) {
            int left = std::lower_bound(book.begin(), book.end(), x[i]) - book.begin() + 1;
            int right = std::lower_bound(book.begin(), book.end(), y[i] + 1) - book.begin() + 1;
            cnt[left]++;
            cnt[right]--;
        }
    }
    int len = book.size();
    for (int i = 1; i <= len; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 1; i < len; i++)
        mp[cnt[i]] += book[i] - book[i - 1];
    ll ans = n;
    for (auto i = mp.rbegin(); i != mp.rend(); i++) {
        ll val = i->first;
        ll c = i->second;
        if (m > c) {
            ans += val * c;
            m -= c;
        } else {
            ans += val * m;
            break;
        }
    }
    std::cout << "Case #" << id << ": ";
    std::cout << ans << '\n';
}

int main() {
    freopen("slicing2.in", "r", stdin);
    freopen("slicing.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    int id = 1;
    while (T--)
        sol(id++);
    return 0;
}
/*
很直观的想法：差分，区间覆盖
然后统计每一个区间覆盖发生变化的位置，类似扫描线
对于每一段，统计覆盖的次数
开一个 map，记录[覆盖次数]：可用切割点
那么区间巨大如何？离散化，每一个变化的区间映射回原值
*/