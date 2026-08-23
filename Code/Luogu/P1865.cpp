#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;

int n, m, PrimCnt[MAX];
bool NotPrime[MAX];
std::vector<int> Prime;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 2; i <= m; i++) {
        if (!NotPrime[i])
            Prime.push_back(i), PrimCnt[i] = 1;
        for (auto p : Prime) {
            if (p * i > m)
                break;
            NotPrime[p * i] = 1;
            if (i % p == 0)
                break;
        }
    }
    for (int i = 1; i <= m; i++)
        PrimCnt[i] += PrimCnt[i - 1];
    while (n--) {
        int l, r;
        std::cin >> l >> r;
        if (1 <= l && l <= r && r <= m)
            std::cout << PrimCnt[r] - PrimCnt[l - 1] << '\n';
        else
            std::cout << "Crossing the line\n";
    }
    return 0;
}