#include <bits/stdc++.h>
const int MAX = 2e7 + 5;

std::string s;
int len, n, r[MAX];
char ch[MAX];
int q;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> len >> s;
    ch[++n] = '|';
    for (char c : s) {
        ch[++n] = c;
        ch[++n] = '|';
    }
    ch[++n] = '|';
    for (int i = 1, j = 0, m = 0; i < n; i++) {
        if (i <= j)
            r[i] = std::min(r[2 * m - i], j - i + 1);
        while (ch[i - r[i]] == ch[i + r[i]])
            r[i]++;
        if (i + r[i] - 1 >= j) {
            j = i + r[i] - 1;
            m = i;
        }
    }

    std::cin >> q;
    std::string name[2] = {"Mr.Xu\n", "Mr.Shi\n"};
    auto check = [&](int ql, int qr) { return r[ql + qr] >= qr - ql + 1; };
    while (q--) {
        int ql, qr;
        std::cin >> ql >> qr;
        if (check(ql, qr)) {
            std::cout << name[1];
        } else {
            if ((qr - ql + 1) & 1)
                std::cout << name[0];
            else
                std::cout << name[1];
        }
    }
    return 0;
}