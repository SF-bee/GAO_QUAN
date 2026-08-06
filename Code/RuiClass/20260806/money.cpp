#include <bits/stdc++.h>
using ll = long long;
const int MAX = 6e5 + 5;

int n;
ll k, pre[MAX];

struct BIT {
    ll sum[MAX];
#define lowbit(x) (x & (-x))
    void add(int pos, ll x) {
        for (; pos < MAX; pos += lowbit(pos))
            sum[pos] += x;
    }
    ll query(int pos) {
        ll res = 0;
        while (pos) {
            res += sum[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
#undef lowbit
} bit;

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    std::vector<ll> book;
    std::unordered_map<ll, int> mp;
    for (int i = 1; i <= n; i++) {
        std::cin >> pre[i];
        pre[i] += pre[i - 1];
        book.push_back(pre[i]);
        book.push_back(pre[i] - k);
    }
    book.push_back(0);
    std::sort(book.begin(), book.end());
    book.erase(std::unique(book.begin(), book.end()), book.end());
    for (int i = 0; i < book.size(); i++)
        mp[book[i]] = i + 1;
    ll ans = 0;
    bit.add(mp[0], 1);
    for (int i = 1; i <= n; i++) {
        ans += bit.query(mp[pre[i] - k]);
        bit.add(mp[pre[i]], 1);
    }
    if (0 >= k)
        ans++;
    std::cout << ans << '\n';
    return 0;
}
/*
考虑前缀和
等价于求出所有的(i,j)使得sum_j - sum_i-1 >= k;

对于一个固定的j，它对答案的贡献就是比最小的sum_i-1大的元素个数
考虑维护一个前缀最小值，如何求出前缀中所有比它大的元素个数？
考虑权值树状数组
*/