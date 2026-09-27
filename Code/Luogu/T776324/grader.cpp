#include <bits/stdc++.h>

int n, m;
std::vector<bool> s;

int cnt;
int dream(int x, int y, int z) {
    cnt++;
    return s[x] + s[y] + s[z];
}

#include "T776324.cpp"
int main() {
    freopen(".in", "r", stdin);
    std::cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        int ch;
        std::cin >> ch;
        s[i] = ch;
    }
    std::cin >> m;

    auto ans = solve(n);
    std::cout << (ans == s && cnt <= m ? "AC\n" : "WA\n");
    std::cout << cnt << '\n';
    return 0;
}