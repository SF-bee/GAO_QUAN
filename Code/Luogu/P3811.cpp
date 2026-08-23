#include <bits/stdc++.h>
const int MAX = 3e6 + 5;
using ll = long long;

int n, p;
int inv[MAX];

int main() {
    std::cin.tie()->sync_with_stdio(0);

    std::cin >> n >> p;
    inv[1] = 1;
    std::cout << inv[1] << '\n';
    for (int i = 2; i <= n; i++) {
        inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
        std::cout << inv[i] << '\n';
    }
    return 0;
}