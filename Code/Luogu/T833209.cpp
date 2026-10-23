#include <bits/stdc++.h>
using ll = long long;
const int MAX = 3e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n;
struct Sub {
    ll h, m, a, b;
    bool operator<(const Sub &rhs) const { return h > rhs.h; }
} s[MAX];

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> s[i].h >> s[i].m >> s[i].a >> s[i].b;

    auto check = [&](ll x) {
        ll cnt = 0;
        std::vector<std::pair<int, ll>> lst;
        for (int i = 1; i <= n; i++) {
            if (s[i].h >= x) {
                cnt += s[i].m;
                continue;
            } else {
                ll v = std::max(s[i].a, s[i].b);
                ll res = (x - s[i].h + v - 1) / v;
                if (res <= s[i].m) cnt += s[i].m - res;
                else
                    lst.emplace_back(i, s[i].h + s[i].m * v);
            }
        }
        bool flag = true;
        for (auto [i, v] : lst) {
            cnt -= (x - v + s[i].b - 1) / s[i].b;
            if (cnt < 0) flag = false;
        }
        return flag;
    };
    ll ans = 1;
    for (ll l = 1, r = INF, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) {
        if (check(mid)) {
            ans = mid;
            // std::cout << l << ' ' << r << ' ' << mid << '\n';
            // std::cout << check(mid) << '\n';
            l = mid + 1;
        } else
            r = mid - 1;
    }
    std::cout << ans << '\n';
    return 0;
}
/*
最小值最大，一眼二分，二分掌握度的最小值
现在考虑如何验证答案，假设最低掌握度为 x
难道是按照 h' 排序？然后把那些已经不需要学的课统计下来
首先，对应学科的课当然要先用来学那一科，不可能用别的课来自习，那不如直接在这节课自习一定是不劣的
按照a,b决定正课是听课还是学习
然后如果正课不够那么就把没用完的课补这门
顺序是个问题，我们应该把所有课都确认完毕拿总的剩下的课去分配给那些学科，否则可能导致某个学科需要后面的学科的课时
*/