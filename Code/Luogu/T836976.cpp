#include <bits/stdc++.h>
using ll = long long;
const int N = 2e5 + 5;

int n;
ll a[N];
int GetNum(ll x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}
struct BIT {
    ll sum[N];
#define lowbit(x) ((x) & -(x))
    void add(int x, ll v) {
        for (; x <= n; x += lowbit(x))
            sum[x] += v;
    }
    ll query(int x) {
        ll res = 0;
        for (; x; x -= lowbit(x))
            res += sum[x];
        return res;
    }
#undef lowbit
} bit;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        // 前面出现 i - 1 次，后面出现 n - i 次，系数就是 (n - i) - (i - 1)
        ans += GetNum(a[i]) * (2 * i - n - 1);

    ll base = 1;
    for (int k = 1; k <= 15; k++) {
        base *= 10;
        std::vector<ll> v, book;
        memset(bit.sum, 0, sizeof(bit.sum));
        for (int i = 1; i <= n; i++)
            v.push_back(a[i] % base);
        book = v;
        std::sort(book.begin(), book.end());
        book.erase(std::unique(book.begin(), book.end()), book.end());
        // 统计后减前，那要统计的是比它大的呀
        for (int i = 1; i <= n; i++) {
            ll pos = std::lower_bound(book.begin(), book.end(), v[i - 1]) - book.begin() + 1;
            ans += (bit.query(n) - bit.query(pos)) * 9;
            bit.add(pos, 1);
        }
    }
    std::cout << ans << "\n";
    return 0;
}
/*
n = 2000 可以直接暴力
然后 a <= 9 可以想一下
首先注意到的是 a 的顺序不影响答案，这也许可以排序？
所以正解应该是固定一个端点，然后a_j - a_i每个位的求和可能是一个与前缀有关的值
假如已知 s(a_j) - s(a_i) 呢？
那么就是对于每一位，如果它借了位，就会让答案 +9
按照每一位扫一遍数组，然后统计逆序对！？
*/