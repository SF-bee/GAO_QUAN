#include <bits/stdc++.h>
const int MAX = 2e6 + 5;

int n, m;
int a[MAX];
std::array<int, 32> cnt;

void Update(int u, int v) {
    for (int i = 0; i < 32; i++) {
        if (~a[u] & (1 << i) && v & (1 << i))
            cnt[i]++;
        else if (a[u] & (1 << i) && ~v & (1 << i))
            cnt[i]--;
    }
    a[u] = v;
}
int GetAns() {
    for (int j = 0; j < 32; j++) {
        if (cnt[j] != n && cnt[j] != 0)
            return j + 1;
    }
    return -1;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int v, i = 1; i <= n; i++) {
        std::cin >> v;
        Update(i, v);
    }

    while (m--) {
        int u, v;
        std::cin >> u >> v;
        Update(u, v);
        std::cout << GetAns() << '\n';
    }
    return 0;
}