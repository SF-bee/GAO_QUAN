#include <bits/stdc++.h>
using ll = long long;
const int N = 1e7 + 5;
const int MAX = 1e5 + 5;

int n;
int tk[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int a, i = 1; i <= n; i++) {
        std::cin >> a;
        tk[a]++;
    }
    std::queue<ll> q1, q2;
    for (int i = 0; i < MAX; i++)
        while (tk[i]--)
            q1.push(i);

    auto getn = [&]() {
        ll x = LONG_LONG_MAX, y = LONG_LONG_MAX;
        if (!q1.empty())
            x = q1.front();
        if (!q2.empty())
            y = q2.front();
        if (x <= y) {
            q1.pop();
            return x;
        } else {
            q2.pop();
            return y;
        }
    };
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ll x = getn(), y = getn();
        ans += x + y;
        q2.push(x + y);
    }
    std::cout << ans << '\n';
}