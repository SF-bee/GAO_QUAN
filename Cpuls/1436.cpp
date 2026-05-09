#include <bits/stdc++.h>
const int MAX = 500;
const int MAX_H = 4e4 + 5;

int k, m;
struct block {
    int h, a, c;
    bool operator<(const block &rhs) const { return a < rhs.a; }
};
std::array<block, MAX> b;
std::bitset<MAX_H> dp, lim;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> k;
    for (int i = 1; i <= k; i++) {
        std::cin >> b[i].h >> b[i].a >> b[i].c;
        m = std::max(m, b[i].a);
    }

    std::sort(b.begin() + 1, b.begin() + k + 1);
    dp[0] = 1;
    lim.set();
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= b[i].c; j++) {
            dp |= (lim >> (MAX_H - 1 - b[i].a)) & (dp << b[i].h);
        }
    }

    for (int hig = m; hig >= 0; hig--)
        if (dp[hig]) {
            std::cout << hig << '\n';
            break;
        }

    return 0;
}