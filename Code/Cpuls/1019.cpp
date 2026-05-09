#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, l, r;
std::array<ll, MAX> a, f, que;
int cur = 0, head = 1, tail = 0; // 手写deque，存储最小值的下标

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    f.fill(INF), f[0] = 0;
    que[++tail] = 0;
    for (int i = 1; i <= n; i++) {
        int _l = std::max(i - r - 1, 0);
        int _r = std::max(i - l - 1, 0);
        while (head <= tail && que[head] < _l)
            head++;
        while (cur <= _r) {
            if (f[cur] != INF) {
                while (head <= tail && f[que[tail]] > f[cur])
                    tail--;
                que[++tail] = cur;
            }
            cur++;
        }
        que[++tail] = _r;
        f[i] = f[que[head]] + a[i];
    }

    std::cout << (f[n] == INF ? -1 : f[n]) << '\n';
    return 0;
}