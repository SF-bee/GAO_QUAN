#include <bits/stdc++.h>
const int MAX = 200;

int n;
// 注意数字是字符数字
std::pair<char, char> mes[MAX];

void sol1() {
    std::set<std::pair<char, char>> ty;
    std::map<std::pair<char, char>, int> s;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        s[mes[i]]++, ty.insert(mes[i]);
        if (mes[i].first != '1' && mes[i].first != '9' && mes[i].second != 'c') flag = 0;
    }
    if (ty.size() == 7) std::cout << "1/1\n";
    else if (ty.size() >= 13 && flag)
        std::cout << "1/1\n";
    else if (s.size() == 5) {
        int cnt2 = 0, cnt3 = 0;
        for (auto [u, v] : s) {
            if (v == 2) cnt2++;
            if (v == 3) cnt3++;
        }
        if (cnt2 == 1 && cnt3 == 4) std::cout << "1/1\n";
        else
            std::cout << "0/1\n";
    } else
        std::cout << "0/1\n";
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> mes[i].first >> mes[i].second;
    if (n <= 14) sol1();
    return 0;
}
/*
1～4的点好做啊！
等于 14，那就必须全部拿
*/