#include <bits/stdc++.h>
#define int long long

int T;

void exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
}

signed main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    while (T--) {
        int a, b, c, x, y;
        std::cin >> a >> b >> c;
        int g = std::__gcd(a, b);
        if (c % g != 0)
            std::cout << -1 << '\n';
        else {
            exgcd(a, b, x, y);
            x = x * (c / g);
            y = y * (c / g);
            int Maxt = std::ceil(1.0 * x / (b / g)) - 1;
            int Mint = std::floor(-1.0 * y / (a / g)) + 1;
            if (Maxt < Mint)
                std::cout << x - b / g * Maxt << ' ' << y + a / g * Mint << '\n';
            else {
                std::cout << Maxt - Mint + 1 << ' ';
                std::cout << x - b / g * Maxt << ' ' << y + a / g * Mint << ' ';
                std::cout << x - b / g * Mint << ' ' << y + a / g * Maxt << '\n';
            }
        }
    }
    return 0;
}