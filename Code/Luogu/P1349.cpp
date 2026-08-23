#include <bits/stdc++.h>
using ll = long long;

ll p, q, a, b, n, m;
struct Mat {
    ll mt[2][2];
    Mat operator*(const Mat &rhs) const {
        Mat res;
        res.mt[0][0] = (mt[0][0] * rhs.mt[0][0] + mt[0][1] * rhs.mt[1][0]) % m;
        res.mt[0][1] = (mt[0][0] * rhs.mt[0][1] + mt[0][1] * rhs.mt[1][1]) % m;
        res.mt[1][0] = (mt[1][0] * rhs.mt[0][0] + mt[1][1] * rhs.mt[1][0]) % m;
        res.mt[1][1] = (mt[1][0] * rhs.mt[0][1] + mt[1][1] * rhs.mt[1][1]) % m;
        return res;
    }
} x;

Mat qpow(Mat x, ll b) {
    Mat res;
    res.mt[0][1] = res.mt[1][0] = 0;
    res.mt[0][0] = res.mt[1][1] = 1;
    while (b) {
        if (b & 1)
            res = res * x;
        x = x * x;
        b >>= 1;
    }
    return res;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> p >> q >> a >> b >> n >> m;
    x.mt[0][0] = p;
    x.mt[0][1] = q;
    x.mt[1][0] = 1;
    if (n == 1) {
        std::cout << a % m;
        return 0;
    }
    if (n == 2) {
        std::cout << b % m;
        return 0;
    }
    x = qpow(x, n - 2);
    std::cout << (b * x.mt[0][0] + a * x.mt[0][1]) % m << '\n';
    return 0;
}